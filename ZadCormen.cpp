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

//2.Heap-Delete(A,i) usuwa wartość z węłza i w kopcu A. O(logn) dla n elementowego kopca


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

//5. Heap Extract_MIN, insert, increse-key, decrease-key,
//6.d-kopce, podaj operacje insert ,extract_max

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
    cout<<C[b]-C[a]<<endl;

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
    for(int i=1;i<1000;i*=10)
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
    int arr[] = {1, 20, 6, 4, 5};
    print(arr,5);
    cout<<"MA WYJŚĆ 5 PODOBNO"<<endl;
    cout<<MergeSort(arr,0,4)<<endl;
    print(arr,5);

    int n=10;
    int G[n]={11,22,212,889,12,45,12,33,689,11};

    cout<<"Wersja dla ciągów różniej długości: liczby"<<endl;
    print(G,n);
    RadixSort(G,n);
    print(G,n);
    DoyouwantmeBABE(G,n,1000,0,999);
}
//7,1-4
