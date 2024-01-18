#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int n, q, k, v, ans = 0;
vector<pi> adj[5001];

void dfs(int cur, int prev, int dis){
    if(dis >= k) ans++;
    for(auto v : adj[cur])
        if(v.first != prev) dfs(v.first, cur, min(dis, v.second));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    for(int i = 0, u, v, c; i < n - 1; i++){
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    while(q--){
        cin >> k >> v;
        ans = -1;
        dfs(v, 0, INT_MAX);
        cout << ans << "\n";
    }

    return 0;
}