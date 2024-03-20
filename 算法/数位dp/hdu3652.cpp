//数位dp+记忆化搜索 
#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[20],dp[20][20][5];
int dfs(int pos,int sum,int state,int limit)
{
	//state 0--剩余状态，1--上一位是1，2--出现过13
	if(pos==0)return state==2&&sum==0;//做完了 
	if(!limit && dp[pos][sum][state]!=-1)
		return dp[pos][sum][state];//无限制记忆化
	int x=limit?a[pos]:9;//能到达的最大位数
	int ret=0;
	for(int i=0;i<=x;i++)
	{
		int nxt_sum=(sum*10+i)%13;
		int nxt_state=state;
		if(state==0&&i==1)nxt_state=1;
		if(state==1&&i!=1)nxt_state=0;
		if(state==1&&i==3)nxt_state=2;
		//状态转化 
		ret+=dfs(pos-1,nxt_sum,nxt_state,limit&&i==x);
	}
	if(!limit)dp[pos][sum][state]=ret;
	//无限制记忆化 
	return ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	while(scanf("%d",&n)!=EOF)
	{
		cnt=0;while(n)a[++cnt]=n%10,n/=10;
		//初始化 
		printf("%d\n",dfs(cnt,0,0,1));
	}
	return 0;
}
