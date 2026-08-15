#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define ll long long

struct Edge {
    ll to;
    ll sum;
};

/*
 * Indexing: I'm attemping to 0-index everything
 * DFS: Iterative via stack
 */

void solve()
{
    ll n, m;
    cin >> n >> m;
    
    vector<int> rA (n), rB (n);
    for (auto& a : rA) cin >> a;
    for (auto& b : rB) cin >> b;

    vector<vector<Edge>> edges (n + 1);
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        Edge e1; e1.to = b; e1.sum = c;
        Edge e2; e2.to = a; e2.sum = c;
        edges[a].push_back(e1);
        edges[b].push_back(e2);
    }
    
    ll totalSum = 0;

    bool impossible = false;

    vector<int> visited (n, 0);
    vector<pair<ll, ll>> xterms (n); // component, integer

    for (int i = 0; i < n; i++) {
        if (impossible) {
            break;
        }
        if (visited[i]) {
            continue;
        }

        vector<ll> component;
        stack<ll> stacker;

        stacker.push(i);

        bool isForced = false;
        ll forcedX = __LONG_LONG_MAX__;

        xterms[i].first = 1;
        xterms[i].second = 0;
        visited[i] = 1;

        while (stacker.size() > 0 && impossible == false) {
            ll currNode = stacker.top();
            stacker.pop();
            component.push_back(currNode);

            for (auto& [to, sum] : edges[currNode]) {
                if (visited[to]) {
                    if (xterms[to].first == -1 * xterms[currNode].first) {
                        if (xterms[to].second + xterms[currNode].second != sum) {
                            impossible = true;
                            break;
                        }
                    }
                    else {
                        ll temp = sum - xterms[to].second - xterms[currNode].second;
                        if (temp % 2 != 0) {
                            impossible = true;
                            break;
                        }
                        ll curForce = temp / (xterms[to].first * 2);

                        if (isForced == true && curForce != forcedX) {
                            impossible = true;
                            break;
                        }

                        isForced = true;
                        forcedX = curForce;
                    }
                }
                else {
                    visited[to] = 1;
                    xterms[to].first = xterms[currNode].first * -1;
                    xterms[to].second = sum - xterms[currNode].second;
                    stacker.push(to);
                }
            }
        }
        if (isForced == true) {
            ll counter = 0;
            for (auto& c : component) {
                ll actualValue = forcedX * xterms[c].first + xterms[c].second;
                if (actualValue >= rA[c] && actualValue <= rB[c]) {
                    counter++;
                }
            }
            totalSum += counter;
        }
        else {
            vector<pair<ll, int>> points;
            for (auto& c : component) {
                if (xterms[c].first == 1) {
                    points.push_back({rA[c] - xterms[c].second, 1});
                    points.push_back({rB[c] - xterms[c].second + 1, -1});
                }
                else {
                    points.push_back({xterms[c].second - rB[c], 1});
                    points.push_back({xterms[c].second - rA[c] + 1, -1});
                }
            }
            sort(points.begin(), points.end());
            ll current = 0, maximal = 0;
            for (auto& poi : points) {
                current += poi.second;
                maximal = max(current, maximal);
            }
            totalSum += maximal;
        }
    }

    if (impossible) {
        cout << -1 << '\n';
        return;
    }
    cout << totalSum << '\n';
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}