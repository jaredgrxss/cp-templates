#include <bits/stdc++.h>
using namespace std;


void solve() {
	string s;
	cin >> s;
	int n=s.length();
	if(n==1){
		if(s[0]=='^'){
			cout << 1 << endl;
			return;
		} else {
			cout << 2 << endl;
			return;
		}
	}
	stack<char> st;
	int ans=0;
	for(int i=0; i<n; i++){
		if((st.empty() && s[i]=='_') || (st.top()=='_' && s[i]=='_')){
			ans++;
			st.push('^');
		} 
		st.push(s[i]);
	}
	ans = (st.top()=='_') ? ans + 1 : ans;
	cout << ans << endl;
	return;
}
int main()
{
	int tc; 
	cin >> tc;
	while(tc--) solve();
	return 0;
}