对于自己定义的元素类型，可能没有hash函数，因此unorderedmap不能进行hash但是我们可以自己进行定义hash函数。


```C++

#include<bits/stdc++.h>  
#include<map>  
using namespace std;  
struct Node{  
    short i,j,r,l;//i,j是索引,r,l是值  
    Node(int i,int j,int l,int r):i(i),j(j),l(l),r(r){}  
    Node(){}  
    bool operator == (const Node&n)const{  
        return n.i==i&&n.j==j&&n.l==l&&n.r==r;  
    }  
};  
  
namespace std {  
    template <>  
    struct hash<Node> {  
        std::size_t operator()(const Node& k) const {  
            using std::size_t;  
            using std::hash;  
            using std::string;  
            // Compute individual hash values for first,  
            // second and third and combine them using XOR  
            // and bit shifting:  
            return k.i+k.j+k.l+k.r;  
        }  
    };  
}  
  
unordered_map<Node,int> m;  
int main(){  
    Node tmp=Node(1,1,1,1);  
    m[tmp]=1;  
}  

```