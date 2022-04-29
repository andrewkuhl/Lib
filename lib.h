#ifndef __LIB_H__
#define __LIB_H__

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
    private:
    public:
    States<T> * states;       //STATES OBJ
    Alphabet<T> * alphabet;      //ALPHABET OBJ
    Transitions<T> * transitions;     //TRANSITIONS OBJ

    DFA()       
    {
        printf("dfa");
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
};




#endif