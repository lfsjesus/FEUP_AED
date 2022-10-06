// AED 2022/2023 - Aula Pratica 03
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 02/10/2022]

#include "funWithSearch.h"
#include <climits>
#include <algorithm>

// ----------------------------------------------------------
// Exercicio 1: Pesquisa Elementar
// ----------------------------------------------------------
// TODO
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
// TODO
int FunWithSearch::lowerBound(const vector<int> &v, int key) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 3: Intervalos
// ----------------------------------------------------------
// TODO
int FunWithSearch::countRange(const vector<int> & v, int a, int b) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 4a: Viagem de mochila às costas (isPossible)
// ----------------------------------------------------------
// TODO
bool FunWithSearch::isPossible(const vector<int> & v, int x, int k) {
    return false;
}

// ----------------------------------------------------------
// Exercicio 4b: Viagem de mochila às costas (partitions)
// ----------------------------------------------------------
// TODO
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