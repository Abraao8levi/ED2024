/*
diagonal.

Entrada

A entrada é composta por uma única linha contendo uma palavra com até 100 caracteres.

Saída

A saída é composta por n linhas sendo n o tamanho da palavra lida.

Exemplo de Entrada

wladimir
Exemplo de Saída

w
 l
  a
   d
    i
     m
      i
       r
Dica:

void diagonal(char * s, int k){
    if(*s == '\0'){
        return;
    }else{
        //imprima k caracteres
        //imprima o primeiro caractere de s e pule a linha
        //faça a chamada recursiva
    }
}



*/


#include <iostream>
#include <string>
using namespace std;
void diagonal(char *s, int k) {
    if(*s=='\0') {
        return;
    } else {
        for(int i = 0; i < k; ++i){
            cout<<"";
        }
         cout << *s;
         cout << endl;
         diagonal(s + 1, k + 1);
    }
}
int main4() {
    char palavra[100];
    cin >> palavra;
    diagonal(palavra, 0);
    return 0;
}