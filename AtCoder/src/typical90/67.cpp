#include <bits/stdc++.h>
using namespace std;

int main()
{
    // long long N;
    string str;
    int K;
    cin >> str >> K;

    for (int i = 0; i < K; ++i)
    {
        // 8 to 10
        unsigned long long N = 0, x = 1;
        for (int j = str.size() - 1; j >= 0; --j)
        {
            N += (str[j] - '0') * x;
            x *= 8;
        }
        // 10 to 9
        str = "";
        if (N == 0)
            str = "0";
        while (N > 0)
        {
            char c = (N % 9) + '0';
            str = c + str;
            N /= 9;
        }
        //'8' to '5'
        for (char &c : str)
            if (c == '8')
                c = '5';
    }
    cout << str << endl;
}