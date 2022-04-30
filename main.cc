#include <cstdlib>
#include <iostream>

#include "lib.h"

using namespace std;

int main()
{
    bool printing = false; //PRINT TESTS FLAG
    
    if(printing)
    {
        testing(printing);
    }
    else
    {
        if(testing(false))
            cout << "OK" << endl;
        else
            cout << "BAD" << endl;
    }

    return 0;
}
