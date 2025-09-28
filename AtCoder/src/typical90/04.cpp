#include <bits/stdc++.h>
using namespace std;
int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<int>> V(H, vector<int>(W));

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> V[i][j];

    vector<int> HSum(H);
    vector<int> WSum(W);

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            HSum[i] += V[i][j];

    for (int i = 0; i < W; i++)
        for (int j = 0; j < H; j++)
            WSum[i] += V[j][i];

    for (int i = 0; i < H; i++)
    {
        int HSum_tmp = HSum[i];
        for (int j = 0; j < W; j++)
            cout << HSum_tmp + WSum[j] - V[i][j] << " ";
        cout << endl;
    }
}