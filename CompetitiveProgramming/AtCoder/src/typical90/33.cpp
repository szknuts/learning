#include <bits/stdc++.h>
using namespace std;
int main()
{
    int H, W;
    cin >> H >> W;
    if (H == 1 || W == 1)
        cout << H * W << endl;
    else
        cout << (++H / 2) * (++W / 2) << endl;
}