#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

unordered_map<string, unordered_set<string>> movieCustomers;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfQueries;
    cin >> numberOfQueries;

    while (numberOfQueries--) {

        string operationType;
        cin >> operationType;

        if (operationType == "BOOK") {

            string customerId, movieId;
            cin >> customerId >> movieId;

            auto &customers = movieCustomers[movieId];

            if (customers.count(customerId) || customers.size() >= 100) {
                cout << "false\n";
            } else {
                customers.insert(customerId);
                cout << "true\n";
            }

        } 
        else if (operationType == "CANCEL") {

            string customerId, movieId;
            cin >> customerId >> movieId;

            auto it = movieCustomers.find(movieId);

            if (it == movieCustomers.end() || !it->second.count(customerId)) {
                cout << "false\n";
            } else {
                it->second.erase(customerId);
                cout << "true\n";
            }

        } 
        else if (operationType == "IS_BOOKED") {

            string customerId, movieId;
            cin >> customerId >> movieId;

            auto it = movieCustomers.find(movieId);

            if (it != movieCustomers.end() && it->second.count(customerId))
                cout << "true\n";
            else
                cout << "false\n";

        } 
        else if (operationType == "AVAILABLE_TICKETS") {

            string movieId;
            cin >> movieId;

            auto it = movieCustomers.find(movieId);

            int booked = (it == movieCustomers.end()) ? 0 : it->second.size();

            cout << (100 - booked) << "\n";
        }
    }

    return 0;
}
