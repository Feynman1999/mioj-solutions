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

ll n;

const int maxn = 1e5;

ll f[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    ll n;
    cin>>n;
    if(n<=3) cout<<f[n]<<endl;
    else{
        for(int i=4;i<=n;++i){
            f[i] = f[i-1] + f[i-2];
        }
        cout<<f[n]<<endl;
    }
    return 0;
}

