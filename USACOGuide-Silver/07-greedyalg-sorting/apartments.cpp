/*

    Information
    ======================
    August 3rd, 2026
    CSES Problemset - Apartments

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> people (n);
    vector<int> apartments (m);
    for (auto& person : people) {
        cin >> person;
    }
    for (auto& apart : apartments) {
        cin >> apart;
    }
    sort(people.begin(), people.end());
    sort(apartments.begin(), apartments.end());

    int counter = 0;
    int i = 0;
    int j = 0;
    while (true) {
        if (i == n || j == m) {
            break;
        }
        if (abs(people[i] - apartments[j]) <= d) {
            counter++;
            i++;
            j++;
        }
        else if (people[i] > apartments[j]) {
            j++;
        }
        else if (apartments[j] > people[i]) {
            i++;
        }
    }
    cout << counter << '\n';
}