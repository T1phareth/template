#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[100010],l[100010],c[100010];
bool check(int p)
{
	for(int i=1;i<=p;i++)
		l[i]=a[i],c[i]=1;
	int w=1;
	for(int i=p+1;i<=n;i++)
	{
		if(a[i]>=l[w]*2)
			l[w]=a[i],c[w]++,w++;
		if(w>p)w-=p;
	}
	for(int i=1;i<=p;i++)
		if(c[i]<k)return false;
	return true;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int l=0,r=n/k,ans;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))
				ans=mid,
				l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
