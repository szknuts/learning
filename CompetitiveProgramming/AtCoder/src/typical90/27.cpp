#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    string s;
    map<string, bool> m;
    for (int i = 1; i < N + 1; i++)
    {
        cin >> s;
        if (!m[s])
            cout << i << endl;
        m[s] = true;
    }
}