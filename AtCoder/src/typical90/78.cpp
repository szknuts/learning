#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i < N + 1; i++)
    {
        int count = 0;
        for (int j : v[i])
            if (i > j)
                count++;
        if (count == 1)
            ans++;
    }
    cout << ans << endl;
}