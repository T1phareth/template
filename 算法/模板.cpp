//逆元 
inv[1]=1;
for(int i=2;i<=n;++i)
  inv[i]=MOD-(long long)MOD/i*inv[MOD%i]%MOD;

//笛卡尔树
int st[N], ls[N], rs[N], n, A[N];// ls代表笛卡尔树每个节点的左孩子，rs代表笛卡尔树每个节点的右孩子
int top = 0;
 
for (int i = 1; i <= n; ++i) 
{
    while (top && A[st[top]] > A[i]) ls[i] = st[top--]; //栈顶元素为当前元素的左孩子
    if (top) rs[st[top]] = i; //当前元素为栈顶元素的右孩子
    st[++top] = i;
}

//数位dp
#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[20],dp[20][状态];
int dfs(int pos,状态,int limit)
{
	if(pos==0)return 是否符合要求;
	if(!limit && dp[pos][状态]!=-1)
		return dp[pos][状态];
	int x=limit?a[pos]:9;
	int ret=0;
	for(int i=0;i<=x;i++)
		ret+=dfs(pos-1,新状态,limit&&i==x);
	if(!limit)dp[pos][状态]=ret;
	return ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	cnt=0;while(n)a[++cnt]=n%10,n/=10;
	printf("%d\n",dfs(cnt,状态,1));
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
