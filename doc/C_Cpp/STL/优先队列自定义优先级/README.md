默认的优先队列是个极大堆，如果要改变优先队列中元素的优先级，有下面这些方法

```C++
struct cmp1    
{      
    bool operator ()(int &a,int &b)    
    {      
        return a>b;//最小值优先       
    }      
};      
struct cmp2    
{      
    bool operator ()(int &a,int &b)    
    {      
        return a<b;//最大值优先       
    }      
};      
struct node1    
{      
    int u;      
    bool operator < (const node1 &a) const     
    {      
       return u>a.u;//最小值优先       
    }      
};      
struct node2    
{      
    int u;      
    bool operator < (const node2 &a) const     
    {      
        return u<a.u;//最大值优先       
    }      
};     
    
priority_queue<int>q1;//采用默认优先级构造队列         
priority_queue<int,vector<int>,cmp1>q2;//最小值优先       
priority_queue<int,vector<int>,cmp2>q3;//最大值优先       
priority_queue<int,vector<int>,greater<int> >q4;//注意“>>”会被认为错误，       
                                                //这是右移运算符，所以这里用空格号隔开,最小值优先     
priority_queue<int,vector<int>,less<int> >q5;//最大值优先        
priority_queue<node1>q6;  //自定义优先级    
priority_queue<node2>q7;  
```