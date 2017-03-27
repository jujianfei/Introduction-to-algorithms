## 算法分析

这一部分，我看的是[网易云课堂的CLRS视频。](http://open.163.com/movie/2010/12/R/E/M6UTT5U0I_M6V2TG4RE.html)

槽的数量是m，对象个数是n。

非成功的搜索，==O(1+(n/m))，当m==O(n)时候，算法复杂度是常数级别的。

## 哈希函数

- division

k mod prime

- multiplcation

```
m = 2 ^ r

h(k) = (A*k mod 2^w) >> (w-r)

A % 2 == 1
```

## 开放寻址法和二次探测法

- 开放寻址法就是一次试探不成功之后，再进行独立的下一次探测。

- 二次探测法

```
h(k, i) = [h1(k) + i * h2(k)] mod M
h2(k) % 2 == 1
```

- 探测次数 == 1 / (1 - (n/m))


- [线性探测法的实现](hash_table_liner.cpp)

特别注意delete的方法的实现


