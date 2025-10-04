// ac realtime
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string X, Y;
    cin >> Y >> X;

    if (X == "Ocelot")
        cout << "Yes" << endl;

    else if (X == "Serval")
        if (Y == "Serval" || Y == "Lynx")
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    else if (X == "Lynx")
        if (Y == "Lynx")
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
}