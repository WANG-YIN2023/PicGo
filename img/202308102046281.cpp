#include<bits/stdc++.h>
using namespace std;
#define N 100100
#define mod 1000000007
#define ll long long

int n,flag;
ll a[N],num[N*10],mx;
ll fac[N],inv[N];
ll ans;

inline ll ksm(ll a,ll x){
	ll ans=1;
	while(x){
		if(x&1) ans=ans*a%mod;
		a=a*a%mod;
		x>>=1;
	}
	return ans;
}

inline void inti(){
	fac[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	inv[N-1]=ksm(fac[N-1],mod-2);
	for(int i=N-2;i>=1;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
	inv[0]=1;
}

int main(){
	freopen("bogo.in","r",stdin);
	freopen("bogo.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	inti();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		num[a[i]]++;
		if(i>1&&a[i]<a[i-1]) flag=1;
	}
	if(!flag){
		cout<<"0\n";
		return 0;
	}
	ans=fac[n];
	for(int i=1;i<=mx;i++){
		ans=ans*inv[num[i]]%mod;
	}
	cout<<ans<<"\n";

	return 0;
}
