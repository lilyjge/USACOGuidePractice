#include <bits/stdc++.h>
//originally all is 0, set good ones with values so we can add on
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int w, h; cin >> w >> h;
    int n; cin >> n;
    int width[n + 1] = {}, height[n + 1] = {};
    for(int i = 1; i <= n; i++) cin >> width[i] >> height[i];
    int dp[w + 1][h + 1]; memset(dp, 0, sizeof(dp));//max area of tiles obtained
    
    for(int i = 1; i <= n; i++){
        dp[width[i]][height[i]] = width[i] * height[i];
    }
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= h; j++){
            for(int k = 1; k <= i; k++){
                dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]); //we can fit another group of dp[i - k][j]
            }
            for(int k = 1; k <= j; k++){
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
            }
        }
    }
    
    cout << w * h - dp[w][h] << "\n";

    return 0;
}