#include <bits/stdc++.h>
//dsu efficiently create relationships, not destroy, reverse order
//cnt number of components, each successful connectipn = -1
using namespace std;
int p[200003];

int find_set(int d){
    if(d != p[d])
        p[d] = find_set(p[d]);
    return p[d];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) p[i] = i;
    int comps = 0;
    bool ans[n + 1] = {};
    bool open[n + 1] = {};
    int order[n + 1] = {};
    for(int i = n; i >= 1; i--) cin >> order[i];
    for(int i = 1; i <= n; i++){
        comps++;
        int pu = find_set(order[i]);
        open[order[i]] = true;
        for(int v : adj[order[i]]){
            if(!open[v]) continue;
            int pv = find_set(v);
            if(pu != pv){
                p[pv] = pu;
                comps--;
            }
        }
        if(comps == 1) ans[n + 1 - i] = true;
    }
    for(int i = 1; i <= n; i++){
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}