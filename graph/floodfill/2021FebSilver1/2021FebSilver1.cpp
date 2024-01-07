#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int n; 
bool cow[3003][2003];
bool vis[3003][3003];
set<pi> added;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("7.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> n;
    for(int t = 0; t < n; t++){
        int x, y; cin >> x >> y;
        x+=1000; y+=1000;
        cow[x][y] = true;
        if(added.find({x, y}) != added.end()){
            added.erase({x, y});
            cout << added.size() << "\n";
            continue;
        }
        queue<pi> q;
        q.push({x, y});
        for(int k = 0; k < 4; k++){
            int nr = x + dir[k][0], nc = y + dir[k][1];
            if(nr < 0 || nr > 3002 || nc < 0 || nc > 3002) continue;
            vis[nr][nc] = false;
        }
        vis[x][y] = true;
        while(!q.empty()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            int notadj = 0, ar, ac;
            for(int k = 0; k < 4; k++){
                int nr = i + dir[k][0], nc = j + dir[k][1];
                if(nr < 0 || nr > 3002 || nc < 0 || nc > 3002){
                    notadj++;
                    continue;
                }
                if(!cow[nr][nc]){
                    notadj++;
                    ar = nr; 
                    ac = nc;
                    continue;
                }
                if(!vis[nr][nc]){
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            if(notadj == 1){
                //cout << "round " << t << " from cow at " << i-1 << " " << j-1 << " adding " << ar-1 << " " << ac-1 << endl;
                cow[ar][ac] = true;
                added.insert({ar, ac});
                vis[ar][ac] = true;
                for(int k = 0; k < 4; k++){
                    int nr = ar + dir[k][0], nc = ac + dir[k][1];
                    if(nr < 0 || nr > 3002 || nc < 0 || nc > 3002 || nr == i && nc == j) continue;
                    vis[nr][nc] = false;
                }
                q.push({ar, ac});
            }
        }
        cout << added.size() << "\n";
    }

    return 0;
}