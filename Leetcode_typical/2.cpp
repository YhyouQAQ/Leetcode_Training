//注释风格：注释体写在被注释内容上方
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    //声明成员变量val和next
    int val;
    ListNode* next;
    ListNode(int v = 0,ListNode* nxt = nullptr) : val(v) ,next(nxt) {}
    //对v,nxt的参数初始化
    //初始化列表用v初始化val，用nxt初始化next
    //构造函数体为空
    //如果说ListNode是一类对象，那么ListNode*就是指向这类对象的指针，也算作是一种类型声明
    //对象和指针的区别会在之后有所说明
};
//在这里在此处（buildList函数前）写作的注释会在你将鼠标停留在函数体上时显示注释，一般用作用法说明
//struct 结构体的语法要求是段末加分号
//可以如此理解，如果说声明变量的魔法是int i （类型+变量名），
//那么声明新类型的魔法就是struct ListNode （结构体方法+类型名）。
ListNode* buildList(const vector<int>& arr) {
    //const 即只读：禁止修改原件
    //&即引用：直接使用原件而不是另复制一份使用以减少性能开销
    ListNode* dummy = new ListNode(0);
    //1.new方法会调用：后方类型的构造函数
    //2.new方法的返回值是指向初始化对象的指针
    ListNode* cur = dummy;
    for(int v : arr) {
        //range-based “for” loop
        //基于range范围的for循环（loop：循环）
        //该语法在C++11引入
        cur->next = new ListNode(v);
        //cur的类型是ListNode指针
        //cur->next是通过指针访问类型中成员变量
        //如果是通过对象访问成员变量，则是这样写的“node.next = new ListNode(v);”
        //Only 指针 can do "cur->next",用一个小箭头
        cur = cur->next;
    }
    return dummy->next;
}
int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    //<iostream>库中的利用cin读入acm输入流的操作示例
    //cin和cout的断句是c语言的in和out，不要连读成“心”和“曹特”

    ListNode* l1 = buildList(a);
    ListNode* l2 = buildList(b);

    //用转换了类型的l1,l2，接住转换类型的结果
    vector<int> out;
    //用数组更方便的承接结果
    int carry = 0;
    //知识点1：l1的类型是指针，为了判断l1链表是否还有剩余非空数位需要计算的方法
    //是判断l1是否为空指针，即nullptr
    //知识点2：||短路或 && 短路与
    while(l1 != nullptr || l2 != nullptr || carry != 0) {
        //语法点：判断赋值
        //条件判断（l1 != nullptr）二分选择 (? val1 : val2;)
        int x = l1 != nullptr ? l1->val : 0;
        int y = l2 != nullptr ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        out.push_back(sum % 10);
        //nullptr 没有 next 的成员变量，不能尝试访问，必须加上条件限制
        //然后大家要牢记l1，l2是指针不是全链表
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }
    //我们发现i此次声明的类型不是int了，而是size_t，
    //好吧也许你并没有看出size_t是类型，或者在原先声明int的位置
    //size_t这种类型 1.无符号2.整数（考虑到容量大小的真实物理意义，这一点是显而易见的）
    //为什么此处要把i声明成size_t类型呢?
    //因为size_t是out.size()的返回值的数值类型
    //而要写 i < out.size() 就要让两者同一类型，因为
    //int 和 size_t 比较有隐式转换风险，若i为负数例-1，则会被隐式转换，在64位下则是64位最大值减一，-1竟然大于out.size()了
    //因此有两种写法
    //其一是 i < (int)out.size()
    //另一个就是 size_t i; 了
    //不过第一种方法将size_t转换成int依然有风险，在此处不做展开

    //执行结果列表元素个数次的输出，每次输出一个元素，在除了第一个元素前加入间隔space
    for(size_t i = 0; i < out.size(); i++){
        if (i != 0) cout << ' ';
        cout << out[i];
    }
    cout << '\n';
    return 0;
}