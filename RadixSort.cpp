//
// Created by Karolina on 18.03.2018.
//
#include <iostream>
#include <string>
using namespace std;
const int n=10;
void print_array(string A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
void print(int A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
long int potega(long int podstawa, int wykladnik)
{
    int wynik = 1;

    for (int i = 0; i<wykladnik; i++)
        wynik*=podstawa;

    return wynik;
}
// poprawnie wedlug cormena
void CountingSort(int A[],int k){
    int B[n],C[k];//B będzie przechowywany wynik koncowy, w C tymczasowe dane pomocniczne
    for(int i =0 ;i<k;i++)
        C[i]=0;
    for(int i=0;i<n;i++)
        C[A[i]]++;// C zawiera liczbe elemenetow rownych i
    for(int i=1;i<k;i++)
        C[i]+=C[i-1];//liczba elementow rownych i lub mniejsza od i jest wpisywana
    for(int i=n-1;i>=0;i--){
        B[C[A[i]]-1]=A[i]; //elementy tablicy A sa umieszczane na wlasciwych pozycjach w tablicy B
        C[A[i]]--;// musimu to robić dy liczby nie sa parami rozne ,dzieki temu nastepny element o wartosci A[i]
        //  zostanie wstawiony do tablicy B na pozycje o 1 mniejsza
    }
    for (int i = 0; i < n; i++)
        A[i] = B[i];
    // delete []B;
    // delete []C;
}


void Counting_Sort_R(int A[], int n, int exp) //k - zakres , exp - waga potegi ,zlożoność O(n+k+n+n)=O(k+n)
{
    int k=10;   //zakres liczb od 0 do k w tradycyjnej procedurze w radix jest to po prostu ilosc cyfr
    int B[n],C[k];
    int i;
    for(int i =0 ;i<k;i++)
        C[i]=0;
    for (i = 0; i < n; i++)
        C[(A[i] / exp) % 10]++;
    for (i = 1; i < k; i++)
        C[i] += C[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        B[C[(A[i] / exp) % 10] - 1] = A[i];
        C[(A[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        A[i] = B[i];
}
void RadixSort_C(int A[],int p,int l){  //  l*O(k+n)=O(l*(k+n)) po pierwsze tak jest w cormenie l-ilosc cyfr k-zakres n-rozmiar tablicy
    for (int i = 1; i<l; i ++)
        Counting_Sort_R(A, n, potega(10,i));
}

//podnosimy poprzeczke i sortujemy tablice liczb o dowolnym zakresie
//sortujemy najpierw wedlug najwiekszej liczby czyli najdluzszej
int max_number(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}

void RadixSort_C2(int A[],int p){  //  l*O(k+n)=O(l*(k+n)) po pierwsze tak jest w cormenie l-ilosc cyfr k-zakres n-rozmiar tablicy
    int m=max_number(A,p);
    //zakres w tym przypadku to najwieksza liczba
    for (int i = 1; m/i>0; i*=10)
        Counting_Sort_R(A, n,i);
}

//zabieramy sie za tablice stringow
// ciag slow roznej dlugosci


void Counting_Sort_W(string A[], int n, int exp) //k - zakres , exp- numer literki od konca ,zlożoność O(n+k+n+n)=O(k+n)
{
    int k=254;   //zakres reprezentacji liter w string
    string B[n];
    int C[k];
    int i;
    for(int i =0 ;i<k;i++)
        C[i]=0;
    for (i = 0; i < n; i++)
        C[(int) A[i][exp]]++;

    for (i = 1; i < k; i++)
        C[i] += C[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        B[C[(int)A[i][exp]] - 1] = A[i];
        C[(int)A[i][exp]]--;
    }
    for (i = 0; i < n; i++)
        A[i] = B[i];
}

int max_length(string A[], int p){
    int max=A[0].length();
    for(int i=1;i<n;i++){
        if(A[i].length()>max)
            max=A[i].length();
    }
    return max;
}

void RadixSort_word(string A[],int p){
    int m=max_length(A,p);
    for(int i=m;i>=0;i--)
        Counting_Sort_W(A, p, i);

}

int main() {
    int k =20;
    int A[n]={1,4,6,8,19,18,11,15,0,4};
    print(A,n);
    CountingSort(A,k);
    print(A,n);
    int p=4;
    int P[p]={123,834,356,121};
    int K[n]={111,222,121,555,222,190,654,158,900,121};
    int G[n]={11,22222,531212,7889,12,45,12,33,689,11};

    cout<<"Wersja poprawna z O(l*(n+k)): liczby"<<endl;
    print(K,n);
    RadixSort_C(K,n,3);
    print(K,n);
    cout<<"Wersja dla ciągów różniej długości: liczby"<<endl;
    print(G,n);
    RadixSort_C2(G,n);
    print(G,n);
    cout<<"Wersja dla ciagu slow roznej dlugosci"<<endl;
    string B[]={"aab","aaaab","ccc","sss","cab","cba","aaaaa","cbacc","pl","zz"};
    print_array(B,n);
    RadixSort_word(B,n);
    print_array(B,n);
    return 0;
}










