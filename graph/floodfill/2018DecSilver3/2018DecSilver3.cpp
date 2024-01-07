#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("2.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int grid[n][10];
    for(int r = 0; r < n; r++){
        for(int c = 0; c < 10; c++){
            char p; cin >> p;
            grid[r][c] = p - '0';
        }
    }
    int comps = 0;
    do{
        comps = 0;
        for(int c = 0; c < 10; c++){
            int index = n-1;
            int temp[n] = {};
            for(int r = n-1; r >= 0; r--){
                if(grid[r][c] == 0) continue;
                temp[index] = grid[r][c];
                index--;
            }
            for(int r = n-1; r >= 0; r--) grid[r][c] = temp[r];
        }
        /*
        cout << "post falling\n";
        for(int r = 0; r < n; r++){
        for(int c = 0; c < 10; c++){
            cout << grid[r][c];
        }
        cout << "\n";
    }*/
        bool vis[n][10]; memset(vis, 0, sizeof(vis));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < 10; c++){
                if(!vis[r][c] && grid[r][c] != 0){
                    int cur = grid[r][c];
                    queue<pi> q;
                    q.push({r, c});
                    vis[r][c] = true;
                    int cnt = 1;
                    while(!q.empty()){
                        int i = q.front().first, j = q.front().second;
                        q.pop();
                        for(int t = 0; t < 4; t++){
                            int nr = i + dir[t][0], nc = j + dir[t][1];
                            if(nr < 0 || nr >= n || nc < 0 || nc >= 10 || vis[nr][nc] || grid[nr][nc] != cur) continue;
                            vis[nr][nc] = true;
                            cnt++;
                            q.push({nr, nc});
                        }
                    }
                    if(cnt < k) continue;
                    q.push({r, c});
                    grid[r][c] = 0;
                    while(!q.empty()){
                        int i = q.front().first, j = q.front().second;
                        q.pop();
                        for(int t = 0; t < 4; t++){
                            int nr = i + dir[t][0], nc = j + dir[t][1];
                            if(nr < 0 || nr >= n || nc < 0 || nc >= 10 || grid[nr][nc] != cur) continue;
                            grid[nr][nc] = 0;
                            q.push({nr, nc});
                        }
                    }
                    comps++;
                    
                }
            }
        }/*
        cout << "post removal\n";
        for(int r = 0; r < n; r++){
        for(int c = 0; c < 10; c++){
            cout << grid[r][c];
        }
        cout << "\n";
    }*/
    }while(comps > 0);
    for(int r = 0; r < n; r++){
        for(int c = 0; c < 10; c++){
            cout << grid[r][c];
        }
        cout << "\n";
    }

    return 0;
}