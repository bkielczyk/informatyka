#include <iostream>

using namespace std;

int main()
{
    int ile;

    cout << "Ile liczb: ";
    cin >> ile;

    int liczba = 2;
    int pierwsze = 0;

    while (pierwsze < ile) {
        bool pierwsza = 1;
        for (int j = 2; j < liczba; j++) {
            if (liczba % j == 0) {
                pierwsza = 0;
            }
        }
        if (pierwsza == 1) {
            cout << liczba << ", ";
            pierwsze++;
        }
        liczba++;
    }
}