#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include "Tree.h"

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l = nullptr, Node *r = nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
    }
};


Tree::Tree(std::string serial) {
    _root = nullptr;
    std::stringstream ss(serial);
    _serializeTree(ss, &_root);
}

void Tree::_serializeTree(std::stringstream& ss, Node **node) {
    std::string value;
    ss >> value;
    if(value == "#") // filho == nullptr
        return;
    int key = std::stoi(value);
    *node = new Node(key);
    _serializeTree(ss, &((*node)->left));
    _serializeTree(ss, &((*node)->right));
}

Tree::~Tree() {
    _clear(_root);
}

Node *Tree::_clear(Node *node) {
    if(node != nullptr) { // caso geral: vamos liberar essa arvore
        node->left = _clear(node->left);
        node->right = _clear(node->right);
        delete node;
    }
    return nullptr;
}

void Tree::inorder() {
    _inorder(_root);
}

void Tree::_inorder(Node *node) {
    if(node != nullptr) { // Caso Geral
        _inorder(node->left);
        std::cout << node->key << " ";
        _inorder(node->right);  
    }
}

void Tree::bshow(){
    _bshow(_root, "");
}

void Tree::_bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->left, heranca + "l");
}



int Tree::sum_keys() { // TODO
    //soma das chaves
    return _sum_keys(_root);
}

int Tree::_sum_keys(Node *node) { // TODO
    //Escreva uma função que devolva a soma de todas as chaves de uma árvore binária
    if (node->left == nullptr && node->right == nullptr) {
        return node->key;
    }
    int soma = 0;
    if (node->left != nullptr) {
        soma += _sum_keys(node->left);
    }
    if (node->right != nullptr) {
        soma += _sum_keys(node->right);
    }
    return soma + node->key;
}

// Para fazer essa funcao, suponha que as arvores dos testes nunca serao vazias,
// assim, sempre havera um menor valor de chave a ser retornado
int Tree::min_key() { // TODO
    //menor chave da arvore
    return _min_key(_root);
}


// Supoe que o ponteiro recebido sempre eh diferente de nullptr
int Tree::_min_key(Node *node) { // TODO
    //menor chave da arvore
    if (node->left == nullptr && node->right == nullptr) {
        return node->key;
    }
    int menor = INT_MAX;
    if (node->left != nullptr) {
        menor = _min_key(node->left);
    }
    if (node->right != nullptr) {
        menor = std::min(menor, _min_key(node->right));
    }
    return std::min(menor, node->key);
}

int Tree::total_internal_nodes() { // TODO
    //total de nos internos
    return _total_internal_nodes(_root);
}
    
int Tree::_total_internal_nodes(Node *node) { // TODO
    //Escreva uma função que retorne a quantidade de nós de uma árvore binária que possuem apenas um filho.
    if (node->left == nullptr && node->right == nullptr) {
        return 0;
    }
    int total = 0;
    if (node->left != nullptr) {
        total += _total_internal_nodes(node->left);
    }
    if (node->right != nullptr) {
        total += _total_internal_nodes(node->right);
    }
    return total + 1;
}

int Tree::um_filho() { // TODO
    //total de nos com um filho
    return _um_filho(_root);
}

int Tree::_um_filho(Node *node) { // TODO
    //Escreva uma função que retorne a quantidade de nós de uma árvore binária que possuem apenas um filho.
    if (node->left == nullptr && node->right == nullptr) {
        return 0;
    }
    if (node->left == nullptr && node->right != nullptr) {
        return _um_filho(node->right) + 1;
    }
    if (node->left != nullptr && node->right == nullptr) {
        return _um_filho(node->left) + 1;
    }
    return _um_filho(node->left) + _um_filho(node->right);
}


