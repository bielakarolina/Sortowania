//
// Created by Karolina on 02.04.2018.
//

#include <iostream>
#include <string>
using namespace std;
//Zadanie 1. Dana jest struktura opisująca listę jednokierunkową przechowującą liczby typu double:
//struct Node { Node* next; double value; };
//Proszę zaimlementować funkcję Node* sortList( Node* L ), która sortuje listę wejściową w kolejności nierosnącej
//        i zwraca wskaźnik na element, który po posortowaniu został głową tej listy (wejściowa lista nie ma wartownika).
//Funkcja powinna być możliwie jak najszybsza (wiadomo, że liczby w wejściowej liście zostały wygenerowane zgodnie z
//rozkładem jednostajnym na przedziale (0,4)).

struct Node {
    Node* next;
    double value;
};

void insSort(Node * &first){
    if (first == NULL || first->next == NULL) return;

    Node *last = first, *curr = first->next;
    Node *p, *prev;

    while (curr != NULL) {
        p = first, prev = NULL;
        while (p != NULL && p != curr && p->value < curr->value) {
            prev = p;
            p = p->next;
        }

        if (p == curr) {
            last = curr;
        } else if (p == first) {
            last->next = curr->next;
            curr->next = first;
            first = curr;
        } else {
            last->next = curr->next;
            prev->next = curr;
            curr->next = p;
        }

        curr = last->next;
    }
}
Node *mergebuckets(Node **bucket, int n){
    Node * result=new Node;
    Node * guard = result;
    for(int i=0;i<n;i++){
        if(bucket[i]){
            result->next=bucket[i];
            while(result->next) result=result->next;
        }
    }
    return guard;
}

void add(Node* &l,double value){
    Node* temp=l;
    if(temp){
        while(temp->next) temp=temp->next;
        temp->next=new Node;
        temp->next->value=value;
        temp->next->next=NULL;
    } else {
        l=new Node;
        l->value=value;
        l->next=NULL;
    }
}

void print_l(Node* list){
    Node * l= list;
    while(l){
        cout << l->value << " ";
        l=l->next;
    }
    cout << endl;
}
void add_Node_at_start(Node *&first,Node *new_Node){
    new_Node->next = first;
    first = new_Node;

}
Node* sortList( Node* L ){
    Node * first;
    first = L;
    int n=0;
    while(first){
        first=first->next;
        n++;
    }

    first=L;
    if(n==0) return NULL;
    Node ** bucket = new Node *[n];
    for(int i =0;i<n;i++){
        bucket[i]=new Node;
        bucket[i]=NULL;
    }
    Node * tmp=new Node;
    //print_l(first);

    while(first){
        print_l(first);
        tmp = first;
        first=first->next;
        tmp->next=NULL;

        add_Node_at_start(bucket[((int)(tmp->value*n)/10)],tmp);
        //print_l(first);
    }
    for(int i=0;i<n;i++) {
      //  print_l(bucket[i]);
        insSort(bucket[i]);
    }
    first=mergebuckets(bucket,n);
    return first;
}



//Dany jest ciąg [a1..b1],....,[an,bn] przedziałów domkniętych. Proszę zaimplementować funkcję:
//int largestIntersection(double a[],double b[],int n);
//która zwraca największą liczbę przedziałów, które mają nie puste przecięcie.Np dla przedziałów
//[1,10],[6,12],[2,5],[9,11] odp to 3 ponieważ [9,10] .Proszę także opisać alg w kilku zdaniach
//i podać złoż czasowa.
//tworzymy strukture w tórej będziemy zapamiętywać
int largestIntersection(double a[],double b[],int n){

}
int main() {
    //zadanie numer 1
    cout << "BucketSort" << endl;
    Node *list = NULL;
    srand((unsigned) time(NULL));
    double value;
    for (int i = 15; i > 0; i--) {
        value = (double) (rand() % 40)/10;

        add(list, value);
    }
    print_l(list);
    sortList(list);
    cout << "Po posortowaniu:\n\n";
    print_l(list);
    cout << endl;
}