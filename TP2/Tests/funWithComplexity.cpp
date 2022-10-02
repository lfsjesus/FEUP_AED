// AED 2022/2023 - Aula Pratica 02
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 25/09/2022]

#include "funWithComplexity.h"

// ----------------------------------------------------------
// Exercicio 4: Sequencias
// ----------------------------------------------------------

int FunWithComplexity::maxSubArray(const vector<int> & v) {
    /*
    int sum = 0;
    int max = v[0];

    for (int i = 0; i < v.size(); i++) {
        sum = 0;
        for (int j = i; j < v.size(); j++) {
            sum += v[j];
            if (sum >=  max) {
                max = sum;
            }
        }
    }
    return max;
     */
    int local_max = 0;
    int global_max = v[0];
    for (int i = 0; i < v.size(); i++) {
        local_max = max(v[i], v[i] + local_max);
        if (local_max > global_max) {
            global_max = local_max;
        }
    }
    return global_max;
}



// ----------------------------------------------------------
// Exercicio 5: Analisando um rio
// ----------------------------------------------------------

int FunWithComplexity::river(const vector<int> & v, int k, int t) {
    int above = 0;
    int regions = 0;

    for (int i = 0; i < k; i++) {
        if (v[i] >= t) above++;
    }
    if (above >= k / 2.0) regions++;

    for (int i = k; i < v.size(); i++) {
        if (v[i] >= t) above++;
        if (v[i - k] >= t) above--;

        if (above >= k / 2.0 ) regions++;
    }

    return regions;
}

// ----------------------------------------------------------
// Exercicio 6: Espiral de Números
// ----------------------------------------------------------
// TODO
pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};
    return ans;
}

// ----------------------------------------------------------
// Exercicio 8: Caderno Quadriculado
// ----------------------------------------------------------
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}