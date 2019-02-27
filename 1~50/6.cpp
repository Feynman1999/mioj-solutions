#include<bits/stdc++.h>
using namespace std;

vector<string> strs;

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

string s1,s2,s;

bool flag = false;

void dfs(int id,int id1,int id2){
    if(id==s.length()) flag = true;
    if(s[id] == s1[id1]) dfs(id+1,id1+1,id2);
    if(s[id] == s2[id2]) dfs(id+1,id1,id2+1);
    //return false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    string tp;
    cin>>tp;
    //cout<<tp<<endl;
    strs = split_string_coma(tp);
    s1=strs[0];
    s2=strs[1];
    s=strs[2];
//    for(auto k:strs){
//        cout<<k<<endl;
//    }
    if(s1.length()+s2.length()  != s.length()){
        cout<<"false"<<endl;
        return 0;
    }
    dfs(0,0,0);
    if(flag){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}
