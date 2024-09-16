#include <iostream>
#include <unordered_set>

bool repetido(int V[], int n) {
    std::unordered_set<int> elementos;
    
    for (int i = 0; i < n; i++) {
        if (elementos.find(V[i]) != elementos.end()) {
            return true; 
        }
        elementos.insert(V[i]); 
    }
    return false; 
}

int main() {
    int *V = new int[100];
    int n;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> V[i];
    }

    if (repetido(V, n)) {
        std::cout << "repete" << std::endl;
    } else {
        std::cout << "unico" << std::endl;
    }

   
}
