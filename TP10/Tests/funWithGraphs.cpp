// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include "funWithGraphs.h"

// ----------------------------------------------------------
// Some Example Graphs
// ----------------------------------------------------------

Graph FunWithGraphs::graph1() {
    Graph g(9, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(5,7);
    g.addEdge(6,9);
    g.addEdge(7,8);
    return g;
}

Graph FunWithGraphs::graph2() {
    Graph g(9, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(6,9);
    g.addEdge(6,7);
    g.addEdge(8,7);
    g.addEdge(8,9);
    return g;
}

Graph FunWithGraphs::graph3() {
    Graph g(12, false);
    g.addEdge(8,1);
    g.addEdge(8,2);
    g.addEdge(8,3);
    g.addEdge(8,7);
    g.addEdge(8,9);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(5,6);
    g.addEdge(5,11);
    g.addEdge(5,12);
    g.addEdge(6,11);
    g.addEdge(6,12);
    g.addEdge(12,11);
    g.addEdge(11,10);
    return g;
}

Graph FunWithGraphs::graph4() {
    Graph g(9, true);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(9,6);
    g.addEdge(7,5);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph5() {
    Graph g(4, true);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(3,1);
    return g;
}

Graph FunWithGraphs::graph6() {
    Graph g(8, true);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(3,1);
    g.addEdge(5,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(6,8);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph7() {
    Graph g(3, true);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(3,2);
    return g;
}

Graph FunWithGraphs::graph8() {
    Graph g(9, false);
    g.addEdge(1,2, 5);
    g.addEdge(1,3, 4);
    g.addEdge(2,4, 8);
    g.addEdge(3,4, 7);
    g.addEdge(4,5, 3);
    g.addEdge(5,6, 5);
    g.addEdge(5,7, 9);
    g.addEdge(6,9, 1);
    g.addEdge(7,8, 2);
    g.addEdge(8,9, 42);
    return g;
}

Graph FunWithGraphs::graph9() {
    Graph g(4, false);
    g.addEdge(1,2, 3);
    g.addEdge(1,3, 4);
    g.addEdge(2,4, 3);
    g.addEdge(3,4, 4);
    return g;
}

Graph FunWithGraphs::graph10() {
    Graph g(8, true);
    g.addEdge(1,3, 3);
    g.addEdge(2,1, 2);
    g.addEdge(4,2, 1);
    g.addEdge(5,4, 1);
    g.addEdge(5,6, 2);
    g.addEdge(6,8, 1);
    g.addEdge(6,7, 2);
    g.addEdge(8,7, 3);
    return g;
}

Graph FunWithGraphs::graph11() {
    Graph g(3, true);
    g.addEdge(2,1, 2);
    g.addEdge(1,3, 8);
    g.addEdge(3,2, 1);
    return g;
}


// ----------------------------------------------------------
// Exercicio 5: Contagem de Celulas
// ----------------------------------------------------------
int dfs_grid(int r, int c, string* m, char v[100][100], int rows, int cols) {
    int nodes_visited = 1;
    int dx[] = {0, 0, -1, -1, -1, 1, 1, 1};
    int dy[] = {1, -1, 0, -1, 1, 0, -1, 1};

    v[r][c] = true;
    for (int d = 0; d < 8; d++) {
        int new_x = r + dx[d];
        int new_y = c + dy[d];

        if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= cols) continue;
        if (!(v[new_x][new_y]) && m[new_x][new_y] == '#') {
            nodes_visited += dfs_grid(new_x, new_y, m, v, rows, cols);
        }
    }
    return nodes_visited;
}

int FunWithGraphs::largestMicrobe(int rows, int cols, string m[]) {
    char visited[100][100];
    int big_microbe = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            visited[i][j] = false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] == '#' && !visited[i][j]) {
                int size = dfs_grid(i, j, m, visited, rows, cols);
                if (size > big_microbe) big_microbe = size;
            }
        }
    }
    return big_microbe;
}


// ----------------------------------------------------------
// Exercicio 6: Labirinto de Barras
// ----------------------------------------------------------
typedef vector<vector<int>> vii;
typedef vector<int> vi;

pair<int, int>FunWithGraphs::slashMaze(int rows, int cols, string m[]) {
    pair<int, int> ans = {-1, -1};
    int num_cells = rows * (cols-1) + (rows-1) * cols;
    Graph g(num_cells);
    vii grid(rows*2-1, vi(cols, 0));

    int node_number = 1;
    for (int i = 0; i < rows*2-1; i++) {
        for (int j = 0; j < cols; j++) {
            if (i%2 == 0 && j == cols-1) continue;
            grid[i][j] = node_number++;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols-1; j++) {
            char l = m[i][j], r = m[i][j+1];
            if (l == '/' && i != rows-1) g.addEdge(grid[i*2][j], grid[i*2+1][j]);
            if (l == '\\' && i != 0) g.addEdge(grid[i*2][j], grid[i*2-1][j]);
            if (r == '\\' && i != rows-1) g.addEdge(grid[i*2][j], grid[i*2+1][j+1]);
            if (r == '/' && i != 0) g.addEdge(grid[i*2][j], grid[i*2-1][j+1]);
        }
    }

    int big_cycle = 0, num_cycles = 0;

    for (auto &n : g.nodes) {
        n.color = 0;     // white
        for (auto &e : n.adj) e.color = 0;
    }

    for (int n = 1; n <= g.n; n++) {
        if (g.nodes[n].color == 0) {
            auto r = g.dfs_cycle_count(n);
            if (r.first) {
                num_cycles++;
                big_cycle = max(big_cycle, r.second);
            }
        }
    }

    return {num_cycles, big_cycle};
}