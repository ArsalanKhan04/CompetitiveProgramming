#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long

const int md=1e9+7;

ll modpw(ll vl, ll pw){
  ll y=1;
  while (pw){
    if (pw&1){
      y*=vl;
      y%=md;
    }
    pw/=2;
    vl*=vl;
    vl %= md;
  }
  return y;
}

ll modinv(ll vl){
  return modpw(vl, md-2);
};

vector<ll> Fac(1,1);
vector<ll> Inv(1,1);

ll comb(ll n, ll r){
  if (n < r || n < 0 || r < 0) return 0;
  while (Fac.size() <= n){
    ll fvl = Fac.back()*Fac.size();
    fvl%=md;
    Fac.push_back(fvl);
    Inv.push_back(modinv(fvl));
  }
  ll res=Fac[n];
  res*=Inv[n-r]; res%=md;
  res*=Inv[r]; res%=md;
  return res;
}

#define vll vector<ll>

int main(){
  comb(int(4e5+2), 3);


  // Defining this early to prefix sum
  // 

  int tcs; cin>>tcs; while(tcs--){
    int n; cin>>n; vll a(n+1); for(int i=0;i<n+1;i++) cin>>a[i];
    bool fl=0;
    for (int i=0;i<n+1;i++){
      if (a[i]==-1){
        continue;
      }
      if (a[i]>n){
        fl=1; break;
      }
      if (a[i]!=0 && a[a[i]]==-1){
        a[a[i]]=i;
      }
      if (a[i]>0 && a[a[i]]!=i){
        fl=1; break;
      }
    }
    if (fl){
      cout << 0 << endl;
      continue;
    }

    ll an=0; ll cnt=0;
    for(int i=1; i<n; i++){ // not including 0 or n
      // cerr << a[i] << " ";
      if (a[i]==-1){
        cnt++;
      }
    }
    // cerr << endl;
    ll cad=0;

    // cerr << cnt << endl;
    for (int sz=0; sz<=cnt; sz+=2){

      int szh=sz/2;
      ll perms=Fac[2*szh];
      perms*=comb(cnt,sz); perms %= md;
      ll div = modpw(2, szh);
      div *= Fac[szh]; div %= md;
      perms *= modinv(div);
      perms %= md;
      perms=max(perms,1LL); // only if sz is 0


      int rm=cnt-sz; // itself or 0
      // cerr << "rm: " << rm << endl;
      ll oths = modpw(2, rm);
      cad = perms*oths; cad %= md;
      an += cad;
      // cerr << "cad: " << cad << " " << perms << " " << oths << endl;
      an %= md;
    }

    // cerr << an << endl;
    if (a[n]==-1){ // only if not already taken/
      cnt--;
      cad=0;
      for (int sz=0; sz<=cnt; sz+=2){

        int szh=sz/2;
        ll perms=Fac[2*szh];
        perms*=comb(cnt,sz); perms %= md;
        ll div = modpw(2, szh);
        div *= Fac[szh]; div %= md;
        perms *= modinv(div);
        perms %= md;
        perms=max(perms,1LL); // only if sz is 0
                              //
                              //
        int rm=cnt-sz; // itself or 0
        ll oths = modpw(2, rm);
        cad = perms*oths; cad %= md;
        cad *= cnt+1; cad %= md;
        an += cad;
        an %= md;
      }
    }
     
    cout << an << endl;
    continue;

    
    /*

    for (int sz=0;sz<=cnt;sz+=2){
      ll perms=(sz*(sz-1))/2; perms %= md;
      perms=max(perms,1LL);
      cad = comb(cnt, sz)*perms;
      cad %= md;
      an+=cad;
      an %= md;
      cerr << an << " .an" << endl;
    }

    cnt--; // paired with 0

    ll zad = 0; // for each paired with 0
    for (int sz=0; sz<=cnt;sz+=2){
      ll perms=(sz*(sz-1))/2; perms %= md;
      perms=max(perms,1LL);
      cad = comb(cnt, sz)*perms;
      cad %= md;
      zad+=cad;
      zad %= md;
    }
    cnt++;
    cnt -= (a[n]==-1);
    an += zad*cnt;
    cerr << zad << " " << cnt << endl;

    zad = 0;

    

    cout << an << endl;
    */
  }
}
