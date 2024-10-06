#include <bits/stdc++.h>
using namespace std;


struct Segtree {
    const static int N = 1e6;
    int n;
    int *t = new int[2 * N];
    Segtree(int n) { this->n = n; }

    void build(vector<int>& arr) {
        for (int i = 0; i < this->n; ++i) t[this->n+i] = arr[i];
		int nodes = this->n / 2, used = 0, orp = 1;
		for (int i = this->n - 1; i > 0; i--) {
			if (orp) t[i] = t[i<<1] | t[i<<1|1];
			else t[i] = t[i<<1] ^ t[i<<1|1];
			used++;
			if (used == nodes) {
				nodes /= 2;
				used = 0;
				orp ^= 1;
			}
		}
    };

    void modify(int p, int v) {
		int orp = 1;
		for (t[p += this->n] = v; p > 1; p >>= 1) {
			if (orp) {
				int x = t[p] | t[p^1];
				t[p>>1] = t[p] | t[p^1];
			} else {
				int x = t[p] ^ t[p^1];
				t[p>>1] = t[p] ^ t[p^1];
			}
			orp ^= 1;
		}
    };

	int query() { return t[1]; }

	void deleteT() {
		delete this->t;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	// cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		int n, m; cin >> n >> m;
		vector<int> a(pow(2,n));
		for (int& i : a) cin >> i;
		Segtree tree(pow(2,n));
		tree.build(a);
		for (int i = 0; i < m; i++) {
			int p, b; cin >> p >> b;
			p--;
			tree.modify(p, b);
			cout << tree.query() << endl;
		}
		tree.deleteT();
	}
}
