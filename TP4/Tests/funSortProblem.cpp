#include "funSortProblem.h"
#include <algorithm>
#include <limits.h>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    sort(products.begin(), products.end());
    if (products.size() > k)
        products.erase(products.begin() + k, products.end());
}


int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if (nc > values.size()) return -1;
    vector<unsigned> sorted_values = values;
    sort(sorted_values.begin(), sorted_values.end());
    int min = INT_MIN;
    for (int i = 0; i < sorted_values.size(); i++) {
        if (sorted_values[nc + i - 1] - sorted_values[i] < min) {
            min = sorted_values[nc + i - 1] - sorted_values[i];
        }
    }
    return min;

}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    return 0;
}

//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    return 0;
}

// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}

