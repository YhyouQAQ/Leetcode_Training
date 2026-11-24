#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int left = 0;
    int best = 0;
    int n = s.size();
    unordered_map<char,int> last;
    //用char访问int
    //(find char it->second int)
    //在char有find方法
    for (int right = 0; right < n; right++){
        char ch = s[right];
        auto it = last.find(ch);
        if (it != last.end() && it->second >= left){
            left = it->second + 1;
        }
        best = max(best,right - left + 1);
        last[ch] = right;
    }
    cout << best << '\n';
    return 0;
}