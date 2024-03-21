#include <iostream>
using namespace std;

void increment(int * x) {
    (*x) ++;
    
}
int main1(){
    int num = 5;
    increment(&num);
    cout << num << endl;
    return 0;
}