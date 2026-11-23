#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> num;
    for (int i = 0; i < 10; i++) {
        cout << setfill('0');
        cout << setw(4) << i * 1111 << endl;
        int a, b;
        cin >> a >> b;
        if (a == 4) return 0;
        if (a == 0) continue;
        for (int j = 0; j < a; j++){
            num.push_back(i);
        }
    }
    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            for(int c = 0; c < 4; c++){
                for(int d = 0; d < 4; d++){
                    cout << num[a] << num[b] << num[c] << num[d] << endl;
                    int A, B;
                    cin >> A >> B;
                    if (A == 4)return 0;
                }
            }
        }
    }
}