/*
Faça um program que imprima todos os sufixos de uma palavra do menor sufixo até o maior.

Entrada

A entrada é composta por uma única linha contendo uma palavra com até 100 caracteres.

Saída

A saída é composta por n linhas sendo n o tamanho da palavra lida.

Exemplo de Entrada

wladimir
Exemplo de Saída

r
ir
mir
imir
dimir
adimir
ladimir
wladimir  


*/
#include <iostream>
#include <string>

int main(){
    std:: string palavra;
    std:: cin >> palavra;
    for(int i = palavra.size() - 1; i >= 0; i--){
        std::cout << palavra.substr(i) << std::endl;
    }
    return 0;
}
