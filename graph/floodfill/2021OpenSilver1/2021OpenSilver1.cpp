#include <bits/stdc++.h>
//SKIPPING
//werid indexing thing, 3x3 grid turned into numbers, 3^9 states, conversion from each grid to number
using namespace std;
typedef pair<int, int> pi;
int n;
int ans = 0;
char grid[26][26];
pi coords[26][26];
bool vis[26][26];

//void dfs(int r, int c, )

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> n;
    int br, bc; 
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= n; c++){
            char a, b, d;
            cin >> a >> b >> d;
            if(a == 'B'){
                br = r; bc = c;
                continue;
            }
            grid[r][c] = a;
            if(a == 'O' || a == 'M') coords[r][c] = {b, d};
        }
    }
    //dfs(br, bc);
    cout << ans << "\n";

    return 0;
}