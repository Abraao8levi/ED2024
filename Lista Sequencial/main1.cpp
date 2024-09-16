#include <iostream>
#include <string>

void minMax(int V[], int n, int *min, int *max) {
    if (n <= 0) return; 
    *min = V[0];
    *max = V[0];
    for(int i = 1; i < n; i++) {
        if(V[i] < *min) {
            *min = V[i];
        }
        if(V[i] > *max) {
            *max = V[i];
        }
    }
}

bool isPalindrome(const std::string &W) {
    int len = W.length();
    for(int i = 0; i < len / 2; i++) {
        if(W[i] != W[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, min = 0, max = 0;

    // Leitura do tamanho do vetor
    std::cin >> n;
    if (n > 0) {
        int *V = new int[n]; 

        // Leitura dos elementos do vetor
        for(int i = 0; i < n; i++) {
            std::cin >> V[i];
        }
        minMax(V, n, &min, &max);    
        std::cout << min << " " << max << std::endl;

        
        delete[] V;
    }

    // Leitura da string para verificação de palíndromo
    std::string W;
    std::cin >> W;
    if (isPalindrome(W)) {
        std::cout << "nao palindromo" << std::endl; 
    } else {
        std::cout << "palindromo" << std::endl;
    }

    return 0;
}
