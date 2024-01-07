#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int n, m, r;
    cin >> n >> m >> r;
    vector<ll> cows(n);
    for(int i = 0; i < n; i++) cin >> cows[i];
    sort(cows.begin(), cows.end());
    vector<pi> stores(m);
    for(int i = 0; i < m; i++) cin >> stores[i].second >> stores[i].first;
    sort(stores.begin(), stores.end(), greater<pair<ll, ll>>());
    vector<ll> rent(r);
    for(int i = 0; i < r; i++) cin >> rent[i];
    sort(rent.begin(), rent.end(), greater<ll>());
    ll ans = 0, rm = 0, mm = 0, milk = 0;
    for(int i = 0; i < min(r, n); i++) rm += rent[i];
    for(int i = n - 1; i >= r; i--) milk += cows[i];
    ll milkused = 0; int index = 0;
    for(; index < m; index++){
        int i = index;
        ll price = stores[i].first, gallons = stores[i].second;
        ll mh = min(gallons, milk - milkused);
        milkused += mh;
        mm += price * mh;
        stores[i].second -= mh;
        if(milkused >= milk) break;
    }
    ans += rm + mm;
    for(int i = min(r - 1, n-1); i >= 0; i--){
        rm -= rent[i];
        milk += cows[i];
        //cout << "m: " << milk << endl;
        for(; index < m; index++){
            int j = index;
            ll price = stores[j].first, gallons = stores[j].second;
            ll mh = min(gallons, milk - milkused);
            //cout << "using " << mh << " gallons at " << price << endl;
            milkused += mh;
            mm += price * mh;
            stores[j].second -= mh;
            if(milkused >= milk) break;
        }
        //cout << "rent money: " << rm << " milk money: " << mm << endl;
        ans = max(ans, rm + mm);
    }
    cout << ans << "\n";

    return 0;
}
