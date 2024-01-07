#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int psa[2503][2503];
int psaSum(int x1, int y1, int x2, int y2){
    return psa[x2 + 1][y2 + 1] - psa[x2 + 1][y1] - psa[x1][y2 + 1] + psa[x1][y1];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pi> pos;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        pos.push_back({x, y});
    }
    sort(pos.begin(), pos.end());
    for(int i = 0; i < n; i++) pos[i].first = i + 1;
    sort(pos.begin(), pos.end(), [](pi x, pi y){return x.second < y.second;});
    for(int i = 0; i < n; i++) pos[i].second = i + 1;
    for(int i = 0; i < n; i++) psa[pos[i].first][pos[i].second] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int xa = pos[i].first, ya = pos[i].second;
            int xb = pos[j].first, yb = pos[j].second;
            int left = psaSum(0, i, min(xa, xb) - 1, j);
            int right = psaSum(max(xa, xb) - 1, i, n - 1, j);
            ans += left * right;
        }
    }
    cout << ans + 1 << "\n";

    return 0;
}
