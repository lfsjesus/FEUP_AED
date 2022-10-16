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


unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    vector<float> sorted_arrival = arrival;
    vector<float> sorted_departure = departure;
    sort(sorted_arrival.begin(), sorted_arrival.end());
    sort(sorted_departure.begin(), sorted_departure.end());

    int final = 1;
    int platforms = 1;
    int a = 1;
    int d = 0;
    while (a < arrival.size() && d < arrival.size()) {
        if (sorted_departure[d] >= sorted_arrival[a]) {
            platforms++;
            a++;
        }
        else if(sorted_arrival[a] > sorted_departure[d]) {
            platforms--;
            d++;
        }
        if (platforms > final) final = platforms;
    }

    return final;
}

unsigned mergeSort(vector<int>&v){

    if (v.size()==1) {
        return 0;
    }
    vector<int>left(v.begin(),v.begin()+(v.size()-1)/2+1);

    vector<int>right(v.begin()+(v.size() - 1)/2+1,v.end());

    unsigned res = 0;

    res += mergeSort(left);
    res += mergeSort(right);

    int i = 0, j = 0;

    while (i < left.size() || j < right.size()) {
        if ((left[i] <= right[j] && i < left.size()) || j == right.size()) {
            v[i+j] = left[i];
            i++;
        }
        else {
            v[i+j] = right[j];
            j++;
            res += (left.size()-i);
        }
    }
    return res;
}

unsigned FunSortProblem::numInversions(vector<int>v) {
    return mergeSort(v);
}


// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}

