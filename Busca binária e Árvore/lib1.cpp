/*       ATIVIDADE        */
#include <iostream>

// Node: classe utilizada para representar um No
// Nao altere essa classe
struct Node {
    int info; // Informacao salva pelo usuario na arvore
    Node *left; // Ponteiro para o No filho a esquerda
    Node *right; // Ponteiro para o No filho a direita

    // CAMPOS FALTANTES QUE VOCE DEVE PREENCHER NO METODO 'FILL' //
    Node *parent; // Ponteiro para o No pai (nao iniciado)
    int size; // Quantidade de Nos de sua sub arvore (nao iniciado)
    int level; // Nivel do No atual em relacao ao No raiz (nao iniciado)
    int height; // Altura do No atual (nao iniciado)

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

    // Dado uma arvore onde os Nos foram iniciados com apenas os valores
    // de 'left' e 'right', sua tarefa consiste em preencher os valores
    // faltantes de 'parent', 'level', 'height' e 'size'.
    void fill(){
        // TODO: Complexidade O(n)
        // Dica: Voce pode implementar e chamar os
        // seguintes metodos:
        // fill_parent(root, NULL);
        // fill_size(root);
        // fill_level(root, 1);
        // fill_height(root);
        // Mas sinta-se a vontade para alterar os metodos auxiliares.
        fill_parent(root, NULL);    // Preenche os pais
        fill_size(root);            // Preenche os tamanhos das subárvores
        fill_level(root, 1);        // Preenche os níveis dos Nós
        fill_height(root);          // Preenche as alturas dos Nós
    }
        // Preenche o campo 'parent' dos Nós
    void fill_parent(Node* current, Node* parent){
        // TODO: Complexidade O(n)
        if (current == NULL) return;
        current->parent = parent;
        fill_parent(current->left, current);
        fill_parent(current->right, current);
    }
      // Preenche o campo 'size' de cada Nó
    int fill_size(Node* current){
        // TODO: Complexidade O(n)
        if (current == NULL) return 0;
        // O tamanho de um nó é 1 (ele próprio) + o tamanho das suas subárvores
        current->size = 1 + fill_size(current->left) + fill_size(current->right);
        return current->size;
    }
     // Preenche o campo 'level' de cada Nó
    void fill_level(Node* current, int level){
        // TODO: Complexidade O(n)
        if (current == NULL) return;
        current->level = level;
        fill_level(current->left, level + 1);
        fill_level(current->right, level + 1);
    }
        // Preenche o campo 'height' de cada Nó
    int fill_height(Node* current){
        // TODO: Complexidade O(n)
         if (current == NULL) return 0;
        // A altura de um nó é o maior valor entre as alturas dos filhos + 1
        current->height = 1 + std::max(fill_height(current->left), fill_height(current->right));
        return current->height;
    }

    // Exemplo do FILL:
    // 
    //  T =     32
    //         /  \
    //        45  12
    //       /  \
    //      10  37
    //
    //
    //  No45 = T.root.left
    //  No45.parent == NULL
    //  No45.size == -1
    //  No45.level == -1
    //  No45.height == -1
    //  
    //  T.fill()  
    //
    //  No45.parent == T.root
    //  No45.size == 3
    //  No45.level == 2
    //  No45.height == 2
    //  

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

