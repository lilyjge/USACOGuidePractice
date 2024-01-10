#include <bits/stdc++.h>
//interesting problem, gave up and read solution
using namespace std;
typedef pair<int, int> pi;
int snow[251], depth[251], dist[251]; 
bool vis[251][251]; //boot, dis
int ans;
int n, b;
void dfs(int boot, int dis){
    if(vis[boot][dis]) return;
    vis[boot][dis] = true;
    if(dis == n){
        ans = min(boot - 1, ans);
        return;
    }
    for(int i = dis + 1; i <= n && i - dis <= dist[boot]; i++)
        if(depth[boot] >= snow[i]) dfs(boot, i);
    for(int i = boot + 1; i <= b; i++)
        if(depth[i] >= snow[dis]) dfs(i, dis);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> n >> b;
    ans = n;
    for(int i = 1; i <= n; i++) cin >> snow[i];
    for(int i = 1; i <= b; i++){
        cin >> depth[i]; cin >> dist[i];
    }
        
    dfs(0, 0);
    cout << ans << "\n";

    return 0;
}