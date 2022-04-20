//
// Created by Sam on 6/12/2021.
//

#ifndef THEJOLLYBANKER_TRANSACTIONS_H
#define THEJOLLYBANKER_TRANSACTIONS_H
#include <iostream>
#include <string>
using namespace std;

class Transactions
{
    friend ostream& operator<<(ostream& out, const Transactions& t);
public:

    Transactions(char type, int accountID, int fundID, int amount);
    Transactions(char type, int accountID, int fundID, int accountID2, int fundID2, int amount);
    Transactions(char type, int accountID);
    Transactions(char type, int accountID, int fundID);
    Transactions(char type, int accountID, string lastName, string firstName);

    char getType() const;
    bool setType(char type);
    int getAccountID() const;
    bool setAccountID(int accountID);
    int getAccountID2() const;
    bool setAccountID2(int accountID);
    int getFundID() const;
    bool setFundID(int id);
    int getFundID2() const;
    bool setFundID2(int id);
    int getAmount() const;
    bool setAmount(int amount);
    string getFirstName() const;
    bool setFirstName(string name);
    string getLastName() const;
    bool setLastName(string name);
    bool setTransactionStatment(bool statment);
    bool getTransactionStatment() const;

private:
    int accountID_, fundID_, amount_, accountID2_, fundID2_;
    string firstName_, lastName_;
    char type_;
    bool statment_ = false;
};


#endif //THEJOLLYBANKER_TRANSACTIONS_H
