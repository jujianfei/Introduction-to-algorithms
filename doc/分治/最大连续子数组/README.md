## 求一个数组的最大连续子数组，空的数组不计入

- 分治的解法

```C++

int A[10] = {-10,-20,-30,-1,-20,30,300,-40,-50,-60};

int find_max_crossarray(int low, int mid, int high, int &res_low, int &res_high) {
    int sum = 0, left_sum = -INF;
    for (int i=mid; i>=low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            res_low = i;
            left_sum = sum;
        }
    }
    sum = 0;
    int right_sum = -INF;
    for (int i=mid+1; i<=high; i++) {
        sum += A[i];
        if (sum > right_sum) {
            res_high = i;
            right_sum = sum;
        }
    }
    return left_sum + right_sum;
}

int find_max_subarray(int low, int high, int &res_low, int &res_high) {
    if (low == high) {
        res_low = res_high = low;
        return A[low];
    }

    int mid = (low + high)/2;
    int left_low, left_high, right_low, right_high, cross_low, cross_high;
    int left_sum = find_max_subarray(low, mid, left_low, left_high);
    int right_sum = find_max_subarray(mid+1, high, right_low, right_high);
    int cross_sum = find_max_crossarray(low, mid, high, cross_low, cross_high);

    if (left_sum >= right_sum && left_sum >= left_sum) {
        res_low = left_low, res_high = left_high;
        return left_sum;
    } else if (right_sum >= left_sum && right_sum >= cross_sum) {
        res_low = right_low, res_high = right_high;
        return right_sum;
    } else {
        res_low = cross_low, res_high = cross_high;
        return cross_sum;
    }
}

int main() {
    int x=INF, y=INF;
    cout << find_max_subarray(0, 9, x, y) << endl;
    cout << x << y << endl;
}
```


如果数组中的元素都是负的呢？那么会返回一个最大的元素

- 现在修改定义，如果允许有空的元素呢？

需要修改的地方大概有两个，


The base case needs to return an empty array if A[low] is negative.

The subroutine needs to return an empty array in case the maximum subarray has a negative sum.


```C
#include <limits.h>

typedef struct {
    unsigned left;
    unsigned right;
    int sum;
} max_subarray;

max_subarray find_max_crossing_subarray(int A[], unsigned low, unsigned mid, unsigned high) {
    max_subarray result = {mid + 1, mid, 0};
    int sum = 0,
        left_sum = INT_MIN,
        right_sum = INT_MIN;

    for (int i = mid - 1; i >= (int) low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            result.left = i;
        }
    }

    sum = 0;

    for (int j = mid; j < high; j++) {
        sum += A[j];
        if (sum > right_sum) {
            right_sum = sum;
            result.right = j + 1;
        }
    }

    if (left_sum + right_sum < 0) {
        max_subarray empty = { mid, mid, 0 };
        return empty;
    } else {
        result.sum = left_sum + right_sum;
        return result;
    }
}

max_subarray find_maximum_subarray(int A[], unsigned low, unsigned high) {
    if (high == low + 1) {
        if (A[low] < 0) {
            max_subarray empty = {low, low, 0};
            return empty;
        } else {
            max_subarray result = {low, high, A[low]};
            return result;
        }
    } else {
        unsigned mid = (low + high) / 2;
        max_subarray left = find_maximum_subarray(A, low, mid);
        max_subarray right = find_maximum_subarray(A, mid, high);
        max_subarray cross = find_max_crossing_subarray(A, low, mid, high);

        if (left.sum >= right.sum && left.sum >= cross.sum) {
            return left;
        } else if (right.sum >= left.sum && right.sum >= cross.sum) {
            return right;
        } else {
            return cross;
        }
    }
}
```


## 线性级别的算法

方法一：

保存前缀的和，然后，通过不断遍历前缀和的过程中，保存一个前缀和的最小值，然后通过当前前缀和减去最小值的前缀和求出那个区间的和的大小，当然要维护这个前缀最小和，并记录整个遍历过程中，这些区间和的最大值。


方法二：


动态规划

```C++
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int maxsubset(int *a,int l,int r){
    int i,
        temp=0,
        summax=INT_MIN;
    for(i=l;i<=r;i++){
        temp+=a[i];
        if(temp > summax) summax=temp;
        if(temp < 0) temp=0;
    }
    return summax;
}
int main(){
    int a[]={3,-1,2,5,-3,4,-6,-7,1,8,-3,5,9};

    printf("the maxsubset:%d\n",maxsubset(a,0,12));
    return 0;
}

```