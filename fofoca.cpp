/*   O código da fofoca ED 2024*/

#include  <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <functional>
#include <utility>

using namespace std;
void  gossip(int n) {
    if (n==1)
    {
        cout << " nenhuma ligação será feita\n";
    }else if (n==2)
    {
        cout << "pessoa 11 liga para pessoa2\n" ;
    }else if(n==3){
        cout <<"pessoas 1  liga  para a 2\n";
        cout <<"pessoas 2  liga para as 3\n";
        cout  <<  "pessoa 3 liga para pessoa 1\n";
    }else if (n==4){
        cout<<"pessoa 1  liga para 2\n";
        cout<<"pessoa 3  liga  para pessoa4\n";
        cout<<"pessoa 1 liga para pessoa 4\n" ;
        cout << "pessoa 2 liga para pessoa 3\n";

    }else {
        cout << "pessoa " << n <<  " liga para pessoa 1\n";
        gossip(n-1);
        cout << "pessoa " << 1 <<  " liga para pessoa " << n <<  "\n";   
    }
}
    int main(){

    int n;

    cout << "Entre com o numero de pessoas:";
    cin >> n;

    gossip(n);

        



}
    
    
    
    
    
    
