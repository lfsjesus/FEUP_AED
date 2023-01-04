// AED 2022/2023 - Aula Pratica 12
// Pedro Ribeiro (DCC/FCUP) [last update: 11/12/2022]

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
    Graph g(12, false);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(1,8);
    g.addEdge(2,8);
    g.addEdge(3,8);
    g.addEdge(7,8);
    g.addEdge(8,9);
    g.addEdge(10,11);
    g.addEdge(11,12);
    g.addEdge(11,5);
    g.addEdge(11,6);
    g.addEdge(12,5);
    g.addEdge(12,6);
    g.addEdge(5,6);
    return g;
}

Graph FunWithGraphs::graph3() {
    Graph g(10, false);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,6);
    g.addEdge(5,10);
    g.addEdge(2,6);
    g.addEdge(4,10);
    g.addEdge(6,7);
    g.addEdge(7,8);
    g.addEdge(8,9);
    g.addEdge(9,10);
    return g;
}

// ----------------------------------------------------------
// Exercicio 2: Um labirinto 2D
// ----------------------------------------------------------
int FunWithGraphs::maze(int rows, int cols, string m[]) {
    pair<int, int> start, end;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] == 'P') start = {i, j};
            if (m[i][j] == 'T') end = {i, j};
        }
    }
    bool visited[rows][cols];
    int dist[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = false;
            dist[i][j] = -1;
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) { // 4 directions
            int x  = u.first + dx[i];
            int y = u.second + dy[i];
            if (!visited[x][y] && m[x][y] != '#') {
                visited[x][y] = true;
                dist[x][y] = dist[u.first][u.second] + 1;
                q.push({x, y});
            }

        }
    }
    return dist[end.first][end.second];
}

// ----------------------------------------------------------
// Exercicio 3: Nuvem de Cinzas
// --------------------------------------------------------
pair<int, int> FunWithGraphs::volcano(int rows, int cols, string m[]) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int dist[rows][cols];

    queue<pair<int, int>> q; // queue of unvisited nodes
    int airports = 0, airports_covered = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] == '#') {
                q.push({i, j});
                dist[i][j] = 0;
            }
            else dist[i][j] = -1;
            if (m[i][j] == 'A') airports++;
        }
    }

    pair<int, int> ans = {-1, -1};
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {  // for each direction
            int x = u.first + dx[i];
            int y = u.second + dy[i];

            if (x >= 0 && x < rows && y >= 0 && y < cols) {
                if (dist[x][y] == -1) {
                    dist[x][y] = dist[u.first][u.second] + 1;
                    q.push({x, y});
                    if (m[x][y] == 'A') {
                        if (airports_covered == 0) ans.first = dist[x][y];
                        airports_covered++;
                        if (airports_covered == airports) {
                            ans.second = dist[x][y];
                            return ans;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

// ----------------------------------------------------------
// Exercicio 4: Quadrados Mágicos
// ----------------------------------------------------------
pair<int, string> FunWithGraphs::game(const vector<int> & target) {
    return {0, ""};
}
