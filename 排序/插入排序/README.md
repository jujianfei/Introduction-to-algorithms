# 插入排序

```C++
void insertsort(){
    for(int i=1;i<n;i++){
        int tmp=a[i];
        int k;
        for(k=i-1;k>=0;k--){
            if(a[k]>tmp){
                a[k+1]=a[k];//移动而不是交换，能够提高效率
            }else{//注意要break
                break;
            }
        }
        a[k+1]=tmp;
    }
}

```

插入排序的元素移动次数和逆序数的对数是相同的

最好的情况是 ==O(n)

最坏和平均情况是 ==O(n^2)

适合非随机的数组 部分有序的数组 小规模数组

基本上会比选择排序方法快一倍