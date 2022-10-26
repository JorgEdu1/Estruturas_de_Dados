#include <sstream>
#include <string>
#include "Node.h" 
#include "CircularList.h" 

void CircularList::push_back(const Item& val) { 
    if(this->size() == 0){//caso 1: lista vazia
        Node *aux = new Node(val, nullptr);
        m_head = aux;
        m_head->next = m_head;
    }else{//caso 2: lista com elementos
        Node *ajuda = m_head;
        while(ajuda->next != m_head){
            ajuda = ajuda->next;
        }
        Node *novo = new Node(val, m_head);
        ajuda->next = novo;
    }
        m_size++;
}
void CircularList::pop_back() {
    if(m_head == nullptr){//caso 1: lista com 0 elementos
        return;
    }
    if(m_head->next == m_head){//caso 2: lista com 1 elemento
        delete m_head;
        m_head = nullptr;
        m_size--;
    }else{//caso 3: lista com 2 ou mais elementos
        Node *ajuda = m_head;
        while(ajuda->next->next != m_head){
            ajuda = ajuda->next;
        }
        delete ajuda->next;
        ajuda->next = m_head;
        m_size--;
    }
}
std::string CircularList::toString() const {
    std::stringstream ss;
    ss << "[ ";
    if(m_head != nullptr){
        ss << m_head->value << " ";
        Node *aux = m_head;
        while(aux->next != m_head){
            aux = aux->next;
            ss << aux->value << " ";
        }
    }
    ss << "]";
    return ss.str();
}
Item& CircularList::operator[](int index) {
    Node *aux = m_head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->value;
}
const Item& CircularList::operator[](int index) const {
    Node *aux = m_head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }

    return aux->value;
}
void CircularList::clear() {
    if(m_head != nullptr) {
        Node *aux1 = m_head->next;
        Node *aux2 = m_head->next;
        while(aux1 != m_head) {
            aux2 = aux2->next;
            delete aux1;
            aux1 = aux2;
        }
        delete m_head;
        m_head = nullptr;
        m_size = 0;
    }
}
CircularList::~CircularList() {
    clear();
}

