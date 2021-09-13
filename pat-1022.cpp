#include<bits/stdc++.h>
using namespace std;

struct ss{
    int num;
    char title[100],author[100],key[11][100],puber[100],year[100],id[100];
}a[10010];

bool cmp(const ss &p, const ss&q){
    return strcmp(p.id , q.id)<0;
}

int ans[10000];

void scan(char as[100]){
    char ch;
    int k = 0;
    while((ch=getchar()) != '\n')
        as[k++] = ch;
    as[k] = '\0';
}

int main(){
    int n;
    scanf("%d", &n);
    char tmp[1001];
    for(int i = 0; i < n; ++i){
        scanf(" %s", a[i].id);
        getchar();
        scan(a[i].title);
        scan(a[i].author);
        scan(tmp);
        scan(a[i].puber);
        scanf(" %s", &a[i].year);
        a[i].num = 0;
        int len = strlen(tmp);
        int k = 0;
        for(int j = 0; j < len; ++j)if(tmp[j] == ' '){
            a[i].key[a[i].num++][k] = '\0';
            k = 0;
        }else {
            a[i].key[a[i].num][k++] = tmp[j];
        }a[i].key[a[i].num++][k] = '\0';
    }sort(a,a+n,cmp);/*
    for(int i = 0; i < n; ++i){
        printf("-------------------");
        printf("%d\n%s\n%s\n",a[i].id,a[i].title, a[i].author);
        for(int j = 0; j < a[i].num; ++j)
            printf("%s\n",a[i].key[j]);
        printf("%s\n%d",a[i].puber, a[i].year);
        printf("*******************");
    }*/
    int m;
    scanf("%d", &m);
    while(m--){
        int op;
        char k[100];
        scanf("%d: ",&op);
        scan(k);
        printf("%d: %s\n",op,k);
        bool flag = true;
        if(op == 1){
            for(int i = 0; i < n; ++i)
                if(strcmp(a[i].title, k) == 0){
                    printf("%s\n", a[i].id);
                    flag = false;
                }
        }else if(op == 2){
            for(int i = 0; i < n; ++i)
                if(strcmp(a[i].author, k) == 0){
                    printf("%s\n", a[i].id);
                    flag = false;
                }
        }else if(op == 3){
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < a[i].num; ++j)
                if(strcmp(a[i].key[j], k) == 0){
                    printf("%s\n", a[i].id);
                    flag = false;
                    break;
                }
        }else if(op == 4){
            for(int i = 0; i < n; ++i)
                if(strcmp(a[i].puber, k) == 0){
                    printf("%s\n", a[i].id);
                    flag = false;
                }
        }else if(op == 5){
            for(int i = 0; i < n; ++i)
                if(strcmp(a[i].year, k)==0){
                    printf("%s\n", a[i].id);
                    flag = false;
                }
        }
        if(flag)puts("Not Found");
    }
    return 0;
}

/*
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
*/
