#include <bits/stdc++.h>

using namespace std;
int b, e, p, n, m; 
vector<int> adj[40003];
vector<vector<int>> dis;
void bfs(int start, int index){
    queue<int> q;
    q.push(start);
    dis[index][start] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dis[index][v] != -1) continue;
            dis[index][v] = dis[index][u] + 1;
            q.push(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> b >> e >> p >> n >> m;
    dis.assign(3, vector<int>(n + 1, -1));
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1, 0);
    bfs(2, 1);
    bfs(n, 2);
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++)
        ans = min(ans, b * dis[0][i] + e * dis[1][i] + p * dis[2][i]);
    cout << ans << "\n";

    return 0;
}