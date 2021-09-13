#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

const int maxn = 1e3 + 10;
const double eps = 1e-4;
struct ss{
    int x, y;
    double z;
    bool operator <(const ss &q)const{
        return z < q.z;
    }
}a[maxn];
int n, k;

bool judge(double mid){
    double xx = 0, yy = 0;
    for(int i = n-1; i >=0; --i)
        a[i].z =a[i].x - mid * a[i].y;
    sort(a,a+n);
    for(int i = n-1;i >= k; --i)
        xx += a[i].x, yy += a[i].y;
    return xx + eps > mid * yy;
}

int main(){
    while(cin >> n >> k && n){
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i].x);
        for(int i = 0; i < n; ++i)
            scanf("%d",&a[i].y);
        double l = 0, r = 1.0;
        while(r - l > eps){
             double mid = (r + l) / 2;
             if(judge(mid))
                  l = mid;
            else r = mid;
        }printf("%.0f\n", (l*100));
    }return 0;
}
