//
// Created by Sam on 5/12/2021.
//

#include "BSTree.h"

BSTree::BSTree()
{
    root = nullptr;
}

BSTree::~BSTree()
{
}

bool BSTree::recrusiveInsert(Acoount *acc, Node*& root)
{
    if (root == nullptr)
    {
        root = new Node;
        root->pAcct = acc;
        root->left = nullptr;
        root->right = nullptr;
        return true;
    }
    else
    {
        if (root->pAcct->getAccountID() > acc->getAccountID())
        {
            if (root->left == nullptr)
            {
                Node* temp = new Node;
                temp->pAcct = acc;
                temp->left = nullptr;
                temp->right = nullptr;
                root->left = temp;
                return true;
            }
            else
            {
                return recrusiveInsert(acc, root->left);
            }
        }
        else if (root->pAcct->getAccountID() < acc->getAccountID())
        {
            if (root->right == nullptr)
            {
                Node* temp = new Node;
                temp->pAcct = acc;
                temp->left = nullptr;
                temp->right = nullptr;
                root->right = temp;
                return true;
            }
            else
            {
                return recrusiveInsert(acc, root->right);
            }
        }
        else
        {
            return false;
        }
    }
}

bool BSTree::Insert(Acoount *acc)
{
    return recrusiveInsert(acc,root);
}

bool BSTree::Retrieve(const int &accountID, Acoount *& acc) const
{
    if (root == nullptr)
    {
        return false;
    }
    return recrusiveRetrieve(accountID, acc, root);
}

bool BSTree::recrusiveRetrieve(int accountID, Acoount *& acc, Node *root) const
{
    if (root == nullptr)
    {
        acc = nullptr;
        return false;
    }
    else if (accountID == root->pAcct->getAccountID())
    {
        acc = root->pAcct;
        return true;
    }
    else if (accountID < root->pAcct->getAccountID())
    {
        return recrusiveRetrieve(accountID, acc, root->left);
    }
    else
    {
        return recrusiveRetrieve(accountID, acc, root->right);
    }
}

void BSTree::Display() const
{
    if (root != nullptr)
    {
        recrusiveDisplay(root);
    }
}

void BSTree::recrusiveDisplay(Node* root) const
{
    if (root != nullptr)
    {
        recrusiveDisplay(root->left);
        cout << root->pAcct->getFirstName() << " " << root->pAcct->getLastName() <<
        " Account ID: " << root->pAcct->getAccountID() << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << "  " << root->pAcct->getFundtype(i) << ": $" << root->pAcct->getBalance(i) << endl;
        }
        cout << endl;
        recrusiveDisplay(root->right);
    }
}

void BSTree::Empty()
{
    delete root;
    root = nullptr;
}

bool BSTree::isEmpty() const
{
    return root == nullptr;
}
