#include <iostream>
#include <chrono>

using namespace std;

chrono::duration<double> elapsed_seconds;

int szukaj(int szukana) 
{
    int tab[15] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };

    int l = 0;
    int p = 15;
    int sr = (l + p) / 2;

    while (l <= p) {
        if (tab[sr] == szukana) {
            return sr;
        }
        if (tab[sr] > szukana) {
            p = sr - 1;
        }
        else {
            l = sr + 1;
        }
        sr = (l + p) / 2;
    }
    return -1;
}

int main()
{
    chrono::system_clock::time_point start = chrono::system_clock::now();

    int szukana;
    cout << "Podaj liczbe ktora chcesz znalezc: ";
    cin >> szukana;

    int pozycja = szukaj(szukana);
    
    if (pozycja == -1) {
        cout << "Nie ma tej liczby w zbiorze";
    }
    else {
        cout << "Liczba " << szukana << " wystepuje w zbiorze w komorce o indeksie " << pozycja;
    }

    chrono::system_clock::time_point end = chrono::system_clock::now(); // czas stop

    elapsed_seconds += end - start;	// obliczenie czasu
    cout << "\nCzas: " << endl;
    // wyswietlenie czasu w roznych jednostkach
    cout << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds).count() << "\t milliseconds\n";
    cout << std::chrono::duration_cast<std::chrono::seconds>(elapsed_seconds).count() << "\t seconds\n";

}
