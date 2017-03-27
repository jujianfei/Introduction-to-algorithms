// 就是单纯的Dijkstra函数吧，有点繁琐而已

#include<bits/stdc++.h>
#include<vector>
#define N 2007
#define INF 0x3f3f3f
using namespace std;
struct Node{
    int v;
    double w;
    Node(){}
    Node(int v,double w):v(v),w(w){}
};
int n, k, m, ds;

double dist[N];
int visit[N];
int path[N];

vector<Node> G[N];
vector<int> canidate;
double ret_max = -INF;
double avr = INF;
int indexer = INF;

struct Point{
    double w;
    int id;
    Point(double w,int id):id(id),w(w){}
    Point(){}
    bool operator<(const Point n)const{
        return w>n.w;
    }
};

int Dijkstra(int s){
    for (int i=0; i<N; i++) dist[i] = INF;
    memset(visit,0,sizeof(visit));
    priority_queue<Point> q;
    q.push(Point(0,s));
    dist[s]=0;
    while(q.empty()==false){
        double w=q.top().w;
        int id=q.top().id;
        q.pop();
        visit[id]=true;
        for(int i=0;i<G[id].size();i++){
            int adj=G[id][i].v;
            double value=G[id][i].w;

            if(dist[id]+value<dist[adj]){
                dist[adj] = dist[id]+value;
                    if(visit[adj]==true)continue;
                    q.push(Point(dist[adj],adj));

            }
        }
    }
    double sum = 0;
    double miner = INF;
    for (int i=1; i<=n-k; i++) {
        //cout << dist[i] << endl;
        miner = min(miner, dist[i]);
        sum += dist[i];
        if (dist[i] > ds) return 0;
    }

    if (miner > ret_max) {
        ret_max = miner;
        avr = sum / (n-k);
        indexer = s;
        return 1;
    } else if (miner == ret_max) {
        if (sum/(n-k) <= avr) {
            avr = sum/(n-k);
            indexer = s;
            return 1;
        } else {
            return 0;
        }
    }
}
template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}




int main(){
    //freopen("in.txt","r",stdin);
    cin >> n >> k >> m >> ds;
    string b, e;
    int x, y;
    int w;
    for (int i=0; i<m; i++) {
        cin >> b >> e >> w;
        if (b[0] == 'G') {
            x = StringTo<int>(string(b.begin()+1, b.end())) + n;
        } else {
            x = StringTo<int>(b);
        }
        if (e[0] == 'G') {
            y = StringTo<int>(string(e.begin()+1, e.end())) + n;
        } else {
            y = StringTo<int>(e);
        }
        G[x].push_back(Node(y, w));
        G[y].push_back(Node(x, w));
    }
    n = n + k;
    for (int i=n; i>n-k; i--) {
        Dijkstra(i);
    }

    if (indexer == INF) {
        cout << "No Solution" << endl;
        return 0;
    }
    cout << "G";
    cout << indexer-(n-k) << endl;
    printf("%.1f %.1f\n", ret_max, avr+0.001);
    //Dijkstra(6);
}
