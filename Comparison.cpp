#include<iostream>
#include<fstream>
#include <cstdlib>
#include<time.h>
using namespace std;


//QUICKSORT
int Partition2(int A[], int p, int r) // p - pocz�tek przedzia�u, r = koniec
{
    int x = A[r]; // x to ostatni element
    int i = p - 1; // i ustawiamy przed przedzia�em
    int j;
    for (j = p; j < r; j++) {
        if (A[j] <= x) // elementy mniejsze od x s� przek�adane na pocz�tek
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
        QuickSort(t,p,q-1);
        QuickSort(t,q+1,r);
    }
}


//RADIX SORT
void Counting_Sort_R(int A[], int n, int exp)
{
    int k=10;
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

int max_number(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}

void RadixSort_C2(int A[],int n){
    int m=max_number(A,n);
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

    srand(time(0));
    fstream plik( "dane.txt", ios::out );
    if( plik.good() )
    {
        for( int i = 1; i <= N; i++ )
        {
            plik << rand() % 10000000 + 1000000<<" ";
            plik.flush();
        }
        plik.close();
    }

}

void data_to_table(int N,int *T){
    ifstream plik("dane.txt");
    if(plik)
        for(int j = 0; j < N; j++)
            plik >> T[j];


    else  cout << "Chujowy masz plik Moja Droga." << endl;
}


bool compare(double quick, double radix){
    if(radix > quick) return true;
    return false;
}

int iterations(int N){

    time_t startQuick, koniecQuick, startRadix, koniecRadix;
    double roznicaQuick = 0, roznicaRadix = 0;


    while(!compare(roznicaQuick, roznicaRadix)){
        cout<<"Hai";
        generate_data(N);
        int *T = new int [N];
        int *G = new int [N];
        data_to_table(N,T);
        G = T;

        time( & startQuick);
        QuickSort(T,0,N);
        time( & koniecQuick);

        roznicaQuick = difftime(koniecQuick, startQuick);

        time( & startRadix);
        RadixSort_C2(G,N);
        time( & koniecRadix);

        roznicaRadix = difftime(koniecRadix, startRadix);

        N+=1000;

    }

    return N;
}


int main()
{

    int N=1000;

    int x = iterations(N);
    cout<<endl;
    cout<<x<<endl;

    return 0;
}
