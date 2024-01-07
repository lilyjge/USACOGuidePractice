#include <bits/stdc++.h>

using namespace std;
vector<int> adj[503];
bool reachable[503][503];

void dfs(int u, int i){
    reachable[i][u] = true;
    for(int v : adj[u]) 
        if(!reachable[i][v]) dfs(v, i);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x == i) flag = false;
            if(flag) adj[i].push_back(x);
        }
    }
    for(int i = 1; i <= n; i++)
        dfs(i, i);
    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int j = 0; j < adj[i].size(); j++){
            if(reachable[adj[i][j]][i]){
                cout << adj[i][j] << "\n";
                flag = false;
                break;
            }
        }
        if(flag) cout << i << "\n";
    }

    return 0;
}