#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    // unsigned long long bc = pow(c, b);
    unsigned long long bc = 1;
    while (b--)
    {
        bc *= c;
    }

    if (a < bc)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}