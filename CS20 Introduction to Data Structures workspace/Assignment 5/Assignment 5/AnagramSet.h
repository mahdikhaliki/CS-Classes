#ifndef AnagramSet_h
#define AnagramSet_h

#include <iostream>
#include <string>
#include "LetterBag.h"
#include "OList.h"
using namespace std;

class AnagramSet {
    friend ostream &operator<<(ostream &out, AnagramSet &data);
private:
    LetterBag key;
    OList<string> words;
public:
    AnagramSet();
    AnagramSet(LetterBag key, string word, AnagramSet *next = NULL);
    bool operator ==(const LetterBag &other) const;
    void addWord(string word);
    int getSize();
    void clear();
    LetterBag &getKey();
    OList<string> &getWords();
    bool isEmpty();
};

#endif /* AnagramSet_h */
