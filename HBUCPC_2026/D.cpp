#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    // t = pd * w
    ll n, m, l;
    cin >> n >> m >> l;
    vector<ll> p(n+2);
    p[0] = 0;
    p[n+1] = l;
    for(ll i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<ll> w(n+1);
    for(ll i = 0; i < n + 1; i++) {
        cin >> w[i];
    }
    vector<ll> t(n+1);
    ll mx = 0;
    ll sum = 0;
    for(ll i = 0; i < n + 1; i++) {
        t[i] = (p[i+1] - p[i]) * w[i];
        sum += t[i];
        mx = max(t[i],mx);
    }
    auto check = [&](ll T) ->bool {
        int parts = 1;
        ll cur = 0;
        for(int i = 0; i < n + 1; i++) {
            if(t[i] > T) {return false;}
            if(cur + t[i] > T) {
                parts += 1;
                cur = t[i];
            }else {
                cur += t[i];
            }
        }
        return parts - 1 <= m;
    };
    ll hi = sum, lo = mx;
    while(hi > lo) {
        ll mid = lo + (hi - lo) / 2;
        if(check(mid)) {hi = mid;}
        else{lo = mid + 1;}
    }
    cout << hi << '\n';
    return 0;

}