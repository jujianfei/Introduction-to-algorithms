// 15119506_AC_157MS_1132K.cc
 #include <iostream>
 #include <queue>
 using namespace std;
 priority_queue<long long> q;
 int main(){
     long long n;
 	while (cin >> n){
 	    long long ans=0;
 	    for (long long i(1);i<=n;i++){
 	        long long k;
 	        cin >> k;
 	        q.push(-k);
 	    }
 	    while (q.size()>1){
 	        long long a=q.top();
 	        q.pop();
 	        long long b=q.top();
 	        q.pop();
 	        ans+=a+b;
 	        q.push(a+b);
 	    }
 	    q.pop();
 	    cout << -ans << endl;
 	}
 	return 0;
 }