#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    map<int, int> A, B, C;
    for (int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        A[tmp % 46]++;
    }
    for (int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        B[tmp % 46]++;
    }
    for (int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        C[tmp % 46]++;
    }

    unsigned long long ans = 0;
    for (const auto &[a_key, a_val] : A)
        for (const auto &[b_key, b_val] : B)
            for (const auto &[c_key, c_val] : C)
            {
                if ((a_key + b_key + c_key) % 46 == 0)
                {
                    ans += 1ll * a_val * b_val * c_val;
                }
            }
    cout << ans;
}