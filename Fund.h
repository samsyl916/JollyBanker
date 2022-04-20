//
// Created by Sam on 6/12/2021.
//

#ifndef THEJOLLYBANKER_FUND_H
#define THEJOLLYBANKER_FUND_H
#include "Transactions.h"
#include <vector>
using namespace std;

class Fund
{
public:
    Fund();
    Fund(string fundType);
    ~Fund();

    string getFundType() const;
    bool setFundType(string fundType);
    int getBalance() const;
    bool setBalance(int amount);
    bool Deposit(int amount);
    bool Withdraw(int amount);
    bool addTransaction(Transactions t);
    void printHistory() const;
    bool checkFundBalance(int amount) const;
    Fund operator=(const Fund& f);

private:
    string fundType_;
    int balance_ = 0;
    vector<Transactions> fundHistory;
};


#endif //THEJOLLYBANKER_FUND_H
