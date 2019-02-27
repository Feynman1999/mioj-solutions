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
        int num=0;
        for(int i=0;i<s.size();++i){
            if(s[i]==','){
                a[++num]=tp;
                //cout<<tp<<endl;
                tp=0;
            }else{
                tp*=10;
                tp+=s[i]-'0';
            }
        }
        int num1=1;
        for(int i=2;i<=num;++i){
            if(a[i]>a[i-1]) num1++;
            else break;
        }
        int num2=num-num1;
        int t=(((num/2+1-num2)<1)?(num/2+1-num2+num):(num/2+1-num2)) ;
        cout<<a[t]<<endl;
    }
    return 0;
}
