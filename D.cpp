#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
	int l, r, a, b;
	node(int l, int r, int a, int b) {
		this->l = l;
		this->r = r;
		this->a = a;
		this->b = b;
	}
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n; cin >> n;
		map<pair<int,int>, pair<int,int>> p;
		for (int i = 0; i < n; i++) {
			int l, r, a, b;
			cin >> l >> r >> a >> b;
			if (p.find({l,r}) != p.end()) {
				int fa = p[{l,r}].first, fb = p[{l,r}].second;
				p[{l, r}] = {min(a,fa), max(b, fb)};
			} else {
				p[{l,r}] = {a, b};
			}
		}
		vector<node> arr;
		for (auto& point : p) {
			int l = point.first.first, r = point.first.second;
			int a = point.second.first, b = point.second.second;
			if (arr.empty()) {
				node v(l, r, a, b);
				arr.push_back(v);
			} else {
				auto ln = arr.back();
				if (l <= ln.r && ln.b >= l) {
					arr.pop_back();
					ln.a = min(a, ln.a);
					ln.b = max(b, ln.b);
					ln.r = max(ln.r, r);
					ln.l = min(ln.l, l);
					arr.push_back(ln);
				} else {
					arr.push_back(node(l, r, a, b));
				}
			}
		}
		// cout << "PRINTING NODES= " << endl;
		// for (auto& u : arr) {
		// 	cout << u.l << " " << u.r << " " << u.a << " " << u.b << endl;
 		// }


		int q; cin >> q;
		vector<int> original(q);
		vector<int> query(q);
		for (int i = 0; i < q; i++) {
			cin >> original[i];
			query[i] = original[i];
		}
		sort(query.begin(), query.end());
		// cout << "SORTED QUERIES" << endl;
		// for (int& i : query) {
		// 	cout << i << " ";
		// }
		// cout << endl;
		int ptr = 0;
		map<int,int> mapper;
		for (int i = 0; i < query.size(); i++) {
			int x = query[i];
			while (ptr < arr.size() && x > arr[ptr].r) {
				ptr++;
			}
			if (ptr == arr.size() || x < arr[ptr].l) {
				mapper[x] = x;
			} else {
				mapper[x] = max(x, arr[ptr].b);
				int ptr2 = ptr;
				while(ptr2 < arr.size()) {
					if (arr[ptr2].l > x) break;
					mapper[x] = max(mapper[x], arr[ptr2].b);
					ptr2++;
				}
			}
		}
		for (int i = 0; i < q; i++) {
			cout << mapper[original[i]] << " ";
		}
		cout << endl;
	}
	return 0;
}