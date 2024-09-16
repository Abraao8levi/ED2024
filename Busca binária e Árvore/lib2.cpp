/*       ATIVIDADE        */
#include <iostream>

// Node: classe utilizada para representar um No
// Nao altere essa classe
struct Node {
    int info; // Informacao salva pelo usuario na arvore
    Node *left; // Ponteiro para o No filho a esquerda
    Node *right; // Ponteiro para o No filho a direita

    // Construtores
    Node(); 
    Node(int info, Node *left=NULL, Node *right=NULL);
    
    // Destrutor
    ~Node();
};

// Binary Search Tree ou
// Arvore de busca binaria
// Altere somente os campos marcados com TODO
struct BSTree {
    Node *root;   // Ponteiro para o No raiz da arvore

    BSTree(){
        root = NULL;
    }

    ~BSTree(){ // Destrutor
        clear();
    }

    // Retorna o No da arvore que possui sua informacao igual a 'info',
    // ou retorna um No vazio (NULL) caso a arvore nao possua tal 'info'.
    Node* search(int info){
        // TODO: Complexidade O(h), onde h = altura da arvore
        Node* current = root;
        while (current != NULL) {
            if (info == current->info) {
                return current; // Encontrou o nó
            } else if (info < current->info) {
                current = current->left; // Vai para a esquerda
            } else {
                current = current->right; // Vai para a direita
            }
        }
         return NULL; // Não encontrou o nó
    }

    // Adiciona um elemento na arvore.
    // Esse novo elemento deve ser inserido no lugar
    // de um No vazio e ao mesmo tempo respeitar as propriedades
    // de uma arvore binaria de busca. 
    // info: informacao do elemento a ser inserido
    void insert(int info){
        // TODO: Complexidade O(h), onde h = altura da arvore
        Node* newNode = new Node(info);
    if (root == NULL) {
        root = newNode; // Caso a árvore esteja vazia
        return;
    }

    Node* current = root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (info < current->info) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (info < parent->info) {
        parent->left = newNode; // Insere à esquerda
    } else {
        parent->right = newNode; // Insere à direita
    }
    }
    // Exemplo:
    // 
    //    T =   40
    //         /  \
    //        20  70
    //       /  \
    //      10  30
    //
    // T.insert(90)
    // 
    //    T =   40
    //         /  \
    //        20  70
    //       /  \   \
    //      10  30  90


    // Retorna a quantidade de elementos da arvore.
    int size(){
        // TODO: Complexidade O(n)
        return _size(root);
}

     int _size(Node* current) {
    if (current == NULL) return 0;
    return 1 + _size(current->left) + _size(current->right);
}
     

    // Retorna o menor elemento da arvore, ou -1 caso nao exista
    int min(){
        // função percorre a subárvore esquerda até o último nó, pois em uma árvore binária de busca o menor valor está sempre à esquerda.
        // TODO: Complexidade O(h), onde h = altura da arvore
        if (root == NULL) return -1;
        Node* current = root;
        while (current->left != NULL) {
            current = current->left;
        }
        return current->info;
    }


    // Retorna o maior elemento da arvore, ou -1 caso nao exista
    int max(){
        // TODO: Complexidade O(h), onde h = altura da arvore
        //A função percorre a subárvore direita até o último nó, pois o maior valor estará sempre à direita.
        if(root == NULL) return -1;
        Node* current = root;
        while (current->right != NULL) {
            current = current->right;
        }
        return current->info;
    }

    // Deixa a lista vazia, com zero elementos
    void clear(){
        _clear(root);
        root = NULL;
    }

    void _clear(Node* current){
        if(current == NULL) return;
        _clear(current->left);
        _clear(current->right);
        delete current;
    }

    // Devolve true se vazia e false caso contrario
    bool empty(){
        return root == NULL;
    }

    // Printa as informacoes da lista
    void print(){
        std::cout << "BSTree: ";
        _print(root);
        std::cout << std::endl;
    }

    void _print(Node *current){
        if(current != NULL){
            std::cout << "Node-" << current->info << "{(";
            _print(current->left);
            std::cout << ", ";
            _print(current->right);
            std::cout << ")}";
        }
    }
};

