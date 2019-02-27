#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll,short> mapp;

int main()
{
    ios::sync_with_stdio(false);
    ll n;
    while(cin>>n && n)
    {
        mapp[n]++;
    }
    for(auto k:mapp)
    {
        //cout<<k.first<<" "<<k.second<<endl;
        if(k.second==1){
            cout<<k.first<<endl;
            break;
        }
    }
    return 0;
}
