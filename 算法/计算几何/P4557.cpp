#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
struct Node
{
	ll x,y;
	Node operator - (Node A) {return (Node){x-A.x,y-A.y};}
	Node operator + (Node A) {return (Node){x+A.x,y+A.y};}
	Node operator * (ll A) {return (Node){x*A,y*A};}
	ll operator * (Node A) const {return x*A.y-y*A.x;}
	ll len() const {return x*x+y*y;}
}A[N],C1[N],C2[N],s1[N],s2[N];
ll cmp1(const Node&A,const Node&B) {return A.y<B.y||(A.y==B.y&&A.x<B.x);}
ll cmp2(const Node&A,const Node&B) {return A*B>0||(A*B==0&&A.len()<B.len());}
ll n,m,sta[N],top,q,totA,totB,totC;
void Convex(Node *A,ll &n)
{
	sort(A+1,A+n+1,cmp1);
	A[0]=A[1];sta[top=1]=1;
	for(ll i=1;i<=n;i++) A[i]=A[i]-A[0];
	sort(A+2,A+n+1,cmp2);
	for(ll i=2;i<=n;sta[++top]=i,i++)
		while(top>=2&&(A[i]-A[sta[top-1]])*(A[sta[top]]-A[sta[top-1]])>=0) top--;
	for(ll i=1;i<=top;i++) A[i]=A[sta[i]]+A[0];
	n=top;A[n+1]=A[1];
}
void Minkowski(Node *C1,Node *C2,Node *A,ll &tot)
{
	for(ll i=1;i<n;i++) s1[i]=C1[i+1]-C1[i];s1[n]=C1[1]-C1[n];
	for(ll i=1;i<m;i++) s2[i]=C2[i+1]-C2[i];s2[m]=C2[1]-C2[m];
	A[tot=1]=C1[1]+C2[1];
	ll p1=1,p2=1;
	while(p1<=n&&p2<=m) ++tot,A[tot]=A[tot-1]+(s1[p1]*s2[p2]>=0?s1[p1++]:s2[p2++]);
	while(p1<=n) ++tot,A[tot]=A[tot-1]+s1[p1++];
	while(p2<=m) ++tot,A[tot]=A[tot-1]+s2[p2++];
}
ll in(Node a,Node *A,ll tot)
{
	if(a*A[2]>0||A[tot]*a>0||(a*A[2]==0&&a.len()>A[2].len())||(A[tot]*a==0&&a.len()>A[tot].len())) return 0;
	ll ps=lower_bound(A+1,A+tot+1,a,cmp2)-A-1;
	return (a-A[ps])*(A[ps%tot+1]-A[ps])<=0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> q;
	for(ll i=1;i<=n;i++)
		cin >> C1[i].x >> C1[i].y;
	Convex(C1,n);
	for(ll i=1;i<=m;i++)
		cin >> C2[i].x >> C2[i].y,C2[i]=C2[i]*-1;
	Convex(C2,m);
	Minkowski(C1,C2,A,totA),Convex(A,totA);
	A[0]=A[1];for(ll i=totA;i>=1;i--)A[i]=A[i]-A[0];
	while(q--)
	{
		Node tmp;cin >> tmp.x >> tmp.y;
		cout << in(tmp-A[0],A,totA) << endl;
	}
	return 0;
}
