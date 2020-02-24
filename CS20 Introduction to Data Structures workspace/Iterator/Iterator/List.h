#include <iostream>
using namespace std;
struct Node {
    int data;
    Node * next;
};

class Iterator {
    friend class LinkedList;
private:
    Node * current;
public:
    Iterator(Node * current) {
        this->current = current;
    }
    Iterator & operator++() {
        if (current->next != nullptr) // can't iterate past tail
        {
            current = current->next;
        }
        return *this;
    }
    Iterator operator++(int dummy)
    {
        Iterator temp = *this;
        operator++();
        return temp;
    }
    bool operator==(const Iterator& other) const {
        return current == other.current;
    }
    bool operator!=(const Iterator& other) const {
        return !operator==(other);
    }
    int& operator*() {
        return current->data;
    }
    Iterator operator+(int offset)
    {
        Iterator result = *this;
        for (int i = 0; i < offset; i++)
            result++;
        return result;
    }
    Iterator operator+=(int offset) {
        return *this = *this + offset;
    }
    
    
};

class LinkedList {
    //friend class Iterator;
private:
    Node head, tail;
    int length;
    
public:
    LinkedList() {
        head.next = &tail;
        tail.next = nullptr;
        length = 0;
    }
    LinkedList(const LinkedList & other) {
        length = other.length;
        head.next = &tail;
        tail.next = nullptr;
        if (other.isEmpty())
            return;
        Node *pre = &head;
        Node * otherp = other.head.next;
        Node * temp;
        while (otherp != &other.tail) {
            temp = new Node();
            temp->data = otherp->data;
            pre->next = temp;
            pre = temp;
            otherp = otherp->next;
        }
        temp->next = &tail;
    }
    
    ~LinkedList() {
        clear();
    }
    
    void removeFirst() {
        if (!isEmpty()) {
            Node * temp = head.next;
            head.next = head.next->next;
            delete temp;
            length--;
        }
    }
    void insertFirst(int d) {
        Node * temp = new Node();
        temp->next = head.next;
        temp->data = d;
        head.next = temp;
        length++;
    }
    
    void insertAfter(Iterator i, int data) {
        if (i == end())
            return; // can't insert after tail node
        
        Node *p = i.current, *temp = new Node();
        temp->data = data;
        temp->next = p->next;
        p->next = temp;
        length++;
    }
    
    bool isEmpty() const {
        return length == 0;
    }
    
    void clear() {
        while (!isEmpty())
            removeFirst();
    }
    
    Iterator begin() {
        return Iterator(head.next);
    }
    Iterator end() {
        return Iterator(&tail);
    }
};
