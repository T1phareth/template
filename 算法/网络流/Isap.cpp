/*
��ǰ���Ż�&��·���� 
һ������һ��������û���꣬�ͽ�������������������µĿ��� 
ĳһ�������ŵĵ�����˶ϲ㣬�϶��޽� 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=110,M=100010,inf=1e9;
int n,m,s,t,cnt=1,head[N],cur[N],level[210],gap[210];
//gap[i]��ʾ������(level)��i�ĵ�ĸ��� 
struct node{int v,w,nxt;}e[M];
void add(int u,int v,int w){e[++cnt]={v,w,head[u]},head[u]=cnt;}
int sap(int u,int flow)
{
	if(u==t)return flow;
	int rec=0;//���Ѿ����˶��� 
	for(int &i=cur[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(level[u]!=level[v]+1||e[i].w==0)continue;
		int ret=sap(v,min(flow-rec,e[i].w));
		e[i].w-=ret,e[i^1].w+=ret,rec+=ret;
		if(rec==flow)return flow;
	}
	gap[level[u]]--;
	if(gap[level[u]]==0)level[s]=n;
	level[u]++,gap[level[u]]++;
	cur[u]=head[u];
	return rec;
}
int main()
{
	//�Ƚ������� 
	memcpy(cur,head,sizeof(head));
	int maxflow=0;gap[0]=n;
	while(level[s]<n)maxflow+=sap(s,inf);
	printf("maxflow=%d\n",maxflow);
	return 0;
}
