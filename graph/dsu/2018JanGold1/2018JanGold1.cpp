#include <bits/stdc++.h>
//sorting queries, keeping track of component sizes
using namespace std;
typedef pair<int, int> pi;
int p[100003], s[100003];

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

    int n, q; cin >> n >> q;
    vector<pair<int, pi>> edges;
    for(int i = 0; i < n - 1; i++){
        int p, q, r; cin >> p >> q >> r;
        edges.push_back({r, {p, q}});
    }
    sort(edges.begin(), edges.end(), [](pair<int, pi> x, pair<int, pi> y){
        return x.first > y.first;
    });
    vector<pair<int, pi>> queries; 
    for(int i = 1; i <= q; i++){
        int k, v; cin >> k >> v;
        queries.push_back({i, {v, k}});
    }
    sort(queries.begin(), queries.end(), [](pair<int, pi> x, pair<int, pi> y){
        return x.second.second > y.second.second;
    });
    int sol[q + 1] = {};
    int idx = 0;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        s[i] = 1;
    }
    for(int i = 0; i < q; i++){
        int v = queries[i].second.first, k = queries[i].second.second;
        while(idx < edges.size() && edges[idx].first >= k){
            int a = edges[idx].second.first, b = edges[idx].second.second;
            int pa = find_set(a), pb = find_set(b);
            if(pa != pb){
                p[pb] = pa;
                s[pa] += s[pb];
            }
            idx++;
        }
        sol[queries[i].first] = s[find_set(v)] - 1;
    }
    for(int i = 1; i <= q; i++) cout << sol[i] << "\n";

    return 0;
}