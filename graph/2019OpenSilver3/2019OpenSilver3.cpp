#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<pi> cows(n + 1);
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        cows[i] = {x, y};
    }
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a);
    }
    int ans = INT_MAX;
    bool vis[n + 1] = {};
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        vector<int> group;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int u = q.front(); q.pop();
            group.push_back(u);
            for(int v : adj[u]){
                if(vis[v]) continue;
                vis[v] = true;
                q.push(v);
            }
        }
        int minx = INT_MAX, maxx = 0, miny = INT_MAX, maxy = 0;
        for(int j = 0; j < group.size(); j++){
            minx = min(minx, cows[group[j]].first);
            maxx = max(maxx, cows[group[j]].first);
            miny = min(miny, cows[group[j]].second);
            maxy = max(maxy, cows[group[j]].second);
        }
        ans = min(ans, 2 * (maxx - minx + maxy - miny));
    }
    cout << ans << "\n";

    return 0;
}