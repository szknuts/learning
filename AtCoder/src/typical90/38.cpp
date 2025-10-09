#include <bits/stdc++.h>
#include <numeric>

using namespace std;
int main()
{
    // lcm(A, B) =  A * B / gcd(A, B);

    // A * B / gcd(A, B) <= 10^18
    // x = B / gcd(A, B)
    // A * x <= 10^18
    // x <= 10^18 / A
    unsigned long long A, B, x;
    cin >> A >> B;
    x = B / gcd(A, B);

    if (x > 1000000000000000000 / A)
        cout << "Large" << endl;
    else
        cout << x * A << endl;
}