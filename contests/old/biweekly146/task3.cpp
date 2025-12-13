
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int
#define MOD % 1000000007
#define FL(i, a, b) for (int i = a; i < b; i++)
#define FE(i, a, b) for (int i = a; i <= b; i++)
#define FF(i, a, b) for (int i = a; i > b; i--)
#define FFE(i, a, b) for (int i = a; i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'
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

#define REMAX(a, b) a = max((a), (b))
#define REMIN(a, b) a = min((a), (b))

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define INF int(1e9) + 9
 
#define endl '\n'
 
#define condprt(x) cout << ((x) ? "YES" : "NO") << endl


class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
      int m = rectangles.size();
      sort(ALL(rectangles), [](const vi&a, const vi&b){
        return a[2] < b[2];
          });
      sort(ALL(rectangles), [](const vi&a, const vi&b){
        return a[0] < b[0];
          });

      stack<pii> horz_st;
      FL(i, 0, m){
        if (horz_st.empty()){ horz_st.push({rectangles[i][0], rectangles[i][2]});
          continue;
        }
        if (horz_st.top().second > rectangles[i][0]){
          horz_st.top().second = max(horz_st.top().second, rectangles[i][2]);
        } else {
          horz_st.push({rectangles[i][0], rectangles[i][2]});
        }
      }

      sort(ALL(rectangles), [](const vi&a, const vi&b){
        return a[3] < b[3];
          });
      sort(ALL(rectangles), [](const vi&a, const vi&b){
        return a[1] < b[1];
          });
      stack<pii> vert_st;
      FL(i, 0, m){
        if (vert_st.empty()){ vert_st.push({rectangles[i][1], rectangles[i][3]});
          continue;
        }
        if (vert_st.top().second > rectangles[i][1]){
          vert_st.top().second = max(vert_st.top().second, rectangles[i][3]);
        } else {
          vert_st.push({rectangles[i][1], rectangles[i][3]});
        }
      }


      int horz = horz_st.size();
      int verts =vert_st.size();

      cout << horz << " " << verts << endl;
      if (horz >= 3 || verts >= 3){
        return true;
      }
      return false;
    }
};
