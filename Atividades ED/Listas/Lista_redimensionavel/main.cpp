#include <iostream>
#include <sstream>
using namespace std;

// classe que implementa uma lista redimensionável
class Vector {
private:
    int m_capacity {0}; //esse {} é o modo de inicializar default do c++ a partir do c++11
    int m_size {0};
    int * m_data {nullptr}; //inicializar pra não conter lixo

public:
	// construtor vazio
    Vector(){
        this->m_capacity = 10;
        this->m_size = 0;
        this->m_data = new int[this->m_capacity];
    }

	// construtor
    Vector(int capacity){
        if(capacity <= 0){
            this->m_capacity = 10;
        }else{
            this->m_capacity = capacity;
        }
        this->m_size = 0;
        this->m_data = new int[this->m_capacity];
    }

	// destrutor
    ~Vector(){
        delete this->m_data;
    }

	int size() {
		return this->m_size;
	}

	int capacity() {
		return this->m_capacity;
	}

    Vector(Vector& other){
        this->m_capacity = other.m_capacity;
        this->m_size = other.m_size;
        delete this->m_data;
        this->m_data = new int[this->m_capacity];
        for(int i = 0; i < this->m_size; i++){
            this->m_data[i] = other.m_data[i];
        }
    }


    const Vector& operator = (const Vector& other){
		if(this != &other) {
            this->m_capacity = other.m_capacity;
            this->m_size = other.m_size;
            if(this->m_data != nullptr){
                delete this->m_data;
            }
            this->m_data = new int[this->m_capacity];
            for(int i = 0; i < this->m_size; i++){
                this->m_data[i] = other.m_data[i];
            }
		}
		return *this;
    }

    //adiciona um valor ao final da lista
    void push_back(int value){
        if(this->m_size == this->m_capacity){
            this->m_capacity *= 2;
            int * new_data = new int[this->m_capacity];
            for(int i = 0; i < this->m_size; i++){
                new_data[i] = this->m_data[i];
            }
            delete this->m_data;
            this->m_data = new_data;
        }
        this->m_data[this->m_size] = value;
        this->m_size++;
    }

	//remove um valor do final da lista
    int pop_back(){
        if(this->m_size == 0){
            throw std::runtime_error("Erro: Lista vazia!");
        }else{
            int aux = this->m_data[this->m_size - 1];
            this->m_size--;
            if(this->m_size < this->m_capacity/2){
                this->m_capacity /= 2;
                int * new_data = new int[this->m_capacity];
                for(int i = 0; i < this->m_size; i++){
                    new_data[i] = this->m_data[i];
                }
                delete this->m_data;
                this->m_data = new_data;
            }
            return aux;
        }
        
    }

    std::string toString(){
        std::stringstream ss;
        ss << "[ ";
        for(int i = 0; i < this->m_size; i++){
            ss << this->m_data[i];
            ss << " ";
        }
        ss << "]";
        return ss.str();
    }
};


/* NAO MEXA DAQUI PRA BAIXO */
int main(){
    string line, cmd;
    int value;
    Vector v(0);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init"){
            ss >> value;
            v = Vector(value);
        } else if(cmd == "status"){
            cout << "size:" << v.size() << " capacity:" << v.capacity() << "\n";
        } else if(cmd == "push_back"){
            while(ss >> value)
                v.push_back(value);
        } else if(cmd == "pop_back"){
            ss >> value;
            cout << "popped: ";
            for(int i = 0; i < value; ++i)
                cout << v.pop_back() << " ";
            cout << endl;
        } else if(cmd == "show"){
            cout << v.toString() << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}