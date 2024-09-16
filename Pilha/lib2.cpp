#include <iostream>
#include <stack>

// Pilha Dupla
// Classe implementa duas pilhas sequenciais A e B que
// compartilham o mesmo Array de elementos
// Altere somente os campos marcados com "TODO"
struct DoubleStack {
    int sizeA;  // Quantidade de elementos da pilha A
    int sizeB;  // Quantidade de elementos da pilha B
    int capacity;  // Quantidade máxima de elementos permitidos dentro da pilha
    int *Arr; // Array onde sao salvas ambas informacoes da pilha A e pilha B

    DoubleStack(int capacity){
        sizeA = 0;
        sizeB = 0;
        this->capacity = capacity;
        Arr = new int[capacity];
    }

    ~DoubleStack(){
        delete[] Arr;
    }

    bool full(){
        return sizeA + sizeB == capacity;
    }

    ////              PILHA A             ////

    // Adiciona um elemento no topo da pilha A.
    // Nao faz nada caso a pilha esteja cheia.
    // info: informacao do elemento a ser inserido
    void pushA(int info){
        if(!full()){
            Arr[sizeA] = info;
            sizeA++;
        }
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // pushA(10)
    // Pilha A:[1,2,3,10]
    // Pilha B:[4,5]


    // Remove um elemento do topo da pilha.
    // Nao faz nada caso a pilha esteja vazia.
    void popA(){
        // TODO: Complexidade O(1)
        if (!emptyA()) {
            sizeA--; // Decrementa o tamanho da pilha A
        }
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // popA()
    // Pilha A:[1,2]
    // Pilha B:[4,5]


    // Retorna a informacao do elemento no topo da pilha A.
    // Retorna -1, caso a pilha A esteja vazia.
    int peekA(){
        // TODO: Complexidade O(1)
        if (!emptyA()) {
            return Arr[sizeA - 1]; // Aqui retorna  o elemento no topo da pilha A
        }
        return -1;
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // peekA() == 3


    // Remove todos os elementos da pilha
    void clearA(){
        // TODO: Complexidade O(1)
        sizeA = 0; // zera o tamanho da pilha A
    }
    // Exemplo:
    // Pilha A:[]
    // Pilha B:[4,5]
    // peekA() == 3


    // Devolve true se vazia e false caso contrario
    bool emptyA(){
        // TODO: Complexidade O(1)
        return sizeA == 0; // Retorna true se o tamanho da pilha A for 0
    }
    // Exemplo:
    // Pilha A:[]
    // Pilha B:[4,5]
    // emptyA() == true


    // Devolve true se cheia e false caso contrario
    // Considere o tamanho da Pilha A e Pilha B

    ///        PILHA B        ///

    // Adiciona um elemento no topo da pilha A.
    // Nao faz nada caso a pilha esteja cheia.
    // info: informacao do elemento a ser inserido
    void pushB(int info){
        // TODO: Complexidade O(1)
        if (!full()) {
            Arr[capacity - 1 - sizeB] = info; // Adiciona o elemento no top da pilha B
            sizeB ++; // Incremente o tamanho da pilha B
        }
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // pushB(10)
    // Pilha A:[1,2,3]
    // Pilha B:[4,5,10]


    // Remove um elemento do topo da pilha.
    // Nao faz nada caso a pilha esteja vazia.
    void popB(){
        // TODO: Complexidade O(1)
        if (!emptyB()) {
            sizeB--; //  Acontece o decremento no tamanho da pilha B
        }
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // popB()
    // Pilha A:[1,2,3]
    // Pilha B:[4]


    // Retorna a informacao do elemento no topo da pilha A.
    // Retorna -1, caso a pilha A esteja vazia.
    int peekB(){
        // TODO: Complexidade O(1)
        if (!emptyB()) {
            return Arr[capacity - sizeB]; // Retorna o elemento no top da pilha B
        }
        return -1;
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // peekB() == 5


    // Remove todos os elementos da pilha
    void clearB(){
        // TODO: Complexidade O(1)
        sizeB = 0; // zera p tamanho da pilha B 
    }
    // Exemplo:
    // Pilha A:[1,2,3]
    // Pilha B:[4,5]
    // clearB()
    // Pilha A:[1,2,3]
    // Pilha B:[]


    // Devolve true se vazia e false caso contrario
    bool emptyB(){
        // TODO: Complexidade O(1)
        return sizeB == 0; // se o tamanho da pilha b for 0
    }


    // Printa as informacoes da lista
    void print(){
        std::stack<int> stk;

        std::cout << "Pilha A: [";
        while(!emptyA()){
            stk.push(peekA());
            popA();
        }

        while(!stk.empty()){
            std::cout << stk.top();
            pushA(stk.top());
            stk.pop();
            if(!stk.empty()) std::cout << ", ";
        }
        std::cout << "]" << std::endl;

        //////////////////////////////////////////

        std::cout << "Pilha B: [";
        while(!emptyB()){
            stk.push(peekB());
            popB();
        }

        while(!stk.empty()){
            std::cout << stk.top();
            pushB(stk.top());
            stk.pop();
            if(!stk.empty()) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }  
};

