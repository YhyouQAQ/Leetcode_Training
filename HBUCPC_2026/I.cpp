#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    int mx = 0;
    int cur = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        cur -= x;
        cur += y;
        mx = max(mx, cur);
    }
    cout << mx << '\n';
    return 0;
}