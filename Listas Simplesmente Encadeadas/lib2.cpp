#include <iostream>

// Node: classe utilizada para representar um No
// NAO ALTERE ESSA STRUCT
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
struct OrderedSLinkedList {
    Node *head; // Ponteiro para a cabeca da lista (primeiro No)

    OrderedSLinkedList(){
        this->head = NULL;
    }

    // Para esse exercicio, nao precisa implementar o destrutor
    // ~OrderedSLinkedList();

    // Adiciona um elemento na lista, mantendo a ordenação das informacoes da lista
    // info: informacao do elemento a ser inserido
    void push(int info){
        // TODO: Complexidade O(n)
        Node* newNode = new Node(info);// Criação de um novo nó 
        if(head == NULL || head->info >= info){// Se a lista estiver vazia ou se o valor do novo nó for menor ou igual ao valor do primeiro nó (cabeça), o novo nó se torna a nova cabeça da lista.
            newNode->next = head;
            head = newNode;
        } else {
            //Caso contrário, percorro a lista até encontrar o ponto onde o valor do novo nó deve ser inserido. Insiro o novo nó nesse ponto, mantendo a ordem.
            Node* current = head;
            while (current->next != NULL && current->next->info < info) {
                current = current->next;
        }
        newNode->next = current->next;
            current->next = newNode;
        }
    }
    // Exemplo:
    // L == []
    // L.push(4)
    // L == 4
    // L.push(10)
    // L == 4 -> 10
    // L.push(18)
    // L == 4 -> 10 -> 18
    // L.push(1)
    // L == 1 -> 4 -> 10 -> 18
    // L.push(4)
    // L == 1 -> 4 -> 4 -> 10 -> 18

    // Retorna a maior informacao da lista
    // Pode assumir que a lista possui pelo menos 1 elemento
    int min(){
        // TODO
        if (head != NULL) {//retorna o menor valor da lista sempre o primeiro.
            return head->info;
        }
        return -1; // Valor de erro, embora a premissa seja que sempre há pelo menos 1 elemento
    }
    
    // Exemplo:
    // L == 1 -> 4 -> 4 -> 10 -> 18
    // L.min() == 1


    // Retorna a maior informacao da lista
    // Pode assumir que a lista possui pelo menos 1 elemento
    int max(){
        // TODO
      Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        return current->info;
    }
    // Exemplo:
    // L == 1 -> 4 -> 4 -> 10 -> 18
    // L.max() == 18

    // Remove todos elementos com informacao duplicada da lista.
    // Sobrando apenas os nos com informacoes únicas.
    void remove_duplicated(){//Remove os nós duplicados de uma lista encadeada simples
        // TODO: Complexidade O(n)
        // dica: aproveite que os elementos estao ordenados
        Node* current = head;
        while (current != NULL && current->next != NULL) {
            if (current->info == current->next->info) {
                Node* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;
            } else {
                current = current->next;
            }
        }
    }
    // Exemplo:
    // L == 1 -> 1 -> 1 -> 1 -> 2 -> 2 -> 2 -> 4 -> 4 -> 8
    // L.remove_duplicated()
    // L == 1 -> 2 -> 4 -> 8
    // L.remove_duplicated()
    // L == 1 -> 2 -> 4 -> 8

    bool empty(){
        return head == NULL;
    }

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

