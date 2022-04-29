#ifndef __ALPH_H__
#define __ALPH_H__

#include <map>
#define DEFAULT 0       //DEFAULT 0

template <class T> class Alphabet             //ALPHABET CLASS
{
    private:
        int asize;      //ALPHABET SIZE  (ASIZE)
        std::map<T,int> amap;       //ALPHABET MAP (AMAP)

    public:
    Alphabet()    //ALPHABET CONSTRUCTOR
    {
        printf(".");
        asize = DEFAULT;      //ALPHABET SIZE DEFAULT (0)  
    }
    bool add(T _char)      //ADD CHARACTER TO AMAP
    {
        if(amap.count(_char))      //CHECK AMAP FOR CHARACTER
        {
            return false;       //IF FOUND RETURN FALSE
        }
        else        //IF NOT FOUND RETURN TRUE
        {
            asize++;        //ADD 1 TO ASIZE
            amap.insert(std::pair<T,int>(_char, asize));       //INSERT CHARACTER TO AMAP
            return true;    
        }
    }
    bool del(T _char)      //DELETE CHARACTER FROM AMAP
    {
        if(amap.count(_char))      //CHECK AMAP FOR CHARACTER
        {   
            asize--;        //ADD -1 TO ASIZE
            amap.erase(amap.find(_char));      //ERASE CHARACTER FROM AMAP
            return true;        //IF FOUND RETURN TRUE
        }
        else        //IF NOT FOUND RETURN FALSE
        {
            return false;
        }
    }
    bool find(T _char)     //CHECK IF AMAP CONTAINS CHARACTER
    {
        if(amap.count(_char))      //CHECK AMAP FOR CHARACTER
        {   
            return true;        //IF FOUND RETURN TRUE
        }
        else        //IF NOT FOUND RETURN FALSE
        {
            return false;
        }
    }
    T * list()      //RETURN ARRAY OF CHARACTERS
    {
        T * _list = new T(asize);       //DYNAMIC ARRAY[ASIZE]
        
        typename std::map<T, int>::iterator it;

        int i = 0;
        for (it = amap.begin(); it != amap.end(); it++)     //ITERATE MAP
        {
            _list[it->second - 1] = it->first;      //ADD MAP KEY (CHARACTER) TO ARRAY
        }
        return _list;
    }
    int size()
    {
        return asize;
    }
};

#endif