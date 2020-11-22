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

    // v.resize(n);
    // for (int i = 0; i < n; ++i) {
    //     v[i] = rand() & n;
    // }
    // for (auto c: v) cout << c << " ";
    // cout << endl;

    // a + b = a^b + 2*(a&b);
    vector<int> res(n);

    int xor01 = qxor(0, 1), xor12 = qxor(1,2), xor02 = xor01 ^ xor12;
    int and01 = qand(0, 1), and02 = qand(0, 2), and12 = qand(1, 2);
    int x = xor01 + 2*and01;
    int y = xor02 + 2*and02;
    int z = xor12 + 2*and12;

    int a0 = (x + y - z) / 2;
    res[0] = a0;
    res[1] = x - a0;
    res[2] = y - a0;

    for (int i = 3; i < n; ++i) {
        int tmp = qxor(0, i);
        res[i] = a0 ^ tmp;
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