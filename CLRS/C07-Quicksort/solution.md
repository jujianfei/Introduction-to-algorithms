# after-modification
```
#!/usr/bin/env python
# coding=utf-8

def quicksort(items, p, r):
    if p < r:
        q = partition(items, p, r)
        quicksort(items, p, q-1)
        quicksort(items, q+1, r)

def partition(items, p, r):
    x = items[r]
    i = p-1
    for j in range(p, r):
        if items[j] <= x:
            i = i + 1
            items[i],items[j] = items[j],items[i]

    items[i+1],items[r] = items[r],items[i+1]
    return i+1



items = [2,5,9,3,7,0,-1]
quicksort(items, 0, len(items)-1)
print items
```
# random-quicksort

```
#!/usr/bin/env python
# coding=utf-8

import random

def randomized_quicksort(items, p, r):
    if p < r:
        q = randomized_partition(items, p, r)
        randomized_quicksort(items, p, q-1)
        randomized_quicksort(items, q+1, r)

def randomized_partition(items, p, r):
    i = random.randint(p, r)
    items[i],items[r] = items[r],items[i]
    return partition(items, p, r)

def partition(items, p, r):
    x = items[r]
    i = p-1
    for j in range(p, r):
        if items[j] <= x:
            i = i + 1
            items[i],items[j] = items[j],items[i]

    items[i+1],items[r] = items[r],items[i+1]
    return i+1



items = [2,5,9,3,7,0,-1]
randomized_quicksort(items, 0, len(items)-1)
print items
```

# origin quicksort

```
#!/usr/bin/env python
# coding=utf-8

def quicksort(items, p, r):
    if p < r:
        q = partition(items, p, r)
        quicksort(items, p, q)
        quicksort(items, q+1, r)

def partition(items, p, r):
    x = items[p]
    i = p - 1
    j = r + 1
    while True:
        
        while True:
            j = j - 1
            if items[j] <= x:
                break
        while True:
            i = i + 1
            if items[i] >= x:
                break
        if i < j:
            items[i],items[j] = items[j],items[i]
        else:
            return j


items = [13,19,9,5,12,8,7,4,11,2,6,21]
quicksort(items, 0, len(items)-1)
print items
```

# three way quicksort

```
# include<bits/stdc++.h>
using namespace std;
#define N 100
int a[N];
//sort a[lo-hi]
void sorter(int lo, int hi){
    if(lo >= hi) return;
    int v = a[lo];
    int i = lo + 1;
    int lt = lo, gt = hi;
    while (i <= gt) {
        // finaly
        // lo <= x < lt => < piv
        // lt <= x <= gt => == piv
        // gt < x < hi => > piv
        
        // when ... i <= x <= gt , unknow.
        int tmp = a[i];
        if (tmp == v) i++;
        else if (tmp > v) swap(a[i], a[gt--]);
        else swap(a[i++], a[lt++]);
    }
    sorter(lo, lt-1);
    sorter(lt, gt);
    sorter(gt+1, hi);
}


```

