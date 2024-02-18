#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, xl, yl, xb, yb; 
    cin >> n >> xl >> yl >> xb >> yb;
    pi pts[n + 2] = {};
    unordered_map<int, vector<int>> x;
    unordered_map<int, vector<int>> y;
    pts[0] = {xl, yl};
    pts[n + 1] = {xb, yb};
    x[xl].push_back(0); y[yl].push_back(0);
    x[xb].push_back(n + 1); y[yb].push_back(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> pts[i].first >> pts[i].second;
        x[pts[i].first].push_back(i);
        y[pts[i].second].push_back(i);
    }
    int dis[n + 2]; fill(dis, dis + n + 2, -1);
    queue<pi> q;
    q.push({0, 2}); //0 for hor, 1 for ver
    dis[0] = 0;
    while(!q.empty()){
        int u = q.front().first, dir = q.front().second;
        q.pop();
        int curx = pts[u].first, cury = pts[u].second;
        if(dir != 0){ //ver
            for(int v : y[cury]){
                if(dis[v] != -1) continue;
                dis[v] = dis[u] + 1;
                q.push({v, 0});
            }
        }
        if(dir != 1){ 
            for(int v : x[curx]){
                if(dis[v] != -1) continue;
                dis[v] = dis[u] + 1;
                q.push({v, 1});
            }
        }
    }
    if(dis[n + 1] != -1) cout << dis[n + 1] - 1 << "\n";
    else cout << -1 << "\n";

    return 0;
}