#ifndef LIST_H
#define	LIST_H
#include <iostream>
#include "Node.h"
template <typename T>
class List{
    private:
        Node<T>*m_head{nullptr};
        int m_size{0};
    public:
        class iterator{
            private:
                Node<T>*m_ptr{nullptr};
            public:
                iterator(Node<T>*ptr):m_ptr(ptr){}
                iterator& operator++(){
                    m_ptr = m_ptr->next;
                    return *this;
                }
                iterator& operator--(){
                    m_ptr = m_ptr->prev;
                    return *this;
                }
                T& operator*(){
                    return m_ptr->value;
                }
                bool operator==(const iterator& other){
                    return m_ptr == other.m_ptr;
                }
                bool operator!=(const iterator& other){
                    return m_ptr != other.m_ptr;
                }
        };
        iterator begin(){
            return iterator(m_head->next);
        }
        iterator end(){
            return iterator(m_head);
        }
        //construtor default
        List(){
            m_head = new Node<T>(0, nullptr, nullptr);
            m_head->prev = m_head->next = m_head;
        }
        void push_back(const T& value){
            Node<T>*newNode = new Node<T>(value, m_head->prev, m_head);
            newNode->prev->next = newNode;
            m_head->prev = newNode;
            m_size++;
        }
        T& operator[](int index){
            Node<T>*aux = m_head->next;
            for(int i = 0; i < index; i++){
                aux = aux->next;
            }
            return aux->value;
        }
        const T& operator[](int index) const{
            Node<T>*aux = m_head->next;
            for(int i = 0; i < index; i++){
                aux = aux->next;
            }
            return aux->value;
        }
        int size() const{
            return m_size;
        }
        bool empty() const{
            return m_size == 0;
        } 
        void clear(){
            Node<T> *aux = m_head->prev;
            while(aux != m_head){
                Node<T> *aux2 = aux-;
                aux = aux->prev;
                delete aux2;
                m_size--;
            }
        }
};
#endif