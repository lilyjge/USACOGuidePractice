#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n; cin >> n;
    vector<pi> posts;
    vector<int> ycoords;
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        posts.push_back({x, y});
    }
    vector<pi> yposts = posts;
    sort(posts.begin(), posts.end(), [](pi a, pi b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    sort(yposts.begin(), yposts.end(), [](pi a, pi b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    for(int i = 0; i < n; i++) ycoords.push_back(yposts[i].second);
    ll ans = 0; //for every point, pretend right angle corner, binary search iterate same x value dif ys
    for(int i = 0; i < n; i++){
        int x = posts[i].first, y = posts[i].second;
        int xlb = lower_bound(posts.begin(), posts.end(), make_pair(posts[i].first, INT_MIN)) - posts.begin();
        int ylb = lower_bound(ycoords.begin(), ycoords.end(), y) - ycoords.begin();
        ll totheight = 0, totwidth = 0;
        for(int j = xlb; j < n && posts[j].first == x; j++){
            int ny = posts[j].second;
            totheight += abs(y - ny);
        }
        for(int j = ylb; j < n && yposts[j].second == y; j++){
            int nx = yposts[j].first;
            totwidth += abs(x - nx);
        }
        ans += totheight * totwidth;
        ans %= mod;
    }
    cout << ans << "\n";

    return 0;
}