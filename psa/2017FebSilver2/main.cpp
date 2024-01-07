#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");
    int n, k, b;
    fin >> n >> k >> b;
    int broken[b + 1] = {};
    for(int i = 1; i <= b; i++)
        fin >> broken[i];
    sort(broken, broken + b + 1);
    int ans = b;
    for(int i = 1; i <= b; i++){
        if(broken[i] - broken[i - 1] - 1 >= k || n - broken[b] >= k){
            ans = 0; break;
        }
        for(int j = i; j <= b; j++){
            int consec;
            if(j < b) consec = broken[j + 1] - 1 - broken[i - 1];
            else consec = n - broken[i - 1];
            if(consec >= k){
                ans = min(ans, j - i + 1);
                break;
            }
        }
    }
    fout << ans << "\n";

    return 0;
}
