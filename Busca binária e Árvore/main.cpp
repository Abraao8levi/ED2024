// Arquivo de execucao
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Retorna o indice do elemento igual a 'target'
// dentro do vetor 'V' entre os indices 'i' e 'j'.
// Retorna -1, caso nao haja tal elemento.
// Pode assumir que todos os elementos do vetor sao distintos.
int binary_search(int *V, int i, int j, int target){
    // TODO: complexidade O(log(n))
    while (i <= j) {
        int mid = i + (j - i) / 2; // Calcula o meio do intervalo

        if (V[mid] == target) {
            return mid; // Encontrou o elemento
        }
        if (V[mid] < target) {
            i = mid + 1; // Busca na metade direita
        } else {
            j = mid - 1; // Busca na metade esquerda
        }
    }
    return -1; // Elemento nao encontrado
}
// Exemplo:
// V: [10,20,30,40]
// binary_search(V, 0, n-1, 10) == true
// binary_search(V, 0, n-1, 30) == true
// binary_search(V, 0, n-1, 15) == false

int main(){
    int n, q;
    cin >> n >> q;

    int *Arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> Arr[i];
    }

    for(int i = 0; i < q; i++){
        int target;
        cin >> target;

        cout << binary_search(Arr, 0, n-1, target) << endl;
    }
    
}
