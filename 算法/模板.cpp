//��Ԫ 
inv[1]=1;
for(int i=2;i<=n;++i)
  inv[i]=MOD-(long long)MOD/i*inv[MOD%i]%MOD;

//�ѿ�����
int st[N], ls[N], rs[N], n, A[N];// ls����ѿ�����ÿ���ڵ�����ӣ�rs����ѿ�����ÿ���ڵ���Һ���
int top = 0;
 
for (int i = 1; i <= n; ++i) 
{
    while (top && A[st[top]] > A[i]) ls[i] = st[top--]; //ջ��Ԫ��Ϊ��ǰԪ�ص�����
    if (top) rs[st[top]] = i; //��ǰԪ��Ϊջ��Ԫ�ص��Һ���
    st[++top] = i;
}

//��λdp
#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[20],dp[20][״̬];
int dfs(int pos,״̬,int limit)
{
	if(pos==0)return �Ƿ����Ҫ��;
	if(!limit && dp[pos][״̬]!=-1)
		return dp[pos][״̬];
	int x=limit?a[pos]:9;
	int ret=0;
	for(int i=0;i<=x;i++)
		ret+=dfs(pos-1,��״̬,limit&&i==x);
	if(!limit)dp[pos][״̬]=ret;
	return ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	cnt=0;while(n)a[++cnt]=n%10,n/=10;
	printf("%d\n",dfs(cnt,״̬,1));
	return 0;
}

//exgcd
int Exgcd(int a,int b,int &x,int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int d = Exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
