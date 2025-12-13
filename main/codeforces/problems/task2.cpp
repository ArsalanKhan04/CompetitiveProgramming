#include <bits/stdc++.h>
using namespace std;

#define FL(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define vvi vector<vi>
#define F first
#define S second

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  // grid of size n by m
  constexpr int inf = 2147483647;
  int n, m;
  cin >> n >> m;
  vvi grid(n + 2, vi(m + 2, -1));
  vector<pair<int, int>> mvs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  FL(i, 1, n + 1)
    FL(j, 1, m + 1)
      cin >> grid[i][j];
  queue<pair<int, int>> q;
  FL(i, 1, n + 1){
    FL(j, 1, m + 1){
      if (grid[i][j] == 0){
        q.push({i, j});
      }
    }
  }
  while (!q.empty()){
    auto p = q.front();
    q.pop();
    FL(i, 0, 4){
      if (grid[p.F][p.S] + 1 < grid[p.F + mvs[i].F][p.S + mvs[i].S]){
        q.push({p.F + mvs[i].F, p.S + mvs[i].S});
        grid[p.F + mvs[i].F][p.S + mvs[i].S] = grid[p.F][p.S] + 1;
      }
    }
  }
  FL(i, 1, n + 1){
    FL(j, 1, m + 1){
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

