#include <iostream>
using namespace std;

template <class T>
class Node {
    
public:
    T data;
    Node<T> * next;
    
    Node(const T & data = T(), Node * next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

template <class T>
class List {
    friend ostream & operator<<(ostream & out, const List &alist) {
        cout << "{ ";                 // opening brace
        Node<T> * p = alist.headPtr;  // get a pointer to the head of the list
        while (p != nullptr) {
            out << p->data << " ";    // output data followed by a space
            p = p->next;              // advance to the next node
        }
        out << "}" ;                  // just a closing brace; no endl required
        return out;                   // return the output stream object
    }
    
private:
    Node<T> * headPtr;  // pointer to the head of the list or null if list is empty
public:
    List() {
        headPtr = nullptr;  // create an empty list
    }
    
    void insertFirst(const T & data) {
        headPtr = new Node<T>(data, headPtr); // put the new node at the head of the list
    }
    
    void removeFirst() {
        if (headPtr != nullptr) {
            Node<T> * temp = headPtr;  // save address of headPtr
            headPtr = headPtr->next;   // advance headPtr
            delete temp;  // avoid a memory leak
        }
    }
    
    bool isEmpty() const {
        return headPtr == nullptr;
    }
    void clear() {
        while (!isEmpty())
            removeFirst();
    }
};
