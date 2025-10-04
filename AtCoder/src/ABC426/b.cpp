// ac realtime
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;

    for (int i = 1; i < S.size() - 1; i++)
    {
        if (S[i - 1] == S[i + 1])
        {
            if (S[i - 1] != S[i])
            {
                cout << S[i] << endl;
                return 0;
            }
        }
        else if (S[i - 1] != S[i + 1])
        {
            if (S[i - 1] == S[i])
            {
                cout << S[i + 1] << endl;
                return 0;
            }
            else if (S[i] == S[i + 1])
            {
                cout << S[i - 1] << endl;
                return 0;
            }
        }
    }
}