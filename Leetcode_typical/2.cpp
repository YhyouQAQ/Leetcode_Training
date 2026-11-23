#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v = 0, ListNode* nxt = nullptr) : val(v), next(nxt) {}
};
ListNode* buildList(const vector<int>& arr) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int v : arr) {
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    return dummy->next;
}
int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(n);
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    ListNode* l1 = buildList(a);
    ListNode* l2 = buildList(b);

    vector<int> out;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry > 0){
        int x = l1 != nullptr ? l1->val : 0;
        int y = l2 != nullptr ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        out.push_back(sum % 10);
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }
    for (size_t i = 0; i < out.size(); i++) {
        if (i > 0) cout << " ";
        cout << out[i];

    }
    cout << "\n";
    return 0;
}