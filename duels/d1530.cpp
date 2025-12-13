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

    int TCS = 1;
    cin >> TCS;
    while(TCS--){
      int n;
      cin >> n;
      vi a(n+1);
      FL(i, 1, n+1)
        cin >> a[i];
      vi b(n+1, 0);
      vi rem;
      int fl = 0;
      deque<int> dq;
      FL(i,1,n+1){
        b[a[i]]++;
        dq.push_back(i);
      }
      vi c(n + 1, -1);
      FL(i,1,n+1){
        while (!dq.empty() && b[a[dq.front()]] == 1){
          fl++;
          c[a[dq.front()]] = dq.front();
          dq.pop_front();
        }
        while (!dq.empty() && b[a[dq.back()]] == 1){
          fl++;
          c[a[dq.back()]] = dq.back();
          dq.pop_back();
        }
        if (b[i]==0){
          if (i != dq.front()){
            c[i] = dq.front();
            b[a[dq.front()]]--;
            dq.pop_front();
          } else {
            c[i] = dq.back();
            b[a[dq.back()]]--;
            dq.pop_back();
          }
        }
      }
      while (!dq.empty() && b[a[dq.front()]] == 1){
        fl++;
        c[a[dq.front()]] = dq.front();
        dq.pop_front();
      }

      vi d(n+1);
      FL(i,1,n+1){
        d[c[i]] = i;
      }
      cout << fl << endl;
      FL(i,1,n+1){
        cout << d[i] << " ";
      }
      cout << endl;




    }
#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

