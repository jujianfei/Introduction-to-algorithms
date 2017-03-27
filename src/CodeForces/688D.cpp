#include <bits/stdc++.h>
using namespace std;

long long n, k, a, lcm;

int main() {
    scanf("%I64d%I64d", &n, &k);
    lcm = 1;
    while(n--) {
        scanf("%I64d", &a);
        lcm = a * lcm / __gcd(a, lcm);
        lcm %= k;
    }
    puts(lcm ? "No" : "Yes");
    return 0;
}