//
// Created by Karolina on 01.04.2018.
//
#include <iostream>
#include <string>
using namespace std;
//2014/15
//1. Napisać funkcję: void sortString(string A[]); Funkcja sortuje tablicę n stringów różnej długości.
//Można założyć, że stringi składają się wyłącznie z małych liter alfabetu łacińskiego.
//
void CountingSort(string A[],int n,int k,int exp){
    int C[k];B[n];
    for(int i=0;i<k;i++) C[i] = 0;
    for(int i=n;i<n;i++) C[(int)A[i][exp]]++;
    for(int i=1;i<n;i++) C[i]+=C[i-1];
    for(int i=n-1;i>=0;i--){
        B[C[(int)A[i][exp]] - 1] = A[i];
        C[(int)A[i][exp]]--;
    }
}


//2. Dane są następujące struktury:
//struct Node {
//    Node* next;
//    int val;
//};
//struct TwoLists {
//    Node* even;
//    Node* odd;
//};
//Napisać funkcję: TwoLists split(Node* list);
//Funkcja rozdziela listę na dwie: jedną zawierającą liczby parzyste i drugą zawierającą liczby nieparzyste.
//Listy nie zawierają wartowników.
//
//3. Jak posortować n-elementową tablicę liczb rzeczywistych, które przyjmują tylko log n różnych wartości?
//Uzasadnić poprawność algorytmu i oszacować złożoność. (Nie trzeba implementować).
//create a mapping of how many distinct items are there in the list, and keep the count of each
//(basically a dictionary/hashmap of key, count)
//This is a single iteration over the input list, so O(n) steps.

//Sort the above list of tuples of size log(n) based on their key.
//Say we use merge sort, then the time complexity of merge sort is k*log(k), where k is size of the input.
//Replacing k with log(n), we get complexity of this step as O(log(n)*log(log(n))).

//Since in terms of complexity, O(log(n)*log(log(n))) < O(n), so overall complexity till
//this step is O(n) + O(log(n)*log(log(n))), which is equivalent to O(n) again.

//Iterate over the sorted keys, and generate the sorted list using a single for loop,
//where in each value is repeated by its count. There will be max O(n) iterations here.
//So overall, the algorithm above will run in O(n) time.