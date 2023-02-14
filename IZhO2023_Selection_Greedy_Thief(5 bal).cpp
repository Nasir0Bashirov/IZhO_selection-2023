#include <bits/stdc++.h>
using namespace std;

long long a[200005], res[100000], n;

void solve(int i = 1, long long cur = 0, int t = 1, int par = -1){
    if(i + 1 <= n)
        solve(i + 1, cur, t, par);
    if(par != i - 1){
        res[t] = max(cur + a[i], res[t]);
        if(i + 2 <= n)
            solve(i + 2, cur + a[i], t + 1, i);
    }
    res[t] = max(cur, res[t]);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    solve();
    for(int i = 1; i <= n / 2 + n % 2; i++){
        cout << res[i] << endl;
    }
}
