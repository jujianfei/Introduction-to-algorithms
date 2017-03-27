// 6410863_AC_0ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <deque>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}

struct INFO {
    INFO(){}
    string dir;
    int val;
    INFO(const string tmp) {
        for (int i=0; i<=tmp.size(); i++) {
            if (tmp[i]==',') {
                val = StringTo<int>(tmp.substr(1,i));
                dir = string(tmp.begin()+i+1,tmp.end()-1);
            }
        }
    }
};

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val), right(NULL), left(NULL){}
    Node(){}
};

deque<Node*> d;
vector<int> res;
Node* root;

void construct(INFO& info) {
    string& dir = info.dir;
    Node* now = root;

    for (int i=0; i<dir.size(); i++) {
        if (dir[i]=='L') {
            if (now->left==NULL) {
                now->left=new Node(-1);
                now=now->left;
            } else {
                now = now->left;
            }
        } else if(dir[i] == 'R') {
            if (now->right==NULL) {
                now->right=new Node(-1);
                now=now->right;
            } else {
                now = now->right;
            }
        } else {

        }
    }

    if (now->val != -1) { now->val = -1; }
    else now->val = info.val;

}

void print() {
    int flag = 1; //yes
    d.push_back(root);
    while (d.empty()==false) {
        Node *fro = d.front();
        d.pop_front();
        if (fro->val == -1) { flag = 0; break; }
        else {
            res.push_back(fro->val);
            if (fro->left) { d.push_back(fro->left); }
            if (fro->right) { d.push_back(fro->right); }
        }
    }
    if(flag == 0) {
        cout << "not complete" << endl;
    } else {
        for (int i=0; i<res.size()-1;i++) {
            cout <<res[i] << " ";
        }cout << res[res.size()-1] <<endl;
    }
}


void init() {
    d.clear();
    res.clear();
    root=new Node(-1);
}


int main() {
    //freopen("in.txt", "r", stdin);

    init();
    string tmp;
    INFO info;
    while(cin>>tmp) {

        if (tmp == "()") {
            print();
            init();
        } else {
            info = INFO(tmp);
            //cout << info.val << " " << info.dir << endl;
            construct(info);
        }


    }
}
