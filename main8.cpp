/*
A tabela seguinte apresenta uma relação entre a ordem da imagem na sequência e o número total de peças utilizadas:

ordem	         1	2	3
número de peças	3	8	15
Faça um programa que recebe um inteiro n e devolve o número total de peças da n-ésima imagem da sequência.

Entrada

A entrada é composta por uma única linha contendo um inteiro n representando a posição de um padrão na sequência.

Saída

A saída é composta por uma única linha contendo o total de peças da n-ésima imagem da sequência.

Exemplo de Entrada

3
Exemplo de Saída

15


*/

#include <iostream>
using namespace std;

int main8() {
    int n;
    cin >> n;
    
    int totalPecas = n*n + 2*n;
    
    cout << totalPecas << endl;

    return 0;
}