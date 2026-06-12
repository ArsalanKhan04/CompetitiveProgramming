#include <bits/stdc++.h>
using namespace std;


const int mxN = 20;
const int mxM = 2 * mxN;
const int mxT = 2 * mxN * mxN * mxM; // (3200)

int n, m, t;

vector<string> sV(mxN);
vector<string> sH(mxN);
vector<vector<array<int, 2>>> vall(mxM, vector<array<int, 2>>(2));

struct coords {
  int x;  
  int y;


  bool operator ==(const coords& other) const{
    return x==other.x && y==other.y;  
  }
  bool operator !=(const coords& other) const{
    return x!=other.x || y!=other.y;  
  }

};

struct dst {
  int scr;
  coords pr;
  coords slf;

  bool operator <(const dst& other) const{
    return scr < other.scr;
  }
};

vector<vector<vector<dst>>> dst_mtx(2*mxM, // 0 to M for src then M to 2*M for dest
    vector<vector<dst>>(mxN,
      vector<dst>(mxN)));

void make_dst_mtx(){
  auto djikstra = [&](int idx){
    // I am going to assume it is always facing towards the right
    // if its not, it can
    vector<vector<int>> visited(mxN, vector<int>(mxN));
    priority_queue<dst> pq;
    coords cr;
    auto admv = [&](dst dt, int dir){  
      coords newcr;
      vector<array<int, 2>> mvs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
      newcr = {dt.slf.x+mvs[dir][0], dt.slf.y+mvs[dir][1]};
      if (newcr.x < 0 || newcr.x >= n) return; if (newcr.y < 0 || newcr.y >= n) return;
      
      coords chckcr = newcr;
      if (newcr.x > dt.slf.x || newcr.y > dt.slf.y){
        chckcr = dt.slf;
      }


      if (dir & 1){
        if (sV[chckcr.x][chckcr.y]-'0') return;
      } else {
        if (sH[chckcr.x][chckcr.y]-'0') return;
      }

      int scrad = -2;
      
      if (dt.slf.x-dt.pr.x == newcr.x-dt.slf.x &&  // to handle same direction :)
          dt.slf.y-dt.pr.y == newcr.y-dt.slf.y) scrad = -1; 

      pq.push({dt.scr+scrad, dt.slf, newcr});
    };


    if (idx == 2*m) cr = {0, 0};
    else 
      cr = {vall[idx%m][idx/m][0], vall[idx%m][idx/m][1]};

    pq.push({0, {cr.x, cr.y-1}, cr});

    while (!pq.empty()){
      auto dt = pq.top(); pq.pop();
      // if (idx==m) cout << dt.slf.x << " " << dt.slf.y << endl;
      if (visited[dt.slf.x][dt.slf.y]){
        continue;
      }
      visited[dt.slf.x][dt.slf.y]=true;
      for (int dir = 0; dir < 4; dir++) admv(dt, dir);
      dst_mtx[idx][dt.slf.x][dt.slf.y]=dt;
      // if (idx==m) cout << dt.slf.x << " " << dt.slf.y << endl;
    }
  };

  for (int i = 0; i < 2*m+1; i++){
    // run djikstra from each
    djikstra(i);
  }
}

void print_dst_mtx(int idx){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      auto dst = dst_mtx[idx][i][j];
      cout << dst.scr << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      auto dst = dst_mtx[idx][i][j];
      cout << dst.pr.x << "," << dst.pr.y << " ";
    }
    cout << endl;
  }
}

string get_route(int idx, coords dest){
  string s = "";
  dst cur = dst_mtx[idx][dest.x][dest.y];

  coords src;
  if (idx == 2*m) src = {0, 0};
  else 
    src = {vall[idx%m][idx/m][0], vall[idx%m][idx/m][1]};

  vector<coords> states = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int state = 0;
  while (cur.slf != src){
    coords prv = cur.pr;
    coords delta = {cur.slf.x-prv.x, cur.slf.y-prv.y};
    if (delta != states[state]){
      if (delta == states[(state+1)%4]){
        s+="L";
        state = (state + 1) % 4;
      } else if (delta == states[(state+3)%4]) {
        s+="R";
        state = (state + 3) % 4;
      } else {
        s+="RR";
        state = (state + 2) % 4;
      }
    }
    s+="F";
    cur = dst_mtx[idx][cur.pr.x][cur.pr.y];
  }
  if (state == 1){
    s+="R";
  } else if (state == 2){ 
    s+="RR";
  } else if (state == 3){  
    s+="L";
  }
  return s;
}

string generate(){
  // for each m src and for each dest
  // we need to have a n^n matrix that moves it from the start to end

  string ans = "";
  for (int i = m-1; i>=0; i--){
    // cout << i << endl;
    ans+="S";
    string xx = get_route(i, {vall[i][1][0], vall[i][1][1]});
    ans+=xx;
    ans+="S";
    if (i==0){
      xx = get_route(2*m, {vall[i][0][0], vall[i][0][1]});
      ans+=xx;
    } else {
      xx = get_route(i+m-1, {vall[i][0][0], vall[i][0][1]});
      ans+=xx;
    }
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

string shorten(string s){
  // TODO
  return s;
}

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin>>n>>m>>t;
  
  // wall between [i][j] and [i][j+1]
  for (int i = 0; i < n; i++){
    cin >> sV[i];
  }

  // wall between [i][j] and [i+1][j]
  for (int i = 0; i < n-1; i++){
    cin >> sH[i];
  }

  for (int i = 0; i < m; i++)
    for (int j = 0; j < 2; j++) 
      for (int k = 0; k < 2; k++){
        cin >> vall[i][j][k];
      }


  // m-1 to 2*m-1
  // 2*m-2 to m-1
  // m-2 to 2*m-2
  // ...
  // m+1 to 2
  // 1 to m+1
  // m to 1
  // 0 to m
  // 2*m to 0
  //
  // cout << m << endl;
  // cout << get_route(m, {vall[1][1][0], vall[1][1][1]}) << endl;;

  make_dst_mtx();
  // print_dst_mtx(m);
  string ans = "";
  for (int i = m-1; i>=0; i--){
    // cout << i << endl;
    ans+="S";
    string xx = get_route(i, {vall[i][1][0], vall[i][1][1]});
    ans+=xx;
    ans+="S";
    if (i==0){
      xx = get_route(2*m, {vall[i][0][0], vall[i][0][1]});
      ans+=xx;
    } else {
      xx = get_route(i+m-1, {vall[i][0][0], vall[i][0][1]});
      ans+=xx;
    }
  }
  reverse(ans.begin(), ans.end());

  ans = generate();
  for (auto x: ans){
    cout << x << endl;
  }

}
/*
   reverse(xx.begin(), xx.end());
   cout << xx << endl;
   for (auto vl: xx){
   cout << vl << endl;
   }
   */
