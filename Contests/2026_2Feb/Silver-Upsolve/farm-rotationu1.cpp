#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> valsSingleLen (n);
    set<int> total;
    for (auto& val : valsSingleLen) {
        cin >> val;
        total.insert(val);
    }
    int numVals = total.size();

    vector<int> valsDoubleLen;
    for (int i = 0; i < 2; i++) {
        for (auto& val : valsSingleLen) {
            valsDoubleLen.push_back(val);
        }
    }
    map<int, int> current;
    current[valsDoubleLen[0]]++;
    int pL = 0;
    int pR = 0;
    vector<int> goRight (n);
    vector<int> goLeft (n);
    for (int i = 0; i < n; i++) {
        while ((int) current.size() != (int) numVals) {
            pR++;
            current[valsDoubleLen[pR]]++;
        }
        goRight[i] = pR - pL;
        current[valsDoubleLen[pL]]--;
        if (current[valsDoubleLen[pL]] < 1) {
            current.erase(valsDoubleLen[pL]);
        }
        pL++;
    }
    int pStart = 2 * n - 1;
    int pEnd = 2 * n - 1;
    map<int, int> current2;
    current2[valsDoubleLen[2 * n - 1]]++;
    for (int i = 2 * n - 1; i > n - 1; i--) {
        while ((signed int) current2.size() != (int) numVals) {
            pEnd--;
            current2[valsDoubleLen[pEnd]]++;
        }
        goLeft[i % n] = pStart - pEnd;
        current2[valsDoubleLen[pStart]]--;
        if (current2[valsDoubleLen[pStart]] < 1) {
            current2.erase(valsDoubleLen[pStart]);
        }
        pStart--;
    }

    vector<int> minLeftThenRight (n);
    vector<int> minRightThenLeft (n);

    minLeftThenRight[0] = (goRight[0] - 0);
    for (int i = 1; i < n; i++) {
        minLeftThenRight[i] = min(minLeftThenRight[i - 1], goRight[i] - i);
    }
    minRightThenLeft[n - 1] = goLeft[n - 1] + n - 1;
    for (int i = n - 2; i >= 0; i--) {
        minRightThenLeft[i] = min(minRightThenLeft[i + 1], goLeft[i] + i);
    }

    for (int i = 0; i < n - 1; i++) {
        cout << min(i + minLeftThenRight[i], -1 * i + minRightThenLeft[i]) << " ";
    }
    cout << min(n - 1 + minLeftThenRight[n - 1], -1 * (n - 1) + minRightThenLeft[n - 1]);
    return 0;
}