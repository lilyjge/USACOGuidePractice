#include <bits/stdc++.h>
//fix flow
using namespace std;
typedef pair<int, int> pi;
int n, m; 
vector<pair<int, pi>> adj[1001];
int path(int f){
    priority_queue<pi, vector<pi>, greater<pi>> q;
    int dis[n + 1]; fill(dis, dis + n + 1, INT_MAX);
    bool vis[n + 1] = {};
    q.push({0, 1});
    dis[1] = 0;
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue; vis[u] = true;
        for(auto e : adj[u]){
            int v = e.first, c = e.second.first, cf = e.second.second;
            if(cf >= f && dis[v] > dis[u] + c){
                dis[v] = dis[u] + c;
                q.push({dis[v], v});
            }
        }
    }
    if(vis[n]) return dis[n];
    else return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> n >> m;
    unordered_set<int> flows;
    for(int i = 0; i < m; i++){
        int a, b, c, f; 
        cin >> a >> b >> c >> f;
        adj[a].push_back({b, {c, f}});
        adj[b].push_back({a, {c, f}});
        flows.insert(f);
    }
    int ans = 0;
    for(int f : flows){
        int c = path(f);
        ans = max(ans, 1000000 * f / c);
    }
    cout << ans << "\n";

    return 0;
}