## 组合数的生成

原来的元素在a数组中，要求从前5个元素中选择3个，使用回溯法。

```C++
int a[5] = { 123, 234, 345, 456, 567 };
int tmp[5];
int k = 3;
void dfs(int cur, int depth) {
    if (depth == k){ //完成了选择
        for(int i=0; i<k; i++){
            cout << tmp[i] << " ";
        } cout << endl;
        return;
    }
    if (cur == 5) return;//最然到了结尾但是没有完成选择
    tmp[depth] = a[cur];
    dfs(cur+1, depth + 1);
    dfs(cur+1, depth);
} 
```


应当先判断是否完成了选择，然后判断是否到了结尾，因为可能到达结尾的同时完成了选择。

## 排列的生成

```C++
int a[5]={123,234,345,456,567};
int tmp[5];
void dfs(int cur){
    if(cur==5){
        for(int i=0;i<5;i++){
            cout<<tmp[i]<<" ";
        }cout<<endl;
        
    }
    else for(int i=0;i<5;i++){//一定是对于每一个元素
        int flag=0;//没有出现在之前已经排列好的元素里面
        for(int j=0;j<cur;j++){
            if(tmp[j]==a[i]){
                flag=1;
                break;
            }
        }
        if(!flag){
            tmp[cur]=a[i];
            dfs(cur+1);
        }
    }
}

int main(){
    dfs(0);
}
```

这种解法，只能对a中所有的数字不相同的时候，才是成立的。

嗯，为什么呢？

假如说，我们输入的是1，1，1，那么程序是什么也不输出的。

因此有了下面的这种方法。

```C++

else for (int i=0; i<n; i++) {

    int c1=0, c2=0;
    for (int j=0; j<cur; j++) {
        if (A[j] == P[i]) c1++;
    }
    for (int j=0; j<n; j++) {
        if (A[j] == P[i]) c2++;
    }
    if (c1 < c2) {
        A[cur] = P[i];
        dfs(n, P, A, cur+1);
    }
}

```


但是又有了问题：

就是出现了重复的情况，对于这种情况，只要for循环加一个判断就行。
```
if (!(i==0 || P[i]!=P[i-1])) continue;
```
## 子集的生成（增量法）
```C++
int n=4;
void sub_set(int A[],int cur)
{
    for(int i=0;i<cur;i++)
    {
        cout<<A[i]<<" ";
    }cout<<endl;
    int miner;
    if(cur==0)
        miner=1;
    else{
        miner=A[cur-1]+1;
    }
    for(int i=miner;i<n;i++){
        A[cur]=i;
        sub_set(A,cur+1);
    }
}

int main(){
    int A[10]={};
    sub_set(A,0);
}
```

## 实现生成下一个排列和下一个组合的算法

离散数学及其应用

按照字典顺序生成下一个排列1-n的下一个排列，1-n中没有重复的数字
思想从后往前找到第一个j 使得，a[j] < a[j+1];

然后找到j后面的大于a[j]的最小的数a[k]，交换a[j]和a[k]， 
然后将其他的数字，从小到大排列到后面。

按照字典序找到 (1,2,3,4,5,6)这个集合中的，（1,2,5,6）这个组合的下一个组合
从后往前找到一个i使得，a[i] 不等于 n-r+i； 
用a[i] + 1代替a[i]，对于j = i+1, 以及后面的j，用 
a[i] + j - i + 1代替 a[j]

这道题目答案是 1 3 4 5
