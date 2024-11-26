#include <bits/stdc++.h>
using namespace std;

// void mapper(vector<string> &sent, map<string, int> &mp) {
//     for (const auto &sentence : sent) {
//         string word = "";
//         for (char ch : sentence) {
//             if (ch == ' ') { 
//                 // When encountering a space, process the current word
//                 if (!word.empty()) {
//                     mp[word]++;
//                     word = ""; // Reset word
//                 }
//             } else {
//                 word += ch; // Build the word character by character
//             }
//         }
//         // Add the last word if any
//         if (!word.empty()) {
//             mp[word]++;
//         }
//     }
// }

void mapper(vector<string> &sent, map<string, int> &mp) {
    for (auto it : sent) {
        istringstream stream(it);
        string word;

        while(stream >> word) {
            mp[word]++;
        }
    }

    return;
}

int main() {
    vector<string> sent; 
    map<string, int> mp;
    int n;

    cout << "Enter the number of sent: ";
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++) {
        string t;
        cout << "Enter name " << i + 1 << ": ";
        getline(cin, t); 
        sent.push_back(t); 
    }

    mapper(sent, mp);

    for(auto it:mp) {
        cout<< it.first << " = "<<it.second<<endl;
    }

    return 0;
}