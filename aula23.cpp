/* continuação de ponteiro*/

#include  <iostream>

using namespace std;
int main() {
    int  *p;
    int  vetor [10];

    p =&vetor[0]; //atribui o
    *p=10;
    cout << "\n" << vetor[0] << "\n";

    p += 1; // move o ponteiro para o próximo elemento
    *p = 20; // atribui 20 ao próximo elemento
    cout << "\n" << vetor[1] <<"\n";

    p += 1; // move o ponteiro para o próximo elemento
    *p = 30; // atribui 30 ao próximo elemento
    cout << "\n" << vetor[2] << "\n";
    return 0;
}
