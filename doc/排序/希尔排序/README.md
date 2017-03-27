# 希尔排序


```
void shellsort(){
    int d=n/2;
    while(d>0){//不能是>1
        for(int i=d;i<n;i+=1){//这里的步进是d
            int tmp=a[i];
            int k;
            for(k=i-d;k>=0;k-=d){
                if(a[k]>tmp){
                    a[k+d]=a[k];
                }else{
                    break;
                }
            }
            a[k+d]=tmp;
        }
        d/=2;
    }
}
```

特点

- 算法的证明或者研究十分困难
- 思想是先让任意间隔d的元素有序,如果d很大，那么就能够交换距离比较远的元素
- 其他思路和插入排序相同
- 复杂度 ==O(n^(6/5))?