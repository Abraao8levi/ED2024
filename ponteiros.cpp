//  Ponteiros

#include <iostream>

using namespace std;

int main() {
  int  var1;
  int * pont1;   /* Declaracao de um ponteiro para inteiro */
        var1 = 5;
        pont1= &var1;
            cout << "Valor da variavel, atraves do seu nome": << var1 << endln;   
                cout << " Endereço aramazenado no  ponteiro "<< pont1 << endl;
                    cout << *pont1 << endl;      /* Asterisco antes do nome do ponteiro acesso* ao que ele aponta*/
               // int var2;
                //var2  = *pont1;
                //cout << var2;
                  //    return 0;
                    //*pont1 = 30;
                   // cout <<  var1;
                    var2 = 50;
                    pont1 = &var2;
                    cout <<  *pont1;
                    cout <<  "\n\n Valor da variavel atualizada: ";
                        cout << var1 ;
                            int *pont2;
                            cout << *pont2;





                    return 0;
}