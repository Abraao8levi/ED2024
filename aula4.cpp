//  cacula a ao quadrado
#include <iostream>
using namespace std;

int  exp_it(int a, int b){
    int  res =1;
    for(int i =1; < b; i++)
    res *=a ;
     return res;
}
int main(){
    int a b;
    scanf("%d%d", &a,&b);
    printf("O resultado de %d elevado a %d eh: %d\n", a , b ,exp_it(a,b));

}
