#ifndef __DFA_H__
#define __DFA_H__

//knuth morris pratt algo dna
//but first need dfa class
//second need product construction of dfa
//then need nfa
//convert nfa to dfa

#include <map>
#include "states.h"
#include "alph.h"
#include "trans.h"

#define DEFAULT 0       //DEFAULT 0
template <class T> class DFA               //DFA CLASS
{

    bool running;

    public:
    States<T> * states;       //STATES OBJ
    Alphabet<T> * alphabet;      //ALPHABET OBJ
    Transitions<T> * transitions;     //TRANSITIONS OBJ

    DFA()       
    {
        running = false;
        states = new States<T>();        //INIT STATES
        alphabet = new Alphabet<T>();       //INIT ALPHABET
        transitions = new Transitions<T>();      //INIT TRANSITIONS
    }
    ~DFA()
    {
        delete states;      //DELETE STATES
        delete alphabet;        //DELETE ALPHABET
        delete transitions;         //DELETE TRANSITIONS
    }
    void sset(int len, T slist[])
    {
        states->clear();
        for(int i = 0; i < len; i++)
        {
            states->add(slist[i]);
        }
    }
    void aset(int len, T alist[])
    {
        alphabet->clear();
        for(int i = 0; i < len; i++)
        {
            alphabet->add(alist[i]);
        }
    }
    void tset(int len, T tlist[][3])
    {
        transitions->clear();
        for(int i = 0; i < len; i++)
        {
            transitions->add(tlist[i][0], tlist[i][1], tlist[i][2]);
        }
    }
    bool run()
    {
        if(running == false)
            return true;
        else
            return false;
    }
};




#endif