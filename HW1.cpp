#include "HW1.h"
void swap(int &x,int &y){
    x = x^y;
    y = x^y;
    x = x^y;
}

void insert_sort(int *a,int *n){
    for (int i = 0; i < *n; ++i){
        for (int j = i; (j < *n && (a[i]>a[i+1])); ++j) {
            swap(a[i], a[i+1]);}
    }
}
void merge_sort(int *a,int *n){

}
void hybrid_sort(int *a,int *n){
    if (*n < 10) {
        insert_sort(a);
    }
    else{
        merge_sort(a);
    }    
    
}
int fib(int num){
if (num == 0){
    return 0;
}
else if (num == 1){
    return 1;
}
else{
    return fib(num)+fib(num-1);
}

}