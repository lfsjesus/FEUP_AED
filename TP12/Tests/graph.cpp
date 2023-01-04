// AED 2022/2023 - Aula Pratica 12
// Pedro Ribeiro (DCC/FCUP) [last update: 11/12/2022]

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

// Breadth-First Search: example implementation
void Graph::bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        // show node order
        //cout << u << " ";
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

// ----------------------------------------------------------
// Exercicio 1a: Distáncia entre dois nós
// ----------------------------------------------------------
int Graph::distance(int a, int b) {
    for (int i = 1; i <= n; i++) {
        nodes[i].visited = false;
        nodes[i].dist = -1; // distance from the source node
    }

    queue<int> q;
    q.push(a);
    nodes[a].visited = true;
    nodes[a].dist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto e : nodes[u].adj) {
            int w = e.dest;

            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].dist = nodes[u].dist + 1;
                if (w == b) break;
            }
        }
    }
    return nodes[b].dist;
}

// ----------------------------------------------------------
// Exercicio 1.b: Diâmetro
// ----------------------------------------------------------
int Graph::diameter() {
    int max = 0;

    bfs(1); // BFS to check if the graph is connected
    for (int i = 1; i <= n; i++) {
        if (!nodes[i].visited) return -1; // if the graph is not connected
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int dist = distance (i,j);
            if (dist > max) max = dist;
        }
    }
    return max;
}
