/*
[A, p, r] = [{5,3,7,1,4}, 0, 4]
[A, p, r] = [{1,3,7,5,4}, 1, 4]
[A, p, r] = [{1,3,7,5,4}, 2, 4]
[A, p, r] = [{1,3,4,5,7}, 3, 4]
[A, p, r] = [{1,3,4,5,7}, 4, 4]
*/




void selection_sort(vector <int> & A, int p, int r) {
debug(A,p,r);
if(p < r){
    int min_idx = p;
    for(int K = p +1; K <= r; K++){
        if(A[K] < A[min_idx]) min_idx = k;

    }
    swap(A[p], A[min_idx]);
    selection_sort(A,p+1,r);
}
}


