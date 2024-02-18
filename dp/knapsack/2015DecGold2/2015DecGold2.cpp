#include <bits/stdc++.h>

using namespace std;
int t, a, b; 
int dp[5000001]; //not achievable = 0, achievable w/o water = 1, achiv. w water = 2

void fun(int fullness, int prev){
    if(fullness > t || dp[fullness] != 0) return;
    dp[fullness] = prev;
    fun(fullness + a, dp[fullness]);
    fun(fullness + b, dp[fullness]);
    if(dp[fullness] == 1 && dp[fullness / 2] == 0){
        fun(fullness / 2, 2);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    cin >> t >> a >> b;
    fun(0, 1);
    int ans;
    for(ans = t; ans >= 0; ans--){
        if(dp[ans] != 0)
            break;
    }
    cout << ans << "\n";

    return 0;
}