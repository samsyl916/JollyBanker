//
// Created by Sam on 6/12/2021.
//

#include "Transactions.h"


Transactions::Transactions(char type, int accountID, int fundID, int amount)
{
    setType(type);
    setAccountID(accountID);
    setFundID(fundID);
    setAmount(amount);
    setTransactionStatment(true);
}

Transactions::Transactions(char type, int accountID, int fundID, int accountID2, int fundID2, int amount)
{
    setType(type);
    setAccountID(accountID);
    setFundID(fundID);
    setAccountID2(accountID2);
    setFundID2(fundID2);
    setAmount(amount);
    setTransactionStatment(true);
}

Transactions::Transactions(char type, int accountID)
{
    setType(type);
    setAccountID(accountID);
    setTransactionStatment(true);
}

Transactions::Transactions(char type, int accountID, int fundID)
{
    setType(type);
    setAccountID(accountID);
    setFundID(fundID);
    setTransactionStatment(true);
}

Transactions::Transactions(char type, int accountID, string lastName, string firstName)
{
    setType(type);
    setAccountID(accountID);
    setLastName(lastName);
    setFirstName(firstName);
    setTransactionStatment(true);
}

char Transactions::getType() const
{
    return type_;
}

int Transactions::getAccountID() const
{
    return accountID_;
}

int Transactions::getAccountID2() const
{
    return accountID2_;
}

int Transactions::getFundID() const
{
    return fundID_;
}

int Transactions::getFundID2() const
{
    return fundID2_;
}

int Transactions::getAmount() const
{
    return amount_;
}

string Transactions::getFirstName() const
{
    return firstName_;
}

string Transactions::getLastName() const
{
    return lastName_;
}

bool Transactions::setTransactionStatment(bool statment)
{
    statment_ = statment;
    return true;
}

bool Transactions::getTransactionStatment() const
{
    return statment_;
}

bool Transactions::setType(char type)
{
    type_ = type;
    return true;
}

bool Transactions::setAccountID(int accountID)
{
    accountID_ = accountID;
    return true;
}

bool Transactions::setAccountID2(int accountID)
{
    accountID2_ = accountID;
    return true;
}

bool Transactions::setFundID(int id)
{
    fundID_ = id;
    return true;
}

bool Transactions::setFundID2(int id)
{
    fundID2_ = id;
    return true;
}

bool Transactions::setAmount(int amount)
{
    amount_ = amount;
    return true;
}

bool Transactions::setFirstName(string name)
{
    firstName_ = name;
    return true;
}

bool Transactions::setLastName(string name)
{
    lastName_ = name;
    return true;
}

ostream &operator<<(ostream &out, const Transactions &t)
{
    if (t.getType() == 'D' || t.getType() == 'W')
    {
        out << " " << t.getType() << " " << t.getAccountID() << " " << t.getFundID() << " " << t.getAmount();
    }
    else if (t.getType() == 'T')
    {
        out << " " << t.getType() << " " << t.getAccountID() << " " << t.getFundID() << " " << t.getAccountID2() << " " << t.getFundID2() << " " << t.getAmount();
    }
    if (!t.getTransactionStatment())
    {
        out << " (Failed)";
    }

    return out << endl;
}







