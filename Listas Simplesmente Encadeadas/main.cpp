
#include <iostream>
#include <climits>

struct Node {
    int info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista

    Node(int info, Node *next){
        this->info = info;
        this->next = next;
    };
};

void printNodes(Node* head){
    Node* temp = head;
    while(temp != NULL){
        std::cout << temp->info << std::endl;
        temp = temp->next;
    }
}

// Altere essa funcao.
// Retorne o menor elemento da lista de Nos que inicia do *head
// Pode assumir que a lista tem pelo menos um elemento
int minNode(Node* head){
    //TODO: Declare a variavel min
    int min = head->info; // Importante porque precisa de uma referência inicial para a companhar os outros elementos da lista. 
    
    //TODO: Inicie um No temp que aponta para o primeiro No da lista (head)
    Node* temp = head->next;//  cada interação, o valor do nó atual é comparado com'min', em outras palavras ele atualiza o valor
    
    //TODO: Enquanto nao chegar no final da lista,
    //      Use o min para salvar o valor do menor
    //      use o temp para passar para o proximo No.
     while(temp != NULL){// implementado para percorrer todos os nós da lista, a partir do segundo nó. 
        if(temp->info < min) {
            min = temp->info;
        }
        temp = temp->next;
    }
    return min;
}

// Semelhante ao minNode, mas retorna o maior elemento
int maxNode(Node* head){
    //TODO
    int max = head->info;// atribuir a ela o valor do primeiro nó da lista.

    // Inicia um Nó temp que aponta para o primeiro Nó da lista (head)
    Node* temp = head->next;

    // Enquanto não chegar no final da lista, atualiza o max
    while(temp != NULL){// Implementado para percorre a lista e encontrar o maior valor.
        if(temp->info > max) {
            max = temp->info;
        }
        temp = temp->next;
    }
    return max;

}

int main(){
    // Cria Nos apontando para nada
    Node* node1 = new Node(10, NULL);
    Node* node2 = new Node(99, NULL);
    Node* node3 = new Node(15, NULL);
    Node* node4 = new Node(20, NULL);
    Node* node5 = new Node(2, NULL);

    // Cria variavel head que aponta para o primeiro No
    Node* head = node1;

    // Realiza a ligacao entre os Nos, formando uma lista
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    // [10 -> 99 -> 15 -> 20 -> 2]

    printNodes(head);
    std::cout << "min == " << minNode(head) << std::endl;
    std::cout << "max == " << maxNode(head) << std::endl;
}
