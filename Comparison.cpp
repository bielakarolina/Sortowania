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
            plik << rand() % 5000  + 1;
            plik.flush();
        }
        plik.close();
    }

}

void open_file(){
    ifstream plik("dane.txt");

    if(plik)
    {
        // Uda³o siê otworzyæ plik, a wiêc mo¿na rozpocz¹æ odczytywanie

        string linia;     // Zmienna do przechowywania odczytanych wierszy tekstu

        while(getline(plik, linia))    // Jeli jeszcze nie nast¹pi³ koniec pliku, czytamy dalej
        {

            cout << linia << endl; // Wywietlamy odczytany tekst w konsoli
            // Mo¿na te¿ zrobiæ z nim co innego
        }
    }
    else
    {
        cout << "B£¥D: nie mo¿na otworzyæ pliku do odczytu." << endl;
    }

}

int main()
{



    generate_data(1000);
    open_file();
    cout<<"Sortowanie tablicy QuickSort"<<endl;
    int n=10;
    int T[n]={5, 10, 0, 20, 15, 35, 25, 30, 46, 1};
    print_t(T,n);
    QuickSort(T,0,n);
    print_t(T,n);
    return 0;
}
