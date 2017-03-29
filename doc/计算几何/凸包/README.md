```C++
void solve() {
    sort(a, a+n, cmp);
    int k = 0;
    vector<Point> qs(n*2);
    //构造凸包的下
    for (int i=0; i<n; i++) {
        while (k > 1 && Cross((qs[k-1] - qs[k-2]),(a[i] - qs[k-1])) <= 0) k--;
        qs[k++] = a[i];
    }
    //构造凸包的上
    int t;
    for (int i=n-2, t =k; i>=0; i--) {
        while (k>t && Cross((qs[k-1] - qs[k-2]),(a[i] - qs[k-1])) <= 0) k--;
        qs[k++] = a[i];
    }

    qs.resize(k-1);
}

```


## Pr

- POJ-2187-Beauty_Contest
