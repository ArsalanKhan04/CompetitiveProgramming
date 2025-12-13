#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define FL(i, a, b) for (int i = a; i < b; i++)
#define FE(i, a, b) for (int i = a; i <= b; i++)
#define FF(i, a, b) for (int i = a; i > b; i--)
#define FFE(i, a, b) for (int i = a; i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define vpii vector<pii>
#define vll vector<ll>
#define vvll vector<vll>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vll vector<ll>
#define vvll vector<vll>
#define endl '\n'
#define REMAX(a, b) a = max((a), (b))
#define REMIN(a, b) a = min((a), (b))

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define condprt(x) cout << ((x) ? "YES" : "NO") << endl



int main() {

  ios_base::sync_with_stdio(false);
#ifdef KRAKAR
    ifstream fileIn("input.txt"); 
    cin.rdbuf(fileIn.rdbuf()); 
    ofstream fileOut("output.txt"); 
    cout.rdbuf(fileOut.rdbuf()); 
    auto _clock_start = chrono::high_resolution_clock::now();
#else
    cin.tie(0);
#endif
    ull x;
    cin >> x;
    string bin = "";
    while (x){
      if (x & 1){
        bin = '1' + bin;
      } else {
        bin = '0' + bin;
      }
      x >>= 1;
    }
    struct Node {
      char val;
      Node *left, *right;
      Node(char v) : val(v), left(nullptr), right(nullptr) {}
    };

    Node* root = new Node(bin[0]);
    Node* cur = root;
    for (int i = 1; i < bin.size(); ++i) {
      Node* node = new Node(bin[i]);
      if (bin[i] == '0')
        cur->left = node;
      else
        cur->right = node;
      cur = node;
    }
    string inorder = "";
    function<void(Node*)> dfs = [&](Node* node) {
      if (!node) return;
      dfs(node->left);
      inorder += node->val;
      dfs(node->right);
    };

    dfs(root);
    ull ans = stoull(inorder, nullptr, 2);
    cout << ans << endl;
    
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

