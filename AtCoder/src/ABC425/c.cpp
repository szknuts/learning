// ac after
// 累積和，オーバーフロー，2倍に伸ばして先頭に戻さん
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    vector<long long> B(N * 2 + 1);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    A.insert(A.end(), A.begin(), A.end());
    for (int i = 1; i < N * 2 + 1; i++)
        B[i] = B[i - 1] + A[i - 1];

    int q1, q2, q3;
    int rotate = 0;
    for (int i = 0; i < Q; i++)
    {
        cin >> q1;
        if (q1 == 1)
        {
            cin >> q2;
            rotate += q2;
            rotate %= N;
        }
        else
        {
            cin >> q2 >> q3;
            cout << B[rotate + q3] - B[rotate + q2 - 1] << endl;
        }
    }
}
