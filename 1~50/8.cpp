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

const int maxn=1e4;

ll a[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    string tp;
    cin>>tp;
    vector<string> strs = split_string_coma(tp);
    int id=0;
    for(auto k:strs){
        a[id++] = string_to_num(k);
        //cout<<k<<endl;
    }
    int sum =0 ;
    for(int i=0;i<id;++i){
        for(int j=i+1;j<id;++j){
            if(a[j]<a[i]) sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}


