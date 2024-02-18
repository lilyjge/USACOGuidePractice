#include <bits/stdc++.h>
//memset 1 not big enough sometimes
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("5.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, k; cin >> n >> k;
    int snakes[n + 1] = {};
    int psa[n + 3] = {};
    for(int i = 1; i <= n; i++) cin >> snakes[i];
    for(int i = 1; i <= n; i++) psa[i] = psa[i - 1] + snakes[i];
    int dp[n + 1][k + 1]; //least amt of wasted space with n snakes and k switches
    for(int i = 0; i <= n; i++) fill(dp[i], dp[i] + k + 1, 1e9);
    int big = 0;
    for(int i = 1; i <= n; i++){
        big = max(big, snakes[i]);
        dp[i][0] = big * i - psa[i];
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            int net = snakes[j];
            for(int l = j; l >= 1; l--){ //last net must be able to capture all snakes to last
                net = max(net, snakes[l]);
                int waste = net * (j - l + 1) - (psa[j] - psa[l - 1]);
                dp[j][i] = min(dp[j][i], dp[l - 1][i - 1] + waste);
            }
        }
    }
    cout << dp[n][k] << "\n";

    return 0;
}