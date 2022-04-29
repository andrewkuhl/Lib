#ifndef __LIB_H__
#define __LIB_H__

//knuth morris pratt algo dna
//but first need dfa class
//second need product construction of dfa
//then need nfa
//convert nfa to dfa

#include <map>

#define DEFAULT 0       //DEFAULT 0

template <class T> class States             //STATES CLASS
{
    private:
        int ssize;      //NUMBER OF STATES  (SSIZE)
        std::map<T,int> smap;       //STATES MAP (SMAP)

    public:
    States()    //STATES CONSTRUCTOR
    {
        printf(".");
        ssize = DEFAULT;      //STATES SIZE DEFAULT (0)  
    }
    bool add(T _state)      //ADD STATE TO SMAP
    {
        if(smap.count(_state))      //CHECK SMAP FOR STATE
        {
            return false;       //IF FOUND RETURN FALSE
        }
        else        //IF NOT FOUND RETURN TRUE
        {
            ssize++;        //ADD 1 TO SSIZE
            smap.insert(std::pair<T,int>(_state, ssize));       //INSERT STATE TO SMAP
            return true;    
        }
    }
    bool del(T _state)      //DELETE STATE FROM SMAP
    {
        if(smap.count(_state))      //CHECK SMAP FOR STATE
        {   
            ssize--;        //ADD -1 TO SSIZE
            smap.erase(smap.find(_state));      //ERASE STATE FROM SMAP
            return true;        //IF FOUND RETURN TRUE
        }
        else        //IF NOT FOUND RETURN FALSE
        {
            return false;
        }
    }
    bool find(T _state)     //CHECK IF SMAP CONTAINS STATE
    {
        if(smap.count(_state))      //CHECK SMAP FOR STATE
        {   
            return true;        //IF FOUND RETURN TRUE
        }
        else        //IF NOT FOUND RETURN FALSE
        {
            return false;
        }
    }
    T * list()      //RETURN ARRAY OF STATES
    {
        T * _list = new T(ssize);       //DYNAMIC ARRAY[SSIZE]
        
        typename std::map<T, int>::iterator it;

        int i = 0;
        for (it = smap.begin(); it != smap.end(); it++)     //ITERATE MAP
        {
            _list[it->second - 1] = it->first;      //ADD MAP KEY (STATE) TO ARRAY
        }
        return _list;
    }
    int size()
    {
        return ssize;
    }
};
template <class T> class Alphabet          //ALPHABET CLASS
{
    private:
        int asize;
        std::map<T,int> amap;

    public:
    Alphabet()
    {
        printf(".");
        asize = 0;
    }
};
template <class T> class Transitions        //TRANSITIONS CLASS
{
    private:
        int tsize;
        std::map<T,int> tmap;

    public:
    Transitions()
    {
        printf(".\n");
        tsize = 0;
    }
};

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