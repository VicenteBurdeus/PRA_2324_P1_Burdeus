#ifndef ListLinked_h
#define ListLinked_h

#include <ostream>
#include "Listas.h"
#include "Node.h"

template <class T>
class ListLinked : public List<T>{
    private:
        Node<T>* first;
        int n;
    public:
        ListLinked(){
            first = nullptr;
            n = 0;
        }
        ~ListLinked(){
            while(first != nullptr){
                Node<T>* aux = first;
                first = first->next;
                delete aux;
            }
        }
        T operator[](int pos){
            return get(pos);
        }

        friend std::ostream& operator << (std::ostream &out,const ListLinked<T> &List){
            Node<T>* aux = List.first;
            while(aux != nullptr){
                out << aux->data << " ";
                aux = aux->next;
            }
            return out;
        }

        void insert(int pos, T e) override{
            if(pos < 0 || pos > n){
                throw std::out_of_range("Posicion invalida");
            }
            if(pos == 0){
                first = new Node<T>(e, first);
            } else {
                Node<T>* aux = first;
                for(int i = 0; i < pos-1; i++){
                    aux = aux->next;
                }
                aux->next = new Node<T>(e, aux->next);
            }
            n++;
        }

        void append(T e) override{
            insert(n, e);
        }

        void prepend(T e) override{
            insert(0, e);
        }

        T remove(int pos) override{
            if(pos < 0 || pos >= n){
                throw std::out_of_range("Posicion invalida");
            }
            T aux;
            if(pos == 0){
                aux = first->data;
                Node<T>* aux2 = first->next;
                delete first;
                first = aux2;
            } else {
                Node<T>* aux = first;
                for(int i = 0; i < pos-1; i++){
                    aux = aux->next;
                }
                Node<T>* aux2 = aux->next;
                aux->next = aux2->next;
                aux2->next = nullptr;
                aux = aux2;
                aux2 = nullptr;
                aux2 = aux;
                delete aux2;
            }
            n--;
            return aux;
        }

        T get(int pos) override{
            if(pos < 0 || pos >= n){
                throw std::out_of_range("Posicion invalida");
            }
            Node<T>* aux = first;
            for(int i = 0; i < pos; i++){
                aux = aux->next;
            }
            return aux->data;
        }

        int search(T e) override{
            Node<T>* aux = first;
            for(int i = 0; i < n; i++){
                if(aux->data == e){
                    return i;
                }
                aux = aux->next;
            }
            return -1;
        }

        bool empty() override{
            return n == 0;
        }

        int size() override{
            return n;
        }
        
};


#endif