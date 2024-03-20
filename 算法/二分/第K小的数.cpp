#include<bits/stdc++.h>
#define inf 2e8
#define ll long long 
using namespace std;
int T,n,m,a[100010],b[100010];
ll k; 
ll check(int p)
{
	ll cnt=0;
	int w=m;
	for(int i=1;i<=n;i++)
	{
		while(w>0&&a[i]+b[w]>=p)w--;
		cnt+=w;
	}
	return cnt;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%lld",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		sort(a+1,a+1+n);
		sort(b+1,b+1+m);
		int l=2,r=inf,ans;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid)<k)
				ans=mid,
				l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
