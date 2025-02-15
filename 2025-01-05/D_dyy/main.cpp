#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll gcd(ll a, ll b){ 
	return b ? gcd(b, a % b) : a; 
}

void solve() {
	int n, x, y, u, v;
	ll ans = 0;
	map<pair<int, int>, ll> mp;
	
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		int dx, dy;
		ll g;
		scanf("%d%d%d%d", &x, &y, &u, &v);
		dx=u-x, dy=v-y;
		g = gcd(abs(dx), abs(dy));
		dx /= g, dy /= g;
		mp[make_pair(dx, dy)]++;
		ans += mp[make_pair(-dx, -dy)];
	}
	printf("%lld\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--){
		solve();
	}
	return 0;
}
