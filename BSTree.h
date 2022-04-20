//
// Created by Sam on 5/12/2021.
//

#ifndef THEJOLLYBANKER_BSTREE_H
#define THEJOLLYBANKER_BSTREE_H
#include "Acoount.h"
#include <iostream>
using namespace std;

class BSTree
{
public:
    BSTree();
    ~BSTree();

    bool Insert(Acoount *acc);
    bool Retrieve(const int& accountID, Acoount * & acc) const;
    void Display() const;
    void Empty();
    bool isEmpty() const;

private:
    struct Node
    {
        Acoount *pAcct;
        Node *right;
        Node *left;
    };
    Node *root;
    bool recrusiveInsert(Acoount* acc, Node*& root);
    bool recrusiveRetrieve(int accountID, Acoount * & acc, Node* root) const;
    void recrusiveDisplay(Node* root) const;
};


#endif //THEJOLLYBANKER_BSTREE_H
