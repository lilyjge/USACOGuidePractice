#include <bits/stdc++.h>

using namespace std;
int MM = 1003;
int maxarea = 0, area = 0, minperim = INT_MAX;
bool vis[1003][1003];
char grid[1003][1003];
int n;

int dfs(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == '.') return 1;
    if(vis[r][c]) return 0;
    vis[r][c] = true;
    area++;
    return dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c + 1) + dfs(r, c - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> n;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            cin >> grid[r][c];
        }
    }
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(grid[r][c] == '#' && !vis[r][c]){
                area = 0;
                int newperim = dfs(r, c);
                if(area > maxarea){
                    maxarea = area;
                    minperim = newperim;
                }                
                else if(area == maxarea) minperim = min(minperim, newperim);
            }
        }
    }
    cout << maxarea << " " << minperim << "\n";

    return 0;
}