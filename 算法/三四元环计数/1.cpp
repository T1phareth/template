#include<bits/stdc++.h>
#define ll long long
#define pb push_back
const int P=1e9+7;
const int N=5e5+10;
using namespace std;
int n,m,d[N],x[N],y[N],vis[N],tag[N];
vector<int>T[N],e[N];
ll ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;cin >> t;
	while(t--)
	{
		for(int i=1;i<=n;i++)
			T[i].clear(),e[i].clear(),d[i]=0;
		cin >> n >> m,ans=0;
		for(int i=1;i<=m;i++)
		{
			cin >> x[i] >> y[i];
			d[x[i]]++,d[y[i]]++;
			T[x[i]].pb(y[i]);
			T[y[i]].pb(x[i]);
		}
		for(int i=1;i<=m;i++)
		{
			if(d[x[i]]<d[y[i]]||(d[x[i]]==d[y[i]]&&x[i]<y[i]))
				e[x[i]].pb(y[i]);
			else e[y[i]].pb(x[i]); 
		}
		for(int u=1;u<=n;u++)
		{
			ans+=1ll*d[u]*(d[u]-1)/2;
			for(auto v:e[u])
			{
				vis[v]=1;
				for(auto w:T[v])
					if(d[w]>d[u]||(d[w]==d[u]&&w>u))
						ans+=tag[w],tag[w]++;
			}
			for(auto v:e[u])
				for(auto w:e[v])
					if(vis[w])ans+=3;
			for(auto v:e[u])
			{
				vis[v]=0;
				for(auto w:T[v])
					if(d[w]>d[u]||(d[w]==d[u]&&w>u))
						tag[w]=0;
			}
		}
		if(n+m>3)ans+=1ll*m*(n+m-3);
		cout << ans%P << endl;
	}
	return 0;
}
