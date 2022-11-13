#include "funStackQueueProblem.h"
#include "cell.h"

FunStackQueueProblem::FunStackQueueProblem() {}


//-----------------------------------------------------------------

vector<string> FunStackQueueProblem::binaryNumbers(int n) {
    vector<string> res;
    queue<string> binary;

    binary.push("1");

    int i = 0;

    while (i < n) {
        binary.push(binary.front() + "0");
        binary.push(binary.front() + "1");

        res.push_back(binary.front());
        binary.pop();
        i++;
    }
    return res;
}

vector<int> FunStackQueueProblem::calculateSpan(vector<int> prices)
{
    vector<int> res;
    if (prices.empty()) return res;
    res.push_back(1);
    stack<int> aux;
    aux.push(0);

    for (int i = 1; i < prices.size(); i++) {
        while(!aux.empty() && prices[aux.top()] <= prices[i])
            aux.pop(); // Pop the days of the stack while that day price is lower or equal than the current day pryce

        // Here we have in the stack the last day higher than the current day
        if (aux.empty()) res.push_back(i +1);
        else res.push_back(i - aux.top()); // compute the difference -> get the span

        aux.push(i);
    }

    return res;
}


int FunStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {


    return -1;
}






