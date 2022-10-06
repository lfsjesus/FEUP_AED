// AED 2022/2023 - Aula Pratica 02
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 25/09/2022]

#include "funWithComplexity.h"
#include <cmath>

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
pair<int, int> FunWithComplexity::spiral(int n) {
    int x;
    int y;
    int z; //square index
    int k; //corner distance
    int c1; //corners
    int c2;
    int c3;
    int c4;
    int root = sqrt(n);
    if (root*root == n) {
        x = y = (root - 1) / 2;
    }
    else {
        if ((root & 1) == 1) {
            x = y = z = (root + 2) / 2;
        }
        else {
            x = y = z = root / 2;
        }
        c1 = pow(z * 2 + 1, 2);
        c2 = c1 - z * 2;
        c3 = c2 - z * 2;
        c4 = c3 - z * 2;
        if (n >= c2) {
            k = c1 - n;
            x = z - k;
        }
        else if (n >= c3) {
            k = c2 - n;
            x = -z;
            y = z - k;
        }
        else if (n >= c4) {
            k = c3 - n;
            x = -z + k;
            y = -z;
        }
        else {
            k = c4 - n;
            y = -z + k;
        }
    }
    pair<int, int> ans = {x, y};
    return ans;
}

// ----------------------------------------------------------
// Exercicio 8: Caderno Quadriculado
// ----------------------------------------------------------
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}