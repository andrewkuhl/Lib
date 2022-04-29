#ifndef __STATES_H__
#define __STATES_H__

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

#endif