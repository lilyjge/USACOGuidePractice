#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int x, y, k, m;
queue<pi> q;
int ans = 200;
bool vis[201][201];
int dis[201][201];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> x >> y >> k >> m;
    q.push({0, 0});
    vis[0][0] = true;
    while(!q.empty()){
        int a = q.front().first, b = q.front().second;
        q.pop();
        if(dis[a][b] > k) break;
        ans = min(ans, abs(a + b - m));
        if(a != x && !vis[x][b]){
            vis[x][b] = true;
            dis[x][b] = dis[a][b] + 1;
            q.push({x, b});
        }
        if(b != y && !vis[a][y]){
            vis[a][y] = true;
            dis[a][y] = dis[a][b] + 1;
            q.push({a, y});
        }
        if(a != 0 && !vis[0][b]){
            vis[0][b] = true;
            dis[0][b] = dis[a][b] + 1;
            q.push({0, b});
        }
        if(b != 0 && !vis[a][0]){
            vis[a][0] = true;
            dis[a][0] = dis[a][b] + 1;
            q.push({a, 0});
        }
        if(a != 0 && b != y){
            int nb = min(y, b + a);
            int na = max(0, a - (y - b));
            if(!vis[na][nb]){
                vis[na][nb] = true;
                dis[na][nb] = dis[a][b] + 1;
                q.push({na, nb});
            }
        }
        if(b != 0 && a != x){
            int na = min(x, a + b);
            int nb = max(0, b - (x - a));
            if(!vis[na][nb]){
                vis[na][nb] = true;
                dis[na][nb] = dis[a][b] + 1;
                q.push({na, nb});
            }
        }
    }
    cout << ans << "\n";

    return 0;
}