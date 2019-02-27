#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> split_string_coma(string tp){
    vector<string> ans;
    string tp2="";
    for(int i=0;i<tp.length();++i){
        if(tp[i]==','){
            ans.push_back(tp2);
            tp2="";
        }
        else{
            tp2+=tp[i];
        }
    }
    if(tp2.length()){
        ans.push_back(tp2);
    }
    return ans;
}

ll string_to_num(string tp){
    ll flag = 1;
    if(tp[0]=='-'){
        flag = -1;
        tp = tp.substr(1);
    }
    ll num = 0;
    for(int i=0;i<tp.length();++i){
        num *=10;
        num+=tp[i]-'0';
    }
    return flag * num;
}

const int maxn = 5e5;

string s;
ll k;
vector<ll> a;
int num =0;
int len;

struct node{
    int num;
    int id;
};

node b[maxn];

bool cmp(node a,node b){
    if(a.num == b.num){
        return a.id < b.id;
    }
    return a.num> b.num;
}

int main()
{
    //freopen("in.txt","r",stdin);
    cin>>s>>k;
    vector<string> strs = split_string_coma(s);
    for(auto k:strs){
        a.push_back(string_to_num(k));
    }
    len = a.size();
    sort(a.begin(),a.end());
    for(int i=0;i<maxn;++i){
        b[i].id = i;
    }
    for(int i=0;i<len;++i){
        b[a[i]].num++;
    }
    sort(b+1,b+maxn,cmp);

    for(int i=1;i<k;++i){
        cout<<b[i].id<<",";
    }
    cout<<b[k].id<<endl;
    return 0;
}




