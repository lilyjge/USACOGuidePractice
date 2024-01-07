#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int n, q;
    fin >> n >> q;
    int psa[n + 1][4];
    memset(psa, 0, sizeof(psa));
    for(int i = 1; i <= n; i++){
        int cow; fin >> cow;
        psa[i][1] += psa[i-1][1];
        psa[i][2] += psa[i-1][2];
        psa[i][3] += psa[i-1][3];
        psa[i][cow]++;
    }
    while(q--){
        int a, b;
        fin >> a >> b;
        for(int i = 1; i <= 3; i++){
            fout << psa[b][i] - psa[a -1][i];
            if(i != 3) fout << " ";
        }
        if(q != 0) fout << "\n";
    }

    return 0;
}
