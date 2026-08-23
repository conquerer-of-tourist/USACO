/*

    USACO 2015 December Contest, Silver
    Problem 1. Switching on the Lights

    August 22, 2026
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector
#define v1 first
#define v2 second
#define p pair<int, int>

int n, m;

int main()
{
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    map<p, vec<p>> switches;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        switches[{a, b}].push_back({c, d});
    }
    vec<vec<bool>> rooms (n, vec<bool> (n, 0));
    vec<vec<bool>> visit (n, vec<bool> (n, 0));

    stack<p> vals;
    vals.push({0, 0});
    rooms[0][0] = 1;
    while (!vals.empty()) {
        int cX = vals.top().v1;
        int cY = vals.top().v2;
        vals.pop();
        visit[cX][cY] = 1;

        for (auto& thing : switches[{cX, cY}]) {
            int x = thing.v1;
            int y = thing.v2;
            rooms[x][y] = 1;

            if (visit[x][y] == 0) {
                bool reachable = false;
                if ((x > 0 && visit[x - 1][y]) || (x < n - 1 && visit[x + 1][y]) ||
                    (y > 0 && visit[x][y - 1]) || (y < n - 1 && visit[x][y + 1])) {
                    reachable = true;
                }
                if (reachable) {
                    vals.push({x, y});
                    visit[x][y] = 1;
                }
            }
        }

        if (cX > 0 && visit[cX - 1][cY] == 0 && rooms[cX - 1][cY] == 1) {
            vals.push({cX - 1, cY});
            visit[cX - 1][cY] = 1;
        }
        if (cY > 0 && visit[cX][cY - 1] == 0 && rooms[cX][cY - 1] == 1) {
            vals.push({cX, cY - 1});
            visit[cX][cY - 1] = 1;
        }
        if (cX < n - 1 && visit[cX + 1][cY] == 0 && rooms[cX + 1][cY] == 1) {
            vals.push({cX + 1, cY});
            visit[cX + 1][cY] = 1;
        }
        if (cY < n - 1 && visit[cX][cY + 1] == 0 && rooms[cX][cY + 1] == 1) {
            vals.push({cX, cY + 1});
            visit[cX][cY + 1] = 1;
        }
    }


    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            answer += (rooms[i][j] == 1) ? 1 : 0;
        }
    }
    cout << answer << '\n';
    return 0;
}