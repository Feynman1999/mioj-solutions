#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,C,D,mod,n,mod2;
const int maxn=10;
const int maxm=10;
ll F[100];
ll fast_exp(ll a,ll b,ll c){
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%c;b>>=1;a=a*a%c;
    }
    return res;
}
struct Matrix{
    int n,m;//行 列
    ll a[maxn][maxm];
    void Clear(){
        n=m=0;
        memset(a,0,sizeof(a));
    }
    Matrix operator +(const Matrix &b) const{
        Matrix tmp;
        tmp.n=n; tmp.m=m;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                tmp.a[i][j]=(a[i][j]+b.a[i][j])%mod;
        return tmp;
    }
    Matrix operator *(const Matrix &b) const{
        Matrix tmp;
        tmp.Clear();
        tmp.n=n; tmp.m=b.m;
        for(int i=0;i<n;++i)
            for(int j=0;j<b.m;++j)
                for(int k=0;k<m;++k){
                    tmp.a[i][j]+=a[i][k]*b.a[k][j]%mod;
                    tmp.a[i][j]%=mod;
                }
        return tmp;
    }
};
ll solve(ll a[],ll b[],ll m,ll t){
    Matrix M,F,res;//M是辅助常数矩阵 F是转移矩阵
    M.Clear(),F.Clear(),res.Clear();
    M.n=M.m=m;
    res.n=res.m=m;
    F.n=m,F.m=1;
    for(int i=0;i<m-1;++i)
        M.a[i][i+1]=1;
    for(int i=0;i<m;++i){
        M.a[m-1][i]=a[i];//a[i]先存小项的系数 即递推式最靠末尾的系数
        F.a[i][0]=b[i];//b[i]先存小项的值 即f0(通常)
        res.a[i][i]=1;//初始化为单位矩阵
    }
    if(t<m) return F.a[t][0];
    for(t-=m-1;t;t/=2){//t-=m-1为还要转移的次数
        if(t&1) res=M*res;
        M=M*M;
    }
    F=res*F;//res为最后的常数矩阵
    return F.a[m-1][0];
}
string deal(ll ans){
    string tp="000000000";
    int id = 8;
    while(ans){tp[id--]=(ans%10+'0');ans/=10;}
    return tp;
}
ll phi(ll x)
{
    if(x==1) return 1;
    ll res=x;
    for(ll i=2;i*i<=x;++i){
        if(x%i==0){
            res-=res/i;
            do{
                x/=i;
            }while(x%i==0);
        }
    }
    if(x>1) res-=res/x;
    return res;
}
int main()
{
    //freopen("in.txt","r",stdin);
    ll a[2],b[2];
    a[0]=a[1]=1;
    b[0]=0;
    b[1]=1;
    while(scanf("%lld%lld%lld%lld%lld%lld",&A,&B,&C,&D,&mod2,&n)!=EOF)
    {
        ll E = fast_exp(C,D,mod2);
        mod = phi(mod2);
        F[1]=A;
        F[2]=B;
        F[3]=A*B%mod2*E%mod2;
        F[4]=F[2]*F[3]%mod2*E%mod2;
        for(int i=5;i<=50;++i){
            F[i]=F[i-1]*F[i-2]%mod2*E%mod2;
        }
        if(n<=50){
            ll ans =1;
            for(int i=1;i<=n;++i){
                ans = ans*F[i]%mod2;
            }
            cout<<deal(ans)<<endl;
        }
        else{
            ll ans=F[1]*F[2]%mod2;
            ll n_3 = solve(a,b,2,n-3);
            ll n_2 = solve(a,b,2,n-2);
            ll n_1 = solve(a,b,2,n-1);
            ll n_4 = solve(a,b,2,n+2);
            ll zhi_1 = (2*n_2 + n_3 - 1+mod)%mod;
            ll zhi_2 = (2*n_1 + n_2 - 1+mod)%mod;
            ll zhi_3 = (n_4-(n-2)-3+3*mod)%mod;
            zhi_2 = (zhi_2-1+mod)%mod;

            zhi_1 = zhi_1%mod + mod;
            zhi_2 = zhi_2%mod + mod;
            zhi_3 = zhi_3%mod + mod;
            ans=ans*fast_exp(A,zhi_1,mod2)%mod2;
            ans=ans*fast_exp(B,zhi_2,mod2)%mod2;
            ans=ans*fast_exp(E,zhi_3,mod2)%mod2;
            cout<<deal((ans+mod2)%mod2)<<endl;
        }
    }
    return 0;
}
