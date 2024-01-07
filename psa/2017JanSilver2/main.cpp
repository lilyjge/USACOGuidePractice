#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("hps.in");
    ofstream fout("hps.out");
    int n;
    fin >> n;
    int psa[n + 1][3];
    memset(psa, 0, sizeof(psa));
    for(int i = 1; i <= n; i++){
        char g; fin >> g;
        if(g == 'H') psa[i][0]++;
        if(g == 'P') psa[i][1]++;
        if(g == 'S') psa[i][2]++;
        for(int k = 0; k <= 2; k++)
            psa[i][k] += psa[i - 1][k];
    }
    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int a = 0; a <= 2; a++)
            for(int b = 0; b <= 2; b++)
                ans = max(ans, psa[i][a] + psa[n][b] - psa[i][b]);
    }
    fout << ans << "\n";

    return 0;
}
