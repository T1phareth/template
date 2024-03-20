#include<bits/stdc++.h>
using namespace std;
int l,n,m,a[50010],ans;
bool check(int dis)
{
	int count=0,last=0;
	for(int i=1;i<=n;i++)
		if(a[i]-last<dis)count++;
		else last=a[i];
//	cout<<count<<endl;
	return count<=m;
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d%d%d",&l,&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[++n]=l;
	int ll=0,rr=l;
	while(ll<=rr)
	{
		int mid=(ll+rr)/2;
//		cout<<ll<<" "<<rr<<" "<<mid<<endl; 
		if(check(mid))
			ll=mid+1,ans=mid;
		else rr=mid-1;
	}
	printf("%d\n",ans);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
