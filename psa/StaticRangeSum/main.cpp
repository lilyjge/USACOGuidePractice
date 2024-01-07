#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    ll psa[n + 1] = {};
    for(int i = 1; i <= n; i++){
        cin >> psa[i]; psa[i] += psa[i - 1];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << psa[r] - psa[l] << "\n";
    }

    return 0;
}
