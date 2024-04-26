/*
O algoritmo bubblesort é um algoritmo de ordenação baseado em comparações em que
realizamos apenas comparação de elementos adjacentes

*/
#include <stdio.h>
void bubble_sort(vector<int> &A, int p, int r)
{
    debug(A, p, r); // imprime o v
    if (r > p)
    {
        int num_trocas = 0; // contador para most
        for (int K = p; K <= r - 1; K++)
        { //
            {
                if (A[K] < A[K + 1]) // se o elemento da esquerk
                {
                    swap(A[k], A[k + 1]);
                    num_trocas++; // incrementa a contagem de trocas
                }
            }
            debug(A, p, r, num_trocas);
            if (num_trocas > 0)
            {
                bubble_sort(A, p, r - 1);
            }
        }
    }
}
