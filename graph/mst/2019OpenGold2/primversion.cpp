#include <bits/stdc++.h>
//problem comprehension?? why is it min not max
//use prim for not tle (or their implementation anyways, this tled)
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;

ll willwalk(int x, int y){
    return (2019201913 * (ll)x + 2019201949 * (ll)y) % (ll)2019201997;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("2.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<pi> adj[n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            ll dis = willwalk(j, i);
            adj[i].push_back({j, dis});
            adj[j].push_back({i, dis});
        }
    }
    ll dis[n + 1]; fill(dis, dis + n + 1, INT32_MAX);
    bool vis[n + 1] = {};
    priority_queue<pi, vector<pi>, greater<pi>> q;
    dis[1] = 0;
    q.push({0, 1});
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue; vis[u] = true;
        for(auto e : adj[u]){
            int v = e.first, w = e.second;
            if(!vis[v] && dis[v] > w){
                dis[v] = w;
                q.push({dis[v], v});
            }
        }
    }
    vector<ll> used;
    for(int i = 1; i <= n; i++) used.push_back(dis[i]);
    sort(used.begin(), used.end());
    cout << used[n - k + 1] << "\n";

    return 0;
}