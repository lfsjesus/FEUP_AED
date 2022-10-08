// AED 2022/2023 - Aula Pratica 03
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 02/10/2022]

#include "funWithSearch.h"
#include <climits>
#include <algorithm>

// ----------------------------------------------------------
// Exercicio 1: Pesquisa Elementar
// ----------------------------------------------------------

int FunWithSearch::search(const vector<int> & v, int key) {
    int size = v.size();
    int lower = 0;
    int upper = size - 1;

    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;
        if (key == v[mid]) return mid;
        else if (key > v[mid]) {
            lower = mid + 1;
        }
        else {
            upper = mid - 1;
        }
    }
    return -1;

}

// ----------------------------------------------------------
// Exercicio 2: Limite Inferior
// ----------------------------------------------------------

int FunWithSearch::lowerBound(const vector<int> &v, int key) {
    int size = v.size();
    int lower = 0;
    int upper = size - 1;

    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        if (key <= v[mid]) upper = mid;
        else {
            lower = mid + 1;
        }
    }
    if (v[lower] < key) return -1;
    return lower;
}
// ----------------------------------------------------------
// Exercicio 3: Intervalos
// ----------------------------------------------------------
int FunWithSearch::countRange(const vector<int> & v, int a, int b) {
    int low = lowerBound(v, a);
    int up = lowerBound(v, b + 1); // Determines index of the next element after all elements <= b

    if (up == -1) up = v.size();
    if (low == -1) return 0;
    return up - low;
}

// ----------------------------------------------------------
// Exercicio 4a: Viagem de mochila às costas (isPossible)
// ----------------------------------------------------------
bool FunWithSearch::isPossible(const vector<int> & v, int x, int k) {
    int sum1 = 0;
    int partition = 1;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] > x) return false;
        if (sum1 + v[i] <= x) {
            sum1 += v[i];
        }
        else {
            sum1 = v[i];
            partition++;
        }
    }
    if (partition <= k) return true;
    return false;
}

// ----------------------------------------------------------
// Exercicio 4b: Viagem de mochila às costas (partitions)
// ----------------------------------------------------------

int FunWithSearch::partitions(const vector<int> & v, int k) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 5: Somas mais próximas
// ----------------------------------------------------------
// TODO
vector<int> FunWithSearch::closestSums(const vector<int> & v, const vector<int> & p) {
    vector<int> ans;
    return ans;
}

// ----------------------------------------------------------
// Exercicio 6: Jogo de strings
// ----------------------------------------------------------
// TODO
int FunWithSearch::stringGame(const string & a, const string & b, const vector<int> & p) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 7: Regras Quadriculadas
// ----------------------------------------------------------
// TODO
long long FunWithSearch::rules(int k, long long a, long long b) {
    return 0;
}