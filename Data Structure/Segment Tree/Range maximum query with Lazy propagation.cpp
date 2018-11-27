/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 */
#include<iostream>
#include<algorithm>
using namespace std;
#define N 20
#define MAX (1+(1<<6)) /// Why? :D
#define inf 0x7fffffff
int arr[N];
int tree[MAX];
int lazy[MAX];
void build_tree(int node, int a, int b) {
  	if(a > b) return; /// Out of range

  	if(a == b) { /// Leaf node
    		tree[node] = arr[a]; /// Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); /// Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); /// Init right child

	tree[node] = max(tree[node*2], tree[node*2+1]); /// Init root value
}

void update_tree(int node, int a, int b, int i, int j, int value) {

  	if(lazy[node] != 0) { /// This node needs to be updated
   		tree[node] += lazy[node]; /// Update it
		if(a != b) {
			lazy[node*2] += lazy[node]; /// Mark child as lazy
    			lazy[node*2+1] += lazy[node]; /// Mark child as lazy
		}

   		lazy[node] = 0; /// Reset it
  	}

	if(a > b || a > j || b < i) /// Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { /// Segment is fully within range
    		tree[node] += value;
		if(a != b) { /// Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}
    		return;
	}
	update_tree(node*2, a, (a+b)/2, i, j, value); /// Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); /// Updating right child
	tree[node] = max(tree[node*2], tree[node*2+1]); /// Updating root with max value
}
/** Query tree to get max element value within range [i, j]  */
int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return -inf; /// Out of range

	if(lazy[node] != 0) { /// This node needs to be updated
		tree[node] += lazy[node]; /// Update it
		if(a != b) {
			lazy[node*2] += lazy[node]; /// Mark child as lazy
			lazy[node*2+1] += lazy[node]; /// Mark child as lazy
		}
		lazy[node] = 0; /// Reset it
	}
	if(a >= i && b <= j) /// Current segment is totally within range [i, j]
		return tree[node];
	int q1 = query_tree(node*2, a, (a+b)/2, i, j); /// Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); /// Query right child
	int res = max(q1, q2); /// Return final result
	return res;
}
