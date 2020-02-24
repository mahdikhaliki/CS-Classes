//
//  main.cpp
//  Assignment 4
//
//  Created by Mahdi Khaliki on 10/18/17.
//  Copyright © 2017 Mahdi Khaliki. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node *right, *left;
    Node(int d, Node *l = nullptr, Node *r = nullptr) {
        data = d;
        left = l;
        right = r;
    }
};
Node* createNode(int data, Node *p, Node *q) {
    return new Node(data, p, q);
}

Node * makeTree(int maxheight) {
    if (maxheight <= 0) return nullptr;
    Node * p = makeTree(rand() % maxheight);
    Node * q = makeTree(rand() % maxheight);
    return createNode(rand() % 15, p, q);  // You write it.
}

void drawTree(Node * p, int indentation=0) {
    int dashes = 3;
    for (int i = 0; i < indentation; i++)  cout << " ";
    if (p != nullptr) {
        for (int i = 0; i < dashes; i++) cout << "-";
        cout << p->data << endl;
        drawTree(p->left,  indentation + 5);
        drawTree(p->right, indentation + 5);
    }
    else cout << "~" << endl;  // null
}

Node* GetNewNode(int data) {
    return new Node(data);
}

Node* Insert(int data, Node* root = nullptr) {
    if(root == nullptr)
        root = GetNewNode(data);
    else if(data <= root->data)
        root->left = Insert(data, root->left);
    else
        root->right = Insert(data, root->right);
    return root;
}

int getSize(Node *r) {
    if (r == nullptr) return 0;
    return 1 + getSize(r->left) + getSize(r->right);
}

int getHeight(Node *r) {
    if (r == nullptr) return 0;
    return 1 + max(getHeight(r->left), getHeight(r->right));
}

bool isPerfect(Node * r) {
    return pow(2, getHeight(r)) == getSize(r) + 1;
}

bool isComplete(Node *r) {
    if(r == nullptr || (r->left == nullptr && r->right == nullptr)) return true;
    if(r->left == nullptr && r->right != nullptr) return false;
    return isComplete(r->left) && isComplete(r->right);
}

bool isBalanced(Node *r) {
    if(r == nullptr) return true;
    int heightdiff = getHeight(r->left) - getHeight(r->right);
    if( abs(heightdiff) > 1 ) return false;
    else return isBalanced(r->left) && isBalanced(r->right);
}

int getMaxInNONBST(Node * r) {
    if (r == nullptr) return false;
    return max(r->data, max(getMaxInNONBST(r->left), getMaxInNONBST(r->right)));
}

int getMaxInBST(Node * r) {
    while (r->right != nullptr)
        r = r->right;
    return r->data;
}

int getSum(Node * r) {
    if (r == nullptr) return 0;
    return r->data + getSum(r->right) + getSum(r->left);
}

int getNumLeaves(Node * r) {
    if(r == nullptr)
        return 0;
    if(r->left == nullptr && r->right == nullptr)
        return 1;
    else
        return getNumLeaves(r->left) + getNumLeaves(r->right);
}

bool containsInNonBST (Node * r, int target) {
    if (r == nullptr) return false;
    if (r->data == target) return true;
    else if (containsInNonBST (r->left, target)) return true;
    else if (containsInNonBST (r->right, target)) return true;
    return false;
}

bool containsInBST (Node * r, int target) {
    if (r == nullptr) return false;
    if (r->data == target) return true;
    else if (target < r->data) return containsInBST(r->left, target);
    else return (containsInNonBST (r->right, target));
}

void preorder(Node * root) {
    if (root == nullptr) return;
    cout << root->data << " " << flush;
    preorder(root->left);
    preorder(root->right);
}

int main(int argc, const char * argv[]) {
    int data[13] = {50, 25, 75, 15, 35, 55, 85, 5, 20, 30, 40, 100, 1};
    Node *test = nullptr;
    for (int i = 0; i < 13; i++)
        test = Insert(data[i], test);

    preorder(test);
    cout << "\nsize = " << getSize(test) << endl;
    cout << "height = " << getHeight(test) << endl;
    cout << "isPerfect? " << isPerfect(test) << endl;
    cout << "isComplete? " << isComplete(test) << endl;
    cout << "isBalanced? " << isBalanced(test) << endl;
    cout << "Max in NonBST = " << getMaxInNONBST(test) << endl;
    cout << "Max in BST = " << getMaxInBST(test) << endl;
    cout << "Sum = " << getSum(test) << endl;
    cout << "Num of leaves = " << getNumLeaves(test) << endl;
    cout << "Contains 40? NonBST " << containsInNonBST(test, 40) << endl;
    cout << "Contains 2? NonBST " << containsInNonBST(test, 2) << endl;
    cout << "Contains 40? BST " << containsInBST(test, 40) << endl;
    cout << "Contains 2? BST " << containsInBST(test, 2) << endl;

    srand(time(0));
    test = makeTree(10);
    drawTree(test);
    preorder(test);
    cout << endl;
    cout << "\nsize = " << getSize(test) << endl;
    cout << "height = " << getHeight(test) << endl;
    cout << "isPerfect? " << isPerfect(test) << endl;
    cout << "isComplete? " << isComplete(test) << endl;
    cout << "isBalanced? " << isBalanced(test) << endl;
    cout << "Max in NonBST = " << getMaxInNONBST(test) << endl;
//    cout << "Max in BST = " << getMaxInBST(test) << endl;
    cout << "Sum = " << getSum(test) << endl;
    cout << "Num of leaves = " << getNumLeaves(test) << endl;
    cout << "Contains 40? NonBST " << containsInNonBST(test, 40) << endl;
    cout << "Contains 2? NonBST " << containsInNonBST(test, 2) << endl;
//    cout << "Contains 40? BST " << containsInBST(test, 40) << endl;
//    cout << "Contains 2? BST " << containsInBST(test, 2) << endl;
    
    
    return 0;
}
