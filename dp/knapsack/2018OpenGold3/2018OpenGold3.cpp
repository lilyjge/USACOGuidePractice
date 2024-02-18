#include <bits/stdc++.h>
//binary search, come back later
using namespace std;
typedef pair<int, int> pi;
int n, w; 
int weight[251], talent[251];
pi dp[251]; //optimal weight to talent with first i cows

int rto(int we, int ta){
    return 1000 * ta / we;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("2.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> n >> w;
    int tw = 0, tt = 0;
    for(int i = 1; i <= n; i++){
        cin >> weight[i] >> talent[i];
        tw += weight[i];
        tt += talent[i];
    }
    dp[n] = {tw, tt};
    int ans = rto(tw, tt);
    for(int i = n; i >= 1; i--){
        if(i < n) dp[i] = dp[i + 1];
        for(int j = i; j <= n; j++){
            int neww = dp[j].first - weight[i], newt = dp[j].second - talent[i];
            int r = rto(neww, newt);
            //cout << " i: " << i << " j: " << j << " r: " << r << endl;
            if(r > rto(dp[i].first, dp[i].second) && neww >= w)
                dp[i] = {neww, newt};
        }
        if(dp[i].first >= w) ans = max(rto(dp[i].first, dp[i].second), ans);
        cout << "i: " << i << " best w: " << dp[i].first << " b t: " << dp[i].second << endl;
    }
    cout << ans << "\n";

    return 0;
}