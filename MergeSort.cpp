//
// Created by Karolina on 07.03.2018.
//

//Procedura merge scalania dwoch posortowanych list
//merge dziala w czasie O(n) gdzie n=r-p+1 jest liczba scalonych elementow
#include <iostream>
//#include <string>
using namespace std;

void print(int A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
//wersja z cormena
void Merge(int A[],int p,int q,int r){
    int s1=q-p+1;
    int s2=r-q;
    int i,j,k;
    int L[s1+1],R[s2+1];// dodatkowe miejsce dla wartownikow
    L[s1]=INT8_MAX;
    R[s2]=INT8_MAX;
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
            j++;
        }
    }
    // print(A,r);
}

void MergeSort(int A[], int p, int r){
    int q;
    if(p<r){
        q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

//nie dziala do konca jak powinna, nie sortuje ostatniej liczby z tablicy
void MergeSort_it(int A[], int n)
{
    int l; // it - początek przedziału aktualnie sortowanego
    int i;
    for (i = 1; i < n ; i *= 2) // i - długość przedziału aktualnie sortowanego
    {
        for(l=0;l<n-1;l+=2*i){
            int q=l+i-1;
            int p=min(l+2*i-1,n-1);
            Merge(A,l,q,p);
        }
    }
}


struct Node{
    int value;
    Node *next;
};



void print_l(Node* l){
    while(l){
        cout << l->value << " ";
        l=l->next;
    }
    cout << endl;
}
Node *mergeTwoLists(Node* &l1, Node* &l2) {
    Node *head = new Node;
    Node *p = head;

    Node *p1=l1;
    Node *p2=l2;
    while(p1!=NULL && p2!=NULL){
        if(p1->value < p2->value){
            p->next = p1;
            p1 = p1->next;
        }else{
            p->next = p2;
            p2 = p2->next;
        }
        p=p->next;
    }

    if(p1!=NULL){ //wersja bez wartownika, bo tutaj sie nie da
        p->next = p1;
    }

    if(p2!=NULL){
        p->next = p2;
    }

    return head; //head->next , przetestuj później

}

Node *mergeTwoLists2(Node * &p,Node* &l1, Node* &l2) {
    Node *head = new Node;
    p = head;

    Node *p1=l1;
    Node *p2=l2;
    while(p1!=NULL && p2!=NULL){
        if(p1->value < p2->value){
            p->next = p1;
            p1 = p1->next;
        }else{
            p->next = p2;
            p2 = p2->next;
        }
        p=p->next;

    }

    if(p1!=NULL){ //wersja bez wartownika, bo tutaj sie nie da
        p->next = p1;
    }
    if(p2!=NULL){
        p->next = p2;
    }
    while(p->next!=NULL) p=p->next; //aby móc zwrócić koniec listy, bo jeżeli przepinamy końcówkę jednej listy to nie przechodzimy wskaźnikiem do końca
    return head->next;
}


int length(Node * &list){

    int licznik=0;
    Node * tmp=list;

    while(tmp!=NULL){
        licznik++;
        tmp=tmp->next;
    }
    return licznik;
}




    Node * MergeSort_list(Node * &list){ //dzielmy liste na dwie czesci i korzystamy z merge

        Node * list1=list;
        int q = length(list1) / 2 ;

        if (list->next == NULL)
            return list;        // gdy jest tylko jeden element nie ma czego sortować

        while (q - 1 > 0) {
            list1 = list1->next;
            q--;
        }

        Node *list2 = list1->next; //przypisujemy tak jakby druga czesc naszej listy
        list1->next = NULL;
        list1 = list;

        Node *l1 = MergeSort_list(list1);
        Node *l2 = MergeSort_list(list2);
        return mergeTwoLists(l1, l2);

}



void add(Node* &l,int value){
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




int main(){
    int n=10;
    int A[n]={1,4,6,8,19,18,11,15,0,9};
    int A1[n]={1,4,6,4,19,55,11,12,0,90};
    cout<<"Tablica przed sortowaniem"<<endl;
    print(A,n);
    cout<<"Sortowanie rek tab A i A1"<<endl;
    MergeSort(A,0,n-1);
    print(A,n);
    MergeSort(A1,0,n-1);
    print(A1,n);
    cout<<"Sortowanie _it tab A i A1"<<endl;
    MergeSort_it(A,n-1);
    print(A,n);
    MergeSort_it(A1,n-1);
    print(A1,n);


    Node *list1=NULL;
    Node *list2=NULL;
    for(int i=0;i<4;i++) {
        add(list1, i+1);
        add(list2, (i+1)*2);
    }
    Node * list = new Node;
     cout<<"Laczenie dwóch posortowanych list"<<endl;
    print_l(list1);
    print_l(list2);
    mergeTwoLists(list1,list2);
    print_l(list1);
    cout<<"Laczenie dwóch posortowanych list2"<<endl;
    Node *list3=NULL;
    Node *list4=NULL;
    for(int i=0;i<4;i++) {
        add(list3, i+1);
        add(list4, (i+1)*2);
    }
    print_l(list3);
    print_l(list4);
    cout<<mergeTwoLists2(list,list3,list4)->value<<endl;
    cout<<list->value<<endl;
    print_l(list3);
    Node *list5=new Node();
    srand(time(0));
    for(int i=0;i<10;i++)
        add(list5,rand()% 10 + 10 );
    print_l(list5);
    MergeSort_list(list5);
    print_l(list5);
    return 0;
}
