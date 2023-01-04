#include "jackpot.h"


Bet::Bet(vector<int> ns, string p): numbers(ns), player(p) {}

vector<int> Bet::getNumbers() const {
    return numbers;
}

string Bet::getPlayer() const {
    return player;
}

Jackpot::Jackpot()  {}

unsigned Jackpot::getNumBets() const {
    return bets.size();
}

// -----------------------------------------------------------
void Jackpot::addBet(const Bet& b) {
    bets.insert(b);
}


unsigned Jackpot::betsInNumber(unsigned num) const {
	unsigned count = 0;
    for (auto el : bets) {
        for (auto el2 : el.getNumbers()) {
            if (el2 == num) count++;
        }
    }
	return count;
}


vector<string> Jackpot::drawnBets(vector<int> draw) const {
	vector<string> res;

    for (auto el : bets) {
        int counter = 0;
        for (auto el2: el.getNumbers()) {
            for (auto el3 : draw) {
                if (el2 == el3) {
                    counter++;
                }
            }
        }
        if (counter > 3) res.push_back(el.getPlayer());
    }
	return res;
}
