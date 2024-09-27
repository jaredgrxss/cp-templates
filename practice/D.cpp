#include <bits/stdc++.h>
using namespace std;


struct Segtree {
    const static int N = 1e5;
    int n;
    int t[2 * N];
    Segtree(int n) { this->n = n; }

    void build(vector<int>& arr) {
        for (int i = 0; i < this->n; i++) t[this->n+i] = arr[i];
		int h = 0;
		int tn = 2 * n;
		while (tn > 0) {
			h++;
			tn >>= 1;
		}
		for (int l = n, r = 2 * n; l < r; l >>= 1, r >>= 1) {
			if (h & 1) {
				
			}
		}
    };

    void modify() {

    }

    int query() {
        return t[1];
    }
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	// cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		int n, m; cin >> n >> m;
		vector<int> a(n);
		for (int& i : a) cin >> i;
		Segtree tree(n);
		tree.build(a);
		for (int i = 0; i < 1; i++) {
			int p, b; cin >> p >> b;
			cout << tree.query() << endl;
		}
	}
}
