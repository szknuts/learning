// ac realtime
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;

    cin >> N;

    int ans = 0;

    for (int i = 1; i < N + 1; i++)
        if (i % 2 == 0)
            ans += i * i * i;
        else
            ans -= i * i * i;
    cout << ans << endl;
}
