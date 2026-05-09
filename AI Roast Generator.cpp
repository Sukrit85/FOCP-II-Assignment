#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to replace all occurrences of {name} with actual name
string replacePlaceholder(string roast, const string& name) {
    string placeholder = "{name}";
    size_t pos = 0;
    while ((pos = roast.find(placeholder, pos)) != string::npos) {
        roast.replace(pos, placeholder.length(), name);
        pos += name.length();
    }
    return roast;
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Vector storing 10 roast templates with {name} placeholder
    vector<string> roastTemplates = {
        "{name} writes code so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name}'s code runs so slowly that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed and leaves.",
        "{name}'s idea of version control is saving a file as 'final_final_v3_ACTUAL_FINAL.cpp'.",
        "They say every programmer makes mistakes. {name} is just more dedicated to the craft.",
        "{name} once tried to Google their own name — the search engine returned 'Error 404: talent not found'.",
        "Scientists say the universe is infinite, but so is {name}'s ability to write infinite loops.",
        "{name}'s code has more bugs than a rainforest — and somehow less logic.",
        "When {name} pushes to production, the whole team takes a vacation... just in case."
    };

    string userName;

    cout << "==============================" << endl;
    cout << "   Welcome to AI Roast Generator!" << endl;
    cout << "==============================" << endl;
    cout << "Enter your name (or press Enter to exit): ";
    getline(cin, userName);

    // Handle empty input
    if (userName.empty()) {
        cout << "No name entered. Exiting... (even the roaster needs a target!)" << endl;
        return 0;
    }

    // Trim leading/trailing whitespace
    userName.erase(0, userName.find_first_not_of(" \t"));
    userName.erase(userName.find_last_not_of(" \t") + 1);

    if (userName.empty()) {
        cout << "Name cannot be just spaces. Try again next time!" << endl;
        return 0;
    }

    // Pick a random roast
    int randomIndex = rand() % roastTemplates.size();
    string selectedRoast = roastTemplates[randomIndex];

    // Replace {name} with user's actual name
    string finalRoast = replacePlaceholder(selectedRoast, userName);

    cout << "\n--- Your Roast ---" << endl;
    cout << finalRoast << endl;
    cout << "------------------" << endl;
    cout << "\n(Just kidding! You're awesome, " << userName << "!)" << endl;

    return 0;
}
