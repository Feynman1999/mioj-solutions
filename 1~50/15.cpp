#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
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
int len;

set<pair<int,pair<int,int> > > st;

int main()
{
    //freopen("in.txt","r",stdin);
    cin>>s;
    vector<string> strs = split_string_coma(s);
    for(auto k:strs){
        a.push_back(string_to_num(k));
    }
    len = a.size();
    sort(a.begin(),a.end());
    ll sum = 0 ;
    for(int i=0;i<len;++i){
        for(int j=i+1;j<len;++j){
            for(int k=j+1;k<len;++k){
                pair<int,pair<int,int> >  tp = mp(a[i],mp(a[j],a[k]));
                if(a[i]+a[j]==-a[k] && st.count(tp) == 0){
                    sum++;
                    st.insert(tp);
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
