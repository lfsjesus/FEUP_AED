#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

void Game::addKid(const Kid k1) {
 	kids.push_back(k1);
}

list<Kid> Game::getKids() const {
	return this->kids;
}

void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}

//-----------------------------------------------------------------

Kid Game::loseGame(string phrase) {

    int length = numberOfWords(phrase);
    auto index = 0;
    while (kids.size() > 1) {
       index = (index + length - 1) % kids.size();
       auto iterator = kids.begin();

       int temp = 0;

       while (temp < index) {
           temp++;
           iterator++;
       }
       kids.erase(iterator);
    }

    return kids.front();
}


list<Kid> Game::rearrange() {
    list<Kid> res;

    list<Kid> male;
    list<Kid> female;

    for (auto kid : kids) {
        (kid.getSex() == 'm' ? male : female).push_back(kid);
    }

    kids.clear();

    if (female.size() < male.size()) {
        int pattern = male.size()/female.size();

        while (!female.empty()) {
            auto person = female.begin();
            kids.push_back(*person);
            female.pop_front();

            int i = 0;
            while (i < pattern) {
                auto male_person = male.begin();
                kids.push_back(*male_person);
                male.pop_front();
                i++;
            }
        }

        for (auto kid : male) {
            res.push_back(kid);
        }
    }

    else {
        int pattern = female.size() / male.size();

        while (!male.empty()) {
            auto person = male.begin();
            kids.push_back(*person);
            male.pop_front();

            int i = 0;
            while (i < pattern) {
                auto female_person = female.begin();
                kids.push_back(*female_person);
                female.pop_front();
                i++;
            }
        }

        for (auto kid : male) {
            res.push_back(kid);
        }
    }
    return res;
}


list<Kid> Game::shuffle() const {
	list<Kid> newList;
    list<Kid> kids = this->kids;

    while(!kids.empty()) {
        int pos = rand() % kids.size();
        auto it = kids.begin();

        for (int i = 0; i < pos; i++) {
            it++;
        }
        newList.push_back(*it);
        kids.erase(it);
    }

	return newList;
}
