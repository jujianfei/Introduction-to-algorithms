
/*
- Pro 10-3-3：

使用多数组表示的链表，为了让数据紧凑的靠前，修改AllocObj和FreeObj过程。

这个题目我们必须假设链表中的元素的顺序是没有要求的。

假设原来的链表中的1-f是obj，f+1-n是free，那么alloc过程，是选择f+1的位置，delloc假设的是i位置，那么这个位置就留下了一个空的位置I，因此可以，将f位置（尾部）的元素放到这个空的位置。

- Pro 10-3-5:

给定一个多数组链表，整理这个链表，让数据占据前面的位置，自由表占据后边的位置。时间O(n)，空间O(1)。

首先考虑这么一个过程，给定一个array中有两类的对象，目的是让他们区分开来。第一类放在开头，第二类放在结尾。

维护两个指针p1, p2, 0-p1-1之间的是第一类，p2+1~n之间的是第二类，当前位置是p1，如果是第二类，交换，然后移动p2即可。

所以剩余的问题就是如何区分这个对象是位于obj，还是free，其实free中的pre是没有使用的，因此可以指定一个特殊的值来标记，就好了。

最后完成上述步骤之后，整理链表即可。
*/

#include <bits/stdc++.h>
#define N 5
using namespace std;

struct Node {
    int val = 0;
    int next = -1;
    int pre = -1;
};
Node a[N];

// 从0开始的
int head_of_free = 1;
int head_of_obj = 0;

void init() {
    for (int i=1; i<N; i++) a[i].next = i + 1;
    a[N-1].next = -1; // -1 代表是 null
    a[0].next = -1; // 这个节点是一个dummy节点
}

void alloc(int value) {
    if (head_of_free == -1) {
        cout << "no sapace left" << endl;
        return;
    }
    int next_index = a[head_of_free].next;
    // 将元素使用头插法插入到obj链表中

    a[head_of_free].next = head_of_obj;
    a[head_of_free].val = value;
    a[head_of_obj].pre = head_of_free;
    head_of_obj = head_of_free;
    head_of_free = next_index;
}
void display() {
    cout << "head of free :" << head_of_free << endl;
    cout << "head of obj :" << head_of_obj << endl;
    for (int i=0; i<N; i++) {
        cout << a[i].val << " " ;
    } cout << endl;
    for (int i=0; i<N; i++) {
        cout << a[i].pre << " " ;
    } cout << endl;
    for (int i=0; i<N; i++) {
        cout << a[i].next << " " ;
    } cout << endl;
}
void delloc(int tar_index) { // 必须保证所要删除的元素的index是在数组中的
    // 假设输入是合法的
    if (tar_index == head_of_obj) { // 所要删除的就是head
        head_of_obj = a[head_of_obj].next;
        a[tar_index].val = 0;
        a[tar_index].next = head_of_free;
        head_of_free = tar_index;
    } else { //
        int pre_index = a[tar_index].pre;
        int next_index = a[tar_index].next;
        a[pre_index].next = next_index;
        a[next_index].pre = pre_index;
        a[tar_index].val = 0;
        a[tar_index].next = head_of_free;
        head_of_free = tar_index;
    }
}
int main() {
    init();
    alloc(100);
    alloc(200);
    alloc(300);
    alloc(400);
    //alloc(500);
    delloc(2);
    delloc(1);
    delloc(3);
    delloc(4);
    display();
}