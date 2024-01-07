#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n; cin >> n;
    vector<pi> byx, byy;
    set<pi> mountains;
    vector<int> xvals;
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        byx.push_back({x, y});
        byy.push_back({x, y});
        mountains.insert({x, y});
        xvals.push_back(x);
    }
    sort(byx.begin(), byx.end()); //smallest first
    sort(xvals.begin(), xvals.end()); //smallest first
    sort(byy.begin(), byy.end(), [](pi a, pi b){return a.second > b.second;}); //highest first
    for(int i = 0; i < n; i++){
        int x = byy[i].first, y = byy[i].second;
        if(mountains.find({x, y}) == mountains.end()) continue;
        int lb = lower_bound(xvals.begin(), xvals.end(), x-y) - xvals.begin();
        int ub = upper_bound(xvals.begin(), xvals.end(), x+y) - xvals.begin();
        //cout << "x: " << x << " y: " << y << endl;
        for(int j = lb; j < min(ub, n); j++){
            int nx = byx[j].first, ny = byx[j].second;
            if(nx == x && ny == y) continue;
            if(mountains.find({nx, ny}) == mountains.end()) continue;
            //cout << "nx: " << nx << " ny: " << ny << " dif: " << y - abs(x - nx) << endl;
            if(ny <= y - abs(x - nx)) mountains.erase({nx, ny});
        }
    }
    cout << mountains.size() << "\n";

    return 0;
}