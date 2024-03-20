/*
BFS分层
DFS只往层数高的地方走
多路增广，每次用尽流
当前弧优化，一条边只走一次 
*/
#include<bits/stdc++.h>
#define int long long
#define inf 1e10
using namespace std;
int n,m,s,t,ans;
int cnt=1,head[210],edge[10010],to[10010],nxt[10010];
int dep[210],cur[210];
queue<int>q;
int bfs()
{
	memset(dep,-1,sizeof(dep));
	memcpy(cur,head,sizeof(head));
	dep[s]=0,q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i],w=edge[i];
			if(dep[v]!=-1||edge[i]==0)continue;
			dep[v]=dep[u]+1,q.push(v);
		}
	}
	return dep[t]!=-1;
} 
int dfs(int u,int f)
{
	if(u==t)return f;
	int ret=f;
	for(int &i=cur[u];i&&ret;i=nxt[i])
	{
		int v=to[i],w=edge[i];
		if(w==0||dep[v]<=dep[u])continue;
		int r=dfs(v,min(ret,w));
		ret-=r,edge[i]-=r,edge[i^1]+=r;
	}
	return f-ret;
}
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		cnt++,edge[cnt]=w,to[cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
		cnt++,edge[cnt]=0,to[cnt]=u,nxt[cnt]=head[v],head[v]=cnt;
	}
	while(bfs())ans+=dfs(s,inf);
	printf("%lld\n",ans);
	return 0;
}
