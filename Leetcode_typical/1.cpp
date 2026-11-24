//万能头，被无数人追捧吹捧的存在，极大的简化了竞赛场景的#include
#include <bits/stdc++.h>
//std命名空间的展开，或者你可以std::每一个操作
using namespace std;
//main函数会在代码执行时自动执行，在单片机也是如此
int main() {
    //<iostream>库中的cin一般认为比scanf好用，下面使用一例
    //cin的流程是跳过前导空白 → 读入非空白字符 → 遇到空白停止
    //cin的空白：包括space \n \r
    //声明变量
    int n;
    //读取变量
    cin >> n;
    //声明数组vector
    vector<int> nums(n);
    //cin在读入数组时，一次只能取一个值
    //读入vector数值
    //使用nums[i]的前提是事前声明了vector的n长度
    for(int i = 0; i < n; i++) {cin >> nums[i];}
    int target;
    cin >> target;
    //“unordered_map”即闻名遐迩的哈希表
    unordered_map<int,int> seen;
    //执行n次的for循环，最常见常用的就是从0开始小于n的这种结构，刚好一一对应0-based的下标。
    for (int i = 0; i < n; i++) {
        int need = target - nums[i];
        //auto类型的寻找迭代器（不要在意迭代器是什么），如果找到则指向寻找结果，如果没找到则会滑动到seen.end()
        //所以我们通过是否 == seen.end() 的比较来反映是否寻找到
        //如果没有寻找到，我们是不可以访问 it->second 的，会报错
        //尽管说是滑动，但寻找过程并不是逐一的，其时间复杂度一般是O(1)
        //因此对于哈希表，寻找过程一般不是滑动，如果没找到则会返回seen.end()“尾后迭代器”
        auto it = seen.find(need);
        if(it != seen.end()) {cout << it->second << ' ' << i << '\n';}
        //直接通过s[val] = i来创建并自动扩容的操作vector不能做
        //因为a[i]在cpp使用的非常频繁，为了降低性能开销，[]只被设计成一个访问操作，没有加入自动扩容的设计
        //所以在i >= nums.size()时 , nums[i] = …… 并不会自动扩容
        //另外，nums[i] = …… 不会自动扩容还有一重理由，vector 是连续内存。
        //seen[1000000] = 1 若自动扩容，意味着要分配 100 万+ 个 int（4MB）、把中间全部初始化为 0、再搬移旧元素。
        //而 unordered_map 是节点式的，插入一个 key 只是挂一个节点，稀疏下标天然支持。
        //所以"自动扩容 + 稀疏下标"这个组合只有 map 才能廉价提供。
        //所以不要越界访问数组哦
        seen[nums[i]] = i;
    }
    cout << '\n';
    return 0;
}