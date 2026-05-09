#include <bits/stdc++.h>
using namespace std;

unordered_map<string, unordered_set<string>> dataStore;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int queries;
    cin >> queries;

    while (queries--) {

        string command;
        cin >> command;

        if (command == "BOOK") {

            string customer, movie;
            cin >> customer >> movie;

            bool alreadyBooked = dataStore[movie].find(customer) != dataStore[movie].end();
            bool full = dataStore[movie].size() >= 100;

            if (alreadyBooked || full) {
                cout << "false\n";
                continue;
            }

            dataStore[movie].insert(customer);
            cout << "true\n";
        }

        else if (command == "CANCEL") {

            string customer, movie;
            cin >> customer >> movie;

            if (dataStore[movie].find(customer) == dataStore[movie].end()) {
                cout << "false\n";
            } else {
                dataStore[movie].erase(customer);
                cout << "true\n";
            }
        }

        else if (command == "IS_BOOKED") {

            string customer, movie;
            cin >> customer >> movie;

            if (dataStore[movie].find(customer) != dataStore[movie].end())
                cout << "true\n";
            else
                cout << "false\n";
        }

        else {

            string movie;
            cin >> movie;

            int booked = dataStore[movie].size();
            cout << 100 - booked << '\n';
        }
    }

    return 0;
}
