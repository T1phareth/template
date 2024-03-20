#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+10;
int n,m;
int dis[N];
int idx,dfn[N],low[N];
int top,st[N];
int tot=1,head[N],nxt[N<<1],to[N<<1];
bool used[N<<1];
bool flag1,flag2,flag3;
int d[N];
int sz;
void add(int u,int v)
{
	tot++;
	to[tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
int dfs(int u)
{
	int tmp=1;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(dis[v])
		{
			if((dis[u]&1)+(dis[v]&1)!=1)
				flag1=true;
		}
		else dis[v]=dis[u]+1,tmp+=dfs(v);
	}
	return tmp;
}
void tarjan(int u)
{
	int f=0;
	dfn[u]=low[u]=++idx;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(used[i])continue;
		used[i]=used[i^1]=1;
		st[++top]=i;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v])
			{
				int j,num=0;
				do{
					j=st[top--];
					num++;
				}while(i!=j);
				if(num%2==0)flag2=true;
				if(num%2==1&&num>3)flag3=true;
			}
		}
		else low[u]=min(low[u],dfn[v]);
		if(low[v]<dfn[u])f++;
	}
	if(f>1)flag2=true;
}
bool check1()
{
	return flag3;
}
bool check2()
{
	for(int u=1;u<=n;u++)
	{
		if(d[u]==2)
		{
			int v1=to[head[u]],v2=to[nxt[head[u]]];
			if(d[v1]>2||d[v2]>2)return true;
			if(d[v1]==2)
			{
				int v3=to[head[v1]]+to[nxt[head[v1]]]-u;
				if(v3!=v2)return true;
			}
			if(d[v2]==2)
			{
				int v3=to[head[v2]]+to[nxt[head[v2]]]-u;
				if(v3!=v1)return true;
			}
		}
		else if(d[u]>=3)
		{
			for(int i=head[u];i;i=nxt[i])
			{
				int v=to[i];
				if(d[v]>1)return true;
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
		d[x]++;
		d[y]++;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dis[i]=1,sz=max(sz,dfs(i)),tarjan(i);
	if(n<=3)cout << "-1\n";
	else if(flag1&&flag2)cout << "0\n";
	else if(flag2)cout << "1\n";
	else if(flag1)
	{
		if(check1()||check2())cout << "1\n";
		else cout << "2\n";
	}
	else if(sz>=4)cout << "2\n";
	else cout << 5-min(m,2) << endl;
	return 0;
}
