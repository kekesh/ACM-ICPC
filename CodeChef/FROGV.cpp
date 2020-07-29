#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>

 
using namespace std;
 
typedef string str;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pair<ll, ll>> vpl;

#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto &a : x)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"
 
const int MOD = /* 998244353; */ 1000000007;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


class UnionFind {
		private:
				vector<ll> parent, rank;

		public:
				UnionFind(int sz) {
						parent.resize(sz, 0);
						rank.resize(sz, 0);

						for (int i = 0; i < sz; i++) parent[i] = i;
				}

				int findSet(int u) {
						return (parent[u] == u ? u : parent[u] = findSet(parent[u]));
				}

				bool inSameSet(int u, int v) {
						return findSet(u) == findSet(v);
				}

				void unionSet(int u, int v) {
						int x = findSet(u), y = findSet(v);
						if (x == y) return;
						if (rank[x] > rank[y]) {
								parent[y] = x;
						} else {
								parent[x] = y;
								if (rank[x] == rank[y]) {
										rank[y]++;
								}
						}
				}
};

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);

		ll n, k, p;
		cin >> n >> k >> p;
		vpl a(n + 1);
		F0R(i, n) cin >> a[i + 1].f, a[i + 1].s = i + 1;
		sort(a.begin(), a.end());
		UnionFind uf(n + 1);
		for (int i = 1; i < n; i++) {
				if (a[i + 1].f - a[i].f <= k && !uf.inSameSet(a[i].s, a[i + 1].s)) {
						uf.unionSet(a[i].s, a[i + 1].s);
				}
		}

		while (p--) {
				ll a, b;

				cin >> a >> b;

				bool ok = uf.inSameSet(a, b);

				if (ok) cout << "Yes" << endl;
				else cout << "No" << endl;
		}
}
