#include "LetterBag.h"

LetterBag::LetterBag() {
    for (int i = 0; i < 26; i++) counts[i] = 0;
    size = 0;
}

LetterBag::LetterBag(const string & v) { // initialize using letters in v, omitting non letters
    for (int i = 0; i < 26; i++) counts[i] = 0;
    size = 0;
    for (int i = 0; i < v.size(); i++)
        if (inRange(v[i])) {
            counts[v[i] - 'a']++;
            size++;
        }
}

bool LetterBag::operator==(const LetterBag &other) const {  // return true iff *this equals other
    if (size != other.size) return false;
    for (int i = 0; i < 26; i++)
        if (counts[i] != other.counts[i]) return false;
    return true;
}

bool LetterBag::operator!=(const LetterBag &other) const {  // return false iff *this equals other
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

string LetterBag::toString() const { // return a vector with the letters in this object, in sorted order.
    string s;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < counts[i]; j++)
            s += i + 'a';
    return s;
}

bool LetterBag::isSubbag(const LetterBag & other) const {  // return true if *this is a subbag of other.
    for (int i = 0; i < 26; i++)
        if (getFrequency(i + 'a') > other.getFrequency(i + 'a')) return false;
    return true;
}

bool LetterBag::inRange(char c) {
    return 'a' <= c && c <= 'z';
}

LetterBag &LetterBag::operator=(const LetterBag &other) {
    for (int i = 0; i < 26; i++)
        counts[i] = other.counts[i];
    this->size = other.size;
    return *this;
}

