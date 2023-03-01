
#include<bits/stdc++.h>
using namespace std;
#define MX 100001
int a[MX];
/*
#define MX 100001
int a[MX],tr[4*MX+1];
void build(int nd,int st,int en,int a[])
{
	if(st==en)
	{
		tr[nd]=a[st];
		return;
	}
	int mid=(st+en)/2;
	build(nd*2+1,st,mid,a);
	build(nd*2+2,mid+1,en,a);
	tr[nd]=tr[nd*2+1]+tr[nd*2+2]; // for minimum query: tr[nd]=min(tr[nd*2+1],tr[nd*2+2]);
}
int query(int nd,int st,int en,int l,int r)
{
	//no-overlap
	// l-r st-en
	// or
	// st-en l-r
	if(st>r || en<l)
		return 0; // for min return INT_MAX;
	
	//complete overlap 
	// l st-en r
	if(l<=st && r>=en)
		return tr[nd];
	
	int mid=(st+en)/2;
	int left=query(nd*2+1,st,mid,l,r);
	int right=query(nd*2+2,mid+1,en,l,r);
	return left+right; // for minimum query: return min(left,right);
}
void update(int nd,int st,int en,int i,int val)
{
	if(st==en) // leaf node, so this index needs the update
	{
		tr[nd]=val;
		return;
	}
	int mid=(st+en)/2;
	if(i<=mid) // update lies in left part
		update(2*nd+1,st,mid,i,val);
	else // update lies in right part
		update(2*nd+2,mid+1,en,i,val);
	tr[nd]=tr[nd*2+1]+tr[nd*2+2]; // for minimum query: tr[nd]=min(tr[nd*2+1],tr[nd*2+2]);
}
*/


class SegTree{
	vector<int> tr;
public:
	SegTree(int n)
	{
		tr.resize(4*n+1);
	}
	void build(int nd,int st,int en,int a[])
	{
		if(st==en)
		{
			tr[nd]=a[st];
			return;
		}
		int mid=(st+en)/2;
		build(nd*2+1,st,mid,a);
		build(nd*2+2,mid+1,en,a);
		tr[nd]=tr[nd*2+1]+tr[nd*2+2]; // for minimum query: tr[nd]=min(tr[nd*2+1],tr[nd*2+2]);
	}
	int query(int nd,int st,int en,int l,int r)
	{
		//no-overlap
		// l-r st-en
		// or
		// st-en l-r
		if(st>r || en<l)
			return 0; // for min return INT_MAX;
		
		//complete overlap 
		// l st-en r
		if(l<=st && r>=en)
			return tr[nd];
		
		int mid=(st+en)/2;
		int left=query(nd*2+1,st,mid,l,r);
		int right=query(nd*2+2,mid+1,en,l,r);
		return left+right; // for minimum query: return min(left,right);
	}
	void update(int nd,int st,int en,int i,int val)
	{
		if(st==en) // leaf node, so this index needs the update
		{
			tr[nd]=val;
			return;
		}
		int mid=(st+en)/2;
		if(i<=mid) // update lies in left part
			update(2*nd+1,st,mid,i,val);
		else // update lies in right part
			update(2*nd+2,mid+1,en,i,val);
		tr[nd]=tr[nd*2+1]+tr[nd*2+2]; // for minimum query: tr[nd]=min(tr[nd*2+1],tr[nd*2+2]);
	}
};
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//build(0,0,n-1,a);
	
	SegTree tree1(n);
	tree1.build(0,0,n-1,a);
	int l,r;
	cin>>l>>r;
	cout<<tree1.query(0,0,n-1,l,r)<<endl;
	int i,x;
	cin>>i>>x;
	tree1.update(0,0,n-1,i,x);
	cin>>l>>r;
	cout<<tree1.query(0,0,n-1,l,r)<<endl;
	
	
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	SegTree tree2(n);
	tree2.build(0,0,n-1,a);
	cin>>l>>r;
	cout<<tree2.query(0,0,n-1,l,r)<<endl;
	cin>>i>>x;
	tree2.update(0,0,n-1,i,x);
	cin>>l>>r;
	cout<<tree2.query(0,0,n-1,l,r)<<endl;
	return 0;
}

/*
5 // n1
1 2 3 4 5
1 3 // query l-r
1 5 // update index 1 to 5
0 4 // query l-r

6 // n2
0 0 0 0 0 0
1 4 // query l-r
2 10 // update index 2 to 10
1 3 // query l-r
*/
