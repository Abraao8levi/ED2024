/*       ATIVIDADE        */
#include <iostream>

// Node: classe utilizada para representar um No
// Nao altere essa classe
struct Node {
    int info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista

    Node(); // Construtor
    Node(int info, Node *next=NULL); // Construtor
    
    ~Node(); // Destrutor
};

// Singly Linked List ou
// Lista Simplesmente Encadeada
// Altere somente os campos marcados com TODO
struct SLinkedList {
    Node *head;   // Ponteiro para a cabeca da lista (primeiro No)
    Node *tail;   // Ponteiro para a cauda da lista (ultimo No)

    SLinkedList(){
        head = tail = NULL;
    }

    ~SLinkedList(){ // Destrutor
        clear();
    }

    // Retorna true se uma informacao pertence a lista
    // index: posicao do elemento
    bool hasInfo(int info){
        // TODO: Complexidade O(n)
        //A função percorre cada nó da lista 
        //compara a informação armazenada no nó com o valor passado.
        Node* current = head;
    while (current != NULL) {
        if (current->info == info) {
            return true;
        }
        current = current->next;
    }
    return false;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.hasInfo(20) == true
    // L.hasInfo(100) == false

    // Adiciona um elemento no inicio da lista
    // info: informacao do elemento a ser inserido
    void push_front(int info){
        if(head == NULL){ // lista vazia
            head = tail = new Node(info, head);
        }else{
            head = new Node(info, head);
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_front(30)
    // L == 30 -> 10 -> 20 -> 15 -> 50


    // Adiciona um elemento ao final da lista
    // info: informacao do elemento a ser inserido
    void push_back(int info){
        // TODO: Complexidade O(1)
        //Cria um novo nó e o adiciona ao final da lista
        //Se a lista estiver vazia, o nó criado se torna tanto a cabeça quanto a cauda da lista.
         Node* newNode = new Node(info);
    if (tail == NULL) { // lista vazia
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_front(30)
    // L == 10 -> 20 -> 15 -> 50 -> 30


    // Remove o primeiro elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_front(){
        // TODO: Complexidade O(1)
        //Remove o primeiro nó da lista.
        //Se a lista ficar vazia após a remoção, a cauda também é atualizada para NULL.
         if (head != NULL) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL; // lista ficou vazia
        }
        delete temp;
    }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.pop_front()
    // L == 20 -> 15 -> 50


    // Remove o ultimo elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_back(){
        // TODO: Complexidade O(n)
        //Remove o último nó da lista.
        //Se a lista tiver mais de um nó, percorre a lista para encontrar o penúltimo nó e atualiza a cauda.
        if (head == NULL) 
        return; // lista vazia
    if (head == tail) { // apenas um elemento
        delete head;
        head = tail = NULL;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = NULL;
    }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.pop_back()
    // L == 10 -> 20 -> 15


    // Deixa a lista vazia, com zero elementos
    void clear(){
        while(!empty()){
            pop_back();
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.clear()
    // L == []

    // Devolve true se cheia e false caso contrario
    bool empty(){
        return head == NULL;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.empty() == false
    // L == ''
    // L.empty() == true


    // Printa as informacoes da lista
    void print(){
        std::cout << "[";
        for(Node* node = head; node != NULL; node = node->next){
            std::cout << node->info;
            if(node->next != NULL)
                std::cout << " -> ";
        }
        std::cout << "]" << std::endl;
    }    
};

