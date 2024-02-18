#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 1e5 + 3;
int n; 
int p[MM];

int find_set(int d){
    if(d != p[d])
        p[d] = find_set(p[d]);
    return p[d];
}

ll dis(int x1, int x2, int y1, int y2){
    return pow((ll)x1 - x2, 2) + pow((ll)y1 - y2, 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("1.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    cin >> n;
    vector<pair<ll, pi>> edges;
    map<pi, int> idx;
    unordered_map<int, vector<int>> coords;
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        coords[y].push_back(x);
        idx[{x, y}] = i;
        p[i] = i;
    }
    for(auto e : coords){
        int y = e.first; vector<int> xs = e.second;
        for(int i = 0; i < xs.size(); i++){
            int x = xs[i];
            for(int j = 0; j < i; j++){
                int nx = xs[j];
                edges.push_back({dis(x, nx, y, y), {idx[{x, y}], idx[{nx, y}]}});
            }
            if(y + 1 <= 10){
                for(int j = 0; j < coords[y + 1].size(); j++){
                    int nx = coords[y + 1][j];
                    edges.push_back({dis(x, nx, y, y + 1), {idx[{x, y}], idx[{nx, y + 1}]}});
                }
            }
            if(y - 1 >= 0){
                for(int j = 0; j < coords[y - 1].size(); j++){
                    int nx = coords[y - 1][j];
                    edges.push_back({dis(x, nx, y, y - 1), {idx[{x, y}], idx[{nx, y - 1}]}});
                }
            }
        }
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for(auto e : edges){
        ll w = e.first; int a = e.second.first, b = e.second.second;
        int pa = find_set(a), pb = find_set(b);
        if(pa != pb){
            p[pb] = pa;
            ans += w;
        }
    }
    cout << ans << "\n";

    return 0;
}