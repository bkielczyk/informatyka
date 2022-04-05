#include <iostream>
#include <chrono>

using namespace std;

chrono::duration<double> elapsed_seconds;

void szyfr(int klucz, char tab[1000])
{
    int dl = strlen(tab);

    if (klucz >= -26 && klucz <= 26)
    {
        if (klucz >= 0)
        {
            for (int i = 0; i < dl; i++)
            {
                if (tab[i] + klucz <= 'z')
                {
                    tab[i] += klucz;
                }
                else
                {
                    tab[i] = tab[i] + klucz - 26;
                }
            }
        }
        else
        {
            for (int i = 0; i < dl; i++)
            {
                if (tab[i] + klucz >= 'a')
                {
                    tab[i] += klucz;
                }
                else
                {
                    tab[i] = tab[i] + klucz + 26;
                }
            }
        }
    }

    cout << tab;
}


int main()
{

    chrono::system_clock::time_point start = chrono::system_clock::now();


    int klucz;
    char tab[1000];

    cout << "Podaj wyraz skladajacy sie z malych liter: ";
    cin >> tab;

    cout << "Podaj klucz z przedzialu [-26..26]: ";
    cin >> klucz;

    cout << "Po zaszyfrowaniu: ";
    szyfr(klucz, tab);
    cout << endl;

    cout << "Po rozszyfrowaniu: ";
    szyfr(-klucz, tab);
    cout << endl;


    chrono::system_clock::time_point end = chrono::system_clock::now(); // czas stop

    elapsed_seconds += end - start;	// obliczenie czasu
    cout << "\nCzas: " << endl;
    // wyswietlenie czasu w roznych jednostkach
    cout << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_seconds).count() << "\t milliseconds\n";
    cout << std::chrono::duration_cast<std::chrono::seconds>(elapsed_seconds).count() << "\t seconds\n";
}