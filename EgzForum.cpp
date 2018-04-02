////
//// Created by Karolina on 02.04.2018.
////
//
//Mamy kwadrat zlozony z pierscieni wypelnionych losowymi liczbami. Chodzilo o to, zeby w taki sposob
// rozmiescic liczby, aby poczynajac od najbardziej wewnetrznego pierscienia znajdowaly sie w nim liczby
// wieksze niz w kolejnym pierscieniu. Algorytm mial byc w miejscu. Oszacowac zlozonosc i przeprowadzic dyskusje
// czy mozliwy jest algorytm o nizszej zlozonosci.
//ODP:
//        Można O(nlogn) - mergesort w miejscu. Można napisać funkcję ( działającą w czasie O(1) )
// indeksującą tablicę dwuwymiarową po spirali od środka na zewnątrz i tak właśnie zrobiłem i to
// byłoby potrzebne do wspomnianego mergesorta.
//
//Rozwiązanie implementowalne w rozsądnym czasie, O(n^2): Tworzymy klasę iterator przechowującą współrzędne
// punktu w tablicy dwuwymiarowej i operator++ do niej, tak, że na początku przechowuje współrzędne środka tablicy
// a ++ przypisuje mu kolejne współrzędne punktu ze spirali. Używając tak działających iteratorów sortujemy
// selectionsortem jak listę jednokierunkową. Poniżej obrazek wyjaśniający co mam na myśli pisząc spirala:
//        Na czerwono są numery elementów spirali, tak więc np. 11-ty element spirali (czyli element na którym
// iterator znajdzie się po wykonaniu 10 inkrementacji) odpowiada współrzędnym (4,2) w wejściowej tablicy.
// ZŁ: O(n^2*log(n^2))
//

//3) Pracujesz w firmie informatycznej i jako zadanie dostałeś napisać alternatywę do qsorta
// zawartego w standardowych bibliotekach. Qsort przyjmuje następujące argumenty:
//qsort (void * base,int N, int size, void (*comparator)(const void*, const void*)).
//
// Normalny Qsort jest niestabilny oraz czasami wychodzi ze złożonością poza Nlogn.
// Twój algorytm, oczywiście, musi być na to odporny.
//
//ODP: qsort na stosie finito


//2. Mając daną posortowaną tablicę A[1..n] wypełnioną unikalnymi wartościami ze
// zbioru B = {1,2,..,m} (m > n) znajdź najmniejszy element z B taki, że nie należy do A.
//C[A[i]]=true
//przechodzisz for(int i=0;i<m;i++)
//if(C[i] ==false) wypisz i
//„Firma telekomunikacyjna ma za zadanie okablować wysoki biurowiec.
// Wszystkie piętra mają równą wysokość. Znana jest liczba terminali na każdym piętrze.
// Należy założyć, że każdy terminal jest równo oddalony od głównego pionu,
// w którym idą kable pomiędzy piętrami. Firma musi podłączyć każdy terminal
// osobną skrętką do centrali światłowodowej. Proszę opisać i zaimplementować algorytm
// znajdujący piętro, na którym powinna zostać umieszczona centralka,
// aby koszt (łączna długość) skrętek podłączanych od centrali do wszystkich terminali był możliwie najmniejszy.”
//HasHTable
//
#include <iostream>
using namespace std;
// argumenty to liczba pięter i tablica ilości odbiorników na każdym z pięter - funkcja zwraca nr piętra piętro lub (-1) jeśli pięter nie ma;
int ktore_pietro(int n, int termi[]){
    int *koszt = new int[n]; //potrzebuję tablicę określającą koszt położenia instalacji dla każdego z pięter
    int suma = termi[0]; //gdy będziemy poruszać się w pętli będzie nam potrzebna suma wszystkich poprzednich elementów ciągu termi
    int suma_2 = termi[n-1]; //ta zmienna bedzie potrzebna przy schodzeniu "w dół" - nie do się wygodnie odtworzyć kosztu położenia instalacji "w górę" dla poprzedniego piętra, bo została ona zsumowana z kosztem instalacji "w dół"
    koszt[0] = 0; //koszt położenia na 0 piętrze, jeśli jeszcze nie policzyliśmy wszystkich pięter powyżej jest zerowy

    for ( int i = 1; i < n; i++){
        koszt[i] = koszt[i-1]+suma; //położenie instalacji "w dół" na i-tym piętrze wymaga doprowadzenia jej do piętra poniżej i pociągnięcia tylu więcej kabli ile terminali znajduje się poniżej0
        suma += termi[i]; // ilość terminali na i-tym poziomie nie wpływa na koszt montażu na i-tym poziomie
    }

    suma = termi[n-1];
    // teraz poruszamy się w dół i do każdego poziomu doliczamy koszt poprowadzenia instalacji w górę
    for ( int i = n-2; i >= 0 ; i--){
        koszt[i] += suma_2;
        suma += termi[i];
        suma_2 += suma;
    }

    //mamy tablicę kosztów montażu na każdym z pięter - pozostaje wybrać najmniejszy element i zwrócić jego indeks, a zmiennej suma już nie potrzebujemy - użyjemy jej do tego szukania
    suma = (n)?(-1):0; //na wypadek gdyby budynku nie było   :-P
    for (int i=1; i<n; i++)
        suma = (koszt[i]<koszt[suma])?i:suma;
    return suma;
}
int main(){
    int n;
    int *termi;
    cin >> n;
    termi = new int[n];
    for (int i=0; i< n; i++)
        cin >> termi[i];
    cout << ktore_pietro(n, termi);
}

