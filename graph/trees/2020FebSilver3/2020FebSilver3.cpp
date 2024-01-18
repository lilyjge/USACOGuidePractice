#include <bits/stdc++.h>
//algorithm is easy bipartition (but unfamiliar to me), had to read solution
//just have to figure out how to think of it that way, every pair can work 
using namespace std;
const int MX = 2503;
vector<int> adj[MX];
int t[2503];
int n, n1, n2, sum1, sum2;

void dfs(int cur, int colour, int prev){
    if(colour == 0){
        n1++;
        sum1 += t[cur];
    }
    else{
        n2++;
        sum2 += t[cur];
    }
    for(int v : adj[cur])
        if(v != prev) dfs(v, 1 - colour, cur);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, -1);
    if((sum1 % 12) == (sum2 % 12)) cout << n << "\n";
    else if((sum1 + 1) % 12 == (sum2 % 12)) cout << n2 << "\n";
    else if(sum1 % 12 == (sum2 + 1) % 12) cout << n1 << "\n";
    else cout << 0 << "\n";

    return 0;
}