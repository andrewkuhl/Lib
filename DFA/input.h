#ifndef __INPUT_H__
#define __INPUT_H__

#include <vector>

template<class T>
class Input {
    private:
        std::vector<T> list;
    public:
        void add(T _char)
        {
            list.push_back(_char);
        }
        T * get()
        {
            if(!list.empty())
            {
                T * next = new T();
                *next = list.at(0);
                list.erase(list.begin());
                return next;
            }
            else
                return nullptr;
        }
        bool clear()
        {
            list.clear();
            if(list.empty())
                return true;
            else
                return false;

        }
        T * peek()      //RETURN ARRAY OF CHARACTERS
        {
            T * _list = new T(list.size());       //DYNAMIC ARRAY[ASIZE]

            int lsize = list.size();
            for (int i = 0; i < lsize; i++)     //ITERATE LIST
            {
                _list[i] = list.at(i);      //ADD LIST CHARACTER TO ARRAY
            }
            return _list;
        }
        int size()
        {
            return list.size();
        }
        void print()
        {
            int lsize = list.size();
            std::cout << "INPUT ";
            for (int i = 0; i < lsize; i++)     //ITERATE LIST
            {
                std::cout << list.at(i) << " ";
            }
            std::cout << "\n";
        }

};



#endif