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
const ll INF = 2e14;
vector<char> cmds;
vector<vector<int>> nums;
vector<int> skips;

unordered_map<ll, ll> memo;
ll combine(ll index, ll x) {
    return index*1e10 + x;
}

ll dfs(int index, int x, int s) {
    if (x == s) return INF;
    if (index == cmds.size()) return 0;

    ll unique = combine(index, x);
    auto it = memo.find(unique);
    if (it != memo.end()) return it->second;

    ll res = LLONG_MAX;
    if (cmds[index] == 's') {
        // set or skip
        res = min(dfs(index+1, nums[index][0], s),
                  nums[index][1] + dfs(index+1, x, s));
    } else if (cmds[index] == 'i') {
        if (x == nums[index][0]) res = min(res, dfs(index+1, x, s));
        else res = min(res, dfs(skips[index]+1, x, s));
    } else {
        res = min(res, dfs(index+1, x, s));
    }

    return memo[unique] = res;
}

void solve() {
    int n, s; cin >> n >> s;
    cmds.resize(n);;
    nums.resize(n);
    skips.resize(n);

    stack<int> stk;
    rep(i,0,n) {
        string cmd; cin >> cmd;
        cmds[i] = cmd.front();

        int tmp;
        if (cmd.front() == 's') {
            cin >> tmp;
            nums[i].push_back(tmp);
            cin >> tmp;
            nums[i].push_back(tmp);
        } else if (cmd.front() == 'i') {
            cin >> tmp;
            nums[i].push_back(tmp);
            stk.push(i);
        } else {
            skips[stk.top()] = i;
            stk.pop();
        }
    }

    ll res = dfs(0, 0, s);
    cout << res << nndl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // int t; cin >> t;
    // while (t--)
    solve();

    return 0;
}