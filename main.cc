#include <cstdlib>
#include <iostream>

#include "lib.h"

using namespace std;

int main()
{
    bool printing = true; //PRINT TESTS FLAG
    
    if(printing)
    {
        testing(printing);
    }
    else
    {
        if(testing(printing))
            cout << "OK" << endl;
        else
            cout << "BAD" << endl;
    }

    return 0;
}
