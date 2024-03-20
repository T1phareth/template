#include<bits/stdc++.h>
const int P1=39989;
const int P2=1e9;
const int N=1e5+10;
const double eps=1e-9;
using namespace std;
int cmp(double x,double y)
{
	if(x-y>eps)return 1;
	if(y-x>eps)return -1;
	return 0;
}
struct line{double k,b;}l[N];
double calc(int id,int x){return l[id].k*x+l[id].b;}
int n,m,lastans,tr[N<<2];
void add(int x0,int y0,int x1,int y1)
{
	m++;
	if(x0==x1)
		l[m].k=0,l[m].b=max(y0,y1);
	else
		l[m].k=1.0*(y1-y0)/(x1-x0),
		l[m].b=y0-l[m].k*x0;
}
#define ls (nw<<1)
#define rs (ls+1)
#define mid (l+r>>1)
void upd(int nw,int l,int r,int x)
{
	int &y=tr[nw];
	if(cmp(calc(x,mid),calc(y,mid))==1)swap(x,y);
//	if(l==r)return;
//	因为没加这句话死过 
	int L=cmp(calc(x,l),calc(y,l));
	int R=cmp(calc(x,r),calc(y,r));
	if(L==1||(L==0&&x<y))upd(ls,l,mid,x);
	if(R==1||(R==0&&x<y))upd(rs,mid+1,r,x);
}
void update(int nw,int l,int r,int ql,int qr,int x)
{
	if(ql<=l&&r<=qr)
	{
		upd(nw,l,r,x);
		return;
	}
	if(ql<=mid)update(ls,l,mid,ql,qr,x);
	if(qr>mid)update(rs,mid+1,r,ql,qr,x);
}
int query(int nw,int l,int r,int x)
{
	if(l==r)return tr[nw];
	int res;
	if(x<=mid)res=query(ls,l,mid,x);
	else res=query(rs,mid+1,r,x);
	int tmp=cmp(calc(res,x),calc(tr[nw],x));
	if(tmp==1||(tmp==0&&res<tr[nw]))return res;
	return tr[nw];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	while(n--)
	{
		int op;
		cin >> op;
		if(op)
		{
			int x0,y0,x1,y1;
			cin >> x0 >> y0 >> x1 >> y1;
			x0=(x0+lastans-1+P1)%P1+1;
			x1=(x1+lastans-1+P1)%P1+1;
			y0=(y0+lastans-1+P2)%P2+1;
			y1=(y1+lastans-1+P2)%P2+1;
			if(x0>x1)swap(x0,x1),swap(y0,y1);
			add(x0,y0,x1,y1);
			update(1,1,P1,x0,x1,m);
		}
		else
		{
			int k;
			cin >> k;
			k=(k+lastans-1+P1)%P1+1;
			lastans=query(1,1,P1,k);
			cout << lastans << endl;
		}
	}
	return 0;
}
