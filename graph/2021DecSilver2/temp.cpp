#include <bits/stdc++.h>
//succesfully passed first 5 cases with dsu, tle on last 5 :(
using namespace std;
typedef long long ll;
const int MAX_N = 1e5;
int comp[MAX_N];
vector<int> adj[MAX_N];
vector<int> connected[MAX_N];
void dfs(int d, int c){
    if(comp[d] != -1) return;
    comp[d] = c;
    for(int u : adj[d]) dfs(u, c);
}

ll smalldif(int a, int b){
    int dif = MAX_N;
    for(int u : connected[a]){
        int lb = lower_bound(connected[b].begin(), connected[b].end(), u) - connected[b].begin();
        if(lb > 0) dif = min(dif, abs(connected[b][lb - 1] - u));
        if(lb < connected[b].size()) dif = min(dif, abs(connected[b][lb] - u));
    }
    return (ll)dif * dif;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("6.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int t; cin >> t;
    for(int q = 0; q < t; q++){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            adj[i].clear();
            comp[i] = -1;
            connected[i].clear();
        }
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            adj[--a].push_back(--b);
            adj[b].push_back(a);
        }
        int cur = -1;
        for(int i = 0; i < n; i++){
            if(comp[i] == -1) dfs(i, ++cur);
        } 
        for(int i = 0; i < n; i++)
            connected[comp[i]].push_back(i);
        ll ans = smalldif(comp[0], comp[n-1]);
        for(int i = 1; i < cur; i++){
            ans = min(ans, smalldif(comp[0], i) + smalldif(comp[n-1], i));
        }
        cout << ans << "\n";
    }

    return 0;
}