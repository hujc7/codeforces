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
#define endl "\n"

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
const int maxn = 1e6+5;
vector<ll> primes;
void solve() {
    ll n; cin >> n;
    ll nn = n;
    unordered_map<ll, int> counts;
    int length = 1, factor = nn;
    for (auto& p: primes) {
        if (nn % p == 0) {
            auto it = counts.emplace(p, 0).first;
            while (nn % p == 0) {
                it->second++;
                nn /= p;
            }
            if (it->second > length) {
                length = it->second;
                factor = p;
            }
        }
    }
    if (nn > 1) counts[nn]++;

    nn = n;
    cout << length << endl;
    rep(i, 0, length-1) {
        cout << factor << " ";
        nn /= factor;
    }
    cout << nn << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<bool> isPrime(maxn, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= maxn; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= maxn; j += i) {
            isPrime[j] = false;
        }
    }

    rep(i, 2, maxn) {
        if (isPrime[i])
            primes.push_back(i);
    }

    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}