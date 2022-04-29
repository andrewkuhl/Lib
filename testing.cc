#include <cstdlib>
#include <iostream>

#include "lib.h"

using namespace std;

int main()
{
    cout << "TESTING..\n";
    DFA<char> dfa;
    cout << "  dfa obj \tpassed\n";
    cout << "STATE METHODS:\n";
    if(dfa.states->add('a'))
    {
        cout << "  add() \tpassed" << endl;
    }
    else
    {
        cout << "  add() \tfailed" << endl;
    }
    if(dfa.states->find('a'))
    {
        cout << "  find() \tpassed" << endl;
    }
    else
    {
        cout << "  find() \tfailed" << endl;
    }
    if(dfa.states->list()[0] == 'a')
    {
        cout << "  list() \tpassed"  << endl;
    }
    else
    {
        cout << "  list() \tfailed" << endl;
    }
    if(dfa.states->size() == 1)
    {
        cout << "  size() \tpassed"  << endl;
    }
    else
    {
        cout << "  size() \tfailed" << endl;
    }
    if(dfa.states->del('a'))
    {
        cout << "  del() \tpassed"  << endl;
    }
    else
    {
        cout << "  del() \tfailed" << endl;
    }

    cout << "ALPHABET METHODS:\n";
    if(dfa.alphabet->add('a'))
    {
        cout << "  add() \tpassed" << endl;
    }
    else
    {
        cout << "  add() \tfailed" << endl;
    }
    if(dfa.alphabet->find('a'))
    {
        cout << "  find() \tpassed" << endl;
    }
    else
    {
        cout << "  find() \tfailed" << endl;
    }
    if(dfa.alphabet->list()[0] == 'a')
    {
        cout << "  list() \tpassed"  << endl;
    }
    else
    {
        cout << "  list() \tfailed" << endl;
    }
    if(dfa.alphabet->size() == 1)
    {
        cout << "  size() \tpassed"  << endl;
    }
    else
    {
        cout << "  size() \tfailed" << endl;
    }
    if(dfa.alphabet->del('a'))
    {
        cout << "  del() \tpassed"  << endl;
    }
    else
    {
        cout << "  del() \tfailed" << endl;
    }



    return 0;
}
