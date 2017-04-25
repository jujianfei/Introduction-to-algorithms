### 参考链接

[std::set为什么没有一个求集合中小于x的个数的函数？](https://www.zhihu.com/question/50561064)
[C++ 如何实现平衡的名次树？](https://www.zhihu.com/question/58776393)

两个都是 O(N) 时间。

```C++
std::distance(myset.begin(), myset.upper_bound(x));

auto it = myset.begin();
std::advance(it, k);


```


“平板电视”

```C++
#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using order_statistic_tree = __gnu_pbds::tree<
                        int,
                        __gnu_pbds::null_type,
                        less<int>,
                        __gnu_pbds::rb_tree_tag,
                        __gnu_pbds::tree_order_statistics_node_update>;

int main() {
    order_statistic_tree t;
    vector<int> vec { 1, 3, 5, 7, 9, 11, 2 };
    for (int x : vec)
        t.insert(x);

    cout << "order of 7: " << t.order_of_key(7) << endl;
    cout << "order of 8: " << t.order_of_key(8) << endl;
    cout << "order of 1: " << t.order_of_key(1) << endl;

    cout << "key of rank 5: " << *t.find_by_order(5) << endl;
    return 0;
}
```

