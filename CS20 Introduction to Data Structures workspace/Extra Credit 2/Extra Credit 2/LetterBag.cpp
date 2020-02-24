//
//  LetterBag.cpp
//  Extra Credit 2
//
//  Created by Mahdi Khaliki on 11/9/17.
//

#include "LetterBag.h"

LetterBag::LetterBag() {
    for (int i = 0; i < 26; i++) counts[i] = 0;
    size = 0;
}

LetterBag::LetterBag(const vector<char> & v) : LetterBag() { // initialize using letters in v, omitting non letters
    for (int i = 0; i < v.size(); i++)
        if (inRange(v[i])) counts[v[i] - 'a']++;
}

bool LetterBag::operator==(const LetterBag & other) const {  // return true iff *this equals other
    if (size != other.size) return false;
    int i = 0;
    while (i < 26 && counts[i] == other.counts[i]) i++;
    return i == 26 ? true : false;
}

bool LetterBag::operator!=(const LetterBag & other) const {  // return false iff *this equals other
    return !(*this == other);
}

int LetterBag::getCurrentSize() const {  // return the current size of the LetterBag
    return size;
}

bool LetterBag::isEmpty() const {  // return true iff the LetterBag is empty
    return !size;
}

LetterBag& LetterBag::add(char c) { // add an occurrence of c to the LetterBag
    if (!inRange(c)) return *this;
    counts[c - 'a']++;
    size++;
    return *this;
}

LetterBag& LetterBag::remove(char c) { // remove one occurrence of c (if there is one).
    if (counts[c - 'a'] != 0) counts[c - 'a']--;
    size--;
    return *this;
}

LetterBag& LetterBag::clear() { // remove all occurrences of all letters
    for (int i = 0; i < 26; i++) counts[i] = 0;
    size = 0;
    return *this;
}

int LetterBag::getFrequency(char c) const { // count occurrences of c
    return counts[c - 'a'];
}

vector<char> LetterBag::toVector() const { // return a vector with the letters in this object, in sorted order.
    vector<char> vector(size);
    int vectorCount = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < counts[i]; j++)
            vector[vectorCount++] = i + 'a';
    return vector;
}

bool LetterBag::isSubbag(const LetterBag & other) const {  // return true if *this is a subbag of other.
    for (int i = 0; i < 26; i++)
        if (getFrequency(i + 'a') > other.getFrequency(i + 'a')) return false;
    return true;
}

bool LetterBag::inRange(char c) {
    return 'a' <= c && c <= 'z';
}

