#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 1;
struct Node
{
	int ma = INT_MIN, mi = INT_MAX, cnt = 0;
	void assign(int a, int b, int c)
	{
		ma = a;
		mi = b;
		cnt = c;
	}
} seg[4 * mx];
int a[mx], n;

Node merge(Node left, Node right)
{
	Node x;
	x.ma = max(left.ma, right.ma);
	x.mi = min(left.mi, right.mi);
	x.cnt = (left.cnt + right.cnt);
	return x;
}

void build(int i = 1, int l = 0, int r = n - 1)
{
	if (l > r)
		return;
	if (l == r)
	{
		seg[i].assign(a[l], a[l], 1);
	}
	else
	{
		int mid = l + (r - l) / 2;
		build(i << 1, l, mid);
		build(i << 1 | 1, mid + 1, r);
		seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
	}
}

Node query(int ql, int qr, int i = 1, int l = 0, int r = n - 1)
{
	if (r < ql || l > qr)
		return *new Node();
	if (r <= qr && l >= ql)
		return seg[i];
	int mid = l + (r - l) / 2;
	Node left = query(ql, qr, i << 1, l, mid);
	Node right = query(ql, qr, i << 1 | 1, mid + 1, r);
	return merge(left, right);
}

void pointupdate(int ind, int val, int i = 1, int l = 0, int r = n - 1)
{
	if (l > ind || r < ind || l > r)
		return;
	if (l == r)
		seg[i].assign(val, val, 0);
	else
	{
		int mid = l + (r - l) / 2;
		pointupdate(ind, val, i << 1, l, mid);
		pointupdate(ind, val, i << 1 | 1, mid + 1, r);
		seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i <= n - 1; i++) cin >> a[i];
	build();
	int l, r;
	cin >> l >> r;
	Node res = query(l - 1, r - 1);
	cout << res.ma << " " << res.mi << " " << res.cnt << endl;
	int ind, val;
	cin >> ind >> val;
	pointupdate(ind - 1, val);
	res = query(l - 1, r - 1);
	cout << res.ma << " " << res.mi << " " << res.cnt << endl;

}


/*
sample input
5
1 2 -3 -4 5
1 4
2 -6
sample output
2 -4 4
1 -6 3
*/
