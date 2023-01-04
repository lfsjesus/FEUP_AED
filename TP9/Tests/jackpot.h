#ifndef JACKPOT_H_
#define JACKPOT_H_

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Bet {
    vector<int> numbers;
    string player;
public:
    Bet(vector<int> ns, string p);
    vector<int> getNumbers() const;
    string getPlayer() const;
};

//---------------------------------

struct betHash
{
	int operator() (const Bet& b) const {
        vector<int> numbers = b.getNumbers();
        int v = 0;
        for (unsigned int i = 0; i < numbers.size(); i++) {
            v = 37 * v + numbers[i];
        }
        return v;
	}

	bool operator() (const Bet& b1, const Bet& b2) const {
        return b1.getNumbers() == b2.getNumbers() && b1.getPlayer() == b2.getPlayer();
	}
};


typedef unordered_set<Bet, betHash, betHash> tabHBet;

class Jackpot
{
	tabHBet bets;
public:
	Jackpot();
	void addBet(const Bet& ap);
	unsigned betsInNumber(unsigned num) const;
	vector<string> drawnBets(vector<int> draw) const;
    unsigned getNumBets() const;
};

#endif 
