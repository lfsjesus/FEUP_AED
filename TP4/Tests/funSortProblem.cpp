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

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    return 0;
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

