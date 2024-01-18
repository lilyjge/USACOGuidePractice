#include <bits/stdc++.h>
//somehow only passed when add MX??
using namespace std;
const int MX = 100005;
int n, m, a, b;
vector<int> adj[MX];
int p[MX];
string cows; 
int comp;
void dfs(int u){
    if(p[u]) return;
    p[u] = comp;
    for(int v : adj[u])
        if(cows[v-1] == cows[u-1])
            dfs(v);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, m; cin >> n >> m;
    cin >> cows;
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(p[i] == 0){
            comp++;
            dfs(i);
        }           
    }
    for(int i = 0; i < m; i++){
        char c; cin >> a >> b >> c;
        if(p[a] == p[b]){
            cout << (c == cows[a-1]);
        }
        else cout << 1;
    }

    return 0;
}