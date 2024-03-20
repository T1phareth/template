#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fir first
#define sec second
const int P=1e9+7;
using namespace std;
int my_pow(ll x,int y,int p)
{
	x%=p;
	int z=1;
	while(y)
	{
		if(y&1)z=1ll*x*z%p;
		x=1ll*x*x%p,y/=2;
	}
	return z;
}
struct node
{
	int l,r;
	mutable ll v;
	node(int l,int r,ll v):l(l),r(r),v(v){}
	bool operator<(const node&o)const{return l<o.l;}
};
set<node>tr;
auto split(int pos)
{
	auto it=tr.lower_bound(node(pos,0,0));
	if(it!=tr.end()&&it->l==pos)return it;
	it--;
	int l=it->l,r=it->r;
	ll v=it->v;
	tr.erase(it);
	tr.insert(node(l,pos-1,v));
	return tr.insert(node(pos,r,v)).fir;
}
int n,m,seed,vmax,ret;
int rnd()
{
	ret=seed;
	seed=(1ll*seed*7+13)%P;
	return ret;
}
void assign(int l,int r,int v)
{
	auto end=split(r+1),it=split(l),begin=it;
//	for(;it!=end;it++)n-=(it->r-it->l+1)*it->v;
	tr.erase(begin,end);
	tr.insert(node(l,r,v));
//	n+=(r-l+1)*v;
}
void add(int l,int r,int v)
{
	auto end=split(r+1);
	for(auto it=split(l);it!=end;it++)
		it->v+=v;
}
ll kth(int l,int r,int k)
{
	auto end=split(r+1);
	vector<pair<ll,int>>v;
	for(auto it=split(l);it!=end;it++)
		v.pb({it->v,it->r-it->l+1});
	sort(v.begin(),v.end());
	for(auto e:v)
	{
		k-=e.sec;
		if(k<=0)return e.fir;
	}
}
int sum_of_pow(int l,int r,int x,int y)
{
	int ans=0;
	auto end=split(r+1);
	for(auto it=split(l);it!=end;it++)
		ans=(ans+1ll*my_pow(it->v,x,y)*(it->r-it->l+1))%y;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> seed >> vmax;
	for(int i=1;i<=n;i++)
		tr.insert(node(i,i,rnd()%vmax+1));
	for(int i=1;i<=m;i++)
	{
		int op,l,r,x,y;
		op=rnd()%4+1;
		l=rnd()%n+1;
		r=rnd()%n+1;
		if(l>r)swap(l,r);
		if(op==3)x=rnd()%(r-l+1)+1;
		else x=rnd()%vmax+1;
		if(op==4)y=rnd()%vmax+1;
		
		if(op==1)add(l,r,x);
		else if(op==2)assign(l,r,x);
		else if(op==3)cout << kth(l,r,x) << endl;
		else cout << sum_of_pow(l,r,x,y) << endl;
	}
	return 0;
}
