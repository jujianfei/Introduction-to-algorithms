## 最大区间调度

现在有n个工作要完成，每项工作分别在s时间开始，在t时间结束。对于每项工作，你都可以选择参与与否。如果选择了参与，那么自始至终都必须全程参与。此外，参与工作的时间段不能重叠（闭区间）。求你参与的所有工作最大需要耗费多少时间。

```C++

//用于对工作排序的pair数组
pair<int,int> itv[MAX_N];

void solve()
{
    // 对pair进行的是字典序比较，为了让结束时间早的工作排在前面，把T存入first，//把S存入second
    for(int i=0;i<N;i++) {
        itv[i].first=T[i];
        itv[i].second=S[i];
    }

    sort(itv,itv+N);

    dp[0] = itv[0].first-itv[0].second;
    for (int i = 1; i < N; i++) {
        int max;
        // 判断和前面的区间是不是相交
        int nonOverlap ... // 判断是不是和前面的区间不相交
        if (nonOverlap)
            max = dp[nonOverlap] + (itv[i].first-itv[i].second);
        else
            max = itv[i].first-itv[i].second;

        //do not select the ith interval
        dp[i] = max>dp[i-1]? max:dp[i-1];
    }
    printf("%d\n",dp[N-1]);
}

```