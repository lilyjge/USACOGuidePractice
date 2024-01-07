#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("div7.in");
    ofstream fout("div7.out");
    int n;
    fin >> n;
    ll psa[n + 1] = {};
    for(int i = 1; i <= n; i++){
        fin >> psa[i];
        psa[i] += psa[i - 1];
    }
    int ans = 0;
    for(int i = 1; i <= n - ans; i++){
        for(int j = i + ans; j <= n; j++){
            //cout << "sum: " << psa[j] - psa[i - 1] << endl;
            if((psa[j] - psa[i - 1]) % 7 == 0 && j - i + 1 > ans)
                ans = j - i + 1;
        }
    }
    fout << ans << "\n";

    return 0;
}
