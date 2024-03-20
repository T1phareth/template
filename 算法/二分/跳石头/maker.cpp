#include<bits/stdc++.h>
#define MOD1 100000000
#define MOD2 50000
using namespace std;
map<int,bool>mp;
int l,n,m;
int a[MOD2+10];
int main()
{
	freopen("3.in","w",stdout);
	srand(time(NULL));
	l=1ll*rand()*rand()%MOD1;
	n=1ll*rand()*rand()%MOD2;
	m=1ll*rand()*rand()%n;
	mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		do a[i]=1ll*rand()*rand()%l;
		while(mp[a[i]]);
		mp[a[i]]=1;
	}
	sort(a+1,a+1+n);
	printf("%d %d %d\n",l,n,m);
	for(int i=1;i<=n;i++)
		printf("%d\n",a[i]);
	fclose(stdout);
	return 0;
}
