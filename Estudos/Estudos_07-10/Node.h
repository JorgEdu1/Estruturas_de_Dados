#ifndef NODE_H
#define NODE_H
/*
uso do item, use a linha using Item = int;
dps substituir os tipos primitivos int por Item
*/
class Node{
    friend class ForwardList;
    private:
        int value;
        Node* next;
    public:
        Node(const int& value, Node* ptrNext){
            this->value = value;
            this->next = ptrNext;
        }
        //~Node(){
            //std::cout << "Node " << this->value << " destruido..." << std::endl;
        //}
};
#endif