#include <bits/stdc++.h>
using namespace std;

#define FL(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define vvi vector<vi>
#define endl '\n'


int main() {

    int T = 1;
    cin >> T;
    while(T--){
      int n, A, B; cin >> n >> B >> A;
      vvi a(n, vi(n)); string s;
      FL(i, 0, n){
        cin >> s;
        FL(j, 0, n){
          if (s[j] == 'W'){
            a[i][j] = 0;
          } else if (s[j] == 'G'){
            a[i][j] = 1;
          } else a[i][j] = 2;
        }
      }
      int ans = 0;
      bool flag = true;
      FL(i, 0, n){
        FL(j, 0, n){
          if (a[i][j] == 2){
            if (i - A >= 0 && j - B >= 0 && a[i-A][j-B] >= 1){
              a[i-A][j-B] = 2;
              continue;
            }
            flag = false;
            break;
          }
        }
        if (!flag) break;
      }
      if (!flag) {
        cout << -1 << endl;
        continue;
      }
      FL(i, 0, n){
        FL(j, 0, n){
          if (a[i][j] >= 1){
            ans++;
            if (i + A < n && j + B < n && a[i+A][j+B] > 0){
              a[i+A][j+B]--;
            }
          }
        }
      }
      cout << ans << endl;
    }
  return 0;
}

