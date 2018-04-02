////
//// Created by Karolina on 02.04.2018.
////
//
//Zadanie 2. Scalanie dwóch posortowanych list.
//
//Zadanie 1. (zadania krótkie) Proszę rozwiązać następujące zadania:
//1. *5pkt.+ Proszę zaimplementować możliwie jak najszybszą funkcję sortującą tablice n liczb.
//2. [5pkt.] Dany jest typ struct List {List * next; int val; } realizujący listę jednokierunkową.
//Proszę zaimplementować funkcję List * reverse { List *L; }, która odwraca kierunek listy L (bez wartownika) i zwraca wskaźnik na jej głowę.
//
//Zadanie 2. Proszę opisać algorytm bez implementacji dla następującego problemu. Dana jest tablica A zawierająca n struktur tylu
//Struct Interval { int  x, y; };
//Elementy tablicy A opisują przedziały otwarte. Dana jest także liczba int t. Zadanie polega na wypisaniu t (lub mniej) przedziałów,
//których suma daje spójny przedział o maksymalnej długości. Proszę podać złożoność czasową algorytmu i uzasadnić jego poprawność.
//
//Zadanie 4. Proszę omówić i zaimplementować możliwie najszybszą funkcję sortującą listę jednokierunkową z danymi typu double.
//Proszę zdefiniować wszystkie potrzebne struktury danych.
//
//Zadanie 1. Dana jest struktura danych
//Struct Point { double x,y; };
//Opisująca punkty w przestrzeni . Proszę zaimplementować funkcję Void heapsort(Point* A, int n);
//Która otrzymuje na wejściu elementową tablicę struktur typu Point I sortuje ją w kolejności rosnącej względem
//odległości punktu od początku układu współrzędnych, korzystając z algorytmu heapsort.
//
//Zadanie 1. Dana jest struktura danych
//Struct Rectangle { double x,y; double w,h; };
//Opisująca prostokąty (pola x i y to współrzędne lewego górnego rogu prostokąta a w i h to jego wysokość i szerokość).
//Proszę zaimplementować funkcję void heapsort(Rectangle* A, int n); która otrzymuje na wejściu n
//        elementową tablicę struktur typu Rectangle i sortuje ją w kolejności rosnącej względem wartości pola prostokąta, korzystając z algorytmu heapsort.