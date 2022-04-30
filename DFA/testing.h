#ifndef __TESTING_H__
#define __TESTING_H__

#include <cstdlib>
#include <iostream>

#include "DFA.h"
#include <unistd.h>

using namespace std;

void testing()
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
    if(dfa.states->clear()) /*      DEL       */
    {
        cout << "  clear() \tpassed"  << endl;
    }
    else
    {
        check = false;
        cout << "  clear() \tfailed" << endl;
    }

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
    if(dfa.alphabet->clear()) /*      DEL       */
    {
        cout << "  clear() \tpassed"  << endl;
    }
    else
    {
        check = false;
        cout << "  clear() \tfailed" << endl;
    }

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
    if(dfa.transitions->clear()) /*      DEL       */
    {
        cout << "  clear() \tpassed"  << endl;
    }
    else
    {
        check = false;
        cout << "  clear() \tfailed" << endl;
    }

    /*         END TRANSITION TESTS      */

    /*          DFA TESTS           */

    cout << "DFA METHODS:\n";
    char sarr[] = {'A', 'B', 'C'};

    char aarr[] = {'a', 'b', 'c'};

    char tarr[3][3]={'A' , 'a', 'B',
                     'B' , 'b', 'C',
                     'C' , 'c', 'A'};

    dfa.sset(3, sarr);
    cout << "  sset() \tpassed" << endl;
    dfa.aset(3, aarr);
    cout << "  aset() \tpassed" << endl;
    dfa.tset(3, tarr);
    cout << "  tset() \tpassed" << endl;
    if(dfa.run())
        cout << "  run() \tpassed" << endl;
    else
    {
        check = false;
        cout << "  run() \tfailed" << endl;
    }

    cout << "TESTING PRINT" << endl;

    char buffer[96];
    int stdout_save;
    stdout_save = dup(STDOUT_FILENO);
    freopen("NUL", "a", stdout); //redirect stdout to null pointer
    setvbuf(stdout, buffer, _IOFBF, 1024); //set buffer to stdout

    dfa.states->print();
    dfa.alphabet->print();
    dfa.transitions->print();

    freopen("NUL", "a", stdout); //redirect stdout to null again
    dup2(stdout_save, STDOUT_FILENO); //restore the previous state of stdout
    setvbuf(stdout, NULL, _IONBF, 1024); //disable buffer to print to screen instantly
    
    // for(int i = 0; i < 96; i++) //CHECK STATES IN BUFFER
    // {
    //     cout  << "[" << i << " " << buffer[i] << "]";
    // }
    if(buffer[6] =='A' && buffer[14] =='B' && buffer[22] =='C')
    {
        cout << "  states \tpassed" << endl;
    }
    else
    {
        check = false;
        cout << "  states \tfailed" << endl;
    }
    if(buffer[29] =='a' && buffer[36] =='b' && buffer[43] =='c')
    {
        cout << "  alphabet \tpassed" << endl;
    }
    else
    {
        check = false;
        cout << "  alphabet \tfailed" << endl;
    }
    if(buffer[56] =='A' && buffer[58] =='a' && buffer[60] =='B')
    {
        if(buffer[73] =='B' && buffer[75] =='b' && buffer[77] =='C')
            if(buffer[90] =='C' && buffer[92] =='c' && buffer[94] =='A')
                cout << "  transitions \tpassed" << endl;
    }
    else
    {
        check = false;
        cout << "  transitions \tfailed" << endl;
    }

    /*           END DFA TESTS          */
    if(check) //print result
        cout << "\n  OK" << endl;
    else
        cout << "\n  BAD" << endl;
}

#endif