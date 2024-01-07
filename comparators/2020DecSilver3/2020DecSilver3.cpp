#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("2.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n; cin >> n;
    vector<pi> north;
    vector<pi> east;
    map<pi, int> cows;
    vector<pi> order;
    set<pi> moving;
    for(int i = 0; i < n; i++){
        char d; int x, y;
        cin >> d >> x >> y;
        if(d == 'N') north.push_back({x, y});
        else east.push_back({x, y});
        order.push_back({x, y});
        moving.insert({x, y});
        cows[{x, y}] = 0;
    }
    sort(north.begin(), north.end());
    sort(east.begin(), east.end(), [](pi a, pi b){return a.second < b.second;});
    for(int i = 0; i < north.size(); i++){
        int x = north[i].first, y = north[i].second;
        for(int j = 0; j < east.size(); j++){
            int nx = east[j].first, ny = east[j].second;
            if(ny < y || nx > x || moving.find({nx, ny}) == moving.end()) continue; 
            if(ny - y > x - nx){
                cows[{nx, ny}]+=cows[{x, y}] + 1;
                break;
            }
            else if(ny - y < x - nx){
                cows[{x, y}]+=cows[{nx, ny}] +1;
                moving.erase({nx, ny});
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << cows[order[i]] << "\n";
    }

    return 0;
}