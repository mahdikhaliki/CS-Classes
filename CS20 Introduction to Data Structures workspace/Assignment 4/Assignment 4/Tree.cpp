//
//  Mahdi Khaliki
//  Assignment 4

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node *right, *left;
    Node(int d, Node *l = NULL, Node *r = NULL) {
        data = d;
        left = l;
        right = r;
    }
};

Node* createNode(int data, Node *p, Node *q) {
    return new Node(data, p, q);
}

Node * makeTree(int maxheight) {
    if (maxheight <= 0) return NULL;
    Node * p = makeTree(rand() % maxheight);
    Node * q = makeTree(rand() % maxheight);
    return createNode(rand() % 15, p, q);  // You write it.
}

void drawTree(Node * p, int indentation=0) {
    int dashes = 3;
    for (int i = 0; i < indentation; i++)  cout << " ";
    if (p != NULL) {
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

Node* Insert(int data, Node* root = NULL) {
    if(root == NULL)
        root = GetNewNode(data);
    else if(data <= root->data)
        root->left = Insert(data, root->left);
    else
        root->right = Insert(data, root->right);
    return root;
}

int getSize(Node *r) {
    if (r == NULL) return 0;
    return 1 + getSize(r->left) + getSize(r->right);
}

int getHeight(Node *r) {
    if (r == NULL) return 0;
    return 1 + max(getHeight(r->left), getHeight(r->right));
}

bool isPerfect(Node * r) {
    return pow(2, getHeight(r)) == getSize(r) + 1;
}

bool isComplete(Node *r) {
    if(r == NULL || (r->left == NULL && r->right == NULL)) return true;
    if(r->left == NULL && r->right != NULL) return false;
    return isComplete(r->left) && isComplete(r->right);
}

bool isBalanced(Node *r) {
    if(r == NULL) return true;
    int heightdiff = getHeight(r->left) - getHeight(r->right);
    if( abs(heightdiff) > 1 ) return false;
    else return isBalanced(r->left) && isBalanced(r->right);
}

int getMaxInNONBST(Node * r) {
    if (r == NULL) return false;
    return max(r->data, max(getMaxInNONBST(r->left), getMaxInNONBST(r->right)));
}

int getMaxInBST(Node * r) {
    while (r->right != NULL)
        r = r->right;
    return r->data;
}

int getSum(Node * r) {
    if (r == NULL) return 0;
    return r->data + getSum(r->right) + getSum(r->left);
}

int getNumLeaves(Node * r) {
    if(r == NULL)
        return 0;
    if(r->left == NULL && r->right == NULL)
        return 1;
    else
        return getNumLeaves(r->left) + getNumLeaves(r->right);
}

bool containsInNonBST (Node * r, int target) {
    if (r == NULL) return false;
    if (r->data == target) return true;
    else if (containsInNonBST (r->left, target)) return true;
    else if (containsInNonBST (r->right, target)) return true;
    return false;
}

bool containsInBST (Node * r, int target) {
    if (r == NULL) return false;
    if (r->data == target) return true;
    else if (target < r->data) return containsInBST(r->left, target);
    else return (containsInNonBST (r->right, target));
}

void preorder(Node * root) {
    if (root == NULL) return;
    cout << root->data << " " << flush;
    preorder(root->left);
    preorder(root->right);
}

void printStats(Node *root) {
    cout << "preorder: " << flush;
    preorder(root);
    cout << "\nsize = " << getSize(root) << endl;
    cout << "height = " << getHeight(root) << endl;
    cout << "isPerfect? " << isPerfect(root) << endl;
    cout << "isComplete? " << isComplete(root) << endl;
    cout << "isBalanced? " << isBalanced(root) << endl;
    cout << "Max in BST = " << getMaxInBST(root) << endl;
    cout << "Sum = " << getSum(root) << endl;
    cout << "Num of leaves = " << getNumLeaves(root) << endl;
    cout << "Contains 50? " << containsInBST(root, 50) << endl;
    cout << "Contains 2? " << containsInBST(root, 2) << endl << endl;
}

int main(int argc, const char * argv[]) {
    int data[15] = {50, 25, 75, 15, 35, 55, 85, 5, 20, 30, 40, 100, 1, 0, -1};
    Node *BST = NULL, *perfect = NULL, *complete = NULL, *balanced = NULL;

    cout <<  "Testing a BST:" << endl;
    for (int i = 0; i < 15; i++)
        BST = Insert(data[i], BST);
    printStats(BST);

    cout <<  "\nTesting a perfect BST:" << endl;
    for (int i = 0; i < 3; i++)
        perfect = Insert(data[i], perfect);
    printStats(perfect);

    cout <<  "\nTesting a complete BST:" << endl;
    for (int i = 0; i < 4; i++)
        complete = Insert(data[i], complete);
    printStats(complete);

    cout <<  "Testing a balanced BST:" << endl;
    for (int i = 0; i < 13; i++)
        balanced = Insert(data[i], balanced);
    printStats(balanced);

    cout <<  "\nTesting a NonBST:" << endl;
    srand(time(0));
    Node *NonBST = makeTree(15);
    cout << "preorder: " << flush;
    preorder(NonBST);
    cout << "\nsize = " << getSize(NonBST) << endl;
    cout << "height = " << getHeight(NonBST) << endl;
    cout << "isPerfect? " << isPerfect(NonBST) << endl;
    cout << "isComplete? " << isComplete(NonBST) << endl;
    cout << "isBalanced? " << isBalanced(NonBST) << endl;
    cout << "Max in NonBST = " << getMaxInNONBST(NonBST) << endl;
    cout << "Sum = " << getSum(NonBST) << endl;
    cout << "Num of leaves = " << getNumLeaves(NonBST) << endl;
    cout << "Contains 40? NonBST " << containsInNonBST(NonBST, 40) << endl;
    cout << "Contains 2? NonBST " << containsInNonBST(NonBST, 2) << endl;


    return 0;
}
