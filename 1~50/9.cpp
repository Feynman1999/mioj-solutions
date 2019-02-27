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

string s;
int k;

vector<short> get_id(int i)
{
    vector<short> id;
    id.clear();
    int  id1 = 0;
    int  num = 0;
    while(i)
    {
        if(i&1){
            id.push_back(id1);
            num++;
            if(num>k) break;
        }
        i/=2;
        id1++;
    }
    if(num!=k){id.clear();}
    return id;
}

string fun(vector<short> id){
    assert(id.size()==k);
    int id1 = 0;
    string tp = "";
    for(int i=0;i<s.length();++i){
        if(i==id[id1]){
            id1++;
        }
        else{
            tp += s[i];
        }
    }
    assert(tp!="");
    return tp;
}

int main()
{
    //freopen("in.txt","r",stdin);
    cin>>s>>k;
    ll minn = (1LL<<62) -1 + (1LL<<62);
    int len = s.length();
    for(int i=0;i<(1<<len);++i){
        vector<short> id;
        id.clear();
        id = get_id(i);
        if(id.size()){
            string  tp = fun(id);
            minn = min(minn, string_to_num(tp));
        }
    }
    cout<<minn<<endl;
    return 0;
}
