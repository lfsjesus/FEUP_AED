#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}

// ---------------------------------------------

bool WordMean::operator< (const WordMean& wm2) const {
     return word < wm2.word;
}


void Dictionary::readFile(ifstream &f) {
    string word;
    string meaning;
    while (!f.eof()) {
        getline(f, word);
        word.erase(word.size() - 1); // remove carriage \r symbol
        getline(f, meaning);
        if (meaning.at(meaning.size() - 1) == '\r')
            meaning.erase(meaning.size() - 1); // remove carriage \r symbol

        this->words.insert(WordMean(word, meaning));
    }
}

string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    auto itr = words.find(WordMean(w1, ""));

    if (itr != words.end())
        return itr->getMeaning();
    else {
        auto x = words.upper_bound(WordMean(w1, ""));
        if (x != words.end()) {
            WordMean w = (*x);
            next = w;
        }
        if (--x != words.begin()) {
            previous = *x;
        }
    }
    return "word not found";
}

bool Dictionary::update(string w1, string m1) {
    auto finding = words.find(WordMean(w1, m1));

    if (finding != words.end()) {
        words.erase(finding);
        words.insert(WordMean(w1, m1));
        return true;
    }
    words.insert(WordMean(w1, m1));

    return false;
}

void Dictionary::print() const {
    for (auto wordmeaning : words) {
        cout << wordmeaning.getWord() << endl;
        cout << wordmeaning.getMeaning() << endl;
    }
}
