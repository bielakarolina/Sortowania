//
// Created by Karolina on 31.03.2018.
//

//1. Proszę zaimplementować funkcję void SumSort(int A[], int B[], int n).
//Funkcja ta przyjmuje na wejściu dwie n 2 -elementowe tablice (A i B) i
//        zapisuje w tablicy B taką permutację elementów z A,
//        że: nX−1 i=0 B[i] ¬ 2 Xn−1 i=n B[i] ¬ ... ¬ nX2−1 i=n2−n B[i].
//Proszę zaimplementować funkcję SumSort tak, by działała możliwie jak najszybciej.
//Proszę oszacować i podać jej złożoność czasową.
//
//2. Dana jest n elementowa tablica A zawierająca liczby naturalne (potencjalnie bardzo duże).
//Wiadomo, że tablica A powstała w dwóch krokach.
//Najpierw wygenerowano losowo (z nieznanym rozkładem) n różnych liczn nieparzystych i
//        posortowano je rosnąco. Następnie wybrano losowo dlog ne elementów powstałej
//        tablicy i zamieniono je na losowo wybrane liczby parzyste. Proszę zaproponować (bez implementacji!)
//algorytm sortowania tak powstałych danych. Algorytm powinien być możliwie jak najszybszy.
//Proszę oszacować i podać jego złożoność czasową.
//
//3. Dana jest struktura Node opisująca listę jednokierunkową:
//struct Node { Node * next; int value; };
//Proszę zaimplementować funkcję Node* fixSortedList( Node* L ),
//która otrzymuje na wejściu listę jednokierunkową bez wartowanika.
//Lista ta jest prawie posortowana w tym sensie, że powstała z listy posortowanej
//przez zmianę jednego losowo wybranego elementu na losową wartość.
//Funkcja powinna przepiąć elementy listy tak, by lista stała się posortowana i
//        zwrócić wskaźnik do głowy tej listy.
//Można założyć, że wszystkie liczby na liście są różne i że lista ma co najmniej dwa elementy.
//Funkcja powinna działać w czasie liniowym względem długości listy wejściowej.
