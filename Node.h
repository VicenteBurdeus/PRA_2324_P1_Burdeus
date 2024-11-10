#ifndef Node_h
#define Node_h

#include <ostream>
#include "Listas.h"

template <class T>
class Node : public List<T>{
    public:
        T data;
        Node<T>* next;
    
    Node(T data, Node<T>* next = nullptr){
        this->data = data;
        this->next = next;
    }

    friend std::ostream& operator << (std::ostream &out, const Node<T> &node){
        out << node.data;
        return out;
    }

    void insert(int pos, T e) override{
        if(pos == 0){
            next = new Node<T>(data, next);
            data = e;
        } else {
            if(next == nullptr){
                next = new Node<T>(e);
            } else {
                next->insert(pos-1, e);
            }
        }
    }

    void append(T e) override{
        if(next == nullptr){
            next = new Node<T>(e);
        } else {
            next->append(e);
        }
    }

    void prepend(T e) override{
        Node<T>* aux = new Node<T>(data, next);
        data = e;
        next = aux;
    }

    T remove(int pos) override{
        if(pos == 0){
            T aux = data;
            Node<T>* aux2 = next;
            delete this;
            data = aux2->data;
            next = aux2->next;
            return aux;
        } else {
            if(next == nullptr){
                throw std::out_of_range("Posicion invalida");
            } else {
                return next->remove(pos-1);
            }
        }
    }

    T get(int pos) override{
        if(pos == 0){
            return data;
        } else {
            if(next == nullptr){
                throw std::out_of_range("Posicion invalida");
            } else {
                return next->get(pos-1);
            }
        }
    }

    int search(T e) override{
        if(data == e){
            return 0;
        } else {
            if(next == nullptr){
                return -1;
            } else {
                int aux = next->search(e);
                if(aux == -1){
                    return -1;
                } else {
                    return aux+1;
                }
            }
        }
    }

    bool empty() override{
        return next == nullptr;
    }   

    int size() override{
        if(next == nullptr){
            return 1;
        } else {
            return 1 + next->size();
        }
    }
    
};

#endif