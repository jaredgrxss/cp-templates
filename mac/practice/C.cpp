#include <bits/stdc++.h>
using namespace std;

struct Node {
	int len, open, closed;
};

Node combine(Node ln, Node rn) {
	Node res;
	if (ln.len == INT_MAX) return rn;
	if (rn.len == INT_MAX) return ln;
	int valid = min(ln.open, rn.closed);
	res.len = ln.len + rn.len + 2 * valid;
	res.open = ln.open + rn.open - valid;
	res.closed = ln.closed + rn.closed - valid;
	return res;
}

struct Segtree {
    const static int N = 1e6;
    int n;
    Node *t = new Node[2 * N];
    Segtree(int n) { this->n = n; }

    void build(string& s) {
        for (int i = 0; i < this->n; i++) {
			Node curr; 
			curr.open = (s[i] == '(');
			curr.closed = (s[i] == ')');
			curr.len = 0;	
			t[this->n+i] = curr;
		}
        for (int i = this->n - 1; i > 0; i--) {
			t[i] = combine(t[i<<1], t[i<<1|1]);
		}
    };

    Node query(int l, int r) {
        Node lans, rans;
		lans.len = rans.len = INT_MAX;
        for (l += this->n, r += this->n; l < r; l >>= 1, r >>= 1) {
            if (l&1) lans = combine(lans, t[l++]);
            if (r&1) rans = combine(t[--r], rans);
        }
        return combine(lans, rans);
    }
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	// cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		string s; cin >> s;
		Segtree tree(s.length());
		tree.build(s);
		int q; cin >> q;
		for (int i = 0; i < q; i++) {
			int l, r; cin >> l >> r;
			l--;
			Node ans = tree.query(l, r);
			cout << ans.len << endl;
		}
	}
}
