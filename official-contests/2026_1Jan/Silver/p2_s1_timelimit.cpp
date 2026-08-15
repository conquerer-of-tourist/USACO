// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
// using namespace std;

// #define ll long long

// vector<vector<pair<ll, ll>>> graph; // connection, value
// vector<ll> visited;
// vector<pair<ll, ll>> xterms;

// bool flag = false; // true is when we get -1
// bool definite = false; // true when we reach a determined value
// ll defValue = 0;

// void dfs(ll curr, ll prev)
// {
//     if (prev == 0) {
//         xterms[curr].first = 1;
//         xterms[curr].second = 0;
//     }
//     if (flag == true) {
//         return;
//     }
//     visited[curr] = 1;
//     ll coefficient = xterms[curr].first;
//     ll component = xterms[curr].second;

//     for (pair<ll, ll> connection : graph[curr]) {
//         ll other = connection.first;
//         ll otherSum = connection.second;
//         if (visited[other] == 0) {
//             xterms[other].first = -1 * coefficient;
//             xterms[other].second = otherSum - component;
//             dfs(other, 1);
//         }
//         else {
//             if (xterms[other].first == -1 * coefficient) {
//                 if (xterms[other].second + component != otherSum) {
//                     flag = true;
//                     return;
//                 }
//             }
//             else {
//                 if (otherSum - xterms[other].second + component % 2 == 1) {
//                     flag = true;
//                     return;
//                 }
//                 if (definite == true && (otherSum - xterms[other].second + component) / 
//                     2 * coefficient != defValue) {
//                         flag = true;
//                         return;
//                     }
//                 }
//                 defValue = (otherSum - xterms[other].second + component) / 2 * coefficient;
//                 definite = true;
//             }
//         }
//     }
// }

// void solve()
// {
//     ll n, m;
//     cin >> n >> m;

//     flag = false;
//     definite = false;

//     graph.assign(n + 1, {});
//     visited.assign(n + 1, 0);
//     xterms.assign(n + 1, {0, 0});

//     map<ll, pair<ll, ll>> ranges;
//     for (ll i = 0; i < n; i++) {
//         ll a;
//         cin >> a;
//         ranges[i + 1] = {a, 0};
//     }
//     for (ll i = 0; i < n; i++) {
//         ll b;
//         cin >> b;
//         ranges[i + 1].second = b;
//     }

//     graph.resize(n + 5);
//     xterms.resize(n + 5);
//     visited.resize(n + 5);

//     for (ll i = 0; i < m; i++) {
//         ll a, b, c;
//         cin >> a >> b >> c;
//         graph[a].push_back({b, c});
//         graph[b].push_back({a, c});
//     }
    
//     for (ll i = 1; i <= n; i++) {
//         if (visited[i] == 0) {
//             defValue = 0;
//             definite = false;
//             dfs(i, 0);
//         }
//     }

//     if (flag == true) {
//         cout << -1 << '\n';
//         return;
//     }

//     if (definite == true) {
//         ll counter = 0;
//         for (ll i = 1; i <= n; i++) {
//             if (xterms[i].first * defValue + xterms[i].second >= 
//                 (double) ranges[i].first - 0.001 &&
//                 xterms[i].first * defValue + xterms[i].second <= 
//                 (double) ranges[i].second + 0.001) {
//                 counter++;
//             }
//         }
//         cout << counter << '\n';
//         return;
//     }

//     vector<pair<ll, ll>> values;
//     for (auto& range : ranges) {
//         ll s1 = range.second.first;
//         ll s2 = range.second.second;
//         values.push_back({s1, 1});
//         values.push_back({s2 + 1, -1});
//     }
//     sort(values.begin(), values.end());

//     // ll running = 0;
//     // so like.. we already know
//     // the constraints on the x via the array called xterms
//     // and within x terms we have each one as ax + b, where a is 1 or -1
//     // therefore, this means that we can solve for ax + b
//     // so lets say that k <= ax + b
//     // then (k - b) / a <= x (this value is ceiling, closer to 0 if negative, upwards)
//     // lets say that ax + b <= r
//     // then x <= (r - b) / a (this value is floored)
//     // wait nevermind its not floored because a is just 1 or -1, ok all good
//     for (auto& range : ranges) {
//         int i = range.first;
//         int lowerBound = (range.second.first - xterms[i].second) / xterms[i].first;
//         int upperBound = (range.second.second - xterms[i].second) / xterms[i].first;
//         range.second.first = lowerBound;
//         range.second.second = upperBound;
//     }

//     vector<pair<int, int>> values;
//     for (auto& range : ranges) {
//         values.push_back({range.second.first, 1});
//         values.push_back({range.second.second + 1, -1});
//     }

//     sort(values.begin(), values.end());

//     bool run = false;
//     int curVal = INT_MIN;
//     int netWorth = 0;
//     int curWorth = 0;
//     for (int i = 0; i < values.size(); i++) {
//         if (run == false) {
//             run = true;
//             curVal = values[i].first;
//             curWorth += values[i].second;
//             netWorth = max(curWorth, netWorth);
//         }
//     }

//     return;
// }

// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
// }


// // we need to make a dfs function
// // so we start at some value
// // we are given the expression for this value in terms of x
// // the value that starts with value of x can be anything
// // therefore, from here we check with all values that branch off
// // if the value that has branched off already has been visited
// // --> we are going to check if the branching value works or not
// // ----> or if there is a contradiction, for example between -x, x
// // ----> leading to a constant value; this means we return -1
// // --> If the value is not visited yet, 
// // ----> Based on the information in the current value
// // ----> We can give it a value in the array called xterms

// // after the dfs is all finished, goody!
// // so we narrowed it down to whether there is a single value of x
// // that works or not, if it does (remember to check all constralls)
// // then we can see how many ranges work
// // if there isn't a definite x, than we can do the sweep line approach