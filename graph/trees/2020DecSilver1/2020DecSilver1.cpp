#include <bits/stdc++.h>

using namespace std;
const int MX = 100005;
vector<int> adj[MX];
int n;
int dfs(int u, int prev){
    int sendcows = adj[u].size();
    if(prev == -1) sendcows += 1; //have to keep a cow for ourselves
    int days = 0;
    int curcows = 1;
    while(curcows < sendcows){
        curcows *= 2;
        days++;
    }
    for(int v: adj[u]){
        if(v != prev) 
            days += dfs(v, u) + 1;
    }
    return days;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfs(1, -1) << "\n";

    return 0;
}