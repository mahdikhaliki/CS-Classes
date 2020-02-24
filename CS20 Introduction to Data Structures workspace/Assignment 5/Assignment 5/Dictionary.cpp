//
//  Dictionary.cpp
//  Assignment 5
//
//  Created by Mahdi Khaliki on 11/9/17.
//  Copyright © 2017 Mahdi Khaliki. All rights reserved.
//

#include "Dictionary.h"

Dictionary::Dictionary() {
    tableSize = 1000;
    anagrams = new Node<AnagramSet>[1000];
}

Dictionary::Dictionary(int tableSize) {
    this->tableSize = tableSize;
    anagrams = new Node<AnagramSet>[tableSize];
}

Dictionary::Dictionary(string words[], int numWords, int tableSize) {
    this->tableSize = tableSize;
    anagrams = new Node<AnagramSet>[tableSize];

    for (int i = 0; i < numWords; i++) {
        insert(words[i]);
    }
}

void Dictionary::insert(const string word) {
    LetterBag temp(word);
    int hashIndex = makeKey(temp.toString(), tableSize);
    if (anagrams[hashIndex].data.getKey().getCurrentSize() == 0) {
        anagrams[hashIndex].data.getKey() = temp;
        anagrams[hashIndex].data.getWords().insert(word);
    }
    else if (anagrams[hashIndex].data.getKey() == temp) {
        anagrams[hashIndex].data.getWords().insert(word);
    }
    else {
        Node<AnagramSet> *traverse = &anagrams[hashIndex];
        while (traverse->next != NULL)
            traverse = traverse->next;
        traverse->next = new Node<AnagramSet>;
        traverse->next->data.getKey() = temp;
        traverse->next->data.getWords().insert(word);
    }
}

unsigned int Dictionary::makeKey(const string key, int tableSize) {
    int hashVal = 0;
    
    for (int i = 0; i < key.length();  i++)
        hashVal = 37 * hashVal + key[i];
    
    hashVal %= tableSize;
    
    if (hashVal < 0)
        hashVal += tableSize;
    
    return hashVal;
}

bool Dictionary::contains(string word) {
    LetterBag temp(word);
    int hashIndex = makeKey(temp.toString(), tableSize);
    Node<AnagramSet> *traverse = &anagrams[hashIndex];
    while (traverse != NULL) {
        if (temp == traverse->data.getKey())
            return true;
        traverse = traverse->next;
    }
    return false;
}

AnagramSet &Dictionary::getSet(string word) {
    LetterBag temp(word);
    int hashIndex = makeKey(temp.toString(), tableSize);
    Node<AnagramSet> *traverse = &anagrams[hashIndex];
    try {
        while (traverse != NULL) {
            if (temp == traverse->data.getKey())
                return traverse->data;
            traverse = traverse->next;
        }

        throw logic_error("Word is not in the dictionary.");
    }
    catch(logic_error e) {
        cout << e.what() << endl;
    }
    return traverse->data;
}

void Dictionary::remove(string word) {
    LetterBag temp(word);
    int hashIndex = makeKey(temp.toString(), tableSize);
    Node<AnagramSet> *traverse = &anagrams[hashIndex];
        while (traverse != NULL) {
            if (temp == traverse->data.getKey()) {
                traverse->data.getWords().remove(word);
                if (traverse->data.getWords().isEmpty())
                    traverse->data.clear();
                if (traverse->next != NULL) {
                    traverse->next = traverse->next->next;
                }
                else {
                    traverse->next = NULL;
                }
            }
            traverse = traverse->next;
        }
}

ostream &operator<<(ostream &out, Dictionary &data) {
    Node<AnagramSet> *traverse;
    for (int i = 0; i < data.tableSize; i++) {
        traverse = &data.anagrams[i];
        out << i << " : " << flush;
        while (traverse != NULL) {
            if (traverse->data.getKey().getCurrentSize() != 0) {
            out << traverse->data << ", " << flush;
            }
            traverse = traverse->next;
        }
        out << endl;
    }
    return out;
}
