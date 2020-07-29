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
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




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
 
const int MOD = 1000000007;  // 998244353
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);


ll N, M, K;
ll p[101][101];
ll C[101][101][101];
ll color[101];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N >> M >> K;

		F0R(i, N) cin >> color[i];
		F0R(i, N) F0R(j, M) cin >> p[i][j];

		ll finalans = INF;
		for (int i = 1; i <= N; i++) {
				for (int j = 0; j <= K; j++) {
						for (int k = 1; k <= M; k++) {
								if (j > i || j == 0) {
										C[i][j][k] = INF;
										continue;
								}

								if (color[i - 1] != 0 && color[i - 1] != k) {
										C[i][j][k] = INF;
								} else if (color[i - 1] == k) {
										// we don't pay anything to change colors.
										ll ans = INF;
										for (int x = 1; x <= M; x++) {
											if (x != k) {
														ans = MIN(ans, C[i - 1][j - 1][x]);
												} else {
														ans = MIN(ans, C[i - 1][j][x]);
												}
										}
										C[i][j][k] = ans;
								} else if (color[i - 1] == 0) {
										// we pay to color the ith tree with color k.
										ll ans = INF;
										
										for (int x = 1; x <= M; x++) {
												if (x != k) {
														if (j - 1 >= 0) ans = MIN(ans, p[i - 1][k - 1] + C[i - 1][j - 1][x]);
												} else {
														ans = MIN(ans, p[i - 1][k - 1] + C[i - 1][j][x]);
												}
										}
										C[i][j][k] = ans;
								}
								if (i == N && j == K) finalans = MIN(finalans, C[i][j][k]);
						}
				}
		}
		cout << (finalans == INF ? -1 : finalans) << endl;

}
