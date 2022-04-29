#ifndef __TRANS_H__
#define __TRANS_H__

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

#endif