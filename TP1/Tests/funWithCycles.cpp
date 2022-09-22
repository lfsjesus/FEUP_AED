// AED 2022/2023 - Aula Pratica 01
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 18/09/2022]

#include "funWithCycles.h"

// ----------------------------------------------------------
// Exercicio 1: Palindromos
// ----------------------------------------------------------
// TODO

bool FunWithCycles::palindrome(const std::string & s) {
    int size = s.length();
    for (int i = 0; i < size / 2; i++) {
        if (s[i] != s[size - i - 1]) {
            return false;
        }
    }
    return true;
}
// ----------------------------------------------------------
// Exercicio 2: Frases Palindromo
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    string text;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            text.push_back(s[i]);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            text.push_back(tolower(s[i]));
        }

    }
    int size = text.length();
    for (int i = 0; i < size / 2; i++) {
        if (text[i] != text[size - i - 1]) {
            return false;
        }
    }
    return true;
}


// ----------------------------------------------------------
// Exercicio 3: Numeros Interessantes
// ----------------------------------------------------------
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    int i = n + 1;
    while (true) {
        if (digitSum(i) == sum) {
            return i;
        }
        i++;
    }
}

// Esta funcao auxiliar devera devolver a soma dos digitos de n
// TODO
int FunWithCycles::digitSum(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        n = n / 10;
        sum += digit;
    }
    return sum;
}

// ----------------------------------------------------------
// Exercicio 4: O Inverno esta a chegar
// ----------------------------------------------------------
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    vector<int> decrease;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i+1] - v[i] < 0) decrease.push_back(1);
        else decrease.push_back(0);
    }
    int max = 0;
    int count = 0;
    for (int i = 0; i < decrease.size(); i++) {
        if (decrease[i] == 0)  {
            if (count > max) max = count;
            count = 0;
        }
        else if (decrease[i] == 1) {
            count++;
            if (max == 0 && i == decrease.size() - 1) {
                max = count;
            }
        }
    }
    return max;
}


// ----------------------------------------------------------
// Exercicio 5: Brincando com vectores
// ----------------------------------------------------------

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    return 0;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    return false;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {

}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    return ans;
}

// ----------------------------------------------------------
// Exercicio 6: Brincando com numeros primos
// ----------------------------------------------------------

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    return false;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    return ans;
}


// ----------------------------------------------------------
// Exercicio 7: Numeros interessantes (versao desafio)
// ----------------------------------------------------------
// TODO
long long FunWithCycles::fastNextInterestingNumber(long long n, int sum) {
    return 0;
}
