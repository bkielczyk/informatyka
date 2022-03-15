#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Podaj a: ";
    cin >> a;
    cout << "Podaj b: ";
    cin >> b;
    int iloczyn = a * b;
    while (a != b) {
        if (a < b) {
            b = b - a;
        }
        else {
            a = a - b;
        }
    }
    cout << "NWD(a,b): " << a << endl;
    int nww = iloczyn / a;
    cout << "NWW(a,b): " << nww;
}
