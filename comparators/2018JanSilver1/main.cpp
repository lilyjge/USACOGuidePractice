#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("lifeguards.in");
    int n; fin >> n;
    vector<pi> times;
    for(int i = 0; i < n; i++){
        int a, b; fin >> a >> b;
        times.push_back({a, b});
    }
    sort(times.begin(), times.end());
    int low = 0, high = 0, time = 0, ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int nl = times[i].first, nh = times[i].second;
        if(nh > high) time += nh - max(high, nl);
        low = nl;
        high = max(high, nh);
    }
    low = 0; high = 0;
    for(int i = 0; i < n - 1; i++){
        int nl = times[i].first, nh = times[i].second;
        int nnl = times[i + 1].first, nnh = times[i + 1].second;
        ans = min(ans, max(0, min(nnl, nh) - max(nl, high)));
        high = max(nh, high);
    }
    int nl = times[n-1].first, nh = times[n-1].second;
    ans = min(ans, max(high, nh) - max(low, nl));
    //cout << "t: " << time << " ans: " << ans << endl;
    ofstream fout("lifeguards.out");
    fout << time - ans << "\n";

    return 0;
}
