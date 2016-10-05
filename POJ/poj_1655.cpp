
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAXN 20001

using namespace std;

int T, N, dp[MAXN], ans = 0x3f3f3f3f, node = -1;
vector<int> adjList[MAXN];

void dfs(int cur, int pre){
    int tmp = 0;
    dp[cur] = 1;
    for (int i = 0; i < adjList[cur].size(); i++){
        int c = adjList[cur][i];
        if (c != pre){
            dfs(c, cur);
            tmp = max(tmp, dp[c]);
            dp[cur] += dp[c];
        }
    }

    tmp = max(tmp, N - dp[cur]);
    if (tmp < ans){
        ans = tmp;
        node = cur;
    } else if (tmp == ans){
        node = min(node, cur);
    }
}

int main(){
    cin >> T;
    while(T--){
        for (int i = 0; i < MAXN; i++){
            adjList[i].clear();
        }

        memset(dp, 0, sizeof dp);
        ans = 0x3f3f3f3f, node = -1;

        cin >> N;
        for (int i = 0, a, b; i < N - 1; i++){
            cin >> a >> b;
            adjList[a - 1].push_back(b - 1);
            adjList[b - 1].push_back(a - 1);
        }

        dfs(0, -1);

        printf("%d %d\n", node + 1, ans);
    }
}
