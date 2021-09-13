/*************************************************************************
	> File Name: codeforce-504D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月17日 星期五 23时33分23秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
const int INF = 1e9;
int num[maxn];
int l[maxn],r[maxn];

struct node
{
	int left,right,val;//每个节点有三个值，左区间，右区间，和最小值
}c[maxn*4];
void build_tree(int l,int r,int root)//建树
{
	c[root].left=l;
	c[root].right=r;
	if(l==r)//如果左区间等于右区间就赋值
	{
		c[root].val=num[l];
		if(c[root].val == 0) c[root].val = INF;
		return ;
	}
	int mid=(l+r)/2;
	build_tree(l,mid,root*2);
	build_tree(mid+1,r,root*2+1);
	c[root].val=min(c[root*2].val,c[root*2+1].val);//递归得到
}
void find_tree(int l,int r,int &min1,int root)//查找
{
	if(c[root].left==l&&c[root].right==r)
	{
		min1=c[root].val;
		return ;
	}
	int mid=(c[root].left+c[root].right)/2;
	if(mid<l)//先找到所要寻找的区间在树上的区间范围
	find_tree(l,r,min1,root*2+1);
	else if(mid>=r)
	find_tree(l,r,min1,root*2);
	else//找到了所要找的区间
	{
		int min2;
		find_tree(l,mid,min1,root*2);//左儿子一个最小值
		find_tree(mid+1,r,min2,root*2+1);//右儿子一个最小值
		min1=min(min1,min2);//选最小的
	}

}
int main()
{
	int n,q, maxi = 0, num0 = 0;
	scanf("%d%d", &n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]),maxi = max(maxi, num[i]);
		if(num[i] == 0) num0++;
	}
	if(maxi < q&&maxi && num0 == 0){
		puts("NO");
		return 0;
	}if(maxi < q && num0){
		for(int i = 1; i <= n; ++i)
			if(num[i] == 0){
				num[i] = q;
				break;
			}
	}
	build_tree(1,n,1);
	for(int i = 1; i <= n; ++i){
		if(l[num[i]] == 0 && num[i]) l[num[i]] = r[num[i]] = i;
		else if(num[i]) r[num[i]] = i;
	}
	int a,b,min1;
	bool check = true;
	for(int i = 1; i <= q; ++i)
		if(l[i]){
			a = l[i];
			b = r[i];
			find_tree(a,b,min1,1);
			if(min1 < i) check = false;
			if(!check) break;
		}
	if(!check){
		puts("NO");
		return 0;
	}
	puts("YES");
	if(maxi == 0)
		for(int i = 1; i <= n; ++i)
			num[i] = q;
	else {
		int t = 0;
		for(int i = 1; i <= n; ++i)
			if(num[i]){
				t = num[i];
				break;
			}
		for(int i = 1; i <= n; ++i){
			if(num[i] == 0){
				num[i] = t;
			}else t = num[i];
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", num[i]);
	return 0;
}

