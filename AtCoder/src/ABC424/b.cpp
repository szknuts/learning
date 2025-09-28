// ac realtime
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int A, B;
    vector<int> S(N);
    vector<int> ANS;

    for (int i = 0; i < K; i++)
    {
        cin >> A >> B;
        S[A - 1]++;
        if (S[A - 1] == M)
            ANS.push_back(A);
    }

    for (int i = 0; i < ANS.size(); i++)
        cout << ANS[i] << " ";
    if (ANS.size() > 0)
        cout << endl;
}