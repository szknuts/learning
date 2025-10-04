// ac realtime !!!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> V(N + 1, 1);
    V[0] = 0;

    // [A]
    // for (int i = 1; i < V.size(); ++i)
    //     V[i] += V[i - 1];

    int min = 1;
    for (int i = 0; i < Q; ++i)
    {
        int count = 0;
        int x, y;
        cin >> x >> y;

        //[B]
        for (int j = min; j <= x; ++j)
            count += V[j];

        // [A]
        // count = V[x];
        // V[y] += count;
        // for (int j = min; j <= x; j++)
        //     V[j] = 0;

        //[B]
        V[y] += count;
        min = max(min, x + 1);

        cout << count << endl;
    }
}