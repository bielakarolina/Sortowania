//
// Created by Karolina on 31.03.2018.
//

//1. Dana jestr struktura opisująca listę jednokierunkową dla liczb rzeczywistych: struct Node{ Node* next; double value; }
//        Proszę zaimplementować funkcję void Sort( Node* list ),
//        która otrzymuje na wejściu listę liczb rzeczywistych (z wartownikiem),
//        wygenerowaną zgodnie z rozkładem jednostajnym na przedziale [0,10) i sortuje jej zawartość w kolejności niemalejącej.
//Funkcja powinna być możliwie jak najszybsza (biorąc pod uwagę warunki zadania). Proszę oszacować złożoność zaimplementowanej funkcji.

Node struct{
    int value;
    Node * next;
};
//scalanie kubełków, dołączamy niepusty kubełek i przesuwamy się na jego koniec;
Node *merge_buckets(Node **bucket, int n){
    Node * result = new Node, *guard;
    quard = result;
    for(int i=0; i<n; i++){
        if(bucket[i]){
            result->next = bucket[i];
            while(result->next) result = result ->next;
        }
    }
    return quard->next;
}

void add_node_at_start(Node *&first,Node *new_node){
    new_node->next = first;
    first = new_node;
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

    double  interval_length = (double)4/n;
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
    add_node_at_start(bucket[],tmp);     ////////
    }
    for(int i=0; i<n;i++) merge_buckets(bucket[i]);
    first = merge_buckets(bucket, n);
    return first;
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
