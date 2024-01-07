#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int n;
bool grid[4006][4006];
bool vis[4006][4006];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);

    cin >> n;
    int r = 2002, c = 2002;
    grid[r][c] = true;
    map<char, pair<int, int>> dir1{
	    {'N', {-1, 0}}, {'S', {1, 0}}, {'E', {0, 1}}, {'W', {0, -1}}};
    for(int i = 0; i < n; i++){
        char d; cin >> d;
        grid[r + dir1[d].first][c + dir1[d].second] = true;
        grid[r + 2 * dir1[d].first][c + 2 * dir1[d].second] = true;
        r += 2 * dir1[d].first;
        c += 2 * dir1[d].second;
    }
    int ans = 0;
    for(int i = 0; i <= 4003; i++){
        for(int j = 0; j <= 4003; j++){
            if(!vis[i][j] && !grid[i][j]){
                queue<pi> q;
                vis[i][j] = true;
                q.push({i, j});
                while(!q.empty()){
                    r = q.front().first, c = q.front().second; q.pop();
                    for(int k = 0; k < 4; k++){
                        int nr = r + dir[k][0], nc = c + dir[k][1];
                        if(nr < 0 || nr > 4003 || nc < 0 || nc > 4003 || vis[nr][nc] || grid[nr][nc]) continue;
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
                ans++;
            }
        }
    }
    cout << ans - 1 << "\n";

    return 0;
}