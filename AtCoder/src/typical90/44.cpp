#include <bits/stdc++.h>
#include <numeric>

using namespace std;
int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int idx = 0;
    while (Q--)
    {
        int T, X, Y;
        cin >> T >> X >> Y;
        switch (T)
        {
        case 1:
        {
            int xx = (X - idx - 1 + N) % N;
            int yy = (Y - idx - 1 + N) % N;
            swap(A[xx], A[yy]);
            break;
        }
        case 2:
        {
            ++idx;
            idx %= N;
            break;
        }
        case 3:
        {
            cout << A[(X - idx - 1 + N) % N] << endl;
            break;
        }
        default:
            break;
        }
    }
}