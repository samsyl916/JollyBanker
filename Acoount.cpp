//
// Created by Sam on 5/12/2021.
//

#include "Acoount.h"

Acoount::Acoount(string firstName, string lastName, int accountID)
{
    insertCheck_ = false;
    firstName_ = firstName;
    lastName_ = lastName;
    accountID_ = accountID;
    string fundType[] = {"Money Market", "Prime Money Market", "Long-Term Bond",
                         "Short-Term Bond", "500 Index Fund", "Capital Value Fund",
                         "Growth Equity Fund", "Growth Index Fund"};

    for (int i = 0; i < 8; i++)
    {
        funds[i].setFundType(fundType[i]);
        funds[i].setBalance(0);
    }
}

string Acoount::getFirstName() const
{
    return firstName_;
}

string Acoount::getLastName() const
{
    return lastName_;
}

string Acoount::getFundtype(int fundID) const
{
    return funds[fundID].getFundType();
}

int Acoount::getBalance(int fundID) const
{
    return funds[fundID].getBalance();
}

bool Acoount::addFund(int amount, int fundID)
{
    if (amount < 0)
    {
        return false;
    }
    else
    {
        funds[fundID].Deposit(amount);
        return true;
    }

}

bool Acoount::removeFund(int amount, int fundID)
{
    if (funds[fundID].checkFundBalance(amount))
    {
        funds[fundID].Withdraw(amount);
        return true;
    }
    if (fundID >= 0 && fundID <= 3)
    {
        if (fundID == 0)
        {
            if (funds[fundID].getBalance() + funds[1].getBalance() >= amount)
            {
                int newBalance = amount - funds[fundID].getBalance();
                funds[fundID].Withdraw(amount - newBalance);
                funds[1].Withdraw(newBalance);
                Transactions* one = new Transactions('W', accountID_, fundID, amount - newBalance);
                Transactions* two = new Transactions('W', accountID_, fundID, newBalance);
                funds[fundID].addTransaction(*one);
                funds[1].addTransaction(*two);
                insertCheck_ = true;
                return true;
            }
        }
        else if (fundID == 1)
        {
            if (funds[fundID].getBalance() + funds[0].getBalance() >= amount)
            {
                int newBalance = amount - funds[fundID].getBalance();
                funds[fundID].Withdraw(amount - newBalance);
                funds[0].Withdraw(newBalance);
                Transactions* one = new Transactions('W', accountID_, fundID, amount - newBalance);
                Transactions* two = new Transactions('W', accountID_, fundID, newBalance);
                funds[1].addTransaction(*one);
                funds[0].addTransaction(*two);
                insertCheck_ = true;
                return true;
            }
        }
        else if (fundID == 2)
        {
            if (funds[fundID].getBalance() + funds[fundID + 1].getBalance() >= amount)
            {
                int newBalance = amount - funds[fundID].getBalance();
                funds[fundID].Withdraw(amount - newBalance);
                funds[3].Withdraw(newBalance);
                Transactions* one = new Transactions('W', accountID_, fundID, amount - newBalance);
                Transactions* two = new Transactions('W', accountID_, fundID, newBalance);
                funds[fundID].addTransaction(*one);
                funds[3].addTransaction(*two);
                insertCheck_ = true;
                return true;
            }
        }
        else if (fundID == 3)
        {
            if (funds[fundID].getBalance() + funds[fundID - 1].getBalance() >= amount)
            {
                int newBalance = amount - funds[fundID].getBalance();
                funds[fundID].Withdraw(amount - newBalance);
                funds[2].Withdraw(newBalance);
                Transactions* one = new Transactions('W', accountID_, fundID, amount - newBalance);
                Transactions* two = new Transactions('W', accountID_, fundID, newBalance);
                funds[fundID].addTransaction(*one);
                funds[2].addTransaction(*two);
                insertCheck_ = true;
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}

void Acoount::printAll()
{
    for (int i = 0; i < 8; i++)
    {
        funds[i].printHistory();
    }
}

void Acoount::printFundHistory(int fundID)
{
    funds[fundID].printHistory();
}

void Acoount::addToTransaction(Transactions t, int fundID)
{
    funds[fundID].addTransaction(t);
}

bool Acoount::insertCheck() const
{
    return insertCheck_;
}

Acoount::~Acoount()
{
}

void Acoount::setFirstName(string firstName)
{
    firstName_ = firstName;
}

void Acoount::setLastName(string lastName)
{
    lastName_ = lastName;
}

bool Acoount::setAccountID(int accountID)
{
    accountID_ = accountID;
    return true;
}

int Acoount::getAccountID() const
{
    return accountID_;
}




