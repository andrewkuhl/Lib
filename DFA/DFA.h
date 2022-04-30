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
#include "input.h"

#define DEFAULT 0       //DEFAULT 0
template <class T> class DFA               //DFA CLASS
{

    bool running;

    public:
    States<T> * states;       //STATES OBJ
    Alphabet<T> * alphabet;      //ALPHABET OBJ
    Transitions<T> * transitions;     //TRANSITIONS OBJ
    Input<T> * input;     //INPUT  OBJ

    DFA()       
    {
        running = false;
        states = new States<T>();        //INIT STATES
        alphabet = new Alphabet<T>();       //INIT ALPHABET
        transitions = new Transitions<T>();      //INIT TRANSITIONS
        input = new Input<T>();      //INIT INPUT
    }
    ~DFA()
    {
        delete states;      //DELETE STATES
        delete alphabet;        //DELETE ALPHABET
        delete transitions;         //DELETE TRANSITIONS
        delete input;      //DELETE INPUT
    }
    void ssets(T qs)
    {

        states->add(qs, START);
    }
    void ssetf(int len, T qf[])
    {
        states->clear(1);
        for(int i = 0; i < len; i++)
        {
            states->add(qf[i], FINAL);
        }
    }
    void ssetnf(int len, T slist[])
    {
        states->clear(0);
        for(int i = 0; i < len; i++)
        {
            states->add(slist[i], NONFINAL);
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
    void iset(int len, T ilist[])
    {
        input->clear();
        for(int i = 0; i < len; i++)
        {
            input->add(ilist[i]);
        }
    }
    bool run()
    {
        if(!running)
        {
            running = true;
            T currstate = states->start();
            while(running || !states->final(currstate))
            {
                T nextinput = *input->get();
                if(!nextinput)
                {
                    running = false;
                    return false;
                }

                if(!transitions->find(currstate, nextinput))
                {
                    running = false;
                    return false;
                }    

                currstate = transitions->getend(currstate, nextinput);
            }
            return true;
        }
        else
            return false;
    }
    bool isrunning()
    {
        return running;
    }
};




#endif