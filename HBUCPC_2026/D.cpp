#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n, m, l;
    cin >> n >> m >> l;
    vector<ll> p(n+2);
    vector<ll> w(n+1);
    for (int i = 1; i <= n; i++){cin >> p[i];}
    p[0] = 0;
    p[n+1] = l;
    for (int i = 0; i < n + 1; i++){cin >> w[i];}
    vector<ll> t(n+1);
    ll sum = 0, mx = 0;
    for (int i = 0; i < n + 1; i++){
        t[i] = (p[i+1] - p[i]) * w[i];
        sum += t[i];
        mx = max(mx, t[i]);
    }
    //read
    auto check = [&](ll T) -> bool {
        int parts = 1;
        ll cur = 0;
        for (int i = 0; i < n + 1; i++) {
            if (t[i] > T) return false;   // 单个关卡无法被切开
            if (cur + t[i] <= T) {
                cur += t[i];
            } else {
                parts++;
                cur = t[i];
            }
        }
        return parts - 1 <= m;            // 需要 parts-1 个存档点
    };
    //check lambda
    ll lo = mx, hi = sum;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    //min try
    cout << lo << '\n';
    return 0;
    //c out
}