#include <iostream>

// Node: classe utilizada para representar um No
// NAO ALTERE ESSA CLASSE
struct Node {
    int info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista

    Node(); // Construtor
    Node(int info, Node *next=NULL); // Construtor
    
    ~Node(); // Destrutor
};

// Queue ou Pilha
// Altere somente os campos marcados com TODO
struct LinkedQueue {
    Node *front; // Ponteiro para a cabeca da lista (primeiro No)
    Node *back;  // Ponteiro para a cauda da lista (ultimo No)
    int size;    // Quantidade de elementos da fila (salvar esse valor permite sua consulta em O(1))

    LinkedQueue(){
        front = NULL;
        back = NULL;
        size = 0;
    }

    ~LinkedQueue(){
        clear();
    }


    // Adiciona um elemento no topo da fila
    // info: informacao do elemento a ser inserido
    void push(int info){
        // TODO
        Node* newNode = new Node(info);// Cria um novo nó com a informação fornecida
        if (empty()) {
            // se a fila está vazia, o novo nó será tanto front quanto back
            front = back = newNode;
            
        } else {
            // caso contrário, adiciona o nó no final e atualiza o back
            back->next = newNode;
            back = newNode;
        }
        size ++;
        
    }


    // Remove um elemento do topo da fila.
    // Nao faz nada caso a fila esteja vazia.
    void pop(){
        // TODO
        if (!empty()) {
            Node* temp = front; // Salva o nó atual na frente para liberar depois
            front = front->next; // Atualiza o front para o próximo nó
            delete temp; // Libera o nó removido
            size--; // Decrementa o tamanho da fila
            if (front == NULL) { 
                // Se a fila ficar vazia após a remoção, atualiza o back para NULL
                back = NULL;
            }
        }
    }


    // Retorna a informacao do elemento na frente da fila.
    // Retorna -1, caso a fila esteja vazia.
    int peek(){
        // TODO
        if (empty()) {
            return -1; // fila vazia
        }
         return front->info; // Retorna a informação do nó na frente da fila
        
    }


    // Remove todos os elementos da fila
    void clear(){
        // TODO
         while (!empty()) {
            pop(); // Remove todos os nós, um por um
        }
    }


    // Devolve true se cheia e false caso contrario
    bool empty(){
        return front == NULL;
    }


    // Printa as informacoes da lista
    void print(){
        std::cout << "[";
        for(Node* node = front; node != NULL; node = node->next){
            std::cout << node->info;
            if(node->next != NULL)
                std::cout << " -> ";
        }
        std::cout << "]" << std::endl;
    }    
};

