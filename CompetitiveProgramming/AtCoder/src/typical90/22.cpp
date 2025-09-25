#include <bits/stdc++.h>
#include <numeric>

using namespace std;
int main()
{
    long long int A, B, C;
    cin >> A >> B >> C;

    long long int g = gcd(gcd(A, B), C);

    A /= g;
    B /= g;
    C /= g;

    cout << A + B + C - 3 << endl;
}