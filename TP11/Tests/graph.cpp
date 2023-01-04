// AED 2022/2023 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [last update: 04/12/2022]

#include <stack>
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

bool Graph::dfs_bipartido(int v, int color) {
    nodes[v].visited = true;
    nodes[v].color = color;

    for (Edge e : nodes[v].adj)  {
        int w = e.dest;
        if (nodes[w].visited && nodes[w].color == color) return false;
        if (!nodes[w].visited) {
            return dfs_bipartido(w, -color);
        }
    }
    return true;
}

int Graph::dfs_count (int v, int &order, stack<int> & s) {
    nodes[v].visited = true;
    nodes[v].num = nodes[v].low = order++;
    s.push(v);
    nodes[v].inStack = true;

    int counter = 0;

    for (Edge e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
            counter += dfs_count(w, order, s);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
        }
        else if (nodes[w].inStack) {
            nodes[v].low = min (nodes[v].low, nodes[w].num);
        }
    }

    if (nodes[v].low == nodes[v].num) {
        int w;
        do {
            w = s.top();
            s.pop();
            nodes[w].inStack = false;
        } while (w != v);
        counter++;
    }
    return counter;
}

void Graph::dfs_list_scc (int v, int &order, stack<int> &s, list<list<int>> &ll) {
    nodes[v].visited = true;
    nodes[v].num = nodes[v].low = order++;
    s.push(v);
    nodes[v].inStack = true;

    for (Edge e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
            dfs_list_scc(w, order, s, ll);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
        }
        else if (nodes[w].inStack) {
            nodes[v].low = min(nodes[v].low, nodes[w].num);
        }
    }

    if (nodes[v].low == nodes[v].num) {
        int w;
        list<int> scc;

        do {
            w = s.top();
            s.pop();
            scc.push_back(w);
            nodes[w].inStack = false;
        } while (w != v);
        ll.push_back(scc);
    }
}


// ----------------------------------------------------------
// Exercicio 1: DFS e grafos bipartidos
// ----------------------------------------------------------
bool Graph::bipartite() {
    for (Node &node : nodes) {
        node.visited = false;
    }

    for (int i = 1; i <= n; i++) {
        if (!nodes[i].visited)
            return dfs_bipartido(i, 1);
    }
    return false;
}

void Graph::dfs_articulation (int v, int &order, list<int> &l) {
    nodes[v].visited = true;
    nodes[v].num = nodes[v].low = order++;

    int children = 0;
    bool articulation = false;

    for (Edge e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
            children++;
            dfs_articulation(w, order, l);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
            if (nodes[w].low >= nodes[v].num) articulation = true;
        }
        else
            nodes[v].low = min(nodes[v].low, nodes[w].num);
    }

    if ((nodes[v].num == 1 && children > 1) || (nodes[v].num > 1 && articulation))
        l.push_front(v);
}

// ----------------------------------------------------------
// Exercicio 2.a: Contando componentes fortemente conexos.
// ----------------------------------------------------------
int Graph::countSCCs() {
    for (Node &node : nodes) {
        node.visited = false;
        node.inStack = false;
        node.low = 0;
        node.num = 0;
    }

    int count = 0;
    int order = 1;
    stack<int> s;

    for (int v = 1; v <= n; v++) {
        if (!nodes[v].visited) {
            count += dfs_count(v, order, s);
        }
    }

    return count;
}

// ----------------------------------------------------------
// Exercicio 2.b: Listando componentes fortemente conexos
// ----------------------------------------------------------
list<list<int>> Graph::listSCCs() {
    list<list<int>> answer;
    for (Node &node : nodes) {
        node.visited = false;
        node.inStack = false;
        node.low = 0;
        node.num = 0;
    }

    int order = 1;
    stack<int> s;

    for (int v = 1; v <= n; v++) {
        if (!nodes[v].visited) {
            dfs_list_scc(v, order, s, answer);
        }
    }

    return answer;
}

// ----------------------------------------------------------
// Exercicio 3: Pontos de articulação
// ----------------------------------------------------------
list<int> Graph::articulationPoints() {
    list<int> answer;

    for (Node &node : nodes) {
        node.visited = false;
        node.parent = -1;
        node.low = 0;
        node.num = 0;
    }

    int order = 1;
    for (int v = 1; v <= n; v++) {
        if (!nodes[v].visited) {
            dfs_articulation(v, order, answer);
        }
    }

    return answer;
}


