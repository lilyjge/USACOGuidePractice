#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    
    int n, m, c;
    cin >> n >> m >> c;
    int money[n + 1] = {};
    for(int i = 1; i <= n; i++) cin >> money[i];
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int dp[n + 1][1003]; memset(dp, 0, sizeof(dp)); //city, days, net money
    queue<pi> q; //city, day
    q.push({1, 0});
    while(!q.empty()){
        int city = q.front().first, day = q.front().second;
        q.pop();
        for(int v : adj[city]){
            int newm = dp[city][day] + money[v] - (day + day + 1) * c;
            if(day >= 1002) continue;
            if(newm > dp[v][day + 1] || v == 1){
                dp[v][day + 1] = max(dp[v][day + 1], newm);
                q.push({v, day + 1});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= 1002; i++) ans = max(ans, dp[1][i]);
    cout << ans << "\n";

    return 0;
}