#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

double dis(int x1, int y1, int x2, int y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n; cin >> n;
    vector<pair<pi, int>> cows;
    for(int i = 0; i < n; i++){
        int x, y, p; cin >> x >> y >> p;
        cows.push_back({{x, y}, p});
    }
    vector<int> adj[n];
    for(int i = 0; i < n; i++){
        int x = cows[i].first.first, y = cows[i].first.second, p = cows[i].second;
        for(int j = 0; j < n; j++){
            int nx = cows[j].first.first, ny = cows[j].first.second;
            if(dis(x, y, nx, ny) <= p) adj[i].push_back(j);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool vis[n] = {};
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: adj[u]){
                if(vis[v]) continue;
                vis[v] = true;
                q.push(v);
            }
        }
        int g = 0;
        for(int j = 0; j < n; j++){
            if(vis[j]) g++;
        }
        ans = max(g, ans);
    }
    cout << ans << "\n";

    return 0;
}