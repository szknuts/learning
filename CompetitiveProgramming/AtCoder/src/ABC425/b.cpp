// ac realtime
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    queue<int> q;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 1; i < N + 1; i++)
        if (count(A.begin(), A.end(), i) > 1)
        {
            cout << "No" << endl;
            return 0;
        }

    cout << "Yes" << endl;

    for (int i = 1; i < N + 1; i++)
        if (find(A.begin(), A.end(), i) == A.end())
            q.push(i);

    for (int i = 0; i < N; i++)
    {
        if (A[i] != -1)
            cout << A[i] << " ";
        else
        {

            cout << q.front() << " ";
            q.pop();
        }
    }
}
