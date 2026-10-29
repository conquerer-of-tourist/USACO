#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> vals (n);
    for (ll i = 0; i < n; i++) {
        cin >> vals[i];
    }
    for (ll i = 0; i < q; i++) {
        int a;
        cin >> a;
        ll ans = LLONG_MAX;
        for (ll j = 0; j < n; j++) {
            ll curr = ((1 << j) % a != 0) ? 1 : 0;
            curr += (1 << j) / a;
            curr *= vals[j];
            ans = min(ans, curr);
        }
        cout << ans << '\n';
    }
}

/*


arithmetic by 

> storing ratios as a double value
> weighted sort on ratios
> so like
    > something like the cheaper ones rank higher
    > and then we do like a while loop or something
    > so while we haven't been able to obtain the cheapest price or more, yet, we will stil be able to add another option
    > and then it's just the matter of being able to simulate this whole process without overloading in terms of time.


*/