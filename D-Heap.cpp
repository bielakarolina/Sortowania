//
// Created by Karolina on 04.04.2018.
//

#include <iostream>
#include <string>
using namespace std;

int parent(int i, int d){
    return (i-1)/d;
}
int child(int i, int k,int d){
    return(d*i+k);
}

void d_heapify(int A[], int i, int n,int d){
    int indmax=i;
    for(int j=1;j<=d;j++){
        if(A[child(i,j,d)]>A[indmax] && child(i,j,d)<n)
            indmax=child(i,j,d);
    }
    if(indmax!=i){
        swap(A[i],A[indmax]);
        d_heapify(A,indmax,n,d);
    }
}
void d_buildHeap(int A[], int n, int d){
    for(int j=parent(n-1,d);j>=0;j--)
        d_heapify(A,j,n,d);
}
void d_extractMAX(int A[], int &n, int d){
    int m=A[0];
    A[0]=A[n-1];
    n--;
    d_heapify(A,0,n,d);
}
void d_heapSort(int A[], int n, int d){
    d_buildHeap(A,n,d);
    for(int j=n-1;j>=1;j--){
        swap(A[j],A[0]);
        d_heapify(A,0,j,d);
    }
}
void print_t(int A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"Złożoność log(d)(n), podstawa log to d :P"<<endl;
    int n = 8;
    int A[n] = { 6, 8, 3, 5, 9, 2, -1, 0 };
    int d=2;
    print_t(A,n);
    cout<<"Budujemy kopiec"<<endl;
    d_buildHeap(A,n,d);
    print_t(A,n);
    cout<<"Wyciągamy max wartosć"<<endl;
    d_extractMAX(A,n,d);
    print_t(A,n);
    cout<<"Sortujemy"<<endl;
    d_heapSort(A, n,d);
    print_t(A,n);


    return 0;
}