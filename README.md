# Teoria Grafów

Algorytm pobiera dane z pliku Graph.txt. Można podać tylko po 1 grafie. Dane są podane w formie macierzy sąsiedztwa. Podany graf musi być prosty i nie może zawierać ujemnych wag. Krawędź od wierzchołka np. 1 do siebie samego zawsze musi mieć wagę 0. Maksymalna waga krawędzi to 998. Krawędzie, które nie istnieją mają wagę 999. Maksymalna liczba wierzchołków to 100. Jeżeli do danego wierzchołka nie da się dojść, to pokazany zostanie koszt -1. Najpierw podajemy liczbę wierzchołków, następnie macierz sąsiedztwa, a na koniec węzeł, który wybieramy na startowy. Węzły są numerowane od 0. Graph.txt nie może zawierać komentarzy. Możliwe, że trzeba będzie zmienić ścieżkę do pliku Graph.txt na aktualną (Miejsce zaznaczone TODO).

## Przykład 1
![image](https://user-images.githubusercontent.com/72551316/120190822-676b7a80-c219-11eb-8e30-22c03d0ded3c.png)
Przykładowy input

![image](https://user-images.githubusercontent.com/72551316/120189974-45252d00-c218-11eb-8285-8ed9660fa9a6.png)
Output dla podanego przykładu

![image](https://user-images.githubusercontent.com/72551316/120192998-2b85e480-c21c-11eb-8c1c-14fd8394a3bb.png)
Rysunek przykładowego grafu

## Przykład 2
![image](https://user-images.githubusercontent.com/72551316/120203622-334b8600-c228-11eb-8f7b-5e497ffae6cf.png)
Przykładowy input

![image](https://user-images.githubusercontent.com/72551316/120203667-41010b80-c228-11eb-920e-2b0eacaea1bb.png)
Output dla podanego przykładu

![image](https://user-images.githubusercontent.com/72551316/120203970-963d1d00-c228-11eb-9965-02d09a9cab26.png)
Rysunek przykładowego grafu

## Analiza algorytmu
### Jakie problemy rozwiązuje?
Algorytm Dijkstry ma za zadanie znaleźć najkrótszą drogę w grafie z początkowego wierzchołka do każdego innego w danym grafie. Przy okazji oblicza też koszt takiej drogi. Używa w tym celu metody zachłannej i zaznacza już odwiedzone wierzchołki, dzięki czemu nie da się odwiedzić wierzchołka więcej niż 1 raz.
### Przykłady zastosowania
Algorytm ten można stosować w nawigacji do znalezienia najkrótszej drogi do celu.
Można też go użyć do zaprojektowania sieci telekomunikacyjnej, tak aby np. połączenie między dwoma oddziałami firmy było jak najtańsze.
Może też zostać użyty do budowy sieci dróg.
### Z jakich metod korzysta się obecnie do rozwiązywania tych problemów?
Mój algorytm można ulepszyć podając listę sąsiedztwa na wejście i korzystając z kopca - złożoność spada z O(V^2) do O(ELogV). Złożoność algorytmu można też zredukować do O(E + VLogV) jeśli użyjemy kopca Fibbonaciego. Algorytm Dijkstry nie radzi sobie ze znajdowaniem najkrótszej ścieżki w grafie z ujemnymi wartościami krawędzi - w takim wypadku należy skorzystać z algorytmu Bellmana-Forda.
