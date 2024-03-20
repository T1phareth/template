//数位dp+记忆化搜索 
#include<bits/stdc++.h>
using namespace std;
int T,a,b,cnt,t[20],p[20],dp[20][5000];
int dfs(int pos,int sum,int limit)
{
	if(sum<0)return 0;
	if(pos==0)return 1;
	if(!limit && dp[pos][sum]!=-1)
		return dp[pos][sum];
	int x=limit?p[pos]:9;
	int ret=0;
	for(int i=0;i<=x;i++)
		ret+=dfs(pos-1,sum-i*t[pos],limit&&i==x);
	if(!limit)dp[pos][sum]=ret;
	return ret;
}
int f(int x)
{
	int ret=0,ct=1;
	while(x)
	{
		ret+=t[ct]*(x%10);
		x/=10,ct++;
	}
	return ret;
}
int main()
{
	memset(dp,-1,sizeof(dp)),t[1]=1;
	for(int i=2;i<=10;i++)t[i]=t[i-1]*2;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d",&a,&b);
		cnt=0;while(b)p[++cnt]=b%10,b/=10;
		printf("Case #%d: %d\n",i,dfs(cnt,f(a),1));
	}
	return 0;
}
