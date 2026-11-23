#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> vec) {
    int ans = 0;
    for (int i = 0; i < (int)vec.size(); i++) {
        ans += vec[i];
    }
    return ans;
}
vector<int> cg(string s) {
    vector<int> ans;
    for (int i = 0; i < (int)s.size(); i++) {
        ans.push_back(int(s[i]));
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    string a;
    string b;
    cin >> a;
    cin >> b;
    auto va = cg(a);
    auto vb = cg(b);
    if (sum(va) == sum(vb)) {cout <<  "YES" << '\n';}
    else {cout << "NO" << '\n';}
    return 0;
}