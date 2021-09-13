#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
char a[100], b[100];

LL findx(char s[100]){
    LL ans = 0;
    int len = strlen((s));
    for(int i = 0; i < len; ++i){
        if(s[i] >= '0' && s[i] <= '9')
            ans=max(ans,(LL)s[i]-'0');
        else ans = max(ans, (LL)s[i]-'a'+10);
    }return ans+1;
}

LL convert(char s[100], LL r){
    LL ans = 0;
    int len = strlen(s);
    LL u = 1;
    for(int i = len-1; i >= 0; --i){
        LL k;
        if(s[i]>= '0' && s[i] <= '9')
            k = s[i]-'0';
        else k = s[i]-'a'+10;
        ans += u*k;
        u *= r;
    }return ans;
}

LL slove(char s[100], LL tr){
    LL l = findx(s), r = 1e18, mid;
    LL ans = -1;
    while(l <= r){
        mid = l + (r-l)/2;
        LL tmp = convert(s, mid);
        if(tmp < 0 || tmp >= tr){
            r = mid-1;
            if(tmp == tr) ans = mid;
        }
        else l = mid+1;
    }return ans;
}

int main(){
    int t;
    LL r;
    scanf(" %s %s %d %lld",a,b,&t,&r);
    if(strcmp(a,b) == 0){
        printf("%lld\n", r);
        return 0;
    }
    if(t==1){
        LL tr = convert(a, r);
        LL ans = slove(b, tr);
        if(ans == -1)
            printf("Impossible\n");
        else printf("%lld\n", ans);
    }
    if(t==2){
        LL tr = convert(b, r);
        LL ans = slove(a, tr);
        if(ans == -1)
            printf("Impossible\n");
        else printf("%lld\n", ans);
    }
    return 0;
}
