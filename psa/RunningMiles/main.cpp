#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int psa[n + 3] = {};
        for(int i = 1; i <= n; i++){
            cin >> psa[i];
            psa[i] += psa[i-1];
        }
    }

    return 0;
}
