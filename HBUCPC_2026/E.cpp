#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    //check function
    //检查传入值t是否为完全平方数，返回bool值
    auto check = [](__int128 t) -> bool {
        if (t < 0) {return false;}
        if (t == 0) {return true;}
        ll lo = 1, hi = t;
        while (lo <= hi) {
            ll i = lo + (hi - lo) / 2;
            __int128 sq = (__int128) i * i;
            if (sq == t){return true;}
            else if (sq < t){lo = i + 1;}
            else {hi = i - 1;}
        }
        return false;
    };
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        int j = i + 1;
        while (j < n) {
            //check if it is
            if(check((__int128) a[i] * a[j])) {cout << i+1 << ' ' << j+1 << '\n';return 0;}
            j++;
        }
    }
    cout << -1 << '\n';
}