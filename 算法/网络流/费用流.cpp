const int N=5010,M=100010,inf=1e9;
int n,m,s,t,cnt=1,head[N],dis[N],pre[N],vis[N];
struct node{int u,v,w,c,nxt;}e[M];
void add(int u,int v,int w,int c){e[++cnt]={u,v,w,c,head[u]},head[u]=cnt;}
deque<int>q;
bool spfa()
{
	for(int i=1;i<=n;i++)dis[i]=inf;
	dis[s]=0,q.push_back(s);
	while(!q.empty())
	{
		int u=q.front();q.pop_front();
		if(u==t)continue;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(e[i].w==0||e[i].c+dis[u]>=dis[v])continue;
			dis[v]=e[i].c+dis[u],pre[v]=i;
			if(!vis[v])
			{
				vis[v]=1;
				if(q.empty()||dis[v]<dis[q.front()])
					q.push_front(v);
				else q.push_back(v);
			}
		}
		vis[u]=0;
	}
	return dis[t]<inf;
}
int main()
{
	//ÏÈ½¨Á¢ÍøÂç 
	int maxflow=0,ans=0;
	while(spfa())
	{
		int flow=inf;
		for(int i=t;i!=s;i=e[pre[i]].u)
			flow=min(flow,e[pre[i]].w);
		maxflow+=flow,ans+=dis[t]*flow;
		for(int i=t;i!=s;i=e[pre[i]].u)
			e[pre[i]].w-=flow,e[pre[i]^1].w+=flow;
	}
	printf("maxflow=%d cost=%d\n",maxflow,ans);
}
