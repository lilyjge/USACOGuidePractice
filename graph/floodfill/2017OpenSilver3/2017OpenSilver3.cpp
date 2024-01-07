#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int n, ans = 0;
char grid[21][21];
bool vis[21][21];
int minr, maxr, minc, maxc;
unordered_map<char, int> comps;
vector<pair<pi, pi>> pcls;
char curchur;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int r, int c){
    if(r < minr || r > maxr || c < minc || c > maxc || vis[r][c] || grid[r][c] != curchur) return;
    vis[r][c] = true;
    for(int i = 0; i < 4; i++)
        dfs(r + dir[i][0], c + dir[i][1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("3.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    for(minr = 0; minr < n; minr++){
        for(minc = 0; minc < n; minc++){
            for(maxr = n-1; maxr >= minr; maxr--){
                for(maxc = n - 1; maxc >= minc; maxc--){
                    memset(vis, 0, sizeof(vis));
                    comps.clear();
                    bool flag = true;
                    for(int i = minr; i <= maxr; i++){
                        for(int j = minc; j <= maxc; j++){
                            if(!vis[i][j]){
                                curchur = grid[i][j];
                                comps[curchur]++;
                                dfs(i, j);
                            } 
                        }
                    }
                    vector<int> cnts;
                    for(auto e : comps)
                        cnts.push_back(e.second);
                    if(cnts.size() == 2 && ((cnts[0] == 1 && cnts[1] >= 2) || (cnts[0] >= 2 && cnts[1] == 1))){
                        ans++;
                        pcls.push_back({{minr, maxr}, {minc, maxc}});
                    } 
                }
            }
        }
    }
    int ansans = 0;
    for (int i = 0; i < pcls.size(); i++) {
		bool valid_pcl = true;
		for (int j = 0; j < pcls.size(); j++) {
			if (i == j) { continue;}
			int sr = pcls[j].first.first, br = pcls[j].first.second, sc = pcls[j].second.first, bc = pcls[j].second.second;
            int sr1 = pcls[i].first.first, br1 = pcls[i].first.second, sc1 = pcls[i].second.first, bc1 = pcls[i].second.second;
            if(sr1 >= sr && br1 <= br && sc1 >= sc && bc1 <= bc){
                valid_pcl = false;
                break;
            }
		}
		ansans += valid_pcl;
	}
    cout << ansans << "\n";

    return 0;
}