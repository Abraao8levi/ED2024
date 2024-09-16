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
    // TODO
    Node *head;   // Ponteiro para a cabeca da lista (primeiro No)

    // Inicializa a lista com Head apontando para nullptr pois a lista está vazia 
    SLinkedList(): head(nullptr) {} 

    ~SLinkedList(){ // Destrutor
    // TODO
        clear(); // Utiliza esse método para garantir que todos os nós são removidos da memória quando o objeto é destruído.
    }

    // Retorna true se uma informacao pertence a lista, false caso contrario
    bool hasInfo(int info){ 
        //TODO : Complexidade O(n) 
        Node* current = head; // Ponteiro para o nó
        while (current != nullptr) { // É utilizado o loop para verificar se a informação do nó atual que é current -> info é igual à informação que está sendo buscada.
            if (current->info == info) {
                return true; // Se for encontrado um nó com informação desejada, irá retornar verdadeiro imediatamente. 
            }
            current = current->next;
        }
        return false; // Se chegar ao final sem encontrar a informação desejada, é retornado falso.
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.hasInfo(20) == true
    // L.hasInfo(100) == false

    // Retorna a informacao dada uma posicao
    int get(int index) {
        // TODO
        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr) { // Percorre a lista até que o nullptr indique o final da lista 
            if (currentIndex == index) { // A cada iteração, verifica se currentIndex é igual ao índice desejado
                return current->info; // Retorna a informação do nó atual
            }
            current = current->next;
            currentIndex++;
        }
        // Se o loop terminar sem encontrar o índice, lança uma exceção
        throw std::out_of_range("Índice fora dos limites da lista"); // Indica que o índice fornecido não é válido na lista
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.get(0) == 10
    // L.get(1) == 20
    // L.get(2) == 15

    // operador[] sobrecarregado. Retorna a 
    // informacao do elemento na posicao 'index'
    int operator[](int index){
        return get(index);
    }

    // Adiciona um elemento no inicio da lista
    // info: informacao do elemento a ser inserido
    void push_front(int info){
        Node* newNode = new Node(info, NULL);
        newNode->next = head;
        head = newNode;
        // Ou simplesmente
        // head = new Node(info, head);
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_front(30)
    // L == 30 -> 10 -> 20 -> 15 -> 50

    // Adiciona um elemento ao final da lista
    // info: informacao do elemento a ser inserido
    void push_back(int info){
        // TODO: Complexidade O(n)
        Node* newNode = new Node(info); // Cria um novo nó com a informação fornecida
        if (head == nullptr) { // Se head é nullptr, a lista está vazia, então faz head apontar para newNode
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) { // Percorre a lista usando um ponteiro até encontrar o último nó
                current = current->next;
            }
            current->next = newNode; // Faz current->next apontar para newNode, adicionando o novo nó ao final da lista
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_back(30)
    // L == 10 -> 20 -> 15 -> 50 -> 30

    // Remove o primeiro elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_front(){
        // TODO: Complexidade O(1)
        if (head != nullptr) { // Verifica se a lista não está vazia 
            Node* temp = head; // Armazena o nó atual de head em um ponteiro temporário chamado temp
            head = head->next; // Atualiza head para apontar para o próximo nó
            delete temp; // Libera a memória do nó usando delete
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
        if (head == nullptr) { // Se head é nullptr, a lista está vazia e não há nada a fazer
            return;
        }
        if (head->next == nullptr) { // Se head->next é nullptr, significa que há apenas um nó na lista.
            delete head; // Deleta head e define head como nullptr.
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) { // Usa um ponteiro current para percorrer a lista até o penúltimo nó
            current = current->next;
        }
        delete current->next; // Deleta current->next (o último nó) e ajusta current->next para nullptr, removendo o último nó da lista.
        current->next = nullptr;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.pop_back()
    // L == 10 -> 20 -> 15

    // Deixa a lista vazia, com zero elementos
    void clear(){
        // TODO: Complexidade O(n)
        // dica: voce pode usar os metodos pop_front e empty
        while (!empty()) { // Remove cada nó do início da lista até que todos os nós sejam removidos.
            pop_front();
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.clear()
    // L == []

    // Retorna o numero de elementos da lista
    int length(){
        // TODO: Complexidade O(n)
        int count = 0; // Inicia o contador em zero
        Node* current = head;
        while (current != nullptr) { // Percorre a lista 
            count++; // Incrementa o contador para cada nó visitado
            current = current->next;
        }
        return count;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.length() == 4

    // Devolve true se cheia e false caso contrario
    bool empty(){
        // TODO
        return head == nullptr; // Faz a checagem de head
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.empty() == false
    // L == ''
    // L.empty() == true

    // Dado um no, retorna o proximo no da lista
    // Retorna NULL caso nao exista
    Node* successor(Node* node){
        return node->next;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.successor(No 20) == No 15
    // L.successor(No 50) == NULL

    // Dado um No, retorna o proximo No da lista
    // Retorna NULL caso nao exista
    Node* predecessor(Node* node){//Define uma função que recebe um ponteiro para um nó (node) e retorna um ponteiro para o nó predecessor desse nó na lista encadeada.
        // TODO: complexidade O(n)
        if (head == nullptr || head == node) {
            return nullptr;
        }
        Node* current = head;
        while (current->next != nullptr && current->next != node) {
            current = current->next;
        }
        return current->next == node ? current : nullptr;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.predecessor([20]) == [10]
    // L.predecessor([10]) == NULL

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
