#include <bits/stdc++.h>
//problem comprehension?? why is it min not max
//use prim for not tle
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int p[7501];

int find_set(int d){
    if(d != p[d])
        p[d] = find_set(p[d]);
    return p[d];
}

ll willwalk(int x, int y){
    return (2019201913 * (ll)x + 2019201949 * (ll)y) % (ll)2019201997;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<pair<ll, pi>> edges;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            edges.push_back({willwalk(j, i), {j, i}});
        }
    }
    for(int i = 1; i <= n; i++) p[i] = i;
    sort(edges.begin(), edges.end());
    vector<ll> used;
    for(auto e : edges){
        int w = e.first, a = e.second.first, b = e.second.second;
        int pa = find_set(a), pb = find_set(b);
        if(pa != pb){
            p[pb] = pa;
            used.push_back(w);
        }
    }
    sort(used.begin(), used.end());
    cout << used[n - k] << "\n";

    return 0;
}