/*
Jota Marcelo estava pensando em um método para ficar rico. Ele entrou na igreja de Santo Antônio e disse:

Santo Antônio, eu estou muito preocupado com os pobres se você dobrar o dinheiro que eu estou no bolso, eu doarei X reais para os pobres.

Quando ele saiu da igreja e olhou no bolso, o dinheiro tinha dobrado. Em seguida, ele entrou em mais duas igrejas. Contudo, quando ele saiu da terceira igreja, depois que doou o dinheiro que estava no bolso, ele estava com os bolsos vazios.

Sua tarefa é descobrir com quanto de dinheiro ele entrou na primeira igreja.

Entrada:

A entrada possui dois inteiros N e C, separado por um espaço, representando o número de igrejas que Jota Marcelo entrou e valor que seria doado para os pobres, respectivamente

Saída:

Um inteiro representando a quantidade de dinheiro que Jota Marcelinho entrou na primeira igreja.

Exemplo de Entrada

3 20
Exemplo de Saída

17.5


*/

#include <iostream>
#include <cmath>
using namespace std;
double calcularDinheiroInicial(int numIgreja, int doacao) {
    double dinheiro = doacao;
    for(int i = 0; i < numIgreja - 1; ++i) {
        dinheiro = dinheiro *2/3;
    }
    return dinheiro;
}
int main6() {
    int numIgreja, doacao;
    cin >> numIgreja >> doacao;
    double dinheiroInicial = calcularDinheiroInicial(numIgreja, doacao);
    cout <<dinheiroInicial << endl;
    return 0;
}