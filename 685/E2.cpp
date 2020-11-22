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
// vector<int> v;
int qand(int i, int j) {
    cout << "AND " << i+1 << " " << j+1 << endl;
    int res; cin >> res;
    // int res = v[i] & v[j];
    return res;
}

int qor(int i, int j) {
    cout << "OR " << i+1 << " " << j+1 << endl;
    int res; cin >> res;
    // int res = v[i] | v[j];
    return res;
}

int qxor(int i, int j) {
    cout << "XOR " << i+1 << " " << j+1 << endl;
    int res; cin >> res;
    // int res = v[i] ^ v[j];
    return res;
}

void solve() {
    int n; cin >> n;

    vector<int> res(n);

    vector<int> xors(n);
    for (int i = 1; i < n; ++i) {
        xors[i] = qxor(0, i);
    }

    unordered_map<int, int> seen;
    bool found = false; int a1, a2;
    for (int i = 1; i < n; ++i) {
        auto it = seen.find(xors[i]);
        if (it != seen.end()) {
            a1 = it->second; a2 = i;
            found = true;
            break;
        }
        seen[xors[i]] = i;
    }

    if (found) {
        // a1 == a2
        res[a1] = qand(a1, a2);
        res[0] = xors[a1] ^ res[a1];
    } else {
        // all unique
        for (int i = 1; i <= 2; ++i) {
            for (int j = i+1; j < n; ++j) {
                if ((xors[i] ^ xors[j]) == n - 1) {
                    a1 = i;
                    a2 = j;
                }
            }
        }
        // xor01, xor02, xor12
        int and01 = qand(0, a1), and02 = qand(0, a2);
        res[0] = ((xors[a1] + 2*and01) + (xors[a2] + 2*and02) - (n - 1)) / 2;
    }

    for (int i = 1; i < n; ++i) {
        res[i] = res[0] ^ xors[i];
    }

    cout << "!";
    for (auto c: res) cout << " " << c;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}