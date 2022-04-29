#ifndef __TRANS_H__
#define __TRANS_H__

template <class T> class Transitions        //TRANSITIONS CLASS
{
    private:
    int tsize;

    public:
    struct Transition
    {
        T qcurr;
        T input;
        T qend;
    };

    private:
    std::map<Transition,int> tmap;

    public:

    Transitions()
    {
        tsize = 0;
    }
    bool find(T _qcurr, T _input)     //CHECK IF TMAP CONTAINS TRANSITION
    {
        typename std::map<Transition, int>::iterator it;

        for (it = tmap.begin(); it != tmap.end(); it++)     //ITERATE MAP
        {
            if(it->first.qcurr == _qcurr && it->first.input == _input)
            {
                return true;
            }
        }
        return false;
    }
    bool add(T _qcurr, T _input, T _qend)
    {
        Transition newT;
        newT.qcurr = _qcurr;
        newT.input = _input;
        newT.qend = _qend;
        tsize++;
        tmap.insert(std::pair<Transition,int>(newT,tsize));
        return true;
        
    }
    bool del(T _qcurr, T _input)     //CHECK IF TMAP CONTAINS TRANSITION
    {
        return false;
    }
    int size()
    {
        return tsize;
    }
};

#endif