#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int n, m;
vector<pi> on[103][103];
bool vis[103][103];
bool lit[103][103];
bool done[103][103];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, a, b; 
        cin >> x >> y >> a >> b;
        on[x][y].push_back({a, b});
    }
    queue<pi> q;
    q.push({1, 1});
    lit[1][1] = true;
    int ans = 1;
    while(!q.empty()){
        queue<pi> tq = q, nq;
        while(!tq.empty()){
            int x = tq.front().first, y = tq.front().second;
            tq.pop();
            if(vis[x][y]) continue;
            vis[x][y] = true;
            for(pi e : on[x][y]){
                int a = e.first, b = e.second;
                if(!lit[a][b]){
                    lit[a][b] = true;
                    ans++;
                }
            }
        }
        tq = q; tq.push({1, 1});
        memset(done, 0, sizeof(done));
        done[1][1] = true;
        while(!tq.empty()){
            int x = tq.front().first, y = tq.front().second;
            tq.pop();
            for(int i = 0; i < 4; i++){
                int nr = x + dir[i][0], nc = y + dir[i][1];
                if(nr < 1 || nr > n || nc < 1 || nc > n || done[nr][nc] || !lit[nr][nc]) continue;
                done[nr][nc] = true;
                if(!vis[nr][nc])nq.push({nr, nc});
                tq.push({nr, nc});
            }
        }
        q = nq;
    }
    cout << ans << "\n";

    return 0;
}