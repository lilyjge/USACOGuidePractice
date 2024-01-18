#include <bits/stdc++.h>

using namespace std;
int n;
string a, b;
int numgreats, numkids;
unordered_map<string, string> mother; //mother[i] = name of the i's cow's mother
unordered_map<string, vector<string>> children; //children[x] is all of x's children
unordered_set<string> vis;
void dfs(string curcow){
    if(vis.find(curcow) != vis.end() || vis.find(b) != vis.end()) return;
    vis.insert(curcow);
    if(curcow == b) return;
    if(mother.find(curcow) != mother.end()){
        numgreats++; dfs(mother[curcow]); 
        if(vis.find(b) != vis.end()) return;
        numgreats--;
    }
    if(children.find(curcow) == children.end()) return;
    numkids++;
    for(string v : children[curcow])
        dfs(v);
    if(vis.find(b) != vis.end()) return;
    numkids--;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("1.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> n; cin >> a >> b;
    for(int i = 0; i < n; i++){
        string x, y;
        cin >> x >> y;
        mother[y] = x;
        children[x].push_back(y);
    }
    if(mother[a] == mother[b]){
        cout << "SIBLINGS\n";
    }
    else{
        dfs(a);
        if(vis.find(b) == vis.end()){
            cout << "NOT RELATED\n"; return 0;
        }
        //cout << "going up " << numgreats << " going down " << numkids << endl;
        if(numgreats < numkids){ 
            string temp = a;
            a = b;
            b = temp;
            int t = numkids;
            numkids = numgreats;
            numgreats = t;
        } //'b' is always older
        if(numkids == 1){ //aunt
            cout << b << " is the ";
            while(numgreats > 2){
                cout << "great-";
                numgreats--;
            }
            cout << "aunt of " << a << "\n";
        }
        else if(numkids == 0){ //mother
            cout << b << " is the ";
            while(numgreats > 2){
                cout << "great-";
                numgreats--;
            }
            if(numgreats > 1) cout << "grand-";
            cout << "mother of " << a << "\n";
        }
        else{
            cout << "COUSINS";
        }
    }
    
    return 0;
}