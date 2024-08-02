#include <iostream>
#include <string>

void minMax(int V[], int n, int *min, int *max){
    *min = V[0];
    *max = V[0];
    for(int i = 1; i < n; i++){
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
    for(int i = 0; i < len / 2; i++){
        if(W[i] != W[len - i - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    
    int *V = new int[100];
    int n, min, max;

    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> V[i];
    }
    minMax(V, n, &min, &max);    
    std::cout << min << " " << max << std::endl;

    // Código para verificar palíndromo
    std::string W;
    std::cin >> W;
    if (isPalindrome(W)) {
        std::cout << "palindromo" << std::endl;
    } else {
        std::cout << "nao palindromo" << std::endl;
    }

 
}
