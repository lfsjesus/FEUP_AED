// AED 2022/2023 - Aula Pratica 01
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 18/09/2022]

#include "funWithCycles.h"

// ----------------------------------------------------------
// Exercicio 1: Palindromos
// ----------------------------------------------------------
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
int FunWithCycles::count(const vector<int> & v, int n) {
    int oc = 0;
    for (int el : v) {
        if (el == n) oc++;
    }
    return oc;
}

// b) hasDuplicates
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    int size = v.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (v[j] == v[i]) return true;
        }
    }
    return false;
}

// c) removeDuplicates
void FunWithCycles::removeDuplicates(vector<int> & v) {
    vector<int> numbers;
    for (int i = 0; i < v.size(); i++) {
        if (count(numbers, v[i]) == 0) {
            numbers.push_back(v[i]);
        }
    }
    v = numbers;
}

// d) merge
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    int size1 = v1.size();
    int size2 = v2.size();

    int i = 0;
    int j = 0;

    while (i < size1 && j < size2) {
        if (v1[i] < v2[j] ) {
            ans.push_back(v1[i]);
            i++;
        }
        else {
            ans.push_back(v2[j]);
            j++;
        }
    }

    while (i < size1) {
        ans.push_back(v1[i]);
        i++;
    }

    while (j < size2) {
        ans.push_back(v2[j]);
        j++;
    }
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
