//lista simplesmente encadeada
#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
class ForwardList{
    private:
        Node* m_head{nullptr};
        int m_size{0};
    public:
        //construtor default cria uma lista vazia
        //internamente o m_head aponta para o sentinela
        ForwardList(){
            m_head = new Node(0, nullptr);
            m_size = 0;//freezando que m_size é zero! novamente!
        }
        //insete o value no inicio da lista
        void push_front(int value){
            Node* aux = new Node(value,m_head->next);
            m_head->next = aux;
            m_size++;
        }
        //insete o value no fim da lista
        void push_back(int value){
            Node * aux = m_head;
            while(aux->next != nullptr){
                aux = aux->next;
            }
            Node *novo = new Node(value, nullptr);
            aux->next = novo;
            m_size++;
        }
        //retorna uma string contendo os elementos da lista
        std::string toString(){
            std::stringstream ss;
            ss << "[ ";
            Node *atual = m_head->next;
            while(atual != nullptr){
                ss << atual->value << " ";
                atual = atual->next;
            }
            ss << "] ";
            return ss.str();
            }
            //deixa a lista vazia novamente: com 0 elementos
            void clear() {
                while(m_head->next != nullptr){
                    Node *temp = m_head->next;
                    m_head->next = temp->next;
                    delete temp;
                }
                m_size = 0;
            }
            //Destrutor
            ~ForwardList(){
                clear();
                delete m_head;
            }
};
#endif