#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> B(N);
    long int gap = 0;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    for (int i = 0; i < N; i++)
        gap += abs(A[i] - B[i]);

    if (gap > K)
        cout << "No" << endl;
    else if ((gap - K) % 2 != 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}