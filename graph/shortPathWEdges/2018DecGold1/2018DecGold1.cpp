#include <bits/stdc++.h>
//??? negative edges
using namespace std;
typedef pair<int, int> pi;
const int MM = 50001;
int n, m, k;
vector<pi> adj[MM];
int dis1[MM], dis2[MM];

void path(bool st){
    int dis[n + 1]; memset(dis, 0x3f, sizeof(dis));
    bool vis[n + 1] = {};
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, n});
    dis[n] = 0;
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue; vis[u] = true;
        for(auto e : adj[u]){
            int v = e.first, w = e.second;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(st) dis1[i] = dis[i];
        if(!st) dis2[i] = dis[i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> n >> m >> k;
    for(int i = 0, a, b, t; i < m; i++){
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    path(true);
    adj[n].clear();
    for(int i = 0, idx, yum; i < k; i++){
        cin >> idx >> yum;
        adj[n].push_back({idx, dis1[idx] - yum});
    }
    path(false);
    for(int i = 1; i < n; i++){
        cout << (dis2[i] <= dis1[i]) << "\n";
    }

    return 0;
}