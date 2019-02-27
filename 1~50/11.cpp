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

const int maxn = 1e5;


string s1,s2;

unordered_map<char,int> mp1;
unordered_map<char,int> mp2;

int main()
{
    //freopen("in.txt","r",stdin);
    while(cin>>s1>>s2){
        mp1.clear();
        mp2.clear();
        for(int i=0;i<s1.length();++i){
            mp1[s1[i]]++;
        }
        for(int i=0;i<s2.length();++i){
            mp2[s2[i]]++;
        }
        int flag = 1;
        for(auto k:mp1){
            char tp = k.first;
            if(mp2[tp] < k.second){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout<<"true"<<endl;
        }
        else cout<<"false"<<endl;
    }

    return 0;
}


