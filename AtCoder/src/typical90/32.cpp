#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];
    cin >> M;
    vector<vector<bool>> isAble(N, vector<bool>(N, true));
    for (int i = 0; i < M; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        isAble[x][y] = isAble[y][x] = false;
    }

    vector<int> vec;
    for (int i = 0; i < N; i++)
        vec.push_back(i);

    int ans = INT_MAX;
    do
    {
        int sum = 0;
        bool flg = true;
        for (int i = 0; i < N - 1; i++)
            if (isAble[vec[i]][vec[i + 1]] == false)
            {
                flg = false;
                break;
            }

        if (!flg)
            continue;

        for (int i = 0; i < N; ++i)
            sum += A[vec[i]][i];

        ans = min(ans, sum);
    } while (next_permutation(vec.begin(), vec.end()));

    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
}