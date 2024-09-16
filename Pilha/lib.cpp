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

// Stack ou Pilha
// Altere somente os campos marcados com TODO
struct Stack {
    Node *top; // Ponteiro para a cabeca da lista (primeiro No)
    int size;  // Quantidade de elementos da pilha (salvar esse valor permite sua consulta em O(1))

    Stack(){
        top = NULL;
        size = 0;
    }

    ~Stack(){
        clear();
    }


    // Adiciona um elemento no topo da pilha
    // info: informacao do elemento a ser inserido
    void push(int info){
        // TODO
        // Cria um novo nó apontando para o nó atual do topo
        Node* newNode = new  Node(info, top);
        top = newNode; // atualiza o top para o novo nó
        size ++;  // realiza a incrementação do tamanho da pilha
    }


    // Remove um elemento do topo da pilha.
    // Nao faz nada caso a pilha esteja vazia.
    void pop(){
        // TODO
        if (top != NULL) { //  Verifica se a pilha não está vazia
        Node* temp = top; // Armazena o nó atual do topo
        top = top->next; // atualiza o topo para o próximo nó
        delete temp;// remove o nó anterior do topo
        size --; // decrementa o tamanho da pilha
            
        }
    }


    // Retorna a informacao do elemento no topo da pilha.
    // Retorna -1, caso a pilha esteja vazia.
    int peek(){
        // TODO //Aqui irá verifica se a pilha não está vazia
        if (top!= NULL) { // 
            return top-> info; // Retorna a informação do nó no topo
        }
        return -1; // Retorna -1 caso a pilha esteja vazia 
        
    }


    // Remove todos os elementos da pilha
    void clear(){
        // TODO
          while (!empty()) {  // Continua removendo o topo enquanto a pilha não estiver vazia
        pop();
    }
    }


    // Devolve true se cheia e false caso contrario
    bool empty(){
        return top == NULL;
    }


    // Printa as informacoes da lista
    void print(){
        std::cout << "[";
        for(Node* node = top; node != NULL; node = node->next){
            std::cout << node->info;
            if(node->next != NULL)
                std::cout << " -> ";
        }
        std::cout << "]" << std::endl;
    }    
};

