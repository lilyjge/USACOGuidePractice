#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int n, k, r;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool cows[101][101];
bool roads[101][101][101][101];
bool vis[101][101];
vector<int> comps;
int curcows;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> n >> k >> r;
    for(int i = 0; i < r; i++){
        int r, c, r1, c1;
        cin >> r >> c >> r1 >> c1;
        roads[r][c][r1][c1] = true;
        roads[r1][c1][r][c] = true;
    }
    for(int i = 0; i < k; i++){
        int r, c;
        cin >> r >> c;
        cows[r][c] = true;
    }
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            if(!vis[r][c]){
                curcows = 0;
                queue<pi> q;
                q.push({r, c});
                vis[r][c] = true;
                while(!q.empty()){
                    int a = q.front().first, b = q.front().second;
                    q.pop();
                    if(cows[a][b]) curcows++;
                    for(int i = 0; i < 4; i++){
                        int nr = a + dir[i][0], nc = b + dir[i][1];
                        if(nr < 1 || nr > n || nc < 1 || nc > n || vis[nr][nc] || roads[a][b][nr][nc]) continue;
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
                comps.push_back(curcows);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < comps.size(); i++)
        for(int j = i + 1; j < comps.size(); j++)
            ans += comps[i] * comps[j];
    cout << ans << "\n";

    return 0;
}