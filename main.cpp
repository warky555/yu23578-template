#pragma region yu23578

#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
#ifndef DEBUG
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define rep(i,N) for(ll i = 0; i < N; ++i)
#define rrep(i,N) for(ll i = N - 1; i >= 0; --i)
#define drep(i,be,en) for(ll i = be; i < en; ++i)
#define rdrep(i,be,en) for(ll i = en - 1; i >= be; --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define YN(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
using namespace std;
using namespace atcoder;
using mint = modint998244353;
//using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vvvvl = vector<vvvl>;
using vvvvvl = vector<vvvvl>;
using vvvvvvl = vector<vvvvvl>;
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;
using vvvvm = vector<vvvm>;
using vd = vector<ld>;
using vvd = vector<vd>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;
using vvpl = vector<vpl>;

template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (int i = 0; i < (int)v.size(); i++) os << v[i] << (i + 1 != (int)v.size() ? " " : ""); return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) { for (int i = 0; i < (int)v.size(); i++) os << v[i] << endl; return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v) { for (int i = 0; i < (int)v.size(); i++) { os << "i = " << i << endl; os << v[i]; } return os; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
template <typename T, typename S> ostream &operator<<(ostream &os, const map<T, S> &mp) { for (auto &[key, val] : mp) os << key << ":" << val << " "; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &st) { auto itr = st.begin(); for (int i = 0; i < (int)st.size(); i++) { os << *itr << (i + 1 != (int)st.size() ? " " : ""); itr++; } return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &st) { auto itr = st.begin(); for (int i = 0; i < (int)st.size(); i++) { os << *itr << (i + 1 != (int)st.size() ? " " : ""); itr++; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> q) { while (q.size()) { os << q.front() << " "; q.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, deque<T> q) { while (q.size()) { os << q.front() << " "; q.pop_front(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> st) { while (st.size()) { os << st.top() << " "; st.pop(); } return os; }
template <class T, class Container, class Compare> ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> pq) { while (pq.size()) { os << pq.top() << " "; pq.pop(); } return os; }
ostream &operator<<(ostream &os, const mint &i) { os << i.val(); return os; }
ostream &operator<<(ostream &os, const vector<mint> &v) { for (int i = 0; i < (int)v.size(); i++) os << v[i].val() << (i + 1 != (int)v.size() ? " " : ""); return os; }

//https://qiita.com/hamamu/items/4d081751b69aa3bb3557
//////////////// 以下を貼る ////////////////
template<class T> size_t HashCombine(const size_t seed,const T &v){
    return seed^(std::hash<T>()(v)+0x9e3779b9+(seed<<6)+(seed>>2));
}
/* pair用 */
template<class T,class S> struct std::hash<std::pair<T,S>>{
    size_t operator()(const std::pair<T,S> &keyval) const noexcept {
        return HashCombine(std::hash<T>()(keyval.first), keyval.second);
    }
};
/* vector用 */
template<class T> struct std::hash<std::vector<T>>{
    size_t operator()(const std::vector<T> &keyval) const noexcept {
        size_t s=0;
        for (auto&& v: keyval) s=HashCombine(s,v);
        return s;
    }
};
/* tuple用 */
template<int N> struct HashTupleCore{
    template<class Tuple> size_t operator()(const Tuple &keyval) const noexcept{
        size_t s=HashTupleCore<N-1>()(keyval);
        return HashCombine(s,std::get<N-1>(keyval));
    }
};
template <> struct HashTupleCore<0>{
    template<class Tuple> size_t operator()(const Tuple &keyval) const noexcept{ return 0; }
};
template<class... Args> struct std::hash<std::tuple<Args...>>{
    size_t operator()(const tuple<Args...> &keyval) const noexcept {
        return HashTupleCore<tuple_size<tuple<Args...>>::value>()(keyval);
    }
};
////////////////////////////////////////////

template<typename T> using ve = vector<T>;
template<class T> using pq = priority_queue<T, ve<T>>;//大きい順
template<class T> using pq_g = priority_queue<T, ve<T>, greater<T>>;//小さい順
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}

const ll dx[4] = {1,0,0,-1};
const ll dy[4] = {0,-1,1,0};
const ll hdx[8] = {1,1,0,-1,-1,-1,0,1};
const ll hdy[8] = {0,1,1,1,0,-1,-1,-1};
const ll INF = 3e18;
const ld pi = 3.1415926535897932384626; 

/**
 * @brief 線形漸化式の高速計算
 * @docs docs/fps/kitamasa.md
 * FormalPowerSeries<mint> f(K + 1);
 */
//NTT,FFTなどいろいろ
namespace POLYOMINAL{template <typename mint>
struct NTT {
	static constexpr uint32_t get_pr() {
	uint32_t _mod = mint::mod();
	using u64 = uint64_t;
	u64 ds[32] = {};
	int idx = 0;
	u64 m = _mod - 1;
	for (u64 i = 2; i * i <= m; ++i) {
		if (m % i == 0) {
		ds[idx++] = i;
		while (m % i == 0) m /= i;
		}
	}
	if (m != 1) ds[idx++] = m;

	uint32_t _pr = 2;
	while (1) {
		int flg = 1;
		for (int i = 0; i < idx; ++i) {
			u64 a = _pr, b = (_mod - 1) / ds[i], r = 1;
			while (b) {
				if (b & 1) r = r * a % _mod;
				a = a * a % _mod;
				b >>= 1;
			}
			if (r == 1) {
				flg = 0;
				break;
			}
		}
		if (flg == 1) break;
		++_pr;
	}
	return _pr;
	};

	static constexpr uint32_t mod = mint::mod();
	static constexpr uint32_t pr = get_pr();
	static constexpr int level = __builtin_ctzll(mod - 1);
	mint dw[level], dy[level];

	void setwy(int k) {
	mint w[level], y[level];
	w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));
	y[k - 1] = w[k - 1].inv();
	for (int i = k - 2; i > 0; --i)
		w[i] = w[i + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];
	dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] = y[2];
	for (int i = 3; i < k; ++i) {
		dw[i] = dw[i - 1] * y[i - 2] * w[i];
		dy[i] = dy[i - 1] * w[i - 2] * y[i];
	}
	}

	NTT() { setwy(level); }

	void fft4(vector<mint> &a, int k) {
	if ((int)a.size() <= 1) return;
	if (k == 1) {
		mint a1 = a[1];
		a[1] = a[0] - a[1];
		a[0] = a[0] + a1;
		return;
	}
	if (k & 1) {
		int v = 1 << (k - 1);
		for (int j = 0; j < v; ++j) {
		mint ajv = a[j + v];
		a[j + v] = a[j] - ajv;
		a[j] += ajv;
		}
	}
	int u = 1 << (2 + (k & 1));
	int v = 1 << (k - 2 - (k & 1));
	mint one = mint(1);
	mint imag = dw[1];
	while (v) {
		// jh = 0
		{
		int j0 = 0;
		int j1 = v;
		int j2 = j1 + v;
		int j3 = j2 + v;
		for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
			mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
			mint t0p2 = t0 + t2, t1p3 = t1 + t3;
			mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
			a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
			a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
		}
		}
		// jh >= 1
		mint ww = one, xx = one * dw[2], wx = one;
		for (int jh = 4; jh < u;) {
		ww = xx * xx, wx = ww * xx;
		int j0 = jh * v;
		int je = j0 + v;
		int j2 = je + v;
		for (; j0 < je; ++j0, ++j2) {
			mint t0 = a[j0], t1 = a[j0 + v] * xx, t2 = a[j2] * ww,
				t3 = a[j2 + v] * wx;
			mint t0p2 = t0 + t2, t1p3 = t1 + t3;
			mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
			a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;
			a[j2] = t0m2 + t1m3, a[j2 + v] = t0m2 - t1m3;
		}
		xx *= dw[__builtin_ctzll((jh += 4))];
		}
		u <<= 2;
		v >>= 2;
	}
	}

	void ifft4(vector<mint> &a, int k) {
	if ((int)a.size() <= 1) return;
	if (k == 1) {
		mint a1 = a[1];
		a[1] = a[0] - a[1];
		a[0] = a[0] + a1;
		return;
	}
	int u = 1 << (k - 2);
	int v = 1;
	mint one = mint(1);
	mint imag = dy[1];
	while (u) {
		// jh = 0
		{
		int j0 = 0;
		int j1 = v;
		int j2 = v + v;
		int j3 = j2 + v;
		for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
			mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
			mint t0p1 = t0 + t1, t2p3 = t2 + t3;
			mint t0m1 = t0 - t1, t2m3 = (t2 - t3) * imag;
			a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;
			a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;
		}
		}
		// jh >= 1
		mint ww = one, xx = one * dy[2], yy = one;
		u <<= 2;
		for (int jh = 4; jh < u;) {
		ww = xx * xx, yy = xx * imag;
		int j0 = jh * v;
		int je = j0 + v;
		int j2 = je + v;
		for (; j0 < je; ++j0, ++j2) {
			mint t0 = a[j0], t1 = a[j0 + v], t2 = a[j2], t3 = a[j2 + v];
			mint t0p1 = t0 + t1, t2p3 = t2 + t3;
			mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;
			a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;
			a[j0 + v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;
		}
		xx *= dy[__builtin_ctzll(jh += 4)];
		}
		u >>= 4;
		v <<= 2;
	}
	if (k & 1) {
		u = 1 << (k - 1);
		for (int j = 0; j < u; ++j) {
		mint ajv = a[j] - a[j + u];
		a[j] += a[j + u];
		a[j + u] = ajv;
		}
	}
	}

	void ntt(vector<mint> &a) {
	if ((int)a.size() <= 1) return;
	fft4(a, __builtin_ctz(a.size()));
	}

	void intt(vector<mint> &a) {
	if ((int)a.size() <= 1) return;
	ifft4(a, __builtin_ctz(a.size()));
	mint iv = mint(a.size()).inv();
	for (auto &x : a) x *= iv;
	}

	vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
	int l = a.size() + b.size() - 1;
	if (min<int>(a.size(), b.size()) <= 40) {
		vector<mint> s(l);
		for (int i = 0; i < (int)a.size(); ++i)
		for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];
		return s;
	}
	int k = 2, M = 4;
	while (M < l) M <<= 1, ++k;
	setwy(k);
	vector<mint> s(M);
	for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i];
	fft4(s, k);
	if (a.size() == b.size() && a == b) {
		for (int i = 0; i < M; ++i) s[i] *= s[i];
	} else {
		vector<mint> t(M);
		for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];
		fft4(t, k);
		for (int i = 0; i < M; ++i) s[i] *= t[i];
	}
	ifft4(s, k);
	s.resize(l);
	mint invm = mint(M).inv();
	for (int i = 0; i < l; ++i) s[i] *= invm;
	return s;
	}

	void ntt_doubling(vector<mint> &a) {
	int M = (int)a.size();
	auto b = a;
	intt(b);
	mint r = 1, zeta = mint(pr).pow((mint::mod() - 1) / (M << 1));
	for (int i = 0; i < M; i++) b[i] *= r, r *= zeta;
	ntt(b);
	copy(begin(b), end(b), back_inserter(a));
	}
};

template <typename mint>
struct FormalPowerSeries : vector<mint> {
	using vector<mint>::vector;
	using FPS = FormalPowerSeries;

	FPS &operator+=(const FPS &r) {
	if (r.size() > this->size()) this->resize(r.size());
	for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];
	return *this;
	}

	FPS &operator+=(const mint &r) {
	if (this->empty()) this->resize(1);
	(*this)[0] += r;
	return *this;
	}

	FPS &operator-=(const FPS &r) {
	if (r.size() > this->size()) this->resize(r.size());
	for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];
	return *this;
	}

	FPS &operator-=(const mint &r) {
	if (this->empty()) this->resize(1);
	(*this)[0] -= r;
	return *this;
	}

	FPS &operator*=(const mint &v) {
	for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;
	return *this;
	}

	FPS &operator/=(const FPS &r) {
	if (this->size() < r.size()) {
		this->clear();
		return *this;
	}
	int n = this->size() - r.size() + 1;
	if ((int)r.size() <= 64) {
		FPS f(*this), g(r);
		g.shrink();
		mint coeff = g.back().inv();
		for (auto &x : g) x *= coeff;
		int deg = (int)f.size() - (int)g.size() + 1;
		int gs = g.size();
		FPS quo(deg);
		for (int i = deg - 1; i >= 0; i--) {
		quo[i] = f[i + gs - 1];
		for (int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];
		}
		*this = quo * coeff;
		this->resize(n, mint(0));
		return *this;
	}
	return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();
	}

	FPS &operator%=(const FPS &r) {
	*this -= *this / r * r;
	shrink();
	return *this;
	}

	FPS operator+(const FPS &r) const { return FPS(*this) += r; }
	FPS operator+(const mint &v) const { return FPS(*this) += v; }
	FPS operator-(const FPS &r) const { return FPS(*this) -= r; }
	FPS operator-(const mint &v) const { return FPS(*this) -= v; }
	FPS operator*(const FPS &r) const { return FPS(*this) *= r; }
	FPS operator*(const mint &v) const { return FPS(*this) *= v; }
	FPS operator/(const FPS &r) const { return FPS(*this) /= r; }
	FPS operator%(const FPS &r) const { return FPS(*this) %= r; }
	FPS operator-() const {
	FPS ret(this->size());
	for (int i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];
	return ret;
	}

	void shrink() {
	while (this->size() && this->back() == mint(0)) this->pop_back();
	}

	FPS rev() const {
	FPS ret(*this);
	reverse(begin(ret), end(ret));
	return ret;
	}

	FPS dot(FPS r) const {
	FPS ret(min(this->size(), r.size()));
	for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];
	return ret;
	}

	// 前 sz 項を取ってくる。sz に足りない項は 0 埋めする
	FPS pre(int sz) const {
	FPS ret(begin(*this), begin(*this) + min((int)this->size(), sz));
	if ((int)ret.size() < sz) ret.resize(sz);
	return ret;
	}

	FPS operator>>(int sz) const {
	if ((int)this->size() <= sz) return {};
	FPS ret(*this);
	ret.erase(ret.begin(), ret.begin() + sz);
	return ret;
	}

	FPS operator<<(int sz) const {
	FPS ret(*this);
	ret.insert(ret.begin(), sz, mint(0));
	return ret;
	}

	FPS diff() const {
	const int n = (int)this->size();
	FPS ret(max(0, n - 1));
	mint one(1), coeff(1);
	for (int i = 1; i < n; i++) {
		ret[i - 1] = (*this)[i] * coeff;
		coeff += one;
	}
	return ret;
	}

	FPS integral() const {
	const int n = (int)this->size();
	FPS ret(n + 1);
	ret[0] = mint(0);
	if (n > 0) ret[1] = mint(1);
	auto mod = mint::mod();
	for (int i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);
	for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];
	return ret;
	}

	mint eval(mint x) const {
	mint r = 0, w = 1;
	for (auto &v : *this) r += w * v, w *= x;
	return r;
	}

	FPS log(int deg = -1) const {
	assert(!(*this).empty() && (*this)[0] == mint(1));
	if (deg == -1) deg = (int)this->size();
	return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
	}

	FPS pow(int64_t k, int deg = -1) const {
	const int n = (int)this->size();
	if (deg == -1) deg = n;
	if (k == 0) {
		FPS ret(deg);
		if (deg) ret[0] = 1;
		return ret;
	}
	for (int i = 0; i < n; i++) {
		if ((*this)[i] != mint(0)) {
		mint rev = mint(1) / (*this)[i];
		FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg);
		ret *= (*this)[i].pow(k);
		ret = (ret << (i * k)).pre(deg);
		if ((int)ret.size() < deg) ret.resize(deg, mint(0));
		return ret;
		}
		if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));
	}
	return FPS(deg, mint(0));
	}

	static void *ntt_ptr;
	static void set_fft();
	FPS &operator*=(const FPS &r);
	void ntt();
	void intt();
	void ntt_doubling();
	static int ntt_pr();
	FPS inv(int deg = -1) const;
	FPS exp(int deg = -1) const;
};
template <typename mint>
void *FormalPowerSeries<mint>::ntt_ptr = nullptr;

/**
 * @brief 多項式/形式的冪級数ライブラリ
 * @docs docs/fps/formal-power-series.md
 */

template <typename mint>
void FormalPowerSeries<mint>::set_fft() {
  if (!ntt_ptr) ntt_ptr = new NTT<mint>;
}

template <typename mint>
FormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(
	const FormalPowerSeries<mint>& r) {
	if (this->empty() || r.empty()) {
		this->clear();
		return *this;
	}
	set_fft();
	auto ret = static_cast<NTT<mint>*>(ntt_ptr)->multiply(*this, r);
	return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());
}

template <typename mint>
void FormalPowerSeries<mint>::ntt() {
	set_fft();
	static_cast<NTT<mint>*>(ntt_ptr)->ntt(*this);
}

template <typename mint>
void FormalPowerSeries<mint>::intt() {
	set_fft();
	static_cast<NTT<mint>*>(ntt_ptr)->intt(*this);
}

template <typename mint>
void FormalPowerSeries<mint>::ntt_doubling() {
	set_fft();
	static_cast<NTT<mint>*>(ntt_ptr)->ntt_doubling(*this);
}

template <typename mint>
int FormalPowerSeries<mint>::ntt_pr() {
	set_fft();
	return static_cast<NTT<mint>*>(ntt_ptr)->pr;
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {
	assert((*this)[0] != mint(0));
	if (deg == -1) deg = (int)this->size();
	FormalPowerSeries<mint> res(deg);
	res[0] = {mint(1) / (*this)[0]};
	for (int d = 1; d < deg; d <<= 1) {
	FormalPowerSeries<mint> f(2 * d), g(2 * d);
	for (int j = 0; j < min((int)this->size(), 2 * d); j++) f[j] = (*this)[j];
	for (int j = 0; j < d; j++) g[j] = res[j];
	f.ntt();
	g.ntt();
	for (int j = 0; j < 2 * d; j++) f[j] *= g[j];
	f.intt();
	for (int j = 0; j < d; j++) f[j] = 0;
	f.ntt();
	for (int j = 0; j < 2 * d; j++) f[j] *= g[j];
	f.intt();
	for (int j = d; j < min(2 * d, deg); j++) res[j] = -f[j];
	}
	return res.pre(deg);
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int deg) const {
	using fps = FormalPowerSeries<mint>;
	assert((*this).size() == 0 || (*this)[0] == mint(0));
	if (deg == -1) deg = this->size();

	fps inv;
	inv.reserve(deg + 1);
	inv.push_back(mint(0));
	inv.push_back(mint(1));

	auto inplace_integral = [&](fps& F) -> void {
	const int n = (int)F.size();
	auto mod = mint::mod();
	while ((int)inv.size() <= n) {
		int i = inv.size();
		inv.push_back((-inv[mod % i]) * (mod / i));
	}
	F.insert(begin(F), mint(0));
	for (int i = 1; i <= n; i++) F[i] *= inv[i];
	};

	auto inplace_diff = [](fps& F) -> void {
	if (F.empty()) return;
	F.erase(begin(F));
	mint coeff = 1, one = 1;
	for (int i = 0; i < (int)F.size(); i++) {
		F[i] *= coeff;
		coeff += one;
	}
	};

	fps b{1, 1 < (int)this->size() ? (*this)[1] : 0}, c{1}, z1, z2{1, 1};
	for (int m = 2; m < deg; m *= 2) {
	auto y = b;
	y.resize(2 * m);
	y.ntt();
	z1 = z2;
	fps z(m);
	for (int i = 0; i < m; ++i) z[i] = y[i] * z1[i];
	z.intt();
	fill(begin(z), begin(z) + m / 2, mint(0));
	z.ntt();
	for (int i = 0; i < m; ++i) z[i] *= -z1[i];
	z.intt();
	c.insert(end(c), begin(z) + m / 2, end(z));
	z2 = c;
	z2.resize(2 * m);
	z2.ntt();
	fps x(begin(*this), begin(*this) + min<int>(this->size(), m));
	x.resize(m);
	inplace_diff(x);
	x.push_back(mint(0));
	x.ntt();
	for (int i = 0; i < m; ++i) x[i] *= y[i];
	x.intt();
	x -= b.diff();
	x.resize(2 * m);
	for (int i = 0; i < m - 1; ++i) x[m + i] = x[i], x[i] = mint(0);
	x.ntt();
	for (int i = 0; i < 2 * m; ++i) x[i] *= z2[i];
	x.intt();
	x.pop_back();
	inplace_integral(x);
	for (int i = m; i < min<int>(this->size(), 2 * m); ++i) x[i] += (*this)[i];
	fill(begin(x), begin(x) + m, mint(0));
	x.ntt();
	for (int i = 0; i < 2 * m; ++i) x[i] *= y[i];
	x.intt();
	b.insert(end(b), begin(x) + m, end(x));
	}
	return fps{begin(b), begin(b) + deg};
}

/**
 * @brief NTT mod用FPSライブラリ
 * @docs docs/fps/ntt-friendly-fps.md
 */

template <typename mint>
mint LinearRecurrence(long long k, FormalPowerSeries<mint> Q,
                      FormalPowerSeries<mint> P) {
	Q.shrink();
	mint ret = 0;
	if (P.size() >= Q.size()) {
	auto R = P / Q;
	P -= R * Q;
	P.shrink();
	if (k < (int)R.size()) ret += R[k];
	}
	if ((int)P.size() == 0) return ret;

	FormalPowerSeries<mint>::set_fft();
	if (FormalPowerSeries<mint>::ntt_ptr == nullptr) {
	P.resize((int)Q.size() - 1);
	while (k) {
		auto Q2 = Q;
		for (int i = 1; i < (int)Q2.size(); i += 2) Q2[i] = -Q2[i];
		auto S = P * Q2;
		auto T = Q * Q2;
		if (k & 1) {
		for (int i = 1; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
		for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
		} else {
		for (int i = 0; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
		for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
		}
		k >>= 1;
	}
	return ret + P[0];
	} else {
	int N = 1;
	while (N < (int)Q.size()) N <<= 1;

	P.resize(2 * N);
	Q.resize(2 * N);
	P.ntt();
	Q.ntt();
	vector<mint> S(2 * N), T(2 * N);

	vector<int> btr(N);
	for (int i = 0, logn = __builtin_ctz(N); i < (1 << logn); i++) {
		btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (logn - 1));
	}
	mint dw = mint(FormalPowerSeries<mint>::ntt_pr())
					.inv()
					.pow((mint::mod() - 1) / (2 * N));

	while (k) {
		mint inv2 = mint(2).inv();

		// even degree of Q(x)Q(-x)
		T.resize(N);
		for (int i = 0; i < N; i++) T[i] = Q[(i << 1) | 0] * Q[(i << 1) | 1];

		S.resize(N);
		if (k & 1) {
		// odd degree of P(x)Q(-x)
		for (auto &i : btr) {
			S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] -
					P[(i << 1) | 1] * Q[(i << 1) | 0]) *
					inv2;
			inv2 *= dw;
		}
		} else {
		// even degree of P(x)Q(-x)
		for (int i = 0; i < N; i++) {
			S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] +
					P[(i << 1) | 1] * Q[(i << 1) | 0]) *
					inv2;
		}
		}
		swap(P, S);
		swap(Q, T);
		k >>= 1;
		if (k < N) break;
		P.ntt_doubling();
		Q.ntt_doubling();
	}
	P.intt();
	Q.intt();
	return ret + (P * (Q.inv()))[k];
	}
}

template <typename mint>
mint kitamasa(long long N, FormalPowerSeries<mint> Q,
				FormalPowerSeries<mint> a) {
	assert(!Q.empty() && Q[0] != 0);
	if (N < (int)a.size()) return a[N];
	assert((int)a.size() >= int(Q.size()) - 1);
	auto P = a.pre((int)Q.size() - 1) * Q;
	P.resize(Q.size() - 1);
	return LinearRecurrence<mint>(N, Q, P);
}
}
using namespace POLYOMINAL;

//https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
//永続セグ木。使い方 -> https://atcoder.jp/contests/abc453/submissions/76510651
template< typename Monoid >
struct PersistentSegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
 
  struct Node {
    Monoid data;
    Node *l, *r;
 
    Node(const Monoid &data) : data(data), l(nullptr), r(nullptr) {}
  };
 
 
  int sz;
  const F f;
  const Monoid M1;
 
  PersistentSegmentTree(const F f, const Monoid &M1) : f(f), M1(M1) {}
 
  Node *build(vector< Monoid > &v) {
    sz = (int) v.size();
    return build(0, (int) v.size(), v);
  }
 
  Node *merge(Node *l, Node *r) {
    auto t = new Node(f(l->data, r->data));
    t->l = l;
    t->r = r;
    return t;
  }
 
  Node *build(int l, int r, vector< Monoid > &v) {
    if(l + 1 >= r) return new Node(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }
 
  Node *update(int a, const Monoid &x, Node *k, int l, int r) {
    if(r <= a || a + 1 <= l) {
      return k;
    } else if(a <= l && r <= a + 1) {
      return new Node(x);
    } else {
      return merge(update(a, x, k->l, l, (l + r) >> 1), update(a, x, k->r, (l + r) >> 1, r));
    }
  }
 
  Node *update(Node *t, int k, const Monoid &x) {
    return update(k, x, t, 0, sz);
  }
 
  Monoid query(int a, int b, Node *k, int l, int r) {
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {
      return k->data;
    } else {
      return f(query(a, b, k->l, l, (l + r) >> 1),
               query(a, b, k->r, (l + r) >> 1, r));
    }
  }
 
  Monoid query(Node *t, int a, int b) {
    return query(a, b, t, 0, sz);
  }
};

//https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
template <class S, S (*op)(S, S), S (*e)()> class dynamic_segtree {
public:
    dynamic_segtree(size_t n) : n(n), root(nullptr) {}

    void set(size_t p, S x) {
        assert(p < n);
        set(root, 0, n, p, x);
    }

    S get(size_t p) const {
        assert(p < n);
        return get(root, 0, n, p);
    }

    S prod(size_t l, size_t r) const {
        assert(l <= r && r <= n);
        return prod(root, 0, n, l, r);
    }

    S all_prod() const { return root ? root->product : e(); }

    void reset(size_t l, size_t r) {
        assert(l <= r && r <= n);
        return reset(root, 0, n, l, r);
    }

    template <bool (*f)(S)> size_t max_right(size_t l) const {
        return max_right(l, [](S x) { return f(x); });
    }

    template <class F> size_t max_right(size_t l, const F& f) const {
        assert(l <= n);
        S product = e();
        assert(f(product));
        return max_right(root, 0, n, l, f, product);
    }

    template <bool (*f)(S)> size_t min_left(size_t r) const {
        return min_left(r, [](S x) { return f(x); });
    }

    template <class F> size_t min_left(size_t r, const F& f) const {
        assert(r <= n);
        S product = e();
        assert(f(product));
        return min_left(root, 0, n, r, f, product);
    }

private:
    struct node;
    using node_ptr = std::unique_ptr<node>;

    struct node {
        size_t index;
        S value, product;
        node_ptr left, right;

        node(size_t index, S value)
            : index(index),
			value(value),
			product(value),
            left(nullptr),
            right(nullptr) {}

        void update() {
            product = op(op(left ? left->product : e(), value),
                        right ? right->product : e());
        }
    };

    const size_t n;
    node_ptr root;

    void set(node_ptr& t, size_t a, size_t b, size_t p, S x) const {
        if (!t) {
            t = std::make_unique<node>(p, x);
            return;
        }
        if (t->index == p) {
            t->value = x;
            t->update();
            return;
        }
        size_t c = (a + b) >> 1;
        if (p < c) {
            if (t->index < p) std::swap(t->index, p), std::swap(t->value, x);
            set(t->left, a, c, p, x);
        } else {
            if (p < t->index) std::swap(p, t->index), std::swap(x, t->value);
            set(t->right, c, b, p, x);
        }
        t->update();
    }

    S get(const node_ptr& t, size_t a, size_t b, size_t p) const {
        if (!t) return e();
        if (t->index == p) return t->value;
        size_t c = (a + b) >> 1;
        if (p < c) return get(t->left, a, c, p);
        else return get(t->right, c, b, p);
    }

    S prod(const node_ptr& t, size_t a, size_t b, size_t l, size_t r) const {
        if (!t || b <= l || r <= a) return e();
        if (l <= a && b <= r) return t->product;
        size_t c = (a + b) >> 1;
        S result = prod(t->left, a, c, l, r);
        if (l <= t->index && t->index < r) result = op(result, t->value);
        return op(result, prod(t->right, c, b, l, r));
    }

    void reset(node_ptr& t, size_t a, size_t b, size_t l, size_t r) const {
        if (!t || b <= l || r <= a) return;
        if (l <= a && b <= r) {
            t.reset();
            return;
        }
        size_t c = (a + b) >> 1;
        reset(t->left, a, c, l, r);
        reset(t->right, c, b, l, r);
        t->update();
    }

    template <class F>
    size_t max_right(const node_ptr& t, size_t a, size_t b,
                    size_t l, const F& f, S& product) const {
        if (!t || b <= l) return n;
        if (f(op(product, t->product))) {
            product = op(product, t->product);
            return n;
        }
        size_t c = (a + b) >> 1;
        size_t result = max_right(t->left, a, c, l, f, product);
        if (result != n) return result;
        if (l <= t->index) {
            product = op(product, t->value);
            if (!f(product)) return t->index;
        }
        return max_right(t->right, c, b, l, f, product);
    }

    template <class F>
    size_t min_left(const node_ptr& t, size_t a, size_t b,
                    size_t r, const F& f, S& product) const {
        if (!t || r <= a) return 0;
        if (f(op(t->product, product))) {
            product = op(t->product, product);
            return 0;
        }
        size_t c = (a + b) >> 1;
        size_t result = min_left(t->right, c, b, r, f, product);
        if (result != 0) return result;
        if (t->index < r) {
            product = op(t->value, product);
            if (!f(product)) return t->index + 1;
        }
        return min_left(t->left, a, c, r, f, product);
    }
};

//Verify : https://atcoder.jp/contests/abc405/submissions/79639846
//一般ではないsquare_divide。更新がO(1)の場合
template<class S, auto op, auto e> struct square_divide_gun{
	int H;
	vector<S> A0, A1;
	square_divide_gun(const vector<S> &X){
		H = max((ll)sqrtl(X.size()), 1ll) + 2;
		A1 = vector<S>(H * H);
		A0 = vector<S>(H);
		rep(i, H){
			S rui = e();
			rep(j, H){
				if(i * H + j >= X.size()) A1[i * H + j] = e();
				else A1[i * H + j] = X[i * H + j];
				rui = op(rui, A1[i * H + j]);
			}
			A0[i] = rui;
		}
	}

	void update(int pos, S X){
		A1[pos] = op(A1[pos], X);
		A0[pos / H] = op(A0[pos / H], X);
	}

	S query(int L, int R){
		S ans = e();
		int L0 = L / H, R0 = R / H;
		if(L0 == R0){
			for(int i = L; i < R; ++i){
				ans = op(ans, A1[i]);
			}
		}
		else{
			for(int i = L; i < (L0 * H + H); ++i) ans = op(ans, A1[i]);
			for(int i = L0 + 1; i < R0; ++i) ans = op(ans, A0[i]);
			for(int i = (R0 * H); i < R; ++i) ans = op(ans, A1[i]);
		}
		return ans;
	}
};

//使い方 : unordered_map<ll, ll, custom_hash> mp;
//https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//https://qiita.com/drken/items/b97ff231e43bce50199a
// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

vl dij(ll sai, vvpl &G){
	ll n = G.size();
	pq_g<pl> Q;
	vl dist(n,INF);
	vb kaku(n,false);
	Q.push({0,sai});
	dist[sai] = 0;
	while(!Q.empty()){
		auto [cost,pos] = Q.top();
		Q.pop();
		if(kaku[pos]) continue;
		kaku[pos] = true;
		for(pl i:G[pos]){
			if(dist[i.first] > cost + i.second){
				dist[i.first] = cost + i.second;
				Q.push({dist[i.first],i.first});
			}
		}
	}
	return dist;
}

bool in_grid(ll i, ll j, ll H, ll W){
	if(0 <= i && i < H && 0 <= j && j < W) return true;
	return false;
}

ll grid_to_ver(ll i, ll j, ll H, ll W){
	return i*W+j;
}

vl compress(vl &A){
	vl B = A;
	sort(B.begin(),B.end());
	B.erase(unique(B.begin(),B.end()),B.end());
	vl res = A;
	rep(i,res.size()) res[i] = lower_bound(B.begin(),B.end(),res[i]) - B.begin();
	return res;
}

ll tentousuu(vl A){
	ll N = A.size();
	A = compress(A);
	fenwick_tree<ll> fen(N+1);
	ll res = 0;
	rep(i,N){
		res += fen.sum(A[i] + 1, N);
		fen.add(A[i],1);
	}
	return res;
}

template< typename T = ll >
void warshall_floyd(ve<ve< T >> &g){
	for(int k = 0; k < g.size(); k++) {
		for(int i = 0; i < g.size(); i++) {
			for(int j = 0; j < g.size(); j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}

const int COM_MAX = 100;
mint fac[COM_MAX], finv[COM_MAX], inv[COM_MAX];

// テーブルを作る前処理
void COMinit() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < COM_MAX; i++){
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD%i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

// 二項係数計算
mint COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}

#pragma endregion yu23578

///////////////////main///////////////////

void solve(){
	
}

int main(){
	COMinit();
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(20);
    ll Testcase = 1;
	//cin>>Testcase;
    while(Testcase--) solve();
}
