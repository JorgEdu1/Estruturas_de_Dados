/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->value, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString() {
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while(ptr != nullptr) {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 2
 ***********************************************************/

void ForwardList::concat(ForwardList& lst) {
    Node *current = m_head;
    while(current->next != nullptr) {
        current = current->next;
    }
    current->next = lst.m_head->next;
    m_size += lst.m_size;
    lst.m_head->next = nullptr;
    lst.m_size = 0;
}

void ForwardList::remove(const Item& val) {
    Node *current = m_head;
    while(current->next != nullptr) {
        if(current->next->value == val) {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            m_size--;
        } else {
            current = current->next;
        }
    }
}

ForwardList* ForwardList::clone() {
    ForwardList *lst = new ForwardList();
    Node *current = m_head->next;
    while(current != nullptr) {
        lst->insert_at(lst->m_size, current->value);
        current = current->next;
    }
    return lst;
}

void ForwardList::appendVector(const std::vector<Item>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        insert_at(m_size, vec[i]);
    }
}

void ForwardList::swap(ForwardList& lst) {
    Node *temp = m_head;
    m_head = lst.m_head;
    lst.m_head = temp;
    int tempSize = m_size;
    m_size = lst.m_size;
    lst.m_size = tempSize;
}

bool ForwardList::equals(const ForwardList& lst) const {
    if(m_size != lst.m_size) {
        return false;
    }
    Node *current = m_head->next;
    Node *lstCurrent = lst.m_head->next;
    while(current != nullptr) {
        if(current->value != lstCurrent->value) {
            return false;
        }
        current = current->next;
        lstCurrent = lstCurrent->next;
    }
    return true;
}

void ForwardList::reverse() {
    Node *current = m_head->next;
    Node *prev = nullptr;
    while(current != nullptr) {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    m_head->next = prev;
}

Item& ForwardList::get(int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::get(int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}
