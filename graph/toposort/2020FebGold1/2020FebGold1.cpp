#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;
    vector<pi> adj[n + 1];
    int indegree[n + 1] = {};
    for(int i = 1; i <= n; i++){
        int s; cin >> s;
        adj[0].push_back({i, s});
        indegree[i]++;
    }
    for(int i = 0; i < c; i++){
        int a, b, x; cin >> a >> b >> x;
        adj[a].push_back({b, x});
        indegree[b]++;
    }
    int dis[n + 1] = {};
    queue<int> q;
    q.push(0);
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0) 
            q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(pi v : adj[u]){
            int e = v.first, w = v.second;
            indegree[e]--;
            if(indegree[e] == 0)
                q.push(e);
            dis[e] = max(dis[e], dis[u] + w);
        }
    }
    for(int i = 1; i <= n; i++) cout << dis[i] << "\n";

    return 0;
}