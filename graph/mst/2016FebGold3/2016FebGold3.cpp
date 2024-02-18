#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int a, b, n, m; 
int p[4004002];

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

    cin >> a >> b >> n >> m;
    int horizontals[m + 2] = {}, verticals[n + 2] = {};
    for(int i = 1; i <= n; i++) cin >> verticals[i];
    for(int i = 1; i <= m; i++) cin >> horizontals[i];
    verticals[n + 1] = a; horizontals[m + 1] = b;
    sort(horizontals, horizontals + m + 2);
    sort(verticals, verticals + n + 2);
    vector<pair<int, pi>> edges;
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= m + 1; j++){
            int u = i + (j - 1) * (n + 1);
            if(i <= n){
                int v1 = i + 1 + (j - 1) * (n + 1);
                edges.push_back({horizontals[j] - horizontals[j-1], {u, v1}});
            }
            if(j <= m){
                int v2 = i + j * (n + 1);
                edges.push_back({verticals[i] - verticals[i-1], {u, v2}});
            }
        }
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= (n + 1) * (m + 1); i++) p[i] = i;
    ll ans = 0;
    for(auto e : edges){
        int w = e.first, a = e.second.first, b = e.second.second;
        int pa = find_set(a), pb = find_set(b);
        if(pa != pb){
            p[pb] = pa;
            ans += w;
        }
    }
    cout << ans << "\n";

    return 0;
}