#include <bits/stdc++.h>
using namespace std;


struct Link { int gcdv, mn, mncnt; };

Link combine(Link a, Link b) {
	Link res;
	res.gcdv = __gcd(a.gcdv, b.gcdv);
	if (a.mn == INT_MAX) return b;
	if (b.mn == INT_MAX) return a;
	if (a.mn == b.mn) { res.mn = a.mn, res.mncnt = a.mncnt + b.mncnt; }
	else if (a.mn < b.mn) { res.mn = a.mn, res.mncnt = a.mncnt; }
	else { res.mn = b.mn, res.mncnt = b.mncnt; }
	return res;
}

struct Segtree {
    const static int N = 1e5;
    int n;
    vector<Link> t;
    Segtree(int n) { this->n = n; t.resize(2 * N); }

    void build(vector<int>& arr) {
		// leaves
        for (int i = 0; i < this->n; i++) {
			Link curr;
			curr.mn = curr.gcdv = arr[i]; curr.mncnt = 1;
			t[this->n+i] = curr;
		}
		// build links
        for (int i = this->n - 1; i > 0; i--) {
			t[i] = combine(t[i<<1], t[i<<1|1]);
		}
    }

    Link query(int l, int r) {
        Link left, right;
		left.mn = left.mncnt = left.gcdv = INT_MAX;
		right.mn = right.mncnt = right.gcdv = INT_MAX;
        for (l += this->n, r += this->n; l < r; l >>= 1, r >>= 1) {
            if (l&1) left = combine(left, t[l++]);
            if (r&1) right = combine(t[--r], right);
        }
        return combine(left, right);
    }
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	// cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		int n; cin >> n;
		Segtree tree(n);
		vector<int> a(n);
		for (int& i : a) cin >> i;
		tree.build(a);
		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			int l, r;
			cin >> l >> r;
			l--;
			Link res = tree.query(l, r);
			if (res.gcdv == res.mn) {
				cout << r - l - res.mncnt << endl;
			} else {
				cout << r - l << endl;
			}
		}
	}
}
