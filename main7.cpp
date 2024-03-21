/*
ibonacci
Como resultado, se Fn representa o número de pares de coelhos vivos após n -ésimo mês, então obtemos a sequência de Fibonacci com termos que são definidos pela relação de recorrência Fn = Fn − 1 + Fn − 2 (com F1=F2=1 para iniciar a sequência). Embora a sequência tenha o nome de Fibonacci, ela era conhecida pelos matemáticos indianos há mais de dois milênios.

Faça um programa que calcula o número total de pares de coelhos que estarão presentes após n meses, se começarmos com 1 par e em cada geração, cada par de coelhos em idade reprodutiva produz uma ninhada de k pares de coelhos (em vez de apenas 1 par).

Entrada

A entrada é composta por uma única linha contendo dois inteiros (1 ≤ n ≤ 10) e (1 ≤ k ≤ 10)

Saída

A saída é composta por uma única linha contendo o número total de pares de coelhos que estão presentes após n meses, se começarmos com 1 par e em cada geração, cada par de coelhos em idade reprodutiva produz uma ninhada de k pares de coelhos.

Exemplo de Entrada

5 3
Exemplo de Saída

19

*/
#include <iostream>
#include <vector>

std::vector<long long> fib(100, 0);

long long fibonacci(int n, int k) {
    if (n <= 2) {
        return 1;
    }
    if (fib[n] != 0) {
        return fib[n];
    }
    return fib[n] = fibonacci(n - 1, k) + k * fibonacci(n - 2, k);
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << fibonacci(n, k) << std::endl;
    return 0;
}
