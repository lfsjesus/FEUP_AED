// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    // cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

int Graph::count_nodes(int v) {
    int visited_nodes = 1;
    nodes[v].visited = true;

    for (Edge edge : nodes[v].adj) {
        int w = edge.dest;
        if (!nodes[w].visited) {
            visited_nodes += count_nodes(w);
        }
    }
    return visited_nodes;
}

void Graph::dfs_topological(int v, list<int> &l) {
    nodes[v].visited = true;

    for (Edge e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs_topological(w, l);
    }
    l.push_front(v);
}

bool Graph::dfs_cycle(int v) {
    nodes[v].color = 1;

    for (Edge e : nodes[v].adj) {
        int w = e.dest;
        if (nodes[w].color == 1) return true;
        if (nodes[w].color == 0)
            return dfs_cycle(w);
    }
    nodes[v].color = 2;
    return false;
}

pair<bool, int> Graph::dfs_cycle_count(int v) {
    int nodes_visited = 1;
    nodes[v].color = 1;     // gray, visiting

    for (auto &e : nodes[v].adj) {
        if (e.color == 1) continue;
        e.color = 1;
        int w = e.dest;
        for (auto &rev_edge : this->nodes[w].adj) {
            if (rev_edge.dest == v) rev_edge.color = 1;
        }
        if (nodes[w].color == 1) {
            return {true, nodes_visited};
        }        // cycle found!
        if (nodes[w].color == 0) {                                      // if white, visit
            pair<bool, int> r = dfs_cycle_count(w);
            nodes_visited += r.second;
            if (r.first) return {true, nodes_visited};
        }
    }
    nodes[v].color = 2;     // black, finished dfs
    return {false, nodes_visited};
}


// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Devolvendo o grau
int Graph::outDegree(int v) {
    if (v < 1 || v > n) return -1;
    return (int) nodes[v].adj.size();
}

// ..............................
// b) Devolvendo o grau... pesado
int Graph::weightedOutDegree(int v) {
    if (v < 1 || v > n) return -1;
    int sum = 0;
    for (auto el : nodes[v].adj) {
        sum += el.weight;
    }
    return sum;
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
int Graph::connectedComponents() {
    int components = 0;

    for (Node &node : nodes)
        node.visited = false;

    for (int i = 1; i <= n; i++) {
        if (!nodes[i].visited) {
            dfs(i);
            components++;
        }

    }
    return components;
}

// ..............................
// b) Componente gigante
int Graph::giantComponent() {
    int max_size = 0;
    for (Node &node : nodes)
        node.visited = false;

    for (int i = 1; i <= n; i++) {
        if (!nodes[i].visited) {
            int size = count_nodes(i);
            if (size > max_size) max_size = size;
        }

    }
    return max_size;
}

// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
list<int> Graph::topologicalSorting() {
    list<int> order;

    for (Node &node : nodes) node.visited = false;

    for (int i = 1; i <= n; i++) {
        if (!nodes[i].visited)
            dfs_topological(i, order);
    }

    return order;
}

// ----------------------------------------------------------
// Exercicio 4: To be or not be… a DAG!
// ----------------------------------------------------------
bool Graph::hasCycle() {
    for (Node &node : nodes) node.visited = false;

    for (int i = 1; i <= n; i++) {
        if (nodes[i].color == 0)
            return dfs_cycle(i);
    }
    return false;
}
