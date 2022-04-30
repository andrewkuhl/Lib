#ifndef __TRANS_H__
#define __TRANS_H__
template <class T> struct Transition
{
    int id;
    T qcurr;
    T input;
    T qend;

    bool operator <( const Transition &rhs ) const
    {
       return ( id < rhs.id );
    }
};
template <class T> class Transitions        //TRANSITIONS CLASS
{
    public:
    int tsize;
    T trash;
    std::map<Transition<T>,int> tmap;

    Transitions()
    {
        tsize = 0;
    }
    bool find(T _qcurr, T _input)     //CHECK IF TMAP CONTAINS TRANSITION
    {
        typename std::map<Transition<T>, int>::iterator it;

        for (it = tmap.begin(); it != tmap.end(); it++)     //ITERATE MAP
        {
            if(it->first.qcurr == _qcurr && it->first.input == _input)
            {
                return true;
            }
        }
        return false;
    }
    T getend(T _qcurr, T _input)     //CHECK IF TMAP CONTAINS TRANSITION
    {
        typename std::map<Transition<T>, int>::iterator it;

        for (it = tmap.begin(); it != tmap.end(); it++)     //ITERATE MAP
        {
            if(it->first.qcurr == _qcurr && it->first.input == _input)
            {
                return it->first.qend;
            }
        }
        return trash;
    }
    bool add(T _qcurr, T _input, T _qend)
    {
        if(find(_qcurr, _input))
            return false;
        Transition<T> newT;
        newT.qcurr = _qcurr;
        newT.input = _input;
        newT.qend = _qend;
        tsize++;
        newT.id = tsize;
        tmap.insert(std::pair<Transition<T>,int>(newT,tsize));
        if(find(_qcurr, _input))
            return true;
        else
            return false;
        
    }
    bool del(T _qcurr, T _input)     //CHECK IF TMAP CONTAINS TRANSITION
    {
        if(!find(_qcurr, _input))
            return false;

        typename std::map<Transition<T>, int>::iterator it;

        for (it = tmap.begin(); it != tmap.end(); it++)     //ITERATE MAP
        {
            if(it->first.qcurr == _qcurr && it->first.input == _input)
            {
                tmap.erase(it);
                if(!find(_qcurr, _input))
                    return true;
            }
        }
        return false;
    }
    int size()
    {
        return tsize;
    }
    void print()
    {
        typename std::map<Transition<T>, int>::iterator it;

        for (it = tmap.begin(); it != tmap.end(); it++)     //ITERATE MAP
        {
            std::cout << "TRANSITION " << it->first.qcurr << " "
                << it->first.input << " " << it->first.qend << "\n";
        }
    }
    bool clear()
    {
        tmap.clear();
        if(tmap.empty())
            return true;
        else
            return false;
    }
};

#endif