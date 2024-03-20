#include<bits/stdc++.h>
#define pb push_back
#define fir first
#define sec second
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e4+10,M=1e7+10;
typedef pair<int,int> pii;
int n,m,s,rt,q[N],d[N],sz[N],mx[N];
bool tf[M],vis[N],ans[N];
vector<pii>e[N];
void calc1(int u,int f)
{
	sz[u]=1;
	mx[u]=0;
	for(auto E:e[u])
	{
		int v=E.fir,w=E.sec;
		if(v==f||vis[v])continue;
		calc1(v,u);
		mx[u]=max(mx[u],sz[v]);
		sz[u]+=sz[v];
	}
	mx[u]=max(mx[u],s-sz[u]);
	if(mx[u]<mx[rt])rt=u;
}
queue<int>tmp,tag;
void calc2(int u,int f)
{
	for(int i=1;i<=m;i++)
		if(q[i]>=d[u])
			ans[i]|=tf[q[i]-d[u]];
	if(d[u]<M)tmp.push(d[u]);
	for(auto E:e[u])
	{
		int v=E.fir,w=E.sec;
		if(v==f||vis[v])continue;
		d[v]=d[u]+w,calc2(v,u);
	}
}
void dfz(int u,int f)
{
	tf[0]=true;
	tag.push(0);
	vis[u]=true;
	for(auto E:e[u])
	{
		int v=E.fir,w=E.sec; 
		if(v==f||vis[v])continue;
		d[v]=w,calc2(v,u);
		while(!tmp.empty())
		{
			int t=tmp.front();tmp.pop();
			tag.push(t),tf[t]=true;
		}
	}
	while(!tag.empty())
		tf[tag.front()]=false,tag.pop();
	for(auto E:e[u])
	{
		int v=E.fir,w=E.sec;
		if(v==f||vis[v])continue;
		rt=0,s=sz[v];
		calc1(v,u);
		calc1(rt,0);
		dfz(rt,0);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		e[x].pb({y,z});
		e[y].pb({x,z});
	}
	for(int i=1;i<=m;i++)
		cin >> q[i];
	rt=0,s=n;
	mx[rt]=inf;
	calc1(1,0);
	calc1(rt,0);
	dfz(rt,0);
	for(int i=1;i<=m;i++)
		if(ans[i])
			cout << "AYE\n";
		else cout << "NAY\n";
	return 0;
}
