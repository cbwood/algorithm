#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<string>

using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int a[8][6] = {
    {0,1,2,3,4,5},
    {0, 2, 6, 7, 8, 9},
    {0, 2, 10, 11, 12, 13},
    {0, 2, 14, 15, 16, 17},
    {0, 2, 18, 19, 20, 21},
    {0, 2, 22, 23, 24, 25},
    {0, 1, 2, 0 , 0 ,0 }
};

int b[10];

int main(){
    int t = 0;
    while(scanf("%d", &b[1]) != EOF){
        for(int i = 2; i <= 5; ++i)
            scanf("%d", &b[i]);
        for(int i = 1; i <= 4; ++i)
            printf("%d ", a[t][b[i]]);
        printf("%d\n",a[t][b[5]]);
        fflush(stdout);
        t++;
        if(t == 6){
            for(int i = 1; i < 5; ++i)
                printf("%d ", a[t][i]);
            printf("%d\n", a[t][5]);
            fflush(stdout);
            t = 0;
        }
    }return 0;
}
