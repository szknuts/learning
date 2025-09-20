#include <bits/stdc++.h>
using namespace std;
vector<int> A;
vector<int> B;
bool check(int x, int y);

int main()
{
    int N;
    cin >> N;
    vector<int> A(N + 1, 1);
    vector<int> B(N + 1, 1);

    int a, b;

    int ans = 0;

    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i];

    for (int i = 1; i <= N; i++)
    {
        if (check(A[i], B[i]))
            A[i] = 0;
    }

    for (int i = 1; i <= N; i++)
        if (A[i] == 0)
            ans++;

    cout << ans << endl;
}

bool check(int x, int y)
{
    if (x == 0)
        return true;
    else if (check(A[x], B[x]))
    {
        A[x] = 0;
        B[x] = 0;
        return true;
    }
    else if (check(A[y], B[y]))
    {
        A[y] = 0;
        B[y] = 0;
        return true;
    }
    else
        return false;
    return false;
}