//
// Created by Sam on 11/12/2021.
//

#ifndef THEJOLLYBANKER_BANK_H
#define THEJOLLYBANKER_BANK_H
#include "BSTree.h"
#include "Transactions.h"
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Bank
{
public:
    Bank();
    ~Bank();
    void readFile(string name);
    void processTransaction();
    void print();

private:
    BSTree account;
    queue<Transactions> t;
};


#endif //THEJOLLYBANKER_BANK_H
