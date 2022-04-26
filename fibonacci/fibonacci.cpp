#include <iostream>
#include <chrono>

using namespace std;

chrono::duration<double> elapsed_seconds;

int main()
{
    chrono::system_clock::time_point start = chrono::system_clock::now();

    int n;
    int f0, f1, f;
    cout << "Ile wyrazow ciagu wypisac: ";
    cin >> n;

    f0 = 0;
    f1 = 1;
    for (int i = 0; i <= n; i++)
    {
        if (i > 1)
        {
            f = f0 + f1;
            f0 = f1;
            f1 = f;
        }
        else
        {
            f = i;
        }
        cout << f << endl;
    }

    chrono::system_clock::time_point end = chrono::system_clock::now(); // czas stop

    elapsed_seconds += end - start;	// obliczenie czasu
    cout << "\nCzas: " << endl;
    // wyswietlenie czasu w roznych jednostkach
    cout << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds).count() << "\t milliseconds\n";
    cout << std::chrono::duration_cast<std::chrono::seconds>(elapsed_seconds).count() << "\t seconds\n";
}