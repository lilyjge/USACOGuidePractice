#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("10.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n; cin >> n;
    vector<pi> cows;
    int maxx = 0, minx = INT_MAX, maxy = 0, miny = INT_MAX;
    vector<pi> fordi(n), backdi(n); 
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        cows.push_back({x, y});
        maxx = max(x, maxx); minx = min(minx, x);
        maxy = max(y, maxy); miny = min(miny, y);
    }
    sort(cows.begin(), cows.end(), [](pi a, pi b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    ll area = (ll)(maxx - minx) * (maxy - miny); ll ans = area;
    fordi[0] = {cows[0].second, cows[0].second};
    for(int i = 1; i < n; i++){
        int ny = cows[i].second;
        int osy = fordi[i-1].first, oby = fordi[i-1].second;
        fordi[i].first = min(osy, ny);
        fordi[i].second = max(oby, ny);
    }
    backdi[n-1] = {cows[n-1].second, cows[n-1].second};
    for(int i =n-2; i >=0; i--){
        int ny = cows[i].second;
        int osy = backdi[i+1].first, oby = backdi[i+1].second;
        backdi[i].first = min(osy, ny);
        backdi[i].second = max(oby, ny);
    }
    for(int i = 0; i < n - 1; i++){
        if(cows[i].first == cows[i+1].first) continue;
        ll left = (ll)(cows[i].first - cows[0].first) * (fordi[i].second - fordi[i].first);
        ll right = (ll)(cows[n-1].first - cows[i + 1].first) * (backdi[i + 1].second - backdi[i + 1].first);
        ans = min(ans, left + right);
    }
    ans = min(ans, (ll)(cows[n-2].first - cows[0].first) * (fordi[n-2].second -fordi[n-2].first));
    sort(cows.begin(), cows.end(), [](pi a, pi b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;});
    fordi[0] = {cows[0].first, cows[0].first};
    for(int i = 1; i < n; i++){
        int nx = cows[i].first;
        int osx = fordi[i-1].first, obx = fordi[i-1].second;
        fordi[i].first = min(osx, nx);
        fordi[i].second = max(obx, nx);
    }
    backdi[n-1] = {cows[n-1].second, cows[n-1].second};
    for(int i =n-2; i >=0; i--){
        int nx = cows[i].first;
        int osx = backdi[i+1].first, obx = backdi[i+1].second;
        backdi[i].first = min(osx, nx);
        backdi[i].second = max(obx, nx);
    }
    for(int i = 0; i < n - 1; i++){
        if(cows[i].second == cows[i+1].second) continue;
        ll top = (ll)(cows[i].second - cows[0].second) * (fordi[i].second - fordi[i].first);
        ll bot = (ll)(cows[n-1].second - cows[i + 1].second) * (backdi[i + 1].second - backdi[i + 1].first);
        ans = min(ans, top + bot);
    }
    ans = min(ans, (ll)(cows[n-2].second - cows[0].second) * (fordi[n-2].second -fordi[n-2].first));
    cout << area - ans << "\n";
    //cout << "area: " << area << endl;

    return 0;
}