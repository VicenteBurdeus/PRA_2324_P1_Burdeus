#ifndef ListArray_h
#define ListArray_h

#include <ostream>
#include "Listas.h"

template <class T>
class ListArray : public List<T>{
    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;
        void resize(int newsize){
            T* newarr = new T[newsize];
            for(int i = 0; i < n; i++)
            {
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            max = newsize;
        }
    public:
        ListArray(){
            max = MINSIZE;
            arr = new T[max];
            n = 0;
        }

        ~ListArray(){
            delete[] arr;
        }

        T operator[](int i){
            return arr[i];
        }

        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &List)
        {
            for(int i = 0; i < List.n; i++)
            {
                out << List.arr[i] << " ";
            }
            return out;
        }

        void insert(int pos, T e)override{
            if(n+1 >= max){
                resize(max*2);
            }
            for(int i = n; i > pos; i--)//desplaza los elementos a la derecha de la pos ingresada
            {
                arr[i] = arr[i-1];
            }
        arr[pos] = e;
        n++;
            if (n < max/4){
                resize(max/2);
            }
        }

        void append(T e)override{
            insert(n, e);
        }

        void prepend(T e)override{
            insert(0, e);
        }
        
        T remove(int pos)override{
            T e = arr[pos];
            for(int i = pos; i < n-1; i++)//desplaza los elementos a la izquierda de la pos ingresada
            {
                arr[i] = arr[i+1];
            }
            n--;
            if (n < max/4){
                resize(max/2);
            }
            return e;
        }

        T get(int pos)override{
            return arr[pos];
        }

        int search(T e)override{
            for(int i = 0; i < n; i++)
            {
                if(arr[i] == e)
                {
                    return i;
                }
            }
            return -1;
        }

        bool empty()override{
            return n == 0;
        }

        int size()override{
            return n;
        }
};

#endif