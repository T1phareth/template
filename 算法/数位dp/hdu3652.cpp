//��λdp+���仯���� 
#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[20],dp[20][20][5];
int dfs(int pos,int sum,int state,int limit)
{
	//state 0--ʣ��״̬��1--��һλ��1��2--���ֹ�13
	if(pos==0)return state==2&&sum==0;//������ 
	if(!limit && dp[pos][sum][state]!=-1)
		return dp[pos][sum][state];//�����Ƽ��仯
	int x=limit?a[pos]:9;//�ܵ�������λ��
	int ret=0;
	for(int i=0;i<=x;i++)
	{
		int nxt_sum=(sum*10+i)%13;
		int nxt_state=state;
		if(state==0&&i==1)nxt_state=1;
		if(state==1&&i!=1)nxt_state=0;
		if(state==1&&i==3)nxt_state=2;
		//״̬ת�� 
		ret+=dfs(pos-1,nxt_sum,nxt_state,limit&&i==x);
	}
	if(!limit)dp[pos][sum][state]=ret;
	//�����Ƽ��仯 
	return ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	while(scanf("%d",&n)!=EOF)
	{
		cnt=0;while(n)a[++cnt]=n%10,n/=10;
		//��ʼ�� 
		printf("%d\n",dfs(cnt,0,0,1));
	}
	return 0;
}
