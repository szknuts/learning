#include <bits/stdc++.h>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    // vector<int> v;
    deque<int> d;
    int t, x;
    for (int i = 0; i < Q; i++)
    {
        cin >> t >> x;
        switch (t)
        {
        case 1:
            // v.insert(v.begin(), x);
            d.push_front(x);
            break;
        case 2:
            // v.push_back(x);
            d.push_back(x);
            break;
        case 3:
            // cout << v[x - 1] << endl;
            cout << d[x - 1] << endl;
            break;
        default:
            break;
        }
    }
}