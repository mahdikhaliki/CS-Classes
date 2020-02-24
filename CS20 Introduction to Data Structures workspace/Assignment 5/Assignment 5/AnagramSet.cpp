//
//  AnagramSet.cpp
//  Assignment 5
//
//  Created by Mahdi Khaliki on 11/9/17.
//  Copyright © 2017 Mahdi Khaliki. All rights reserved.
//

#include "AnagramSet.h"

AnagramSet::AnagramSet() : key(), words() { }

bool AnagramSet::operator==(const LetterBag &other) const {
    return key == other;
}

void AnagramSet::addWord(string word) {
    words.insert(word);
}

int AnagramSet::getSize() {
    return words.getSize();
}

void AnagramSet::clear() {
    key.clear();
    words.clear();
}

LetterBag &AnagramSet::getKey() {
    return key;
}

OList<string> &AnagramSet::getWords() {
    return words;
}

bool AnagramSet::isEmpty() {
    return key.isEmpty();
}

ostream &operator<<(ostream &out, AnagramSet &data) {
    cout << "{ " << data.key.toString() << ": " << data.words << " }" << flush;
    return out;
}

