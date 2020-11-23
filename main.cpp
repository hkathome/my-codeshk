#include <bits/stdc++.h>
#define ll long long
#define N 200002
using namespace std;

ll bit[N];
ll arr[N];
void update(ll ind,ll val,ll n){
while(ind<=n){
bit[ind]+=val;
ind=ind+(ind&(-ind));
}
}
ll query(ll ind){
ll ans=0;
while(ind>0){
ans+=bit[ind];
ind=ind-(ind&(-ind));
}
return ans;
}
void build(ll n){
for(ll i=1;i<=n;i++){
  update(i,arr[i],n);
}
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll n;
ll i=0;
cin>>n;
while(n>0){
for(ll j=1;j<=n;j++){
cin>>arr[j];
}
build(n);
i++;
vector<ll> ans;
string str;
ll q;
cin>>q;
while(q--){

char x;
ll l;
ll r;
cin>>x>>l>>r;
if(x=='S'){
update(l,r,n);
}
else{
ll u=query(l-1);
ll v=query(r);
ll ans1=v-u;
ans.push_back(ans1);
}
}
cout<<"Case :"<<i<<"\n";
for(int i=0;i<ans.size();i++){
cout<<ans[i]<<"\n";
}
cin>>n;
}
}
