#include <bits/stdc++.h>
//ON HOLD
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, k; cin >> n >> k;
    char play[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> play[i];
    }
    int lh = 0, lp = 0, ls = 0;
    int dp[n + 1][k + 1]; memset(dp, 0, sizeof(dp)); //max number of games won at j games, i switches, if switch to x move rn
    for(int j = 1; j <= n; j++){
        if(play[j] == 'P') lp++;
        if(play[j] == 'S') ls++;
        if(play[j] == 'H') lh++;
        dp[j][0] = max(lp, max(ls, lh));
    }
    lh = 0, lp = 0, ls = 0;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            if(play[j] == 'P'){
                dp[j][i] = max(dp[lp][i-1] + 1, max(dp[lh][i-1], dp[ls][i-1]));
                lp = j;
            }
            else if(play[j] == 'H'){
                dp[j][i] = max(dp[lh][i-1] + 1, max(dp[lp][i-1], dp[ls][i-1]));
                lh = j;
            }
            else if(play[j] == 'S'){
                dp[j][i] = max(dp[ls][i-1] + 1, max(dp[lh][i-1], dp[lp][i-1]));
                ls = j;
            }
        }
        lh = 0, lp = 0, ls = 0;
    }
    cout << dp[n][k] << "\n";

    return 0;
}