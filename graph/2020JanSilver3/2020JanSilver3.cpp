#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int p[100003];
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

    int n, m;
    cin >> n >> m;
    vector<pair<int, pi>> edges;
    vector<int> cows(n + 1);
    for(int i = 1; i <= n; i++) cin >> cows[i];
    for(int i = 0, a, b, w; i < m; i++){
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    sort(edges.begin(), edges.end(), greater<pair<int, pi>>());
    for(int i = 1; i <= n; i++) p[i] = i;
    int w = -1;
    for(int i = 1; i <= n; i++){
        while(find_set(i) != find_set(cows[i])){
            w++;
            int pa = find_set(edges[w].second.first);
            int pb = find_set(edges[w].second.second);
            p[pa] = pb;
        }
    }
    if(w == -1) cout << -1 << "\n";
    else cout << edges[w].first << "\n";

    return 0;
}