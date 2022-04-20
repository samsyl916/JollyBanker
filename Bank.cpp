//
// Created by Sam on 11/12/2021.
//

#include "Bank.h"

Bank::Bank()
{
}

Bank::~Bank()
{
}

void Bank::readFile(string name)
{
    ifstream infile(name);
    string line;
    while (getline(infile, line))
    {
        istringstream theLine(line);
        char type;
        theLine >> type;
        if (type == 'O')
        {
            string lastName, firstName;
            int accountID;
            theLine >> accountID >> lastName >> firstName;
            Transactions temp(type, accountID, lastName, firstName);
            t.push(temp);
        }
        else if (type == 'D' || type == 'W')
        {
            int accountID, amount, fundID;
            theLine >> accountID >> fundID >> amount;
            Transactions temp(type, accountID, fundID, amount);
            t.push(temp);
        }
        else if (type == 'T')
        {
            int accountID, fundID, accountID2, fundID2, amount;
            theLine >> accountID >> fundID >> accountID2 >> fundID2 >> amount;
            Transactions temp(type, accountID, fundID, accountID2, fundID2, amount);
            t.push(temp);
        }
        else if (type == 'A')
        {
            int accountID;
            theLine >> accountID;
            Transactions temp(type, accountID);
            t.push(temp);
        }
        else if (type == 'F')
        {
            int accountID, fundID;
            theLine >> accountID >> fundID;
            Transactions temp(type, accountID, fundID);
            t.push(temp);
        }
        else
        {
            cout << "Transaction Code not found!" << endl;
        }
    }
}

void Bank::processTransaction()
{
    while (!t.empty())
    {
        Transactions temp = t.front();
        if (temp.getType() == 'O')
        {
            Acoount* acc = new Acoount(temp.getFirstName(), temp.getLastName(), temp.getAccountID());
            if (!account.Insert(acc))
            {
                cerr << "ERROR: Account: " << temp.getAccountID() << " is already open. Transferal refused." << endl;
            }
            if (acc->getAccountID() < 0)
            {
                cerr << "ERROR: " << acc->getAccountID() << " is an invalid account ID. Transaction refused." << endl;
            }
        }
        else if (temp.getType() == 'D')
        {
            int fundID = temp.getFundID();
            int accountID = temp.getAccountID();
            int amount = temp.getAmount();
            Acoount *acc;
            if (account.Retrieve(accountID, acc))
            {
//                acc->addFund(amount, fundID);
//                acc->addToTransaction(temp, fundID);
            }
            if (acc->addFund(amount, fundID))
            {
                temp.setTransactionStatment(true);
            }
            else
            {
                temp.setTransactionStatment(false);
                cerr << "ERROR: Deposit amount " << temp.getAmount() << " is not allowed. Transaction refused" << endl;
            }
            if (!acc->insertCheck())
            {
                acc->addToTransaction(temp, fundID);
            }
        }
        else if (temp.getType() == 'W')
        {
            int fundID = temp.getFundID();
            int accountID = temp.getAccountID();
            int amount = temp.getAmount();
            Acoount *acc;
            if (account.Retrieve(accountID, acc))
            {
//                acc->removeFund(amount, fundID);
//                acc->addToTransaction(temp, fundID);
//                temp.setTransactionStatment(true);
            }
            if (acc->removeFund(amount, fundID))
            {
                temp.setTransactionStatment(true);
            }
            else
            {
                temp.setTransactionStatment(false);
                cerr << "ERROR: Not enough funds to withdraw " << temp.getAmount() << " from" << temp.getFirstName()<< " "
                << temp.getLastName() << " " << acc->getFirstName() << " " << acc->getLastName() << " " <<
                acc->getFundtype(fundID) << endl;
            }
            if (!acc->insertCheck())
            {
                acc->addToTransaction(temp, fundID);
            }
        }
        else if (temp.getType() == 'T')
        {
            int fromFundID = temp.getFundID();
            int fromAccID = temp.getAccountID();
            int toFundID = temp.getFundID2();
            int toAccID = temp.getAccountID2();
            int amount = temp.getAmount();

            Acoount *from, *to;
            account.Retrieve(fromAccID, from);
            account.Retrieve(toAccID, to);
            if (account.Retrieve(fromAccID, from))
            {
                if (account.Retrieve(toAccID, to))
                {
                    if (from->removeFund(amount, fromFundID))
                    {
                        to->addFund(amount, toFundID);
                        to->addToTransaction(temp, toFundID);
                        from->addToTransaction(temp, fromFundID);
                    }
                    else
                    {
                        cerr << "ERROR: Unsufficent Funds to conduct transfer. From account number: " <<
                             from->getAccountID() << " account: " << from->getFundtype(fromFundID) << " to account number: " <<
                             to->getAccountID() << " account: " << to->getFundtype(toFundID) << " from the amount of: "
                             << temp.getAmount() << endl;
                    }
                }
                else
                {
                    cerr << "ERROR: Account: " << toAccID << " not found. Transferal refused" << endl;
                }

            }
            else
            {
                cerr << "ERROR: Account: " << fromAccID << " not found. Transferal refused" << endl;
            }
        }
        else if (temp.getType() == 'A')
        {
            if(temp.getAccountID() >= 0)
            {
                Acoount * acc;
                if (account.Retrieve(temp.getAccountID(), acc))
                {
                    cout << "Transaction History for " << acc->getFirstName() << " "
                         << acc->getLastName() << " by fund." << endl;
                    acc->printAll();
                }
                else
                {
                    cerr << "ERROR: Account " << temp.getAccountID() << " not found." << endl;
                }
            }
        }
        else if (temp.getType() == 'F')
        {
            if (temp.getAccountID() >= 0) {
                int fundID = temp.getFundID();
                int accountID = temp.getAccountID();
                Acoount *acc;
                if (account.Retrieve(accountID, acc)) {
                    cout << "Transaction History for " << acc->getFirstName() << " "
                         << acc->getLastName() << " ";
                    acc->printFundHistory(fundID);
                } else {
                    cerr << "ERROR: Account " << accountID << " not found." << endl;
                }
            }
        }
        t.pop();
    }
}

void Bank::print()
{
    cout << "FINAL BALANCES:" << endl;
    account.Display();
}

