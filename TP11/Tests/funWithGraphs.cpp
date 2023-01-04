// AED 2022/2023 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [last update: 04/12/2022]
#include <climits>
#include "funWithGraphs.h"

// ----------------------------------------------------------
// Some Example Graphs
// ----------------------------------------------------------

Graph FunWithGraphs::graph1() {
    Graph g(8, false);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,5);
    g.addEdge(1,6);
    g.addEdge(3,6);
    g.addEdge(3,7);
    g.addEdge(4,8);
    g.addEdge(7,8);
    return g;
}

Graph FunWithGraphs::graph2() {
    Graph g(8, false);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,5);
    g.addEdge(1,6);
    g.addEdge(3,6);
    g.addEdge(3,7);
    g.addEdge(4,8);
    g.addEdge(7,8);
    g.addEdge(6,7);
    return g;
}

Graph FunWithGraphs::graph3() {
    Graph g(7, false);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,5);
    g.addEdge(3,6);
    g.addEdge(4,7);
    g.addEdge(5,6);
    g.addEdge(6,7);
    return g;
}

Graph FunWithGraphs::graph4() {
    Graph g(7, false);
    g.addEdge(1,5);
    g.addEdge(2,5);
    g.addEdge(2,6);
    g.addEdge(3,6);
    g.addEdge(4,6);
    g.addEdge(4,7);
    return g;
}

Graph FunWithGraphs::graph5() {
    Graph g(8, true);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(4,3);
    g.addEdge(5,1);
    g.addEdge(2,6);
    g.addEdge(7,3);
    g.addEdge(3,8);
    g.addEdge(8,4);
    g.addEdge(6,5);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph6() {
    Graph g(8, true);
    g.addEdge(2,1);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(1,5);
    g.addEdge(1,6);
    g.addEdge(6,3);
    g.addEdge(7,3);
    g.addEdge(4,8);
    g.addEdge(8,4);
    g.addEdge(7,6);
    g.addEdge(7,8);
    return g;
}

Graph FunWithGraphs::graph7() {
    Graph g(8, true);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,3);
    g.addEdge(5,1);
    g.addEdge(2,5);
    g.addEdge(4,8);
    g.addEdge(8,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,6);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph8() {
    Graph g(7, true);
    g.addEdge(5,1);
    g.addEdge(5,2);
    g.addEdge(6,2);
    g.addEdge(6,3);
    g.addEdge(4,6);
    g.addEdge(7,4);
    return g;
}

Graph FunWithGraphs::graph9() {
    Graph g(10, false);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(5,7);
    g.addEdge(5,9);
    g.addEdge(7,8);
    g.addEdge(8,9);
    g.addEdge(8,10);
    return g;
}

Graph FunWithGraphs::graph10() {
    Graph g(4, false);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);
    return g;
}

Graph FunWithGraphs::graph11() {
    Graph g(5, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,5);
    return g;
}

Graph FunWithGraphs::graph12() {
    Graph g(8, false);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,5);
    g.addEdge(2,5);
    g.addEdge(3,8);
    g.addEdge(4,8);
    g.addEdge(5,6);
    g.addEdge(7,8);
    return g;
}

// ----------------------------------------------------------
// Exercicio 4: Quartel da Polícia
// ----------------------------------------------------------
pair<int, int> FunWithGraphs::police(vector<int> costs, vector<pair<int, int>> roads) {
    Graph g((int) costs.size(), true);
    for (auto road : roads) g.addEdge(road.first, road.second);
    for (int v = 1; v <= g.n; v++) {
        g.nodes[v].cost = costs[v - 1];
        g.nodes[v].visited = false;
        g.nodes[v].inStack = false;
        g.nodes[v].low = 0;
        g.nodes[v].num = 0;
    }

    list<list<int>> scc;
    int order = 1;
    stack<int> s;
    for (int v = 1; v <= g.n; v++)
        if (!g.nodes[v].visited)
            g.dfs_list_scc(v, order, s, scc);

    int cost = 0;
    int permutations = 1;

    for (const list<int>& l : scc) {
        int min_cost = INT_MAX;
        int n_min = 0;
        for (int v : l) {
            if (g.nodes[v].cost < min_cost) {
                min_cost = g.nodes[v].cost;
                n_min = 1;
            }
            else if (g.nodes[v].cost == min_cost) n_min++;
        }
        cost += min_cost;
        permutations *= n_min;
    }

    return {cost, permutations};
}
