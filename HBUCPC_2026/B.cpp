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
        //若解题数增加，更新解题数，计数ans
        if (after > now) {now = after;ans++;}
    }
    //输出ans
    cout << ans << '\n';
    return 0;
}