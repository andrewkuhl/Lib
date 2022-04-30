#include <cstdlib>
#include <iostream>

#include "lib.h"

using namespace std;

int main()
{
    cout << "TESTING..\n";
    DFA<char> dfa;
    cout << "  dfa obj \tpassed\n";

    /*      STATE TESTS       */

    cout << "STATE METHODS:\n";
    if(dfa.states->add('a')) /*      ADD       */
    {
        cout << "  add() \tpassed" << endl;
    }
    else
    {
        cout << "  add() \tfailed" << endl;
    }

    if(dfa.states->find('a')) /*       FIND      */
    {
        cout << "  find() \tpassed" << endl;
    }
    else
    {
        cout << "  find() \tfailed" << endl;
    }
    if(dfa.states->list()[0] == 'a') /*       LIST      */
    {
        cout << "  list() \tpassed"  << endl;
    }
    else
    {
        cout << "  list() \tfailed" << endl;
    }
    if(dfa.states->size() == 1) /*     SIZE        */
    {
        cout << "  size() \tpassed"  << endl;
    }
    else
    {
        cout << "  size() \tfailed" << endl;
    }
    if(dfa.states->del('a')) /*      DEL       */
    {
        cout << "  del() \tpassed"  << endl;
    }
    else
    {
        cout << "  del() \tfailed" << endl;
    }

    /*       END STATE TESTS      */


    /*      ALPHABET TESTS       */
    cout << "ALPHABET METHODS:\n"; 
    if(dfa.alphabet->add('a')) /*      ADD       */
    {
        cout << "  add() \tpassed" << endl;
    }
    else
    {
        cout << "  add() \tfailed" << endl;
    }
    if(dfa.alphabet->find('a')) /*      FIND       */
    {
        cout << "  find() \tpassed" << endl;
    }
    else
    {
        cout << "  find() \tfailed" << endl;
    }
    if(dfa.alphabet->list()[0] == 'a') /*      LIST       */
    {
        cout << "  list() \tpassed"  << endl;
    }
    else
    {
        cout << "  list() \tfailed" << endl;
    }
    if(dfa.alphabet->size() == 1) /*      SIZE       */
    {
        cout << "  size() \tpassed"  << endl;
    }
    else
    {
        cout << "  size() \tfailed" << endl;
    }
    if(dfa.alphabet->del('a')) /*      DEL       */
    {
        cout << "  del() \tpassed"  << endl;
    }
    else
    {
        cout << "  del() \tfailed" << endl;
    }

    /*      END ALPHABET TESTS       */



    /*      TRANSITION TESTS       */

     cout << "TRANSITION METHODS:\n";
    if(dfa.transitions->add('a', 'b', 'c')) /*      ADD       */
    {
        cout << "  add() \tpassed" << endl;
    }
    else
    {
        cout << "  add() \tfailed" << endl;
    }
    if(dfa.transitions->find('a', 'b')) /*      FIND       */
    {
        cout << "  find() \tpassed" << endl;
    }
    else
    {
        cout << "  find() \tfailed" << endl;
    }
    if(dfa.transitions->size() == 1) /*      SIZE       */
    {
        cout << "  size() \tpassed"  << endl;
    }
    else
    {
        cout << "  size() \tfailed" << endl;
    }
    if(dfa.transitions->del('a', 'b')) /*       DEL      */
    {
        cout << "  del() \tpassed"  << endl;
    }
    else
    {
        cout << "  del() \tfailed" << endl;
    }



    return 0;
}
