#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("4.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n; cin >> n;
    vector<pi> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i].first; 
        nums[i].second = i;
    }
    sort(nums.begin(), nums.end(), [](pi a, pi b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, nums[i].second - i);
    }
    cout << ans + 1 << "\n";

    return 0;
}