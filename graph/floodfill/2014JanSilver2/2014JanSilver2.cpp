#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
const int MM = 503;
int n, m;
int grid[MM][MM];
bool vis[MM][MM];
vector<pi> points;
bool check(int d){
    memset(vis, 0, sizeof(vis));
    queue<pi> q;
    q.push(points[0]);
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vis[points[0].first][points[0].second] = true;
    while(!q.empty()){
        pi u = q.front(); q.pop();
        int r = u.first, c = u.second;
        for(int i = 0; i < 4; i++){
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] || abs(grid[r][c] - grid[nr][nc]) > d) continue;
            vis[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    for(pi e : points){
        if(!vis[e.first][e.second]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> n >> m;
    int big = 0, smol = INT_MAX;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            cin >> grid[r][c];
            big = max(big, grid[r][c]);
            smol = min(smol, grid[r][c]);
        }
    }
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            int x;
            cin >> x;
            if(x == 1) points.push_back({r, c});
        }
    }
    int high = big - smol;
    int low = 0;
    int ans = high;
    while(low <= high){
        int mid = (low + high)/2;
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans << "\n";


    return 0;
}