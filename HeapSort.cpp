//
// Created by Karolina on 13.03.2018.
//

#include <iostream>
#include <string>
using namespace std;

void print_t(int A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


int left(int i) // lewe dziecko
{
    return (2 * i + 1);
}

int right(int i)
{
    return (2 * i + 2);
}

int parent(int i)
{
    return ((i - 1) / 2);
}

void Heapify(int A[], int n, int i) // naprawia kopiec; i - indeks rodzica, n - liczba elementów w tablicy
{
    int indmax = i; // indeks największego elementu w trójce (rodzic + dzieci)
    if (left(i) < n && A[left(i)] > A[indmax])
        indmax = left(i);
    if (right(i) < n && A[right(i)] > A[indmax])
        indmax = right(i);
    if (i != indmax) // i jest rodzicem, więc pod tym indeksem wartość powinna być największa
    {
        swap(A[i], A[indmax]); // jeśli któreś z dzieci jest większe niż rodzic, to zamieniamy i w następnym wywołaniu sprawdzamy wyżej
        Heapify(A, n, indmax);
    }
}

void BuildHeap(int A[], int n)
{
    for (int j = parent(n - 1); j >= 0; j--)
        Heapify(A, n, j);
}

void HeapSort(int A[], int n)
{
    BuildHeap(A, n);
    for (int j = n - 1; j >= 1; j--)
    {
        swap(A[j], A[0]); // wyrzucamy z kopca pierwszy element i naprawiamy resztę (żeby znowu pierwszy element był największy)
        Heapify(A, j, 0); // czyli naprawia od korzenia do (j - 1) elementu
    }
}

int main(){

    const int n = 8;
    int A[n] = { 6, 8, 3, 5, 9, 2, -1, 0 };
    print_t(A,n);
    HeapSort(A, n);
    print_t(A,n);
    return 0;
}
