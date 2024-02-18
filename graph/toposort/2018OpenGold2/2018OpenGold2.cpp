#include <bits/stdc++.h>
//storing edges, new adj list every time, binary search
using namespace std;
typedef pair<int, int> pi;
int n, m; 
vector<pi> edges[50001];
vector<int> good;
bool check(int mi){
    vector<int> adj[n + 1];
    int indegree[n + 1] = {};
    for(int i = 1; i <= mi; i++){
        for(pi e : edges[i]){
            adj[e.first].push_back(e.second);
            indegree[e.second]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0)
            q.push(i);
    vector<int> order;
    while(!q.empty()){
        int u = q.top(); q.pop();
        order.push_back(u);
        for(int v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }
    if(order.size() == n){
        good = order;
        return true;
    }
    else return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> n >> m;
    int a, b;
    for(int i = 1; i <= m; i++){
        int mi; cin >> mi; a = 0;
        for(int j = 0; j < mi; j++){
            cin >> b;
            if(a == 0){
                a = b;
                continue;
            }
            edges[i].push_back({a, b});
            a = b;
        }
    }
    int lo = 0, hi = m, ans = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    for(int i = 0; i < good.size(); i++){
        cout << good[i];
        if(i != good.size() - 1) cout << " ";
    } 

    return 0;
}