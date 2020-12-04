#include <bits/stdc++.h>
// #include <climits>
// #include <iostream>
// #include <vector>
// #include <utility>
using namespace std;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second
#define rep(i,L,R) for (int i = L; i < R; ++i)
#define rrep(i,L,R) for (int i = R; i > L; --i)
#define each(x, a) for (auto& x: a)
#define nndl "\n"

using ul = unsigned long;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using ii = pair<int, int>;

template<class T> void read(T& x) {
    cin >> x;
}
template <class H, class... T>
void read(H& h, T&... t) {
    cin >> h;
    read(t...);
}
template<class T> void read(vector<T>& v) {
    each(x, v)
        read(x);
}
template<class A> void write(A x) {
	cout << x;
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}
template<class T> void print(vector<T>& v) {
    each(x, v)
        write(x, " ");
    write("\n");
}

// code

char getNext(char c, int k) {
    int pos = c - 'a';
    return 'a' + (pos + 1) % k;
}

char getPrev(char c, int k) {
    int pos = c - 'a';
    return 'a' + (pos - 1 + k) % k;
}

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    vector<string> dp(n+1, string(1, 'z'+1));
    dp[0] = "";
    rep(i, 0, n) {
        int c = s[i] - 'a';
        int nc = min({c, (c + 1) % k, (c - 1 + k) % k});
        dp[i+1] = min(dp[i+1], dp[i] + char('a' + nc));
        if (i > 0) {
            // L
            dp[i+1] = min(dp[i+1], dp[i].substr(0, i-1) + s[i] + dp[i].back());
            // RU, RD
            dp[i+1] = min(dp[i+1], dp[i-1] + char('a' + nc) + s[i-1]);
        }
        if (i > 1) {
            // RL
            dp[i+1] = min(dp[i+1], dp[i-1].substr(0, i-2) + s[i] + dp[i-1].back() + s[i-1]);
        }
    }

    cout << dp[n] << nndl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}