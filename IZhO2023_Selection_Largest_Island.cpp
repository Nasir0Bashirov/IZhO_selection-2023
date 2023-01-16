#include <bits/stdc++.h>
using namespace std;

char adj[505][505];
bool used[505][505];
int d[505][505], cnt, res = 0, n, m, cnt2[505][505], ci, cj;
pair<int, int>par[505][505];
const int inf = 1e9;

bool can_go(int x, int y){
    if(adj[x][y] == '-' or x > n or y > m or x < 1 or y < 1 or used[x][y]){
        return false;
    }
    return true;
}

void dfs(int x, int y){
    cnt++;
    used[x][y] = true;
    cnt2[x][y] = cnt;
    if(can_go(x + 1, y)){
        par[x + 1][y] = {par[x][y].first, par[x][y].second};
        dfs(x + 1, y);
    }
    cnt2[x][y] = max(cnt2[x][y], cnt2[x + 1][y]);
    if(can_go(x - 1, y)){
        par[x - 1][y] = {par[x][y].first, par[x][y].second};
        dfs(x - 1, y);
    }
    cnt2[x][y] = max(cnt2[x][y], cnt2[x - 1][y]);
    if(can_go(x, y + 1)){
        par[x][y + 1] = {par[x][y].first, par[x][y].second};
        dfs(x, y + 1);
    }
    cnt2[x][y] = max(cnt2[x][y], cnt2[x][y + 1]);
    if(can_go(x, y - 1)){
        par[x][y - 1] = {par[x][y].first, par[x][y].second};
        dfs(x, y - 1);

    }
    cnt2[x][y] = max(cnt2[x][y], cnt2[x][y - 1]);
}

int dfsminus(int x, int y){
    used[x][y] = true;
    set<pair<int, int>>st;
    int mx = 0;
    if(can_go(x + 1, y)){
        st.insert({par[x + 1][y].first, par[x + 1][y].second});
        //cout << "accepted : ";
    }
    //else{
        //cout << "fail : ";
    //}
    //cout << cnt2[x + 1][y] << " " << x + 1 << " " << y << " " << par[x + 1][y].first << " " << par[x + 1][y].second << "  ";
    if(can_go(x - 1, y)){
        st.insert({par[x - 1][y].first, par[x - 1][y].second});
        //cout << "accepted : ";
    }
    //else{
    //    cout << "fail : ";
    //}
    //cout << cnt2[x - 1][y] << " " << x - 1 << " " << y << " " << par[x - 1][y].first << " " << par[x - 1][y].second << "  ";
    if(can_go(x, y + 1)){
        st.insert({par[x][y + 1].first, par[x][y + 1].second});
        //cout << "accepted : ";
    }
    //else{
    //    cout << "fail : ";
    //}
    //cout << cnt2[x][y + 1] << " " << x << " " << y + 1 << " " << par[x][y + 1].first << " " << par[x][y + 1].second << "  ";
    if(can_go(x, y - 1)){
        st.insert({par[x][y - 1].first, par[x][y - 1].second});
       //cout << "accepted : ";
    }
    //else{
    //    cout << "fail : ";
    //}
    //cout << cnt2[x][y - 1] << " " << x << " " << y - 1 << " " << par[x][y - 1].first << " " << par[x][y - 1].second << "\n";
    for(pair<int, int> i : st){
        mx += cnt2[i.first][i.second];
    }
    return mx + 1;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> adj[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(can_go(i, j)){
                cnt = 0;
                par[i][j] = {i, j};
                dfs(i, j);
            }
        }
    }
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(adj[i][j] == '-' and (can_go(i + 1, j) or can_go(i - 1, j) or can_go(i, j + 1) or can_go(i, j - 1))){
                res = max(res, dfsminus(i, j));
            }
        }
    }
    if(res == 0){
        res = max(cnt, 1);
    }
    cout << res;
}
