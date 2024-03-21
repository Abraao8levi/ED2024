/*
Os coeficientes binomiais são muito importantes para a resolução de vários problemas de contagem. Por exemplo,

C(n,k) representa o número de maneiras de escolher k elementos de um conjunto de n elementos.

C(n + k - 1,k) representa o número de maneiras de escolher k elementos de um conjunto de n elementos se repetições são permitidas.

Os coeficientes binomiais podem ser definidos usando a seguinte recursão:



Sua tarefa é dado dois inteiros n e k, calcula C(n,k).

Entrada

A primeira linha contendo dois inteiros n e k.

Saída

Imprima uma linha contendo C(n,k).

Exemplo de Entrada

8 4
Exemplo de Saída

70


*/
#include <iostream>
#include <vector>

using namespace std;

// Função para calcular o coeficiente binomial C(n, k)
int binomialCoefficient(int n, int k)
{
    // Inicializando uma matriz para armazenar os valores intermediários
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= min(i, k); ++j)
        {

            if (j == 0 || j == i)
                dp[i][j] = 1;
            else

                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main3()
{
    int n, k;
    cin >> n >> k;

    cout << binomialCoefficient(n, k) << endl;

    return 0;
}