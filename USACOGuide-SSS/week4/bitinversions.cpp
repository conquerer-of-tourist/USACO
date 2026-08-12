/*

    August 12th, 2026 - Practice Session / Review
    Hengsheng Wang
    August 12, 2026

*/

#include <bits/stdc++.h>
using namespace std;

void addSplit(set<int>& dividers, multiset<int>& runs, int x)
{
    auto right = dividers.lower_bound(x);
    auto left = right; left--;

    int oldLen = *right - *left;
    runs.erase(runs.find(oldLen));
    runs.insert(x - *left);
    runs.insert(*right - x);
    dividers.insert(x);
}

void removeSplit(set<int>& dividers, multiset<int>& runs, int x) {
    auto right = dividers.upper_bound(x);
    auto mid = right; mid--;
    auto left = mid; left--;

    int oldLeft = *mid - *left;
    int oldRight = *right - *mid;

    runs.erase(runs.find(oldLeft));
    runs.erase(runs.find(oldRight));
    runs.insert(oldLeft + oldRight);

    dividers.erase(mid);
}

int main()
{
    string s;
    cin >> s;
    int n = (int) s.size();
    int q;
    cin >> q;
    vector<int> queries (q);
    for (auto& f : queries) {
        cin >> f;
    }
    set<int> dividers;
    multiset<int> runs;
    int lastVal = s[0];
    dividers.insert(0);
    for (int i = 1; i < n; i++) {
        if (s[i] == lastVal) {
            continue;
        }
        else {
            lastVal = s[i];
            runs.insert(i - *(dividers.rbegin()));
            dividers.insert(i);
        }
    }
    runs.insert(n - *(dividers.rbegin()));
    dividers.insert(n);
    
    for (auto& query : queries) {
        query--;
        if (query > 0) {
            if (dividers.count(query)) {
                removeSplit(dividers, runs, query);
            }
            else {
                addSplit(dividers, runs, query);
            }
        }
        if (query < n - 1) {
            if (dividers.count(query + 1)) {
                removeSplit(dividers, runs, query + 1);
            }
            else {
                addSplit(dividers, runs, query + 1);
            }
        }
        cout << *runs.rbegin() << '\n';
    }
}