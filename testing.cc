#include <cstdlib>
#include <iostream>

#include "lib.h"

using namespace std;

int main()
{
    bool check = true;
    cout << "TESTING..\n";
    DFA<char> dfa;
    cout << "  dfa obj \tpassed\n";

    /*      STATE TESTS       */

    cout << "STATE METHODS:\n";
    if(dfa.states->add('a')) /*      ADD       */
    {
        if(!dfa.states->add('a'))
            cout << "  add() \tpassed" << endl;
    }
    else
    {
        check = false;
        cout << "  add() \tfailed" << endl;
    }

    if(dfa.states->find('a')) /*       FIND      */
    {
        cout << "  find() \tpassed" << endl;
    }
    else
    {
        check = false;
        cout << "  find() \tfailed" << endl;
    }
    if(dfa.states->list()[0] == 'a') /*       LIST      */
    {
        cout << "  list() \tpassed"  << endl;
    }
    else
    {
        check = false;
        cout << "  list() \tfailed" << endl;
    }
    if(dfa.states->size() == 1) /*     SIZE        */
    {
        cout << "  size() \tpassed"  << endl;
    }
    else
    {
        check = false;
        cout << "  size() \tfailed" << endl;
    }
    if(dfa.states->del('a')) /*      DEL       */
    {
        if(!dfa.states->del('a'))
        cout << "  del() \tpassed"  << endl;
    }
    else
    {
        check = false;
        cout << "  del() \tfailed" << endl;
    }

    cout << "adding states A, B, and C" << endl;
    dfa.states->add('A');
    dfa.states->add('B');
    dfa.states->add('C');
    cout << "TESTING PRINT" << endl;
    dfa.states->print();

    /*       END STATE TESTS      */


    /*      ALPHABET TESTS       */
    cout << "ALPHABET METHODS:\n"; 
    if(dfa.alphabet->add('a')) /*      ADD       */
    {
        if(!dfa.alphabet->add('a'))
            cout << "  add() \tpassed" << endl;
    }
    else
    {
        check = false;
        cout << "  add() \tfailed" << endl;
    }
    if(dfa.alphabet->find('a')) /*      FIND       */
    {
        cout << "  find() \tpassed" << endl;
    }
    else
    {
        check = false;
        cout << "  find() \tfailed" << endl;
    }
    if(dfa.alphabet->list()[0] == 'a') /*      LIST       */
    {
        cout << "  list() \tpassed"  << endl;
    }
    else
    {
        check = false;
        cout << "  list() \tfailed" << endl;
    }
    if(dfa.alphabet->size() == 1) /*      SIZE       */
    {
        cout << "  size() \tpassed"  << endl;
    }
    else
    {
        check = false;
        cout << "  size() \tfailed" << endl;
    }
    if(dfa.alphabet->del('a')) /*      DEL       */
    {
        if(!dfa.alphabet->del('a'))
            cout << "  del() \tpassed"  << endl;
    }
    else
    {
        check = false;
        cout << "  del() \tfailed" << endl;
    }

    cout << "adding characters a, b, and c" << endl;
    dfa.alphabet->add('a');
    dfa.alphabet->add('b');
    dfa.alphabet->add('c');
    cout << "TESTING PRINT" << endl;
    dfa.alphabet->print();

    /*      END ALPHABET TESTS       */



    /*      TRANSITION TESTS       */

     cout << "TRANSITION METHODS:\n";
    if(dfa.transitions->add('a', 'b', 'c')) /*      ADD       */
    {
        if(!dfa.transitions->add('a', 'b', 'c'))
            cout << "  add() \tpassed" << endl;
    }
    else
    {
        check = false;
        cout << "  add() \tfailed" << endl;
    }
    if(dfa.transitions->find('a', 'b')) /*      FIND       */
    {
        if(!dfa.transitions->find('m', 'b'))
        cout << "  find() \tpassed" << endl;
    }
    else
    {
        check = false;
        cout << "  find() \tfailed" << endl;
    }
    if(dfa.transitions->size() == 1) /*      SIZE       */
    {
        cout << "  size() \tpassed"  << endl;
    }
    else
    {
        check = false;
        cout << "  size() \tfailed" << endl;
    }
    if(dfa.transitions->del('a', 'b')) /*       DEL      */
    {
        if(!dfa.transitions->del('a', 'b'))
        cout << "  del() \tpassed"  << endl;
    }
    else
    {
        check = false;
        cout << "  del() \tfailed" << endl;
    }
    cout << "adding transitions .." << endl;
    dfa.transitions->add('A' , 'a', 'B');
    dfa.transitions->add('B' , 'b', 'C');
    dfa.transitions->add('C' , 'c', 'A');
    cout << "TESTING PRINT" << endl;
    dfa.transitions->print();

    /*         END TRANSITION TESTS      */

    if(check) //print result
        cout << "OK" << endl;
    else
        cout << "BAD" << endl;
    return 0;
}
