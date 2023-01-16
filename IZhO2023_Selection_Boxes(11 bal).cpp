#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    pair<long long, long long>a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    while(q--){
        long long x, y,res = 0;
        cin >> x >> y;
        vector<pair<long long, long long>>v;
        for(int i = 1; i <= n; i++){
            if(a[i].first >= x and a[i].second <= y){
                res++;
                v.push_back(a[i]);
            }
        }
        sort(v.begin(), v.end());
        int sz = v.size();
        //cout << "look : " << sz << " " << res << endl;
        for(int i = 0; i < sz - 1; i++){
            //cout << "i : " << i << endl;
            if(v[i].first < v[i + 1].first and v[i].second < v[i + 1].second){
                res--;
            }
        }
        cout << res << endl;
    }
}
