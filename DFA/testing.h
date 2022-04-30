#ifndef __TESTING_H__
#define __TESTING_H__

#include <cstdlib>
#include <iostream>

#include "DFA.h"
#include <unistd.h>

using namespace std;

bool testing(bool mode)
{
    bool check = true;
    if(mode)cout << "TESTING..\n";
    DFA<char> dfa;
    if(mode)cout << "  dfa obj \tpassed\n";

    /*      STATE TESTS       */

    if(mode)cout << "STATE METHODS:\n";
    if(dfa.states->add('a', NONFINAL)) /*      ADD       */
    {
        if(!dfa.states->add('a', NONFINAL))
            if(mode)cout << "  add() \tpassed" << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  add() \tfailed" << endl;
    }

    if(dfa.states->find('a')) /*       FIND      */
    {
        if(mode)cout << "  find() \tpassed" << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  find() \tfailed" << endl;
    }
    if(dfa.states->list()[0] == 'a') /*       LIST      */
    {
        if(mode)cout << "  list() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  list() \tfailed" << endl;
    }
    if(dfa.states->size() == 1) /*     SIZE        */
    {
        if(mode)cout << "  size() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  size() \tfailed" << endl;
    }
    if(dfa.states->del('a')) /*      DEL       */
    {
        if(!dfa.states->del('a'))
        if(mode)cout << "  del() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  del() \tfailed" << endl;
    }
    if(dfa.states->clear(0)) /*      CLEAR       */
    {
        if(mode)cout << "  clear() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  clear() \tfailed" << endl;
    }

    /*       END STATE TESTS      */


    /*      ALPHABET TESTS       */
    if(mode)cout << "ALPHABET METHODS:\n"; 
    if(dfa.alphabet->add('a')) /*      ADD       */
    {
        if(!dfa.alphabet->add('a'))
            if(mode)cout << "  add() \tpassed" << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  add() \tfailed" << endl;
    }
    if(dfa.alphabet->find('a')) /*      FIND       */
    {
        if(mode)cout << "  find() \tpassed" << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  find() \tfailed" << endl;
    }
    if(dfa.alphabet->list()[0] == 'a') /*      LIST       */
    {
        if(mode)cout << "  list() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  list() \tfailed" << endl;
    }
    if(dfa.alphabet->size() == 1) /*      SIZE       */
    {
        if(mode)cout << "  size() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  size() \tfailed" << endl;
    }
    if(dfa.alphabet->del('a')) /*      DEL       */
    {
        if(!dfa.alphabet->del('a'))
            if(mode)
                cout << "  del() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  del() \tfailed" << endl;
    }
    if(dfa.alphabet->clear()) /*      CLEAR       */
    {
        if(mode)cout << "  clear() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  clear() \tfailed" << endl;
    }

    /*      END ALPHABET TESTS       */



    /*      TRANSITION TESTS       */

    if(mode)cout << "TRANSITION METHODS:\n";
    if(dfa.transitions->add('a', 'b', 'c')) /*      ADD       */
    {
        if(!dfa.transitions->add('a', 'b', 'c'))
        {
            if(mode)cout << "  add() \tpassed" << endl;
        }
        else
        {
            check = false;
            if(mode)cout << "  add() \tfailed" << endl;
        }
    }
    else
    {
        check = false;
        if(mode)cout << "  add() \tfailed" << endl;
    }
    if(dfa.transitions->find('a', 'b')) /*      FIND       */
    {
        if(dfa.transitions->find('m', 'b'))
        if(mode)cout << "  find() \tpassed" << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  find() \tfailed" << endl;
    }
    if(dfa.transitions->size() == 1) /*      SIZE       */
    {
        if(mode)cout << "  size() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  size() \tfailed" << endl;
    }
    if(dfa.transitions->del('a', 'b')) /*       DEL      */
    {
        if(!dfa.transitions->del('a', 'b'))
        if(mode)cout << "  del() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  del() \tfailed" << endl;
    }
    if(dfa.transitions->clear()) /*      CLEAR       */
    {
        if(mode)cout << "  clear() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  clear() \tfailed" << endl;
    }

    /*         END TRANSITION TESTS      */

    /*      INPUT TESTS       */
    if(mode)cout << "INPUT METHODS:\n"; 
    dfa.input->add('a');/*      ADD       */
    if(*dfa.input->get() == 'a')
    {
        if(mode)cout << "  add() \tpassed" << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  add() \tfailed" << endl;
    }
    dfa.input->add('a');
    if(dfa.input->peek()[0] == 'a') /*      LIST       */
    {
        if(mode)cout << "  peek() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  peek() \tfailed" << endl;
    }
    if(dfa.input->size() == 1) /*      SIZE       */
    {
        if(mode)cout << "  size() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  size() \tfailed" << endl;
    }
    if(dfa.input->clear()) /*      CLEAR       */
    {
        if(mode)cout << "  clear() \tpassed"  << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  clear() \tfailed" << endl;
    }

    /*      END ALPHABET TESTS       */


    /*          DFA TESTS           */

    if(mode)cout << "DFA METHODS:\n";
    char qs = 'A';
    char sarr[] = {'A', 'B', 'C'};
    char qfarr[] = {'B', 'C'};

    char aarr[] = {'a', 'b', 'c'};

    char tarr[3][3]={'A' , 'a', 'B',
                     'B' , 'b', 'C',
                     'C' , 'c', 'A'};

    char iarr[] = {'0', '1', '2'};
    dfa.ssets(qs);
    if(mode)cout << "  ssets() \tpassed" << endl;
    dfa.ssetf(2, qfarr);
    if(mode)cout << "  ssetf() \tpassed" << endl;
    dfa.ssetnf(3, sarr);
    if(mode)cout << "  ssetnf() \tpassed" << endl;
    dfa.aset(3, aarr);
    if(mode)cout << "  aset() \tpassed" << endl;
    dfa.tset(3, tarr);
    if(mode)cout << "  tset() \tpassed" << endl;
    dfa.iset(3, iarr);
    if(mode)cout << "  iset() \tpassed" << endl;
    // if(dfa.run())
    // {
    //     if(mode)cout << "  run() \tpassed" << endl;
    // }
    // else
    // {
    //     check = false;
    //     if(mode)cout << "  run() \tfailed" << endl;
    // }

    if(mode)cout << "TESTING PRINT" << endl;

    char buffer[107];
    int stdout_save;
    stdout_save = dup(STDOUT_FILENO);
    freopen("NULL", "a", stdout); //redirect stdout to null pointer
    setvbuf(stdout, buffer, _IOFBF, 1024); //set buffer to stdout

    dfa.states->print();
    dfa.alphabet->print();
    dfa.transitions->print();
    dfa.input->print();

    freopen("NULL", "a", stdout); //redirect stdout to null again
    dup2(stdout_save, STDOUT_FILENO); //restore the previous state of stdout
    setvbuf(stdout, NULL, _IONBF, 1024); //disable buffer to print to screen instantly
    
    // for(int i = 0; i < 108; i++) //CHECK STATES IN BUFFER
    // {
    //     cout  << "[" << i << " " << buffer[i] << "]";
    // }

    if(buffer[6] =='A' && buffer[14] =='B' && buffer[22] =='C')
    {
        if(mode)cout << "  states \tpassed" << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  states \tfailed" << endl;
    }
    if(buffer[29] =='a' && buffer[36] =='b' && buffer[43] =='c')
    {
        if(mode)cout << "  alphabet \tpassed" << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  alphabet \tfailed" << endl;
    }
    if(buffer[56] =='A' && buffer[58] =='a' && buffer[60] =='B')
    {
        if(buffer[73] =='B' && buffer[75] =='b' && buffer[77] =='C')
            if(buffer[90] =='C' && buffer[92] =='c' && buffer[94] =='A')
                if(mode)cout << "  transitions \tpassed" << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  transitions \tfailed" << endl;
    }

    if(buffer[102] =='0' && buffer[104] =='1' && buffer[106] =='2')
    {
        if(mode)cout << "  input \tpassed" << endl;
    }
    else
    {
        check = false;
        if(mode)cout << "  input \tfailed" << endl;
    }

    remove("NULL");

    /*           END DFA TESTS          */
    if(check) //print result
    {
        if(mode)cout << "\n  OK" << endl;
    }
    else
    {
        if(mode)cout << "\n  BAD" << endl;
    }

    return check;
}

#endif