#include <cstdio>
#include <cstring>
using namespace std;
int n,b[1001],e[1001];
void qsort(int l,int r)
{
	int i,j,m,p;
	i=l;j=r;
	m=e[(l+r)/2];
	while(i<=j)
	{
		while(e[i]<m) ++i;
		while(e[j]>m) --j;
		if (i<=j) 
		{
	      p=b[i];b[i]=b[j];b[j]=p;
	      p=e[i];e[i]=e[j];e[j]=p;
	      ++i;--j;
		}
	}
	if(i<r) qsort(i,r);
	if(l<j) qsort(l,j);
}
int main()
{
	int ans,t,i;
    scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d",&b[i],&e[i]);
	qsort(1,n);
	t=-1;ans=0;
	for(int i=1;i<=n;++i)
	if(b[i]>=t) 
	{
		t=e[i];
		++ans;
	}
	printf("%d",ans);
}
/*
11 
3 5
1 4
12 14
8 12
0 6
8 11
6 10
5 7
3 8
5 9
2 13
*/
