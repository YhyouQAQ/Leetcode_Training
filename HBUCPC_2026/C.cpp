#include <bits/stdc++.h>
using namespace std;
//发现将01交换，0,1的总数都不变，可以将1转移到任何指定位置的基本操作
//因此能否通过交换将a转化到b的充要条件是：0,1的总数相等
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
//实现方法有点邪门是列表和求和，按理说直接加和统计即可
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