//
// Created by Sam on 5/12/2021.
//

#ifndef THEJOLLYBANKER_ACOOUNT_H
#define THEJOLLYBANKER_ACOOUNT_H
#include "Fund.h"
#include "Transactions.h"
#include <vector>
#include <iostream>
using namespace std;

class Acoount
{
public:
    Acoount(string firstName, string lastName, int accountID);
    ~Acoount();

    string getFirstName() const;
    string getLastName() const;
    string getFundtype(int fundID) const;
    int getBalance(int fundID) const;
    int getAccountID() const;
    bool addFund(int amount, int fundID);
    bool removeFund(int amount, int fundID);
    void printAll();
    void printFundHistory(int fundID);
    void addToTransaction(Transactions t, int fundID);
    bool insertCheck() const;
    void setFirstName(string firstName);
    void setLastName(string lastName);
    bool setAccountID(int accountID);

private:
    string firstName_, lastName_;
    int accountID_;
    Fund funds[8];
    bool insertCheck_;
};


#endif //THEJOLLYBANKER_ACOOUNT_H
