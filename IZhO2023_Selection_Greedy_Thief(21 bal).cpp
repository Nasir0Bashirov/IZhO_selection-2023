#include <bits/stdc++.h>
using namespace std;

long long a[200005];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<long long>>dp(n + 5, vector<long long>(n / 2 + 5, 0));
    for(int i = 1; i <= n; i++){
        dp[i][1] = max(dp[i - 1][1], a[i]);
    }
    for(int i = 3; i <= n; i++){
        for(int j = 2; j <= (i & 1 ? i / 2 + 1 : i / 2); j++){
            dp[i][j] = dp[i - 1][j];
            if(i - 2 >= 1){
                dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + a[i]);
            }
            if(i - 4 >= 1){
                dp[i][j] = max(dp[i][j], dp[i - 4][j - 1] + a[i]);
            }
        }
    }
    for(int i = 1; i <= (n & 1 ? n / 2 + 1 : n / 2); i++){
        cout << dp[n][i] << endl;
    }
}
