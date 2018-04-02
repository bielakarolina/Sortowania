////
//// Created by Karolina on 02.04.2018.
////
//
#include <iostream>

#include <math.h>
using namespace std;
//Zadanie 2. Scalanie dwóch posortowanych list.
//
//Zadanie 1. (zadania krótkie) Proszę rozwiązać następujące zadania:
//1. *5pkt.+ Proszę zaimplementować możliwie jak najszybszą funkcję sortującą tablice n liczb.
//2. [5pkt.] Dany jest typ struct List {List * next; int val; } realizujący listę jednokierunkową.
//Proszę zaimplementować funkcję List * reverse { List *L; }, która odwraca kierunek listy L (bez wartownika) i zwraca wskaźnik na jej głowę.
//
//Zadanie 2. Proszę opisać algorytm bez implementacji dla następującego problemu. Dana jest tablica A zawierająca n struktur tylu
//Struct Interval { int  x, y; };
//Elementy tablicy A opisują przedziały otwarte. Dana jest także liczba int t. Zadanie polega na wypisaniu t (lub mniej) przedziałów,
//których suma daje spójny przedział o maksymalnej długości. Proszę podać złożoność czasową algorytmu i uzasadnić jego poprawność.
//
//Zadanie 4. Proszę omówić i zaimplementować możliwie najszybszą funkcję sortującą listę jednokierunkową z danymi typu double.
//Proszę zdefiniować wszystkie potrzebne struktury danych.
//
//Zadanie 1. Dana jest struktura danych
//Struct Point { double x,y; };
//Opisująca punkty w przestrzeni . Proszę zaimplementować funkcję Void heapsort(Point* A, int n);
//Która otrzymuje na wejściu elementową tablicę struktur typu Point I sortuje ją w kolejności rosnącej względem
//odległości punktu od początku układu współrzędnych, korzystając z algorytmu heapsort.
struct Point {
        double x;
        double y;
};
struct Dis{
    Point A;
    int distance;
};
int parent(int i){ return (i-1)/2;}
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}

double d(Point A){
    return sqrt(pow(A.x,2)+pow(A.y,2));
}
void heapify(Point *A,int i,int n){
    int indmax=i;
    if(d(A[left(i)])>d(A[indmax])&& left(i)<n)
        indmax=left(i);
    if(d(A[right(i)])>d(A[indmax])&& right(i)<n)
        indmax=right(i);

    if(i!=indmax){
        swap(A[i],A[indmax]);
        heapify(A,indmax,n);
    }
}
void buildHeap(Point *A,int n){
    for(int i=parent(n-1);i>=0;i--)
        heapify(A,i,n);
}


void Heapsort(Point* A, int n){
    buildHeap(A,n);
    for(int i=n-1;i>=0;i--){
        swap(A[i], A[0]); // wyrzucamy z kopca pierwszy element i naprawiamy resztę (żeby znowu pierwszy element był największy)
        heapify(A,0,i); // czyli naprawia od korzenia do (j - 1) elementu

    }
}
void print(Point A[],int s){
    for(int i=0;i<s;i++){
        cout<<"["<<A[i].x<<",";
        cout<<A[i].y<<"]";
    }
    cout<<endl;

    cout<<endl;
}
int main(){
    Point A[4];
    A[0].x=3;
    A[0].y=4;
    A[1].x=1;
    A[1].y=1;
    A[2].x=0;
    A[2].y=0;
    A[3].x=0;
    A[3].y=3;
    print(A,4);
    Heapsort(A,4);
    print(A,4);


}

//
//Zadanie 1. Dana jest struktura danych
//Struct Rectangle { double x,y; double w,h; };
//Opisująca prostokąty (pola x i y to współrzędne lewego górnego rogu prostokąta a w i h to jego wysokość i szerokość).
//Proszę zaimplementować funkcję void heapsort(Rectangle* A, int n); która otrzymuje na wejściu n
//        elementową tablicę struktur typu Rectangle i sortuje ją w kolejności rosnącej względem wartości pola prostokąta, korzystając z algorytmu heapsort.