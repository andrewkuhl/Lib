#ifndef __STATES_H__
#define __STATES_H__

#include <map>

#define DEFAULT 0       //DEFAULT 0
enum SType {START = 0, FINAL, NONFINAL};
template <class T> class States             //STATES CLASS
{
    private:
        int ssize;      //NUMBER OF STATES  (SSIZE)
        std::map<T,int> smap;       //STATES MAP (SMAP)
        T Qs;
        std::map<T,int> Qf;

    public:
    States()    //STATES CONSTRUCTOR
    {
        ssize = DEFAULT;      //STATES SIZE DEFAULT (0)  
    }
    bool add(T _state, SType _type)      //ADD STATE TO SMAP
    {
        if(_type == START)
        {
            if(!smap.count(_state))      //CHECK SMAP FOR STATE
            {
                Qs = _state;
                ssize++;        //ADD 1 TO SSIZE
                smap.insert(std::pair<T,int>(_state, ssize));
                return true;
            }
        }
        else if(_type == FINAL)
        {
            if(!smap.count(_state) && !Qf.count(_state))      //CHECK SMAP FOR STATE
            {
                ssize++;        //ADD 1 TO SSIZE
                smap.insert(std::pair<T,int>(_state, ssize));
                Qf.insert(std::pair<T,int>(_state, ssize));
                return true;
            }
        }
        else
        {
            if(!smap.count(_state))      //CHECK SMAP FOR STATE
            {
                ssize++;        //ADD 1 TO SSIZE
                smap.insert(std::pair<T,int>(_state, ssize));       //INSERT STATE TO SMAP
                return true;    
            }
        }
        return false;
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
    void print()
    {
        typename std::map<T, int>::iterator it;

        for (it = smap.begin(); it != smap.end(); it++)     //ITERATE MAP
        {
            std::cout << "STATE " << it->first << "\n";
        }
    }
    bool clear(int type)
    {
        if(type == 0)
        {
            smap.clear();
            if(smap.empty())
                return true;
            else
                return false;
        }
        else
        {
            Qf.clear();
            if(Qf.empty())
                return true;
            else
                return false;
        }
    }
    T start()
    {
        return Qs;
    }
    bool final(T _state)
    {
        if(Qf.count(_state))
            return true;
        else
            return false;
    }
};

#endif