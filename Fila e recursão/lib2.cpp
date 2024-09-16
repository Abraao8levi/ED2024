#include <iostream>
#include <queue>
#include <stack>

// Stacked ou Fila empilhada
// Altere somente os campos marcados com TODO
struct StackedQueue {
    std::stack<int> stack;     // Pilha para salvar elementos

    StackedQueue(){}

    // Adiciona um elemento no topo da fila
    // info: informacao do elemento a ser inserido
    void push(int info){
        // TODO: complexidade O(1)
        // Utilize somente a pilha 'stack'
        stack.push(info); // Inserir o elemento diretamente na pilha
    }


    // Remove um elemento do topo da fila.
    // Nao faz nada caso a fila esteja vazia.
    void pop(){
        if(stack.empty()){
            return;
        }
        std::stack<int> aux; // Pilha auxiliar para acessar o elemento do 'fundo' da pilha
        // TODO: complexidade O(n)
        // Utilize a pilha 'stack' e a pilha 'aux'
         // Mover todos os elementos para a pilha auxiliar, exceto o último
    while (stack.size() > 1) {
        aux.push(stack.top());
        stack.pop();
    }

    // Remove o último elemento, que é o primeiro da fila
    stack.pop();

    // Mover os elementos de volta para a pilha original
    while (!aux.empty()) {
        stack.push(aux.top());
        aux.pop();
    }
    }


    // Retorna a informacao do elemento na frente da fila.
    // Retorna -1, caso a fila esteja vazia.
    int peek(){
        if(stack.empty()){ // caso base fila vazia
            return -1;
        }
        std::stack<int> aux; // Pilha auxiliar para acessar o elemento do 'fundo' da pilha
        // TODO: complexidade O(n)
        // Utilize a pilha 'stack' e a pilha 'aux'
        // Mover todos os elementos para a pilha auxiliar, exceto o último
        while (stack.size() > 1) {
            aux.push(stack.top());
            stack.pop();
        }
        // Obter o valor do último elemento, que é o primeiro da fila
       int front = stack.top();

      // Mover os elementos de volta para a pilha original
        aux.push(stack.top());  // Reinsere o último elemento na pilha auxiliar
        stack.pop();

       while (!aux.empty()) {
        stack.push(aux.top());
        aux.pop();
       }

        return front;
    }


    // Remove todos os elementos da fila
    void clear(){
        // TODO: complexidade O(n)
        while (!stack.empty()) {
        stack.pop();
    }
    }


    // Devolve true se cheia e false caso contrario
    bool empty(){
        return stack.empty();
    }

    // Printa as informacoes da lista
    void print(){
        std::queue<int> q;

        while(!empty()){
            q.push(peek());
            pop();
        }

        std::cout << "[";
        while(!q.empty()){
            std::cout << q.front();
            push(q.front());
            q.pop();
            if(!q.empty()){
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }    
};

