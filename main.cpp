#include <iostream>
#include <vector>
#include <fstream>
#include "Bank.h"
using namespace std;

int main(int argc, char* argv[])
{
    Bank b;
    for (int i = 1; i < argc; i++)
    {
        cout << "The command Line argument was: " << argv[i] << endl;
        string file = argv[i];
        b.readFile(file);
        b.processTransaction();
        b.print();
    }
    return 0;
}
