#include <bits/stdc++.h>
//figure out logic, cows that pass through each barn * (amt time reduced -> og dis - t)
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, m, t; cin >> n >> m >> t;
    int cif[n + 1];
    for(int i = 1; i <= n; i++) cin >> cif[i];
    vector<pi> adj[n + 1];
    for(int i = 0; i < m; i++){
        int a, b, t; cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    int prev[n + 1]; fill(prev, prev + n + 1, INT_MAX);
    priority_queue<pi, vector<pi>, greater<pi>> q;
    int dis[n + 1]; fill(dis, dis + n + 1, INT_MAX);
    bool vis[n + 1] = {};
    q.push({0, 1});
    dis[1] = 0;
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue; vis[u] = true;
        for(pi e : adj[u]){
            int v = e.first, w = e.second;
            if(dis[u] + w < dis[v] || dis[u] + w == dis[v] && u < prev[v]){
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
                prev[v] = u;
            }
        }
    }
    int ctp[n + 1] = {};
    for(int i = 1; i <= n; i++){
        int cur = i;
        while(cur != INT_MAX){
            ctp[cur] += cif[i]; //iterating through each field initially to find all fields these cows pass through
            cur = prev[cur];
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, (ll)ctp[i] * (dis[i] - t)); //number of cows that pass through the field multiplied by time each cow saves for each field
    }
    cout << ans << "\n";

    return 0;
}