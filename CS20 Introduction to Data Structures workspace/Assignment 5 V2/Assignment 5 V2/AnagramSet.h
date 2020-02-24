#ifndef AnagramSet_h
#define AnagramSet_h

#include <iostream>
#include <string>
#include "LetterBag.h"
#include "OList.h"
using namespace std;

class AnagramSet {
    friend ostream &operator<<(ostream &out, AnagramSet &data);
protected:
    LetterBag key;
    OList<string> words;
public:
    AnagramSet();
    AnagramSet(LetterBag key, string word);
    void addWord(string word);
    int getSize();
    void clear();
    LetterBag &getKey();
    OList<string> &getWords();
    bool isEmpty();
    bool containsWord(string word);
    bool containsKey(LetterBag &key);
};

#endif /* AnagramSet_h */
