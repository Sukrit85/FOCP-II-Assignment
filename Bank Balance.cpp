#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, long long> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        string op, x;
        long long y;
        cin >> op >> x;

        if (op == "BALANCE") {
            cout << (mp.count(x) ? mp[x] : -1) << "\n";
        } 
        else {
            cin >> y;

            if (op == "CREATE") {
                if (mp.count(x)) {
                    mp[x] += y;
                    cout << "false\n";
                } else {
                    mp[x] = y;
                    cout << "true\n";
                }
            } 
            else if (op == "DEBIT") {
                if (mp.count(x) && mp[x] >= y) {
                    mp[x] -= y;
                    cout << "true\n";
                } else {
                    cout << "false\n";
                }
            } 
            else { 
                if (mp.count(x)) {
                    mp[x] += y;
                    cout << "true\n";
                } else {
                    cout << "false\n";
                }
            }
        }
    }
    return 0;
}
