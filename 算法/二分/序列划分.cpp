#include<bits/stdc++.h>
#define inf 1e14
#define ll long long
using namespace std;
int T,n,m,a[100010];
bool check(ll p)
{
	ll s=0;
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(s+a[i]<=p)s+=a[i];
		else if(a[i]<=p)cnt++,s=a[i];
		else return false;
	}
	return cnt<=m;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ll l=1,r=inf,ans;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(check(mid))
				ans=mid,
				r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
