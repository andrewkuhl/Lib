#include <cstdlib>
#include <iostream>

#include "lib.h"

using namespace std;

int main()
{
    DFA<char> dfa;
    if(dfa.states->add('a'))
    {
        cout << "added ";
        for(int i = 0; i < dfa.states->size(); i++)
        {
            cout << dfa.states->list()[0] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "not added" << endl;
    }
    if(dfa.states->find('a'))
    {
        cout << "found ";
        for(int i = 0; i < dfa.states->size(); i++)
        {
            cout << dfa.states->list()[0] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    if(dfa.states->del('a'))
    {
        cout << "deleted" << endl;
    }
    else
    {
        cout << "not deleted" << endl;
    }



    return 0;
}
