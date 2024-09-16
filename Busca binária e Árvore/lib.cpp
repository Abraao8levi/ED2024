/*       ATIVIDADE        */
#include <iostream>
#include <climits>

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
struct BinaryTree {
    Node *root;   // Ponteiro para o No raiz da arvore

    BinaryTree(){
        root = NULL;
    }

    ~BinaryTree(){ // Destrutor
        clear();
    }

    // Retorna o No da arvore que possui sua informacao igual a 'info',
    // ou retorna um No vazio (NULL) caso a arvore nao possua tal 'info'.
    Node* search(int info){
        // TODO: Complexidade O(n)
         return _search(root, info);// Método recursivo público para fazer a chamada na árvore.
    }
   Node* _search(Node* current, int info) {
    if (current == NULL) {
        return NULL;
    }

    if (current->info == info) {
        return current;
    }

    Node* leftResult = _search(current->left, info);
    if (leftResult != NULL) {
        return leftResult;
    }

    return _search(current->right, info);
}

    // Cria um novo No com a informacao 'info' e o adiciona
    // a esquerda do No 'current'.
    // Pode assumir que o No esquerdo de 'current' esta vazio.
    void insert_left(Node *current, int info){ //Novo nó atribui o novo filho da esquerda
        // TODO: Complexidade O(1)
        if (current != NULL && current->left == NULL ) {
            current->left = new Node(info);
        }
    }
    // Exemplo:
    // 
    //    T =   12
    //         /  \
    //        50  34
    //          \   \
    //           3   10
    //
    // T.insert_left(No[50], 6)
    // 
    //    T =   12
    //         /  \
    //        50  34
    //       /  \   \
    //      6    3  10

    
    // Cria um novo No com a informacao 'info' e o adiciona
    // a direita do No 'current'.
    // Pode assumir que o No direito de 'current' esta vazio.
    void insert_right(Node *current, int info){ // Aponta para o filho da direita
        // TODO: Complexidade O(1)
        if (current != NULL && current->right == NULL) {
        current->right = new Node(info);
    }
    }
    // Exemplo:
    // 
    //    T =   12
    //         /  \
    //        50  34
    //          \   
    //           3   
    //
    // T.insert_right(No[34], 10)
    // 
    //    T =   12
    //         /  \
    //        50  34
    //          \   \
    //           3  10


    // Retorna a quantidade de elementos da arvore.
    int size(){ // 
        // TODO: Complexidade O(n)
        return _size(root); // função recursiva
    }
     int _size(Node* current) {// Realiza o percorimento e a conatgem do nós da árvore
    if (current == NULL) {
        return 0;
    }
    return 1 + _size(current->left) + _size(current->right);
}


    // Retorna o menor elemento da arvore, ou -1 caso nao exista
    int min(){
        // TODO: Complexidade O(n)
        if (root == NULL) return -1;// complexidade utilizada no pior caso
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
       return current->info;
    }


    // Retorna o maior elemento da arvore, ou -1 caso nao exista
    int max(){
        // TODO: Complexidade O(n)
       //Função para acha o maior valor na árvore
        if (root == NULL) return -1;
    return _max(root);
}

int _max(Node* current) {
    if (current == NULL) return INT_MIN;

    int currentMax = current->info;
    int leftMax = _max(current->left);
    int rightMax = _max(current->right);

    return std::max(currentMax, std::max(leftMax, rightMax));
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
        std::cout << "BinaryTree: ";
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

