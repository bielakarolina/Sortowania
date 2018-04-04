////
//// Created by Karolina on 01.04.2018.
////
//
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//1. Proszę zaimplementować funkcję sortującą (rosnąco) listę jednokierunkową metodą QuickerSort.
//Algorytm QuickerSort to odmiana algorytmu QuickSort, w której funkcja podziału dzieli sortowane
//        dane według przyjętej wartości x na trzy grupy: mniejsze od x, równe x, oraz większe od x.
//Następnie rekurencyjnie sortowane są grupy pierwsza i trzecia. Państwa funkcja powinna mieć następujący prototyp:
//
//struct Node { Node* next; int val; }; Node* QuickerSort ( Node* head )
//Argumentem funkcji jest wskaźnik na głowę listy do posortowania a wynikiem powinien być wskaźnik na głowę
//listy posortowanej. Sortowanie powinno polegać na porównywaniu wartości val list oraz przepinaniu wskaźników next.
struct Node {
    Node* next;
    int val;
};
void addNode(Node* h, int val){
    Node* tmp = new Node;
    tmp->next = h->next;
    tmp->val = val;
    h->next = tmp;
}

//Dla listy z straznikiem
Node* buildList(int i, int range){
    Node* head = new Node;
    head->next = NULL;
    srand(time(NULL));
    for(i; i >= 0; i--){
        addNode(head, rand()%range);
    }
    return head;
}

void print(Node* head){
    while(head->next != NULL){
        printf("%d ", head->next->val);
        head = head->next;
    }
    cout<<endl;
}

Node* QuickerSort ( Node* head ){
    if(head==NULL) return head;
    Node * lesser,* equal,* greater, *l,*e,*g, *ret, *retTail;
    lesser=new Node;
    equal=new Node;
    greater=new Node;
    lesser->next=NULL;
    equal->next=NULL;
    greater->next = NULL;
    l=lesser;
    e=equal;
    g=greater;
    int c=head->val;
    while(head != NULL){
        if(head->val == c){
            e->next = head;
            head = head->next;
            e = e->next;
            e->next = NULL;
        }
        else{
            if(head->val < c){
                l->next = head;
                head = head->next;
                l = l->next;
                l->next = NULL;
            }
            else{
                g->next = head;
                head = head->next;
                g = g->next;
                g->next = NULL;
            }
        }
    }

    lesser->next =QuickerSort(lesser->next);
    greater->next = QuickerSort(greater->next);
    ret = new Node;
    ret->next = NULL;
    retTail = ret;

    ret->next = lesser->next;
    while(retTail->next != NULL){
        retTail = retTail->next;
    }

    retTail->next = equal->next;
    while(retTail->next != NULL){
        retTail = retTail->next;
    }

    retTail->next = greater->next;

    retTail = ret->next;
    return retTail;
}


//2. Proszę zaprojektowac strukturę danych przechowującą liczby i pozwalającą na następujące operacje
//(zakładamy, że wszystkie liczby umieszczane w strukturze są różne): Init(n).
//Tworzy zadaną strukturę danych zdolną pomieścić maksymalnie n liczb. Insert(x).
//Dodaje do struktury liczbę x. RemoveMin() Znajduje najmniejszą liczbę w strukturze, usuwa ją i zwraca jej wartość.
//RemoveMax() Znajduje największą liczbę w strukturze, usuwa ją i zwraca jej wartość. Każda z operacji powinna mieć
//        złożoność O(log n, gdzie n to ilość liczb znajdujących się obecnie w strukturze. W tym zadaniu nie trzeba
//        implementować podanych operacji, a jedynie przekonująco opisać jak powinny być zrealizowane i dlaczego mają
//wymaganą złożoność.
// ta struktura byłaby podobna do drzewa binarnego, którego wysokość wynosi logn
//dlatego inicializowanie drzewa, operacja insert będą wynosiły logn
//jeżelu będziemy chcieli odnaleść max lub min ,przejdziemy do najbardziej na prawo, najdalszego prawego syna,lub lewo..,
//czyli do max wysokości drzewa czyli logn+ naprawa drzewa logn

//3. Proszę napisać funkcję bool possible( char* u, char* v, char* w ), która zwraca prawdę jeśli z liter słów u i v
//        da się ułożyć słowo w (nie jest konieczne wykorzystanie wszystkich liter) oraz fałsz w przeciwnym wypadku.
//Można założyć, że w i v składają się wyłącznie z małych liter alfabetu łacińskiego. Proszę krótko uzasadnić wybór
//zaimplementowanego algorytmu.


bool possible( char* u, char* v, char* w ){


    int su=sizeof(u);
    int sv=sizeof(v);
    int sw=sizeof(w);
   int  n=254;
    int C[n];

    for(int i=0;i<n;i++) C[i]=0;
    for(int i=0;i<su;i++) {
        C[(int)u[i]]++;
        cout<<C[(int)u[i]]<<" "<<u[i]<<endl;
    }
    for(int i=0;i<sv;i++) C[(int)v[i]]++;
    for(int i=0;i<sw;i++){
        cout<<C[(int)w[i]]<<" "<<w[i]<<endl;
        C[(int)w[i]]--;
        cout<<C[(int)w[i]]<<" "<<w[i]<<endl;
        if(C[(int)w[i]]<0) return false;
    }
    return true;
}
//zlozonosc powyzszego programu to n+wielkosc kazdej z tablic slowa, czyli O(n+u+v+w) gdzie n jest zakresem liter
int main(){
    //har * ponk="ponk";
    Node* head = buildList(6, 5);
    print(head);
    head->next = QuickerSort(head->next);
    print(head);


    char *ponk = new char[4];
    strcpy(ponk, "ponk");
    //char * kwat="kwat";
    char *kwat = new char[4];
    strcpy(kwat, "kwat");
    char *at = new char[2];
    strcpy(at, "poff");
    if(possible(ponk,kwat,at)) cout<<"YEEEAh"<<endl;
    else
        cout<<"KICHA"<<endl;
}