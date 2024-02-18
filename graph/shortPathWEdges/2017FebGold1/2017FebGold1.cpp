#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, t; cin >> n >> t;
    int grass[n + 1][n + 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> grass[i][j];
    int dis[n + 1][n + 1][4]; memset(dis, 0x3f, sizeof(dis));
    bool vis[n + 1][n + 1][4]; memset(vis, 0, sizeof(vis));
    dis[1][1][3] = 0;
    priority_queue<pair<int, pair<pi, int>>, vector<pair<int, pair<pi, int>>>, greater<pair<int, pair<pi, int>>>> q; //cost, i, j, num
    q.push({0, {{1, 1}, 3}});
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!q.empty()){
        auto e = q.top().second; q.pop();
        int i = e.first.first, j = e.first.second, num = e.second, nn;
        if(vis[i][j][num]) continue; vis[i][j][num] = true;
        if(num == 3) nn = 1;
        else nn = num+1;
        for(int k = 0; k < 4; k++){
            int nr = i + dir[k][0], nc = j + dir[k][1];
            if(!(nr >= 1 && nr <= n && nc <= n && nc >= 1)) continue;
            int w = t; if(nn == 3) w += grass[nr][nc];
            if(dis[nr][nc][nn] > dis[i][j][num] + w){
                dis[nr][nc][nn] = dis[i][j][num] + w;
                q.push({dis[nr][nc][nn], {{nr, nc}, nn}});
            }
        }
    }
    cout << min(dis[n][n][1], min(dis[n][n][2], dis[n][n][3])) << "\n";

    return 0;
}