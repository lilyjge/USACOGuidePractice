#include <bits/stdc++.h>
//not complete
//compressing regions into nodes to save time
using namespace std;
int n;
typedef pair<int, int> pi;
int grid[251][251];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans1 = 0, cnt = 0, ans2 = 0;
bool vis[251][251];
int id[251][251]; int curid;
int colour1, colour2 = 0;
vector<pi> region;
vector<vector<pi>> comps;
void dfs(int r, int c){
    if(r < 1 || r > n || c < 1 || c > n || vis[r][c]) return;
    vis[r][c] = true;
    region.push_back({r, c});
    id[r][c] = curid;
    cnt++;
    for(int i = 0; i < 4; i++){
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if(grid[nr][nc] == colour1 || grid[nr][nc] == colour2) dfs(nr, nc);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!vis[i][j]){
                cnt = 0;
                region.clear();
                curid = comps.size();
                colour1 = grid[i][j];
                dfs(i, j);
                ans1 = max(ans1, cnt);
                comps.push_back(region);
            }
        }
    }
    vector<vector<int>> adj(comps.size());
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i][0], nc = c + dir[i][1];
                if(nr < 1 || nr > n || nc < 1 || nc > n || grid[r][c] == grid[nr][nc]) continue;
                adj[id[r][c]].push_back(id[nr][nc]);
                adj[id[nr][nc]].push_back(id[r][c]);
            }
        }
    }
    bool vis2[comps.size()][comps.size()]; memset(vis2, 0, sizeof(vis2));
    for(int r1 = 0; r1 < comps.size(); r1++){
        for(int r2 : adj[r1]){
            //ID MEANS COLOUR HERE, inconsistent, too lazy to fix
            int id1 = grid[comps[r1][0].first][comps[r1][0].second];
            int id2 = grid[comps[r2][0].first][comps[r2][0].second];
            if(vis[id1][id2] || vis[id2][id1]) continue;
            vis[id1][id2] = true;
            vis[id2][id1] = true;
            int size = 0;
            
        }
    }

    cout << ans1 << "\n" << ans2;

    return 0;
}