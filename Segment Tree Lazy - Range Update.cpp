void RangeUpdate(int node, int st, int end, int l, int r, long long val)
{
	if(Lazy[node] != 0)  // if node is lazy then update it
	{
		tree[node] += (end-st+1)*Lazy[node];
		
		if(st != end) // if its children exist then mark them lazy
		{
			Lazy[2*node] += Lazy[node];
			Lazy[2*node+1] += Lazy[node];
		}
		Lazy[node] = 0;  // No longer lazy
	}
	if( (end < l) || (st > r) ) // If current range doesn't lie inside query range.  
	{
		return ;	
	}	
	if(st >= l && end <= r) // if current range lies completely inside query range.
	{
		tree[node] += (end-st+1)*val;  
		if(st != end)
		{
			Lazy[2*node] += val; // mark its children lazy
			Lazy[2*node+1] += val; 
		}
		return;
	}
	/*Now current range partially overlaps with given range*/
	int mid = (st+end)/2;	
	RangeUpdate(2*node, st, mid, l, r, val);      //update left child
	RangeUpdate(2*node+1, mid+1, end, l, r, val); //update right child
	tree[node] = (tree[2*node] + tree[2*node+1]);  //change the current node value
	return; 
}


ll RangeSum(int node, int st, int end, int l, int r)
{
	/*If node is lazy, update it*/
	if(Lazy[node] != 0)
	{
		tree[node] += (end-st+1)*Lazy[node];
		if(st != end) /*Check if the children exist*/
		{
			Lazy[2*node] += Lazy[node];   /*mark child lazy*/
			Lazy[2*node+1] += Lazy[node]; /*mark child lazy*/
		}
		Lazy[node]=0;  /* no longer lazy */
	}
	/*if current range is out of query range*/
	if(end<l || st>r)
	{
		return 0;
	}
	/*if current range lies inside the query range*/
	if((l <= st) && (end <= r ))
	{
		return tree[node];
	}
	int mid = (st+end)/2;	
	/*Now current range partially overlaps wiht query range*/
	ll ans1 = RangeSum(2*node, st, mid, l, r);  //query left child 
	ll ans2 = RangeSum(2*node+1, mid+1, end, l, r);  // query right child
	return (ans1 + ans2);	
}
