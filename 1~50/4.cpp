#include<bits/stdc++.h>
using namespace std;

int a[1000010];

int main()
{
    string s;
    ios::sync_with_stdio(false);
    while(cin>>s)
    {
        memset(a,0,sizeof(a));
        int tp=0;
        s+=',';
        for(int i=0;i<s.size();++i){
            if(s[i]==','){
                a[tp]++;
                //cout<<tp<<endl;
                tp=0;
            }else{
                tp*=10;
                tp+=s[i]-'0';
            }
        }
        int ans=1;
        tp=0;
        for(int i=0;i<1000010;++i){
            if(a[i]==0){
                ans=max(ans,tp);
                tp=0;
            }
            else{
                tp++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}