/*
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
*/

//string转化成int
template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}

class Solution {
public:
    int calculate(string s) {
        //除掉空格
        for(auto p=s.begin();p!=s.end();){
           if((*p)==' '){
               p=s.erase(p);
           }else{
               p++;
           }
        }
        
        vector<string> v;//预处理之后的普通表达式
        string::iterator p=s.begin(),q=p+1;
        while(p!=s.end()){
            if((*p)<='9'&&(*p)>='0'){
                while(q!=s.end()&&(*q)<='9'&&(*q)>='0'){
                    q++;
                }//如果是数字一直找到那个不是数字的字符停下
                v.push_back(string(p,q));
                p=q;
                q=p+1;
            }else{
                //如果是其他的字符
                v.push_back(string(p,q));
                p=q;
                q=q+1;
            }
        }
        
        vector<string> rev;//逆波兰式
        vector<string> stack;//临时的运算符栈
        for(int i=0;i<v.size();i++){
            if(v[i][0]<='9'&&v[i][0]>='0'){//是数字直接输出结果到逆波兰式中
                rev.push_back(v[i]);
            }else if(v[i]=="("){
                stack.push_back("(");
            }else if(v[i]==")"){//将运算符栈中左括号前面的全部弹出输出到逆波兰式中
                while(stack.back()!="("){
                    rev.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
            }else if(v[i]=="+"||v[i]=="-"){//加法或者减法,将运算符栈中括号前面的运算符号全部弹出输出到逆波兰式中，自己入运算符栈
                while(stack.empty()==false&&stack.back()!="("){
                    rev.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(v[i]);
            }else{//乘法或者除法,将运算符栈中括号前面的运算符号,向右边扫描遇到+-或者(就停止，自己入运算符栈
                while(stack.empty()==false&&stack.back()!="("&&stack.back()!="+"&&stack.back()!="-"){
                    rev.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(v[i]);
            }
        }
        while(stack.empty()==false){
            rev.push_back(stack.back());
            stack.pop_back();
        }
        
        //根据逆波兰式计算表达式的值
        vector<int> res;
        for(int i=0;i<rev.size();i++){
            if(rev[i][0]<='9'&&rev[i][0]>='0'){//如果是数字直接入栈
                res.push_back(StringTo<int>(rev[i]));
            }else{//如果是运算符号那么将后两个计算结果入栈 sec operator fir
                if(rev[i]=="+"){
                    auto fir=res.back();
                    res.pop_back();
                    auto sec=res.back();
                    res.pop_back();
                    res.push_back(fir+sec);
                }else if(rev[i]=="-"){
                    auto fir=res.back();
                    res.pop_back();
                    auto sec=res.back();
                    res.pop_back();
                    res.push_back(sec-fir);
                }else if(rev[i]=="*"){
                    auto fir=res.back();
                    res.pop_back();
                    auto sec=res.back();
                    res.pop_back();
                    res.push_back(sec*fir);
                }else if(rev[i]=="/"){
                    auto fir=res.back();
                    res.pop_back();
                    auto sec=res.back();
                    res.pop_back();
                    res.push_back(sec/fir);
                }else{
                    cout<<"error"<<endl;
                }
            }
        }
        return res[0];
    }
};