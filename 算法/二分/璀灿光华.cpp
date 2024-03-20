#include<bits/stdc++.h>
#define N 200010
#define inf 1e12
#define int long long
using namespace std;
int T,n,m,s,ans,t[N],v[N],l[N],r[N];
int pre[N],pr[N];
int check(int p)
{
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1];
		pr[i]=pr[i-1];
		if(t[i]>=p)
		{
			pre[i]+=v[i];
			pr[i]+=1;
		}
	}
	for(int i=1;i<=m;i++)
		ret+=(pr[r[i]]-pr[l[i]-1])*(pre[r[i]]-pre[l[i]-1]);
	return ret;
}
signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		ans=inf;
		scanf("%lld%lld%lld",&n,&m,&s);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",&t[i],&v[i]);
		for(int i=1;i<=m;i++)
			scanf("%lld%lld",&l[i],&r[i]);
		int ll=0,rr=1e6+10;
		while(ll<=rr)
		{
			int mid=(ll+rr)>>1;
			int ret=check(mid);
			if(ret>s)
			{
				ans=min(ans,ret-s);
				ll=mid+1;
			}
			else
			{
				ans=min(ans,s-ret);
				rr=mid-1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
