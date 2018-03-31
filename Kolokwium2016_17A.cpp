//
// Created by Karolina on 31.03.2018.
//
#include <iostream>
#include <string>
using namespace std;

//1. Dana jestr struktura opisująca listę jednokierunkową dla liczb rzeczywistych: struct Node{ Node* next; double value; }
//        Proszę zaimplementować funkcję void Sort( Node* list ),
//        która otrzymuje na wejściu listę liczb rzeczywistych (z wartownikiem),
//        wygenerowaną zgodnie z rozkładem jednostajnym na przedziale [0,10) i sortuje jej zawartość w kolejności niemalejącej.
//Funkcja powinna być możliwie jak najszybsza (biorąc pod uwagę warunki zadania). Proszę oszacować złożoność zaimplementowanej funkcji.


struct Node{
    double value;
    Node * next;
};
void insertionSort(Node *&first) {

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
//scalanie kubełków, dołączamy niepusty kubełek i przesuwamy się na jego koniec;
Node *merge_buckets(Node **bucket, int n){
    Node * result = new Node, *guard;
    guard = result;
    for(int i=0; i<n; i++){
        if(bucket[i]){
            result->next = bucket[i];
            while(result->next) result = result ->next;
        }
    }
    return guard->next;
}

void add_Node_at_start(Node *&first,Node *new_Node){
    new_Node->next = first;
    first = new_Node;

}

Node * sortList (Node *first){
    int n = 0;
    Node * guard = first;

    while(first){
       first = first->next;
        n++;
    }
    first = guard;
    if(n == 0) return NULL;

    Node ** bucket = new Node *[n];
    for(int i=0; i<n; i++){
        bucket[i] = new Node;
        bucket[i] = NULL;
    }
    Node * tmp = NULL;
    while(first){
        tmp = first;
        first = first->next;
        tmp->next = NULL;
    add_Node_at_start(bucket[((int)(tmp->value*n)/10)],tmp);     ////////
    }

    for(int i=0; i<n;i++) insertionSort(bucket[i]);

    first = merge_buckets(bucket, n);
    return first;
}

//2. Proszę zaimplementować funkcję: int SumBetween(int T[], int from, int to, int n);
// Zadaniem tej funkcji jest obliczyć sumę liczb z n elementowej tablicy T,
// które w posortowanej tablicy znajdywałyby się na pozycjach o indeksach od from do to (włącznie).
// Można przyjąć, że liczby w tablicy T są parami różne (ale nie można przyjmować żadnego innego rozkładu danych).
// Zaimplementowana funkcja powinna być możliwie jak najszybsza. Proszę oszacować jej złożoność czasową
// (oraz bardzo krótko uzasadnić to oszacowanie).

int Partition( int A[], int p, int r){
    int i,j;
    int x=A[r];
    i=p-1;
    for(j=p; j<r ;j++){
        if(A[j]<=x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[r],A[i+1]);
    return i+1;
}

int select(int A[], int p, int r, int k){
    if(p == r) return p;
    int q=Partition(A,p,r);
    int tmp = q-p+1;
    if(tmp == k) return q;
    if(k < tmp) return select(A,p,q-1,k);
    else return select(A,q+1,r,k-tmp);
}
int SumBetween(int T[], int from, int to, int n){
    int p = select(T,0,n-1,from);
    cout<<p<<endl;
    int k = select(T,0,n-1,to);
    cout<<p<<" "<< k<<endl;
    int sum = 0;
    for(int i=p; i<=k ;i++)
        sum += T[i];

    return sum;

}
int main(){
    //zadanie numer 1
    cout<<"BucketSort"<<endl;
    Node *list= NULL;
    srand((unsigned)time(NULL));
    double value;
    for(int i = 10; i >0; i--){
        value= (double)(rand()%10);

        add(list,value);
    }
    print_l(list);
    sortList(list);
    cout << "Po posortowaniu:\n\n";
    print_l(list);
    cout << endl;
    //Zadanie numer 2
     cout<<"Suma pomiędzy kolejnymi wartosciami w tablicy"<<endl;
    int T1[10]={10, 7, 6, 15,7,0,20,50,1,2};
    //cout<<select(T1,0,3,1);
    cout<<SumBetween(T1,3,4,10);
    return 0;
}


//3. Proszę opisać (bez implementacji!) jak najszybszy algorytm, który otrzymuje na wejściu pewien ciąg n liter
// oraz liczbę k i wypisuje najczęściej powtarzający się podciąg długości k
// (jeśli ciągów mogących stanowić rozwiązanie jest kilka, algorytm zwraca dowolny z nich).
// Można założyć, że ciąg składa się wyłącznie z liter a i b.
// Na przykład dla ciągu ababaaaabb oraz k = 3 rozwiązaniem jest zarówno ciąg aba,
// który powtarza się dwa razy (to, że te wystąpienia na siebie nachodzą nie jest istotne).
// Zaproponowany algorytm opisać, uzasadnić jego poprawność oraz oszacować jego złożoność.

//Rozwiazanie:
//1) Dzielimy podany ciag wejsciowy na n-k+1 slow k-elementowych, np. dla ciagu wejsciowego ababaaaabb i k=3 dokonujemy
//        nastepujacego podzialu:
//- aba
//- bab
//- aba
//- baa
//- aaa
//- aaa
//- aab
//- abb
//        Zlozonosc tej operacji to (n-k+1)*k, czyli O(n*k).
//2) Uzyskane w ten sposob k-elementowe podciagi sortujemy radixSortem przechodzac od litery najbardziej na prawo
//do litery najbardziej na lewo. Jako, ze ciagi moga sie skladac wylacznie z liter a i b do sortowania kazdej
//z kolumn uzywamy countingSorta, ktory zlozonosc w tym wypadku wyniesie n-k+1, czyli O(n). Poniewaz do posortowania
//        mamy k kolumn, to sortujac je radixSortem, ktory wykorzystuje countingSorta uzyskamy zlozonosc (n-k+1)*k, czyli
//        O(n*k).
//3) Przegladamy wartosci posortowanej listy podciagow zapamietujac przy tym ciag, ktory powtorzyl sie dotychczas
//najwiecej razy i zapamietujemy takze ilosc jego potworzen. Zlozonosc tej operacji po przegladnieciu calej
//listy/tablicy, w ktorej przechowujemy k-elementowe podciagi wyniesie (n-k+1)*k (bo przegladam kazda z k liter
//        podciagow, ktorych jest n-k+1), czyli bedzie rzedu O(n*k).
//4) Zatem ostateczna zlozonosc przedstawionego algorytmu, to O(n) + O(n*k) + O(n*k), czyli O(n*k).