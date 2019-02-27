#include stdio.h
#include stdlib.h
#include string.h
#include stddef.h
#include ctype.h
typedef long long ll;
const int mod=1e9+7;

ll fast_exp(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=resa%c;
        a=aa%c;
        b=1;
    }
    return res;
}

#define BUFFERSIZE 1000000

 移除行末空格
char rtrim(char s)
{
    char back = s + strlen(s);
    while(isspace(--back));
    (back+1) =' ';
    return s;
}

int main()
{
    char buffer[BUFFERSIZE];

    while (fgets(buffer, BUFFERSIZE, stdin) != NULL) {
         在此处理单行测试数据
         rtrim(buffer)
        ll n;
        sscanf(buffer,%lld,&n);

        printf(%lldn,(fast_exp(3,n+1,mod)-1+mod)%modfast_exp(2,mod-2,mod)%mod);

         打印处理结果，务必输出换行符
         printf(%sn, result);
    }

    return 0;
}


