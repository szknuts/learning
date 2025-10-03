#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;

    if (N % 2 != 0)
    {
        cout << endl;
        return 0;
    }

    string str;
    // bit全探索
    // 1<<N：1をNビット左にずらす => 2^n 繰り返す
    // 1：0010 (2) → 0~1 (000~001)
    // 2：0100 (4) → 0~3 (000~011)
    // 3：1000 (8) → 0~7 (000~111)
    for (int i = 0; i < (1 << N); ++i)
    {
        string str = "";
        for (int j = N - 1; j >= 0; j--)
        {
            // iをjビット右にずらす それと1(001)のand
            // i=3,j=2→ i:011 → 000 & 001 => iのjビット目(右からj+1ビット目)
            if (((i >> j) & 1) == 0)
                str += "(";
            else
                str += ")";
        }

        int count = 0;
        bool flg = true;
        for (int i = 0; i < N; ++i)
        {
            if (str[i] == '(')
                count++;
            else
                count--;
            if (count < 0)
                flg = false;
        }
        if (count != 0)
            flg = false;
        if (flg)
            cout << str << endl;
    }
}