/*
O diagrama mostra os três primeiros padrões em uma sequência em que cada padrão possui um buraco quadrado no meio.


Padrões
Escreva uma função que dado um inteiro n representando a posição de um padrão na sequência, calcule o número de quadrados sombreados.

Entrada

A entrada é composta por uma única linha contendo um inteiro n representando a posição de um padrão na sequência.

Saída

A saída é composta por uma única linha contendo o número de quadrados sombreados do n-ésimo padrão da sequência.

Exemplo de Entrada

1
Exemplo de Saída

20
A primeira imagem do padrão pode ser decomposto em 4 retângulos 1x2 e 4 figuras no formato de L

*/
#include <iostream>
using namespace std;
int numQuadradoSombreados(int n){
    return n *(n+1) + (n-1) * (n-1);
}
int main5() {
    int n;
    cin >> n;
    cout << numQuadradoSombreados(n) << endl;
    return 0;
}