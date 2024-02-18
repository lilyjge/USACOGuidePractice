#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int n; 
int p[2001];

int find_set(int d){
    if(d != p[d])
        p[d] = find_set(p[d]);
    return p[d];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) p[i] = i;
    vector<pair<ll, pi>> edges;
    ll ids[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> ids[i];
        for(int j = i - 1; j >= 1; j--){
            edges.push_back({ids[i] ^ ids[j], {i, j}});
        }
    }
    sort(edges.begin(), edges.end(), greater<pair<ll, pi>>());
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