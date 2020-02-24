#include "Dictionary.h"

Dictionary::Dictionary() {
    tableSize = 1000;
    numWords = 0;
    anagrams = new Node<AnagramSet>*[1000];
    for (int i = 0; i < tableSize; i++) anagrams[i] = NULL;
}

Dictionary::Dictionary(int tableSize) {
    this->tableSize = tableSize;
    numWords = 0;
    anagrams = new Node<AnagramSet>*[tableSize];
    for (int i = 0; i < tableSize; i++) anagrams[i] = NULL;
}

Dictionary::Dictionary(string words[], int numWords, int tableSize) {
    this->tableSize = tableSize;
    this->numWords = 0;
    anagrams = new Node<AnagramSet>*[tableSize];
    for (int i = 0; i < tableSize; i++) anagrams[i] = NULL;
    for (int i = 0; i < numWords; i++)
        insert(words[i]);
}

void Dictionary::insert(const string word) {
    LetterBag temp(word);
    int hashIndex = makeKey(temp.toString(), tableSize);
    Node<AnagramSet> *traverse = anagrams[hashIndex];
    if (traverse == NULL) {
        anagrams[hashIndex] = new Node<AnagramSet>(AnagramSet(temp, word));
        numWords++;
    }
    else {
        while (traverse->next != NULL) {
            if (traverse->data.containsWord(word)) return;
            if (traverse->data.containsKey(temp)) {
                traverse->data.addWord(word);
                numWords++;
                return;
            }
            traverse = traverse->next;
        }
        if (!traverse->data.containsWord(word)) {
            if (traverse->data.containsKey(temp)) {
                traverse->data.addWord(word);
            }
            else {
                traverse->next = new Node<AnagramSet>(AnagramSet(temp, word));
            }
            numWords++;
        }
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
    Node<AnagramSet> *traverse = anagrams[makeKey(temp.toString(), tableSize)];
    while (traverse != NULL) {
        if (traverse->data.containsWord(word))
            return true;
        traverse = traverse->next;
    }
    return false;
}

AnagramSet &Dictionary::getSet(string word) {
    LetterBag temp(word);
    int hashIndex = makeKey(temp.toString(), tableSize);
    Node<AnagramSet> *traverse = anagrams[hashIndex];
    while (traverse != NULL) {
        if (traverse->data.containsKey(temp))
            return traverse->data;
        traverse = traverse->next;
    }
    AnagramSet t;
    return t;
}

void Dictionary::remove(string word) {
    LetterBag key(word);
    int hashIndex = makeKey(key.toString(), tableSize);
    Node<AnagramSet> *traverse = anagrams[hashIndex], *temp;
    if (traverse != NULL && traverse->data.containsKey(key)) {
        traverse->data.getWords().remove(word);
        if (traverse->data.getWords().isEmpty()) {
            temp = traverse;
            temp->data.clear();
            anagrams[hashIndex] = traverse->next;
            delete temp;
        }
    }
    else {
        while(traverse != NULL) {
            if (traverse->next != NULL && traverse->next->data.containsKey(key)) {
                traverse->next->data.getWords().remove(word);
                if (traverse->next->data.getWords().isEmpty()) {
                    temp = traverse->next;
                    temp->data.clear();
                    traverse->next = temp->next;
                    delete temp;
                }
                return;
            }
            traverse = traverse->next;
        }
    }
}

ostream &operator<<(ostream &out,const Dictionary data) {
    Node<AnagramSet> *traverse;
    for (int i = 0; i < data.tableSize; i++) {
        traverse = data.anagrams[i];
        while (traverse != NULL) {
            if (!traverse->data.isEmpty()) {
                out << traverse->data << flush;
            }
            if(traverse->next != NULL)
                out << ", " << flush;
            else
                out << endl;

            traverse = traverse->next;
        }
    }
    return out;
}
