#include <iostream>

struct Node {
    std::string info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista
    Node *previous; // Ponteiro para o elemento anterior da lista

    Node(std::string info, Node *next, Node *previous){
        this->info = info;
        this->next = next;
        this->previous = previous;
    };
};

void printNodes(Node* head){
    std::cout << "[ ";
    Node* temp = head;
    while(temp != NULL){
        std::cout << temp->info << " ";
        temp = temp->next;
    }
    std::cout << "]" << std::endl;
}

// Altere essa funcao.
// Inverte a ordem dos elementos de uma lista, alterando
// os valores de 'next' e 'previous' de cada No.
void invert(Node* head){
    // TODO
    Node* current = head;
    Node* temp = nullptr;
    while (current != nullptr) {
        temp = current->previous;
        current->previous = current->next;
        current->next = temp;
        current = current->previous; // Avança para o próximo nó na lista invertida
    }

    // Se a lista não estiver vazia, o novo 'head' é o último nó antes da inversão
    if (temp != nullptr) {
        head = temp->previous;
    }
}
// Exemplo:
// L == "1" <-> "2" <-> "4" <-> "8" <-> "16"
// invert(L)
// L == "16" <-> "8" <-> "4" <-> "2" <-> "1"

int main(){
    /*    TESTE 1   */
    Node *node1 = new Node("azul", NULL, NULL);
    Node *node2 = new Node("branco", NULL, NULL);
    Node *node3 = new Node("cinza", NULL, NULL);
    Node *node4 = new Node("dourado", NULL, NULL);
    Node *node5 = new Node("escarlate", NULL, NULL);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node2->previous = node1;
    node3->previous = node2;
    node4->previous = node3;
    node5->previous = node4;

    printNodes(node1);
    invert(node1);
    printNodes(node5);
    invert(node5);
    printNodes(node1);
    invert(node1);
    printNodes(node5);
}
