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

    return head;

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

void add_node(Node* &l,Node *gogo){
    Node* temp=l;
    if(temp){
        while(temp->next) temp=temp->next;
        temp->next=new Node;
        temp->next = gogo;
        temp->next->next=NULL;
    } else {
        l=new Node;
        l = gogo;
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

void add_node_at_start(Node *&first,Node *new_node){
    new_node->next = first;
    first = new_node;
    first->next = NULL;
}

Node * sortList (Node *first){
    int n = 0;
    Node * guard = first;

    while(first){
       first = first->next;
        n++;
    }
    //cout<<n<<endl;
    first = guard;
    if(n == 0) return NULL;

    double  interval_length = (double)10/n;
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
    add_node_at_start(bucket[((int)(tmp->value*interval_length)/10)],tmp);     ////////
    }

    for(int i=0; i<n;i++) {
        if(bucket[i]!=NULL)
        MergeSort_list(bucket[i]);}
    first = merge_buckets(bucket, n);
    return first;
}

int main(){
    Node *list= NULL;


// Generujemy zawartość tablicy d[] i wyświetlamy ją

    srand((unsigned)time(NULL));
    double value;

    for(int i = 4; i >0; i--){
        value= (double)i/(rand()%100);

        add(list,value);
   }
  //  add_node_at_start(list,4);
   // add_node_at_start(list,9);
    print_l(list);
    sortList(list);
    cout << "Po sortowaniu:\n\n";
   print_l(list);
    cout << endl;
    return 0;
}



//2. Proszę zaimplementować funkcję: int SumBetween(int T[], int from, int to, int n);
// Zadaniem tej funkcji jest obliczyć sumę liczb z n elementowej tablicy T,
// które w posortowanej tablicy znajdywałyby się na pozycjach o indeksach od from do to (włącznie).
// Można przyjąć, że liczby w tablicy T są parami różne (ale nie można przyjmować żadnego innego rozkładu danych).
// Zaimplementowana funkcja powinna być możliwie jak najszybsza. Proszę oszacować jej złożoność czasową
// (oraz bardzo krótko uzasadnić to oszacowanie).


//3. Proszę opisać (bez implementacji!) jak najszybszy algorytm, który otrzymuje na wejściu pewien ciąg n liter
// oraz liczbę k i wypisuje najczęściej powtarzający się podciąg długości k
// (jeśli ciągów mogących stanowić rozwiązanie jest kilka, algorytm zwraca dowolny z nich).
// Można założyć, że ciąg składa się wyłącznie z liter a i b.
// Na przykład dla ciągu ababaaaabb oraz k = 3 rozwiązaniem jest zarówno ciąg aba,
// który powtarza się dwa razy (to, że te wystąpienia na siebie nachodzą nie jest istotne).
// Zaproponowany algorytm opisać, uzasadnić jego poprawność oraz oszacować jego złożoność.
