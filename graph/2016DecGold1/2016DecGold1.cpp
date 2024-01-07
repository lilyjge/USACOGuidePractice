#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int p[1003];

int find_set(int d){
    if(d != p[d])
        p[d] = find_set(p[d]);
    return p[d];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n; cin >> n;
    vector<pi> coords;
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        coords.push_back({x, y});
    }
    for(int i = 0; i < n; i++) p[i] = i;
    vector<pair<int, pi>> edges;
    for(int i = 0; i < n; i++){
        int x = coords[i].first, y = coords[i].second;
        for(int j = i + 1; j < n; j++){
            int nx = coords[j].first, ny = coords[j].second;
            int dis = pow(abs(ny-y), 2) + pow(abs(nx - x), 2);
            edges.push_back({dis, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for(int i = 0; i < edges.size(); i++){
        int w = edges[i].first, a = edges[i].second.first, b = edges[i].second.second;
        int pa = find_set(a), pb = find_set(b);
        if(pa == pb) continue;
        p[pa] = pb;
        ans = w;
    }
    cout << ans << "\n";

    return 0;
}