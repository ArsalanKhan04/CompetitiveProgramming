#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

vector<int> merge(vector<int> a, vector<int> b, int &inv){
  int i_a = 0, i_b = 0;
  int n_a = a.size(), n_b = b.size();
  vector<int> c(n_a + n_b);
  while (i_a < n_a && i_b < n_b){
    if (a[i_a] < b[i_b]){
      c[i_a+i_b]=a[i_a];
      i_a++;
    } else {
      c[i_a+i_b]=b[i_b];
      inv += n_a - i_a;
      i_b++;
    }
  }
  while (i_a < n_a){
    c[i_a+i_b]=a[i_a];
    i_a++;
  }
  while (i_b < n_b){
    c[i_a+i_b]=b[i_b];
    i_b++;
  }
  return c;
}

vector<int> merge_sort(vector<int> c, int &inv){
  if (c.size() == 1){
    return c;
  }
  vector<int> a, b;
  for (int i = 0; i < c.size() / 2; i++){
    a.push_back(c[i]);
  }
  for (int i = c.size() / 2; i < c.size(); i++){
    b.push_back(c[i]);
  }

  a = merge_sort(a, inv); // recursive part
  b = merge_sort(b, inv); // recursive part

  c = merge(a, b, inv); // combining them
  return c;
};

int inversions(vector<int> a){
  int n = a.size();
  int inv = 0;
  Fenwick<int> fen(n);
  for (int i = 0; i < n; i++){
    inv += fen.rangeSum(a[i]+1, n);
    fen.add(a[i], 1);
  }
  return inv;
};


int main(){
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  cout << inversions(c) << endl;
  int inv = 0;
  c = merge_sort(c, inv);
  for (int i = 0; i < n; i++){
    cout << c[i] << " ";
  }
  cout << endl;
  cout << "inversions: " << inv << endl;

}
