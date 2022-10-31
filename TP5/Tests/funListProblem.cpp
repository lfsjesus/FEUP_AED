#include "funListProblem.h"
#include <algorithm>

FunListProblem::FunListProblem() {}


//-----------------------------------------------------------------

list<int> FunListProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    auto itr = values.begin();

    while (itr != values.end()) {
        if (*itr > x) {
            l1.push_back(*itr);
            itr = values.erase(itr);
        }
        else {
            ++itr;
        }
    }
    return l1;
}


list<pair<int,int>> FunListProblem::overlappingIntervals(list<pair<int,int>> values) {
    list<pair<int,int>> res;
    values.sort();
    for (auto p : values) {
        if (res.size() > 0 && res.back().second >= p.first) {

        }
    }
    return res;
}
