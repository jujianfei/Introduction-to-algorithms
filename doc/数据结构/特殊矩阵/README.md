
## 特殊矩阵

- 对称矩阵的存储

![对称矩阵的存储](array1.PNG) 

- 2d+1对角阵的存储

![2d+1对角阵的存储](array2.PNG)


```
矩阵元素下表从0开始的地址计算公式：
Loc(aij)=Loc(a00)+(2d+1)*i-d+j-i+d
0<=i,j<=n-1, |i-j|<=d
矩阵元素下表从1开始的地址计算公式：
Loc(aij)=Loc(a11)+(2d+1)*(i-1)-d+j-i+d
= Loc(a11)+(2d+1)*(i-1)+j-I
1<=i,j<=n, |i-j|<=d
```


## 一般矩阵

- [三元组顺序表快速转置算法实现](FastTransposeSMatrix.cpp)

![三元组顺序表快速转置算法](array3.PNG)

- 十字链表

![十字链表](array4.PNG)