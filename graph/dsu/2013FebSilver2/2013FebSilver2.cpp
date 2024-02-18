#include <bits/stdc++.h>
//sort edges by cost, add until comp size big enough
using namespace std;
typedef pair<int, int> pi;
int p[250003], s[250003];

int find_set(int d){
    if(d != p[d])
        p[d] = find_set(p[d]);
    return p[d];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("3.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n; cin >> n;
    int grid[n + 1][n + 1]; 
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            cin >> grid[r][c];
        }
    }
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<pair<int, pi>> edges;
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i][0], nc = c + dir[i][1];
                if(nr >= 1 && nr <= n && nc >= 1 && nc <= n && grid[r][c] >= grid[nr][nc]){
                    edges.push_back({grid[r][c] - grid[nr][nc], {(r-1) * n + c, (nr-1) * n + nc}});
                }
            }
        }
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= n * n; i++){
        p[i] = i;
        s[i] = 1;
    }
    int target = n * n;
    if(n % 2 == 0) target /= 2;
    else target = target / 2 + 1;
    for(int i = 0; i < edges.size(); i++){
        int cost = edges[i].first, a = edges[i].second.first, b = edges[i].second.second;
        int pa = find_set(a), pb = find_set(b);
        if(pa != pb){
            p[pb] = pa;
            s[pa] += s[pb];
        }
        if(max(s[pa], s[pb]) >= target){
            cout << cost << "\n"; 
            break;
        }
    }
    return 0;
}