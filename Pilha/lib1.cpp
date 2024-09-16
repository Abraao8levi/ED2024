#include <iostream>

// Stack ou Pilha
// Altere somente os campos marcados com TODO
struct Stack {
    int size;  // Quantidade de elementos da pilha
    int capacity;  // Quantidade máxima de elementos permitidos dentro da pilha
    int *Arr; // Ponteiro para array de elementos onde salvamos as informacoes do usuario

    Stack(int capacity){
        size = 0;
        this->capacity = capacity;
        Arr = new int[capacity];
    }

    ~Stack(){
        delete[] Arr;
    }


    // Adiciona um elemento no topo da pilha
    // info: informacao do elemento a ser inserido
    void push(int info){
        // TODO
        // Verifica se a pilha não está cheia
        if (!full()) {
            Arr[size] = info; // Adiciona o elemento na posição correspondente ao topo 
         size++; // incrementa o tamanho da pilha
            
        }
    }


    // Remove um elemento do topo da pilha.
    // Nao faz nada caso a pilha esteja vazia.
    void pop(){
        // TODO
        if (!empty()) {  // Verifica se a pilha não está vazia
        size--;  // Decrementa o tamanho da pilha, efetivamente removendo o topo
    }
    }


    // Retorna a informacao do elemento no topo da pilha.
    // Retorna -1, caso a pilha esteja vazia.
    int peek(){
        // TODO
        if(!empty()) { // Verifica se a pilha não está vazia
            return Arr[size -1]; // Retorna o elemento no topo da pilha
        }
        return -1; 
        
    }


    // Remove todos os elementos da pilha
    void clear(){
        // TODO
        size = 0; //Zera o tamanho da pilha, efetivamente removendo todos os elementos
    }


    // Devolve true se cheia e false caso contrario
    bool empty(){
        // TODO
        return size == 0; // Se o tamanho pilha for 0
    }

    // Devolve true se vazia e false caso contrario
    // Aqui depende da capacidade da pilha for igual à capacidade máxima 
    bool full(){
        // TODO
        return size == capacity; /// indica que a capaxidade está cheia 
    } 

    // Printa as informacoes da lista
    void print(){
        std::cout << "[";
        for(int i = 0; i < size; i++){
            std::cout << Arr[i];
            if(i < size-1){
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }    
};

