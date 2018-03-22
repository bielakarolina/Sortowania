//
// Created by root on 21.03.18.
//


#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

const int n =10;



int Partition2(int A[], int p, int r) // p - początek przedziału, r = koniec
{
    int x = A[r]; // x to ostatni element
    int i = p - 1; // i ustawiamy przed przedziałem
    int j;
    for (j = p; j < r; j++) {
        if (A[j] <= x) // elementy mniejsze od x są przekładane na początek
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[r], A[i + 1]);
    return i + 1;
}


void QuickSort(int t[], int p, int r)
{
    if(p<r)
    {
        int q=Partition2(t,p,r);
        QuickSort(t,p,q-1); // lub dla odpowiedniego partition QuickSort(t,p,q-1)
        QuickSort(t,q+1,r);
    }

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

long int potega(long int podstawa, int wykladnik)
{
    int wynik = 1;

    for (int i = 0; i<wykladnik; i++)
        wynik*=podstawa;

    return wynik;
}

void RadixSort_C2(int A[],int p){  //  l*O(k+n)=O(l*(k+n)) po pierwsze tak jest w cormenie l-ilosc cyfr k-zakres n-rozmiar tablicy
    int m=max_number(A,p);
    //zakres w tym przypadku to najwieksza liczba
    for (int i = 1; m/i>0; i*=10)
        Counting_Sort_R(A, n,i);
}

void print_t(int A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void generate_data(int N){
    //N ilość danych ktore będziemy generować

    srand(time(0));
    fstream plik( "dane.txt", ios::out );
    if( plik.good() )
    {
        for( int i = 1; i <= N; i++ )
        {
            plik << rand() % 5000  + 1<<" ";
            plik.flush();
        }
        plik.close();
    }

}

void data_to_table(int N,int *T, int *G){
    ifstream plik("dane.txt");


    if(plik){

        for(int j = 0; j < N; j++) {
            plik >> T[j];
            plik >> G[j];
        }

    }
    else
    {
        cout << "Chujowy masz plik Moja Droga." << endl;
    }

}

int main()
{


    int N=1000; //rozmiar danych
    generate_data(N);
    int *T = new int [N];
    int *G = new int [N];
    data_to_table(N,T,G);
    cout<<"Sortowanie tablicy QuickSort"<<endl;
    int n=10;
   // int T[n]={5, 10, 0, 20, 15, 35, 25, 30, 46, 1};
    print_t(T,n);
    QuickSort(T,0,n);
    print_t(T,n);

    print_t(G,n);
    RadixSort_C2(G,n);
    print_t(G,n);
    return 0;
}
