//
// Created by Sam on 6/12/2021.
//

#include "Fund.h"

Fund::Fund()
{
    setBalance(0);
}

Fund::Fund(string fundType)
{
    setFundType(fundType);
    setBalance(0);
}

Fund::~Fund()
{
}

string Fund::getFundType() const
{
    return fundType_;
}

int Fund::getBalance() const
{
    return balance_;
}

bool Fund::Deposit(int amount)
{
    balance_ += amount;
    return true;
}

bool Fund::Withdraw(int amount)
{
    if (checkFundBalance(amount))
    {
        balance_ -= amount;
    }
    return true;
}

bool Fund::addTransaction(Transactions t)
{
    fundHistory.push_back(t);
    return true;
}

void Fund::printHistory() const
{
    if (fundHistory.size() > 0)
    {
        cout << fundType_ << ": $" << balance_ << endl;
        for (int i = 0; i < fundHistory.size(); i++)
        {
            cout << " " << fundHistory[i];
        }
    }
}

bool Fund::setBalance(int amount)
{
    balance_ = amount;
    return true;
}

bool Fund::setFundType(string fundType)
{
    fundType_ = fundType;
    return true;
}

bool Fund::checkFundBalance(int amount) const
{
    if (balance_ >= amount)
    {
        return true;
    }
    return false;
}

Fund Fund::operator=(const Fund &f)
{
    Fund temp;
    temp.fundHistory = f.fundHistory;
    temp.fundType_ = f.fundType_;
    temp.balance_ = f.balance_;
    return temp;
}
