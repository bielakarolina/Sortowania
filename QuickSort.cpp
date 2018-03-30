//
// Created by Karolina on 13.03.2018.
//
#include <iostream>
#include <stack>
using namespace std;

const int n =10;
struct Node{
    Node * next;
    int val;
};

void add1(Node* &l,int value){
    Node* temp=l;
    if(temp){
        while(temp->next) temp=temp->next;
        temp->next=new Node;
        temp->next->val=value;
        temp->next->next=NULL;
    } else {
        l=new Node;
        l->val=value;
        l->next=NULL;
    }
}

void print(Node* p){
    Node* l=p;
    while(l){
        cout << l->val<< " ";
        l=l->next;
    }
    cout << endl;
}
int Partition(int A[], int p, int r) // p - początek przedziału, r = koniec
{
    int i=p;
    int j=r;
    int pivot=A[p];
    while(1)
    {
        while(A[i]<pivot) i++;
        while(A[j>pivot]) j--;
        if(i<j)
        {
            swap(A[i],A[j]);
            i++;
            j--;
        }
        else return j;
    }
}

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
        cout<<q<<endl;
        QuickSort(t,p,q-1); // lub dla odpowiedniego partition QuickSort(t,p,q-1)
        QuickSort(t,q+1,r);
    }

}


//QuickSort dla O(logn) pamieci
/*
Pomys³ polega na pozbyciu siê jednej rekurencji
dzielimy zbior na dwa kawalki i bierzemy ten mniejszy
pamiec sie bierze z rekurencji, petla nie zuzywa wiecej pamieci

*/


void QuickSort_member(int t[], int p, int r)
{
    while(p<r)
    {
        int q=Partition2(t,p,r);
        if(q-p+1<r-q)
        {
            QuickSort_member(t,p,r);
            p=q+1;
        }
        else
        {
            QuickSort_member(t,q+1,r);
            r=q-1;
        }
    }

}


//Metoda Hara jest szybsza w dzia³aniu



// QuickSort na liscie jednokierunkowej
Node *partition_list(Node *&p)
{

    if(p==NULL) return 0;
    Node *q=NULL;
    Node *r=NULL;       //q- mniejsza lista (prawa)
    Node *t=p;          //p - wiêksza lista (lewa)
    int value =p->val;   //pivot
    // print(t);
    //cout<<t->val<<"  ";
    while(p!=NULL)
    {

        if(t->val>=value)
        {
            t->next=q;
            q=t;
            t=p;
        }
        else
        {
            t->next=r;
            r=t;
            t=p;
        }
        p=q;
        p=p->next;
    }
    return r;   // to chyba nie powinno byæ w pêtli

}
//nie działa
void QuickSort_list(Node *&lol)
{
    Node *q;
    Node* head=new Node;
    head =lol;
    //cout<<" ble"<< " "<<endl;
    if(lol!=NULL)
    {
        q=partition_list(head);
        QuickSort_list(head);
        QuickSort_list(q);
        Node * t= q;
        if(t==NULL) return ;
        while(t->next!=NULL)
            t=t->next;
        t->next=head;
        head=q;
    }
 //   print(head->next);
    lol=head;
}




// dopisac Quicksort na stosie - QS bez rekurencji O(logn) pamieci

void QuickSort_stos(int t[n],int p, int l) // kod z notatek Agaty
{
    stack <int> stos;
   // stos.init();
    stos.push(p);
    stos.push(l);
    int q;
    while(!stos.empty())
    {
        l=stos.top();   //wywala dziwny blad, prawdopodobnie zła biblioteka, sprawdzałam kod z innej grupy, jest taki sam
        stos.pop();
        p=stos.top();
        stos.pop();

        q=Partition2(t,p,l);
        cout<<q<<endl;
        if(p<q-1)
        {
            stos.push(p);
            stos.push(q-1);
        }
        if(q+1<l)
        {
            stos.push(q+1);
            stos.push(l);
        }
    }
}


//uzywam funkcji select ktora pod kazda postacja nie dziala
// lopatologicznie szukam od from do to wielkosci i je sumuje
// nie wiem jak inaczej to zrobic niestety bo funkcja select nie dziala i nie wiem jak powinna dzialac


//DZIAŁAJĄCY SELECT
int select1(int * A, int p, int r, int k) {
    if(p == r)
        return A[p];
    int q = Partition2(A, p, r);	// index podzialu
//moja tablica ma rozmiar 4
  //  for(int i=0;i<4;i++)
    //    cout<<A[i]<<" ";
    //cout<<endl;
    int tmp = q - p + 1;	// liczba elementow w lewej podtablicy
    if(k==tmp) return A[q];
    else if(k<tmp) return select1(A,p,q-1,k);
    else return select1(A,q+1,r,k-tmp);

}

int SumBetween(int T[n], int from, int to,int n){

    int k=select1(T,0,n-1,from);
    int l=select1(T,0,n-1,to);
    cout<<k<<" "<<l<<endl;
    int sum=0;
    for(int i=from;i<to;i++)
        sum+=T[i];
    return sum;


}

void print_t(int A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main()
{
//    srand(time(0));
//    Node *list=NULL;
//
////    for(int i=0;i<10;i++)
////        add1(list,rand() /( double ) RAND_MAX *( 10 ));
////    print(list);
////    QuickSort_list(list);
////    print(list);
//  cout<<"Sortowanie tablicy QuickSort - stos"<<endl;
//    int n=10;
//  int T[n]={5, 10, 0, 20, 15, 35, 25, 30, 46, 1};
//    print_t(T,n);
//    QuickSort_stos(T,0,n-1);
//    print_t(T,n);



    //cout<<"Sortowanie tablicy QuickSort:"<<endl;
 //   int T1[4]={10, 7, 6, 15};
//    print_t(T1,4);
//    QuickSort_stos(T1,0,3);
    cout<< "1 element"<<endl;
    int T1[4]={10, 7, 6, 15};
    print_t(T1,4);
    int k=select1(T1,0,3,1);
    cout<<k<<endl;
    cout<< "2 element"<<endl;
    int T2[4]={10, 7, 6, 15};
    //print_t(T2,4);
    k=select1(T2,0,3,2);
    cout<<k<<endl;
    cout<< "3 element"<<endl;
    int T3[4]={10, 7, 6, 15};
    //print_t(T3,4);
    k=select1(T3,0,3,3);
    cout<<k<<endl;
    cout<< "4 element"<<endl;
    int T4[4]={10, 7, 6, 15};
    //print_t(T4,4);
    k=select1(T2,0,3,4);
    cout<<k<<endl;



    // cout<<"Sortowanie tablicy suma pomiędzy indeksami w tablicy"<<endl;
  //  cout<<SumBetween(T1,0,3,10);


    return 0;
}