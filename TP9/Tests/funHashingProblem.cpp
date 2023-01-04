#include "funHashingProblem.h"
#include <unordered_set>

FunHashingProblem::FunHashingProblem() {}

// -------------------------------------


vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    vector<int> res;
    unordered_set<int> hashtable;

    // iteramos sobre os valores e vemos se na hashtable já existe o valor
    for (int i = 0; i < values.size(); i++) {
        if (hashtable.find(values[i]) != hashtable.end()) {
            res.push_back(values[i]);
            // se existir, colocamos no vetor porque é repetido
        }
        hashtable.insert(values[i]); // vamos colocando o valor na hashtable

        if (i >= k) { // eliminar os valores de trás
            hashtable.erase(values[i-k]);
        }
    }
    return res;
}