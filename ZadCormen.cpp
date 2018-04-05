//
// Created by Karolina on 03.04.2018.
//
#include <iostream>
#include <string>
using namespace std;
//1.Podaj lagorytm scalający k posortowanych list gdzie n jest łączną liczba elementów w listach O(nlogk)
//Construct a min heap from the heads of each of the k lists. Then, to find
//the next element in the sorted array, extract the minimum element (in O lg(k)
//time). Then, add to the heap the next element from the shorter list from which
//        the extracted element originally came (also O(lg(k)) time). Since finding the
//        next element in the sorted list takes only at most O(lg(k)) time, to find the
//        whole list, you need O(n lg(k)) total steps.

//korzystamy z funkcji merge
//mergujemy ostatnią listę "j" i pierwszą "i"
//j--,i++
//dokonujemy tych operacji dopóki nie zostanie jedna lista
//mamy n wartości w sumie i k list
//mergowanie dwóch list gdy n1>n2 czyli max rozmiar z dwóch mergowanych
// list gdzie ni to rozmiar każdej z list to log(n1);
//n1+n2+.....ni=n
//i w końcu wyjdzie złożoność nlogk????? bo mergujemy n elementów i k list czyli log(k)
///MOJE rozwiązanie
//bierzemy dwie pierwsze listy, merge na nich i z mergowaną przenosimy na koniec
//kolejne nie zmergowane i znowu na koniec
//i tak dopóki nie zostanie nam jedna



//2.Heap-Delete(A,i) usuwa wartość z węłza i w kopcu A. O(logn) dla n elementowego kopca
//5. Heap Extract_MIN, insert, increse-key, decrease-key,
//6.d-kopce, podaj operacje insert ,extract_max

int parent(int i){return ((i-1)/2);}
int left(int i){return (2*i+1);}
int right(int i){return (2*i+2);}

void print_t(int A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Heapify(int A[],int i,int n){
    int indmax = i;
    if(left(i) < n && A[left(i)] > A[indmax])
        indmax = left(i);
    if(right(i) < n && A[right(i)] > A[indmax])
        indmax = right(i);
    if(i != indmax){
        swap(A[i],A[indmax]);
        Heapify(A,indmax,n);
    }

}
void BuildHeap(int A[], int n){
    for(int i=parent(n-1);i>=0;i--)
        Heapify(A,i,n);
}
void IncreaseKey(int A[], int i, int key, int n){
    if(key<A[i])
        cout<<"New key is smaller than the old one"<<endl;
    A[i]=key;
    while(i>0 && A[parent(i)]<A[i]){
        swap(A[parent(i)],A[i]);
        i=parent(i);
    }
}
//to chyba nie działa
int max_r(int a, int b){
    if(a>b) return a;
    else return b;
}

void DecreaseKey(int A[], int i, int key, int n){
    if(key>A[i])
        cout<<"New key is bigger than the old one"<<endl;
    A[i]=key;
    Heapify(A,i,n);

}
void HeapDelete(int A[], int i, int &n){
    IncreaseKey(A,i,INT8_MAX,n);
    A[0]=A[n-1];
    n--;
    Heapify(A,0,n);
}
void InsertKey(int A[], int key, int &n){
    n++;
    A[n-1]=key;
    int i=n-1;
    while(i>0 && A[parent(i)]<A[i]){
        swap(A[i],A[parent(i)]);
        i=parent(i);
    }
}

void HeapSort(int A[], int n){
    BuildHeap(A,n);
    for (int j = n - 1; j >= 1; j--)
    {
        swap(A[j], A[0]); // wyrzucamy z kopca pierwszy element i naprawiamy resztę (żeby znowu pierwszy element był największy)
        Heapify(A, 0, j); // czyli naprawia od korzenia do (j - 1) elementu
    }
}

void ExtractMin(int A[],int n){

}

//3.Inwersje
//Niech A[n] będzie tablicą zawierającą n różnych liczb, Jesli i<j oraz A[i]>A[j] to para (i,j) jest inwersja w A
//w czasie O(nlogn)
//Policz liczbe inwersji w A.
//kurwa nie działa i nie wiem dlaczego
int merge(int A[], int p, int q,int r){

    int ip=p;
    int ir=q+1;
    int i=0;
    int inv=0;
    int * B=new int[r-p];
    while(ip<=q && ir<=r){
        if(A[ip]<A[ir]){
            B[i]=A[ip];
            ip++;
        }
        else{
            B[i]=A[ir];
            ir++;
            inv+=(q-ip);
        }
        i++;
    }
    if(ip<=q)
        while(ip<=q) B[i++]=A[ip++];
    else
        while(ir<=r)  B[i++]=A[ir++];

    for(i=0;i<=r-p;i++) A[p+i]=B[i];
    return inv;
}
int Merge(int A[],int p,int q,int r){
    int s1=q-p+1;
    int s2=r-q;
    int i,j,k;
    int L[s1+1],R[s2+1];// dodatkowe miejsce dla wartownikow
    L[s1]=INT8_MAX;
    R[s2]=INT8_MAX;
    int inv=0;
    for( i=0; i<s1 ;i++)
        L[i] = A[p + i];
    // print(L,s1);
    for( j=0;j<s2;j++)
        R[j] = A[q + j+1];
    //print(R,s2);
    i=0,j=0;
    for(k=p;k<=r;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            inv+=j;
            j++;
         //   cout<<inv<<endl;
        }
    }
    // print(A,r);
    return inv;
}
int MergeSort(int A[], int p, int r){

    if(p<r){
        int q=(p+r)/2;
        int left=MergeSort(A,p,q);
        int right=MergeSort(A,q+1,r);
        int inv = Merge(A,p,q,r)+left+right;
        return inv;

    }
}
//4. Problem maxymalnej podtablicy 69 strona w Cormenie


//7.Zaprojektuj algorytm, który dla danych n liczb z przedziału od 0 do k, wykonuje wstępne obliczenia a następnie na ich
//podstawie pozwala w czasie O(1) określić, ile spośród danych n liczb leży w przedziale [a...b]
//Counting sort bez kitu :P
//Zł: O(n+k)
void DoyouwantmeBABE(int A[],int n,int k,int a,int b){
    int C[k];
    int B[n];
    for(int i=0;i<k;i++) C[i]=0;
    for(int i=0;i<n;i++) C[A[i]]++;
    for(int i=1;i<k;i++) C[i]+=C[i-1];
    cout<<C[b]-C[a-1]<<endl;

}
//8. Skonsturłuj algo, który pozwala posortować n liczb całkowitych z przedziału 0 do n^3-1 w czasie O(n)
//First run through the list of integers and convert each one to base n, then
//        radix sort them. Each number will have at most logn(n^3) = 3 digits so there
//        will only need to be 3 passes. For each pass, there are n possible values which
//can be taken on, so we can use counting sort to sort each digit in O(n) time.
//8.4-4
void CountingSort(int A[],int n,int exp){
    int C[n];
    int B[n];
    for(int i=0;i<n;i++) C[i]=0;
    for(int i=0;i<n;i++) C[(A[i]/exp)%n]++;
    for(int i=1;i<n;i++) C[i]+=C[i-1];
    for(int i=n-1;i>=0;i--){
        B[C[(A[i]/exp)%n]-1]=A[i];
        C[(A[i]/exp)%n]--;
    }
    for(int i=0;i<n;i++)
        A[i]=B[i];
}
void RadixSort(int A[],int n){
    for(int i=1;i<n*n*n;i*=n)
        CountingSort(A,n,i);
}
//że niby logn(n^3)=3 i dlatego wywołujemy tak ale tego nie czaje
//bo niby mogą być tylko 3 cyfrowe max
void print(int A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n = 8;
//    int A[n] = { 6, 8, 3, 5, 9, 2, -1, 0 };
//    cout<<"Przed HeapSortem"<<endl;
//    print_t(A,n);
//    HeapSort(A, n);//nie wiem czemu nie działa jak nalezy
//    cout<<"Po HeapSort"<<endl;
//    print_t(A,n);
//    cout<<"Zamiana wartości"<<endl;
//    IncreaseKey(A,4,7,n);
//    print_t(A,n);
////    cout<<"Usuwanie wartości"<<endl;
////    HeapDelete(A,0,n);
////    print_t(A,n);
////    cout<<"Dodawanie wartości"<<endl;
////    InsertKey(A,-1,n);
//    BuildHeap(A,n);
//    print_t(A,n);
//
//    cout<<"Degradowanie wartości"<<endl;
//    DecreaseKey(A,0,-2,n);
//    print_t(A,n);

//    int arr[] = {1, 20, 6, 4, 5};
//    print(arr,5);
//    cout<<"MA WYJŚĆ 5 PODOBNO"<<endl;
//    cout<<MergeSort(arr,0,4)<<endl;
//    print(arr,5);
//
    n=100;
    int G[n]={9999,22,99,889,1999,45,12,999,689,9};
    for(int i=10;i<n;i++) G[i]=0;
    cout<<"Wersja dla ciągów różniej długości: liczby"<<endl;
    print(G,n);
    RadixSort(G,n);
    print(G,n);
//    DoyouwantmeBABE(G,n,1000,0,999);
}
//7,1-4
