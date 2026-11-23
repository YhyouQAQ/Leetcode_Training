#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int target;
    cin >> target;
    //
    unordered_map<int, int> seen;
    for (int i = 0; i < n; i++){
        int need = target - nums[i];
        auto it = seen.find(need);//auto类型在指针寻找中应用的非常普遍，主要原因是类型名太复杂了
        if (it != seen.end()){cout << it->second << ' ' << i << '\n';}
        seen[nums[i]] = i;
    }
    cout << '\n';
    return 0;
}