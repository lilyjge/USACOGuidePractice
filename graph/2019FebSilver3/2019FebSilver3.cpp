#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> notadj[n + 1];
    vector<int> adj[n + 1];
    for(int i = 0, a, b; i < m; i++){
        char c; 
        cin >> c >> a >> b;
        if(c == 'S'){
            adj[a].push_back(b);
            adj[b].push_back(a);
        } 
        else{
            notadj[a].push_back(b);
            notadj[b].push_back(a);
        }
    }
    int colours[n + 1] = {};
    queue<pi> q;
    bool good = true;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!colours[i]){
            ans++;
            q.push({i, 1});
            while(!q.empty()){
                int u = q.front().first, c = q.front().second; q.pop();
                colours[u] = c;
                for(int v : adj[u]){
                    if(colours[v] == 3 - c) good = false;
                    if(colours[v] == 0) q.push({v, c});
                }
                for(int v : notadj[u]){
                    if(colours[v] == c) good = false;
                    if(colours[v] == 0) q.push({v, 3 - c});
                }
                if(!good) break;
            }
        }
        if(!good) break;
    }
    if(!good) cout << 0 << "\n";
    else{
        cout << 1;
        for(int i = 0; i < ans; i++) cout << 0;
        cout << "\n";
    }

    return 0;
}