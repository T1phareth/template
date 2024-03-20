#include<bits/stdc++.h>
#define ll long long
const int N=1e5+10;
using namespace std;
int n,X[N<<1],tr[N<<3],c[N<<3],s[N<<3];
bool fl[N<<3],fr[N<<3];
struct node{int t,l,r,x;}p[N<<1];
bool cmp(node a,node b){return a.t==b.t?a.x>b.x:a.t<b.t;}
#define ls (nw<<1)
#define rs (ls+1)
#define mid (l+r>>1)
void up(int nw,int l,int r)
{
	if(c[nw])
	{
		tr[nw]=X[r+1]-X[l];
		s[nw]=1;
		fl[nw]=true;
		fr[nw]=true;
	}
	else if(l!=r)
	{
		tr[nw]=tr[ls]+tr[rs];
		s[nw]=s[ls]+s[rs];
		fl[nw]=fl[ls];
		fr[nw]=fr[rs];
		if(fr[ls]&&fl[rs])s[nw]--;
	}
	else
	{
		tr[nw]=0;
		s[nw]=0;
		fl[nw]=false;
		fr[nw]=false;
	}
}
void update(int nw,int l,int r,int ql,int qr,int x)
{
	if(ql<=X[l]&&X[r+1]<=qr)
	{
		c[nw]+=x;
		up(nw,l,r);
		return;
	}
	if(ql<X[mid+1])update(ls,l,mid,ql,qr,x);
	if(qr>X[mid+1])update(rs,mid+1,r,ql,qr,x);
	up(nw,l,r);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int x1,x2,y1,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		p[i*2-1]={y1,x1,x2,1};
		p[i*2]={y2,x1,x2,-1};
		X[i*2-1]=x1,X[i*2]=x2;
	}
	n<<=1;
	sort(p+1,p+1+n,cmp);
	sort(X+1,X+1+n);
	int tot=unique(X+1,X+1+n)-X-1;
	ll ans=0,lst=0;
	for(int i=1;i<n;i++)
	{
		update(1,1,tot-1,p[i].l,p[i].r,p[i].x);
//		ans+=1ll*tr[1]*(p[i+1].t-p[i].t);
//		求面积 
		ans+=abs(lst-tr[1]),lst=tr[1];
		ans+=2ll*s[1]*(p[i+1].t-p[i].t);
//		求周长 
	}
	ans+=p[n].r-p[n].l;
	cout << ans << endl;
	return 0;
}
