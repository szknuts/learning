#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> PSum1(N + 1, 0);
    vector<int> PSum2(N + 1, 0);

    int c = 0;
    int p = 0;
    cin >> c >> p;
    if (c == 1)
        PSum1[1] = p;
    else
        PSum2[1] = p;

    for (int i = 2; i < N + 1; i++)
    {
        cin >> c >> p;
        PSum1[i] = PSum1[i - 1];
        PSum2[i] = PSum2[i - 1];
        if (c == 1)
            PSum1[i] += p;
        else
            PSum2[i] += p;
    }

    int Q = 0;
    int l, r;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> l >> r;
        cout << PSum1[r] - PSum1[l - 1] << " " << PSum2[r] - PSum2[l - 1] << endl;
    }
}