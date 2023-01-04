// AED 2022/2023 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [last update: 04/12/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        int color;
        int num;
        int low;
        bool inStack;
        int parent;
        int cost;
    };

    // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);

    // Depth-First Search: example implementation
    void dfs(int v);

    // ----- Functions to implement in this class -----
    bool bipartite();
    int countSCCs();
    list<list<int>> listSCCs();
    list<int> articulationPoints();

    bool dfs_bipartido(int v, int color);

    int dfs_count(int v, int &order, stack<int> &s);

    void dfs_list_scc (int v, int &order, stack<int> &s, list<list<int>> &ll) ;

    void dfs_articulation(int v, int &order, list<int> &l);

    vector<Node> nodes;
    int n;
};

#endif
