#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, l; cin >> n >> l;
    vector<pi> forw, back;
    for(int i = 0; i < n; i++){
        int w, x, d; cin >> w >> x >> d;
        if(d == 1) forw.push_back({x, w});
        else back.push_back({x, w});
    }
    sort(back.begin(), back.end());
    sort(forw.begin(), forw.end());
    for(int i = 0; i < back.size(); i++){
        
    }

    return 0;
}