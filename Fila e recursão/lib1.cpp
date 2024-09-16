#include <iostream>

// SequentialQueue ou Pilha Sequencial
// Altere somente os campos marcados com TODO
struct SequentialQueue {
    int front;     // Indice do elemento na frente da fila
    int size;      // Quantidade de elementos da fila
    int capacity;  // Quantidade máxima de elementos permitidos dentro da fila
    int *Arr;      // Ponteiro para array de elementos onde salvamos as informacoes do usuario

    SequentialQueue(int capacity){
        size = 0;
        front = 0;
        this->capacity = capacity;
        Arr = new int[capacity];
    }

    ~SequentialQueue(){
        delete[] Arr;
    }


    // Adiciona um elemento no topo da fila
    // info: informacao do elemento a ser inserido
    void push(int info){
        // TODO
       if (!full()) { // primeiro, verifica se a fila está cheia usando essa função
            // Calcula o índice 'rear' que é o final da fila 
            // garanti que o indice esteja dentro dos limites do array
            int rear = (front + size) % capacity;
            Arr[rear] = info;
            size++; // o elemento é incrementado
        }
    }


    // Remove um elemento do topo da fila.
    // Nao faz nada caso a fila esteja vazia.
    void pop(){
        // TODO
         if (!empty()) {
             // se estiver vazia, atualiza o indice para o próximo elemento
            front = (front + 1) % capacity;
            size--; // aqui decrementa o tamanho da fila
        }
    }


    // Retorna a informacao do elemento no topo da fila.
    // Retorna -1, caso a fila esteja vazia.
    int peek(){
        // TODO
        if (!empty()) {
            return Arr[front];
        } else {
            return -1; // fila vazia
        }
    }


    // Remove todos os elementos da fila
    void clear(){
        // TODO
        size = 0;
        front = 0;
    }


    // Devolve true se cheia e false caso contrario
    bool empty(){
        // TODO
        return size == 0;
    }

    // Devolve true se vazia e false caso contrario
    bool full(){
        // TODO
        return size == capacity;
    }

    // Printa as informacoes da lista
    void print(){
        std::cout << "[";
        for(int i = 0; i < size; i++){
            std::cout << Arr[(front+i)%capacity];
            if(i < size-1){
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }    
};

