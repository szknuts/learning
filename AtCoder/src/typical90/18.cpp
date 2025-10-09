#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, L, X, Y, Q;
    cin >> T >> L >> X >> Y >> Q;
    cout << fixed << setprecision(10);

    while (Q--)
    {
        int E;
        cin >> E;
        // E(経過時間)/T(一周の時間) -> 回転している割合(0~1)
        // 2.0 * M_PI = 2π (360度) -> 1ラジアン
        double theta = 2.0 * M_PI * E / T;
        // - 反時計回り -> 時計回り
        // L/2.0 -> 観覧車の半径
        // sin(θ) -> 縦の座標
        double y = -(L / 2.0) * sin(theta);
        // 半径 - 半径*cos(θ) (-1 ~ 1)
        // cos(θ)
        double z = (L / 2.0) - (L / 2.0) * cos(theta);

        double dist = sqrt(pow(X, 2) + pow(Y - y, 2));
        double angle = atan2(z, dist) * 180.0 / M_PI;
        cout << angle << endl;
    }
}