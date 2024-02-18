#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    int skills[n + 1] = {};
    for(int i = 1; i <= n; i++) cin >> skills[i];
    int dp[n + 1] = {}; //best score with i cows 
    for(int i = 1; i <= n; i++){
        int biggest = 0;
        for(int j = i; j >= max(1, i - k + 1); j--){
            biggest = max(biggest, skills[j]);
            dp[i] = max(dp[i], dp[j - 1] + biggest * (i - j + 1));
            //cout << "cow " << i << " score " << dp[i] << endl;
        }
    }
    cout << dp[n] << "\n";

    return 0;
}