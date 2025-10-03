#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A.begin(), A.end());
    int Q;
    cin >> Q;

    while (Q--)
    {
        long long b;
        cin >> b;
        // 二分探索 (lower_bound: bより大きい要素の最初のイテレータ)
        int idx = lower_bound(A.begin(), A.end(), b) - A.begin();
        // LLONG_MAX: long long の最大の値
        long long ans = LLONG_MAX;
        if (idx < N)
            ans = abs(A[idx] - b);
        if (idx > 0)
            ans = min(ans, abs(A[idx - 1] - b));
        cout << ans << endl;
    }
}
