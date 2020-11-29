#ifndef OList_h
#define OList_h

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T> *next;
    Node(const T &d = T(), Node *n = nullptr) {
        data = d;
        next = n;
    }
};

template <class T>
class OList {
    friend ostream &operator<<(ostream &out, OList<T> data) {
        int i = 0;
        Node<T> *temp = data.head;
        
        out << "{ " << flush;
        while (i < data.size - 1){
            out << temp->data << "," << flush;
            temp = temp->next;
            i++;
        }
        if (data.size != 0)
            out << temp->data << flush;
        out << " }" << flush;
        return out;
    }
private:
    Node<T> *head, *tail;
    int size;
public:
    OList() {
        tail = head = nullptr;
        size = 0;
    }
    
    OList(T array[], int size) {
        int i = 0;
        tail = head = nullptr;
        this->size = 0;
        while (i < size) {
            insert(array[i]);
            i++;
        }
    }
    
    OList(const OList &list) : OList() {
        *this = list;
    }
    
    ~OList() {
        clear();
    }
    
    void insert(const T data) {
        Node<T> *temp = head;
        if (head == nullptr) { // If empty list
            tail = head = new Node<T>(data, nullptr);
        }
        else if (data < head->data) { // If data fits in head of list
            head = new Node<T>(data, head);
        }
        else { // If data fits in the body of the list
            for (int i = 0; i < size; i++) {
                if (i < size - 1 && data > temp->next->data) {
                    temp = temp->next;
                }
            }
            temp->next = new Node<T>(data, temp->next);
            tail = data > tail->data ? temp->next : tail;
        }
        size++;
    }
    
    Node<T>* sortedInsert(T value, Node<T> *current) {
        if (head == nullptr) {
            tail = current = new Node<T>(value);
            head = current;
        }
        else {
            tail->next = current = new Node<T>(value);
        }
        tail = current;
        size++;
        return current;
    }
    
    void print() {
        cout << *this << endl;
    }
    
    void printBackwards() {
        if (size == 0) {
            cout << "{ }" << endl;
            return;
        }
        cout << "{ " << flush;
        backwardsHelper(head);
        cout << " }" << endl;
    }
    
    void backwardsHelper(Node<T> *data) {
        if (data != tail)
            backwardsHelper(data->next);
        if (data == head)
            cout << data->data << flush;
        else
            cout << data->data << "," << flush;
    }
    
    int getSize() const {
        return size;
    }
    
    T getSmallest() const {
        try {
            if (head == nullptr) {
                throw logic_error("Empty list");
            }
            return head->data;
        } catch (logic_error) {
            cout << "Error: List is empty, returning 0" << endl;
        }
        return 0;
    }
    
    T getBiggest() const {
        try {
            if (head == nullptr) {
                throw logic_error("Empty list");
            }
            return tail->data;
        } catch (logic_error) {
            cout << "Error: List is empty, returning 0" << endl;
        }
        return 0;
    }
    
    OList &operator=(const OList &other) {
        if (head == other.head && size != 0) {
            cout << "Self assignment ignored." << endl;
            return *this;
        }
        Node<T> *temp = other.head, *current = head;
        clear();
        for (int i = 0; i < other.size; i++) {
            current = sortedInsert(temp->data, current);
            temp = temp->next;
        }
        return *this;
    }
    
    OList operator+(const OList &other) const {
        OList<T> newList;
        newList = *this;
        newList += other;
        return newList;
    }
    
    OList operator+=(const OList &other) {
        Node<T> *thisTemp = head, *otherTemp = other.head;
        int i = 0, length  = other.size;
        
        if (thisTemp == nullptr) // If this list is empty
            return *this = other;
        if (&otherTemp != nullptr && otherTemp->data < thisTemp->data) {
            head = new Node<T> (otherTemp->data, thisTemp);
            tail = otherTemp->data > tail->data ? thisTemp->next : tail;
            thisTemp = head;
            otherTemp = otherTemp->next;
            i++;
            size++;
        }
        while (i++ < length) {
            while (thisTemp->next != nullptr && otherTemp->data > thisTemp->next->data) {
                thisTemp = thisTemp->next;
            }
            thisTemp->next = new Node<T>(otherTemp->data, thisTemp->next);
            tail = otherTemp->data > tail->data ? thisTemp->next : tail;
            size++;
            
            if (otherTemp->next != nullptr)
                otherTemp = otherTemp->next;
        }
        return *this;
    }
    
    void clear() {
        Node<T> *temp;
        while (!(this->isEmpty())) {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
    
    bool isEmpty() const {
        return head == nullptr;
    }
    
    int find(const T key) const {
        Node<T> *temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->data == key)
                return i;
            temp = temp->next;
        }
        return -1;
    }
    
    bool operator==(const OList &other) const {
        Node<T> *thisTemp = head, *otherTemp = other.head;
        if (size != other.size)
            return false;
        for (int i = 0; i < size; i++) {
            if (thisTemp->data != otherTemp->data)
                return false;
            thisTemp = thisTemp->next;
            otherTemp = otherTemp->next;
        }
        return true;
    }
    
    bool operator!=(OList &other) const {
        return !(*this == other);
    }
    
    void remove(T value, bool recurrence = true) {
        Node<T> *temp = head, *temp1 = nullptr;
        int sizeCount = 0;
        for (int i = 0; i < size; i++) { // Don't check the rest of the list
            if (temp->data > value) {
                size -= sizeCount;
                return;
            }
            if (head->data == value) { // If in head
                temp1 = head;
                head = head->next;
                delete temp1;
                size--;
                temp = head;
                if (!recurrence) return;
            }
            else if (temp->next != nullptr && temp->next->data == value ) { // If in body
                temp1 = temp->next;
                if (temp1 == tail)
                    tail = temp;
                temp->next = temp->next->next;
                delete temp1;
                sizeCount++;
                if (!recurrence) return;
            }
            else { // Traverse
                temp = temp->next;
            }
        }
        size -= sizeCount;
    }
};
#endif /* OList_h */
