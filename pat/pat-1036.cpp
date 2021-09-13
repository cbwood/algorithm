#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    char fname[20], fid[20], mname[20], mid[20];
    int fsc=-1,msc=101;
    for(int i = 0; i < n; ++i){
        char name[20], id[20],sx;
        int sc;
        scanf("%s %c %s %d",name, &sx, id, &sc);
        if(sx == 'M' && sc < msc){
            msc = sc;
            strcpy(mname, name);
            strcpy(mid, id);
        }
        if(sx == 'F' && sc > fsc){
            fsc = sc;
            strcpy(fname, name);
            strcpy(fid, id);
        }
    }
    if(fsc != -1)
        printf("%s %s\n",fname, fid);
    else printf("Absent\n");
    if(msc != 101)
        printf("%s %s\n",mname, mid);
    else printf("Absent\n");
    if(fsc != -1 && msc != 101)
        printf("%d\n",fsc-msc);
    else printf("NA\n");
    return 0;
}