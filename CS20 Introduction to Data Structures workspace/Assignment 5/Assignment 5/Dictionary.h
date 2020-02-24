#ifndef Dictionary_h
#define Dictionary_h

#include <iostream>
#include <string>
#include <exception>
#include "AnagramSet.h"
#include "OList.h"
using namespace std;

class Dictionary {
private:
    int tableSize;
    Node<AnagramSet> *anagrams;
public:
    Dictionary();
    Dictionary(int tableSize);
    Dictionary(string words[], int numWords, int tableSize);
    void insert(const string word);
    unsigned int makeKey(const string key, int tableSize);
    bool contains(string word);
    AnagramSet &getSet(string word);
    void remove(string word);
    friend ostream &operator<<(ostream &out, Dictionary &data);
};

#endif /* Dictionary_h */
