#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
typedef long long LL;

char a[maxn],b[maxn];
int s[maxn];
int n, m,q;

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s%s",a,b);
   for(int i=0;i<n;i++)
    {
        int flag=1;
        for(int j=0;j<m;j++)
            if (a[i+j]!=b[j])
        {
            flag=0;
            break;
        }
        if (flag)
            s[i+1]++;
        s[i+1]+=s[i];
    }
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if (r-m+1>=0&&r-m+1>=l-1)
            printf("%d\n",s[r-m+1]-s[l-1]);
        else printf("0\n");
    }
    return 0;
}
