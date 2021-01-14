#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repi(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vll vector<long long int>
#define vvll vector<vector<long long> >
#define vb vector<bool>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define mod 1000000007
#define mem1(x) memset(x,1,sizeof(x))
#define mem0(x) memset(x,0,sizeof(x))
#define memn1(x) memset(x,-1,sizeof(x))
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define inf 1e17+1
template<class x> x gcd(x a, x b) {return (b == 0) ? a : gcd(b, a % b);}
template<class x> x powerm(x a, x n) {if (n == 0)return 1; x b = powerm(a, n / 2) % mod; return (n & 1) ? ((b * b) % mod * a) % mod : (b * b) % mod;}
const int cnst = 200002;
int a[cnst] ,  pref[cnst];
int n, m;
struct node {
	int ma, mi, len, sum;
	node() {}
	node(int a, int b, int c, int d): mi(a), ma(b), len(c), sum(d) {}
} seg[4 * cnst];

node merge(node l, node r) {
	node ret;
	ret.mi = min(l.mi, r.mi);
	ret.ma = max(l.ma, r.ma);
	ret.sum = l.sum + r.sum;
	ret.len = l.len + r.len;
	return ret;
}

void build(int i = 1, int l = 0, int r = n) {
	if (l == r) {
		seg[i] = *new node(a[l], a[l], a[l], 1);
	}
	else {
		int mid = (l + r) / 2;
		build(i << 1, l, mid); build(i << 1 | 1, mid + 1, r);
		seg[i] = merge(seg[i << 1] , seg[i << 1 | 1]);
	}
}

node query(int ql, int qr, int i = 1, int l = 0, int r = n) {
	if (l > r || ql > r || qr < l) {
		return *new node(INT_MAX, INT_MIN, 0, 0);
	}
	else if (l >= ql && r <= qr) {
		return seg[i];
	}
	else {
		int mid = (l + r) / 2;
		return merge( query(ql, qr, i << 1, l, mid) , query(ql, qr, i << 1 | 1, mid + 1, r) );
	}
}

void update(int qi, int i = 1, int l = 0, int r = n) {
	if (i > r || i < l || l > r) {
		return;
	}
	else {
		int mid = (l + r) / 2;
		update(qi, i << 1, l, mid); update(qi, i << 1 | 1, mid + 1, r);
		seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
	}
}

void solve() {

}

int main() {
#ifndef ONLINE_JUDGE
	//for reading input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output in output.txt
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
