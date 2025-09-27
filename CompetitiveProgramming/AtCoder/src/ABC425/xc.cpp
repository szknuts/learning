// wa realtime
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int q1, q2, q3;
    int rotate = 0;
    for (int i = 0; i < Q; i++)
    {
        cin >> q1;
        if (q1 == 1)
        {
            cin >> q2;
            rotate += q2;
            q2 %= N;
        }
        else
        {
            cin >> q2 >> q3;
            int sum = 0;
            q2 = (q2 + rotate - 1) % N;
            q3 = (q3 + rotate - 1) % N;
            if (q2 <= q3)
                for (int i = q2; i < q3 + 1; i++)
                    sum += A[i];
            else
            {
                for (int i = q2; i < N; i++)
                    sum += A[i];
                for (int i = 0; i < q3 + 1; i++)
                    sum += A[i];
            }
            cout << sum << endl;
        }
    }
}
*/