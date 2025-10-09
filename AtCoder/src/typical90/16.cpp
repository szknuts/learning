#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long a = 0, b = 0, c = 0;
    cin >> a >> b >> c;

    int ans = INT_MAX;

    for (int x = 0; x <= 9999; ++x)
        for (int y = 0; x + y <= 9999; ++y)
        {
            long long nn = n - 1ll * a * x - 1ll * b * y;
            if (nn >= 0 && nn % c == 0)
            {
                int z = nn / c;
                ans = min(ans, x + y + z);
            }
        }
    cout << ans << endl;
}