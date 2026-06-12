#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef KRAKAR
#define dbg(...) cerr << '[' << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define condprt(x) cout << ((x) ? "YES" : "NO") << endl


int N, S, L;
int M, K, P;
int R;

int m_to_p(int idx){
  return (idx / (M/P));
}

int s_to_p(int idx){
  return (idx / (S/P));
}

struct port_details {
  int group_id;
  int spine_id;
  int link_no;
};

int get_oxc_port(port_details pd){
  return pd.group_id * (S/P) * K +
    (pd.spine_id % (S/P)) * K + pd.link_no;
}

port_details get_port_info(int port_id){
  port_details pd;
  pd.group_id = port_id / ((S/P)*K);
  pd.spine_id = (port_id % ((S/P)*K)) / K;
  pd.link_no = port_id % K;
  return pd;
};

struct leaf_wg {
  int group_id;
  int leaf_id;
};
struct flow {
  leaf_wg origin;
  leaf_wg dest;
};

struct query_input {
  int flow_demands;
  vector<flow> flows;
};

query_input input_query(){
  query_input qi;
  cin >> qi.flow_demands;
  qi.flows.resize(qi.flow_demands);
  for (int i = 0; i < qi.flow_demands; i++){
    cin >> qi.flows[i].origin.group_id >> 
      qi.flows[i].origin.leaf_id >>
      qi.flows[i].dest.group_id >>
      qi.flows[i].dest.leaf_id;
  }
  return qi;
}

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

  /*
   N - number of groups
   M - number of OXCs
   */
  cin >> N >> S >> L;
  cin >> M >> K >> P;
  R = N * (S/P) * K;

  for (int query_no = 1; query_no <= 5; query_no++){
    auto qi = input_query();
  }

#ifdef KRAKAR
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
      - _clock_start).count() << "ms." << endl;
#endif
  return 0;

}

