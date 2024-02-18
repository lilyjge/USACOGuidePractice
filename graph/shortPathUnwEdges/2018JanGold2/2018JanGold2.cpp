#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<int> adj[n + 1];
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    int dis[n + 1]; fill(dis, dis + n + 1, -1);
    q.push(k); dis[k] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dis[v] != -1) continue;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
    int dis2[n + 1]; fill(dis2, dis2 + n + 1, -1);
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 1){
            q.push(i);
            dis2[i] = 0; 
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dis2[v] != -1) continue;
            dis2[v] = dis2[u] + 1;
            q.push(v);
        }
    }
    //this works bc branch where she gets caught gets cut off, cnting how many times she gets cut off
    int ans = 0;
    bool vis[n + 1] = {};
    q.push(k);
    vis[k] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dis2[u] <= dis[u]){
            ans++;
            continue;
        }
        for(int v : adj[u]){
            if(vis[v]) continue;
            vis[v] = true;
            q.push(v);
        }
    }
    cout << ans << "\n";
             

    return 0;
}