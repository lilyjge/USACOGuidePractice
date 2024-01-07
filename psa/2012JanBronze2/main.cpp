#include <bits/stdc++.h>

using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int dif[n + 3] = {};
    while(k--){
        int a, b;
        cin >> a >> b;
        dif[a]++;
        dif[b+1]--;
    }
    for(int i = 1; i <= n; i++)
        dif[i] += dif[i - 1];
    vector<int> v;
    for(int i = 1; i <= n; i++){
        v.push_back(dif[i]);
    }
    sort(v.begin(), v.end());
    cout << v[n/2] << "\n";

    return 0;
}
