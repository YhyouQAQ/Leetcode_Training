#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    int now = 0;
    for (int i = 0; i < n; i++){
        int after;
        cin >> after;
        if (after > now) {now = after;ans++;}
    }
    cout << ans << '\n';
    return 0;
}