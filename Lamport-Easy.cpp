#include <bits/stdc++.h>
using namespace std;

int main() {
    int p1 = 0, p2 = 0; // Initialize logical clocks for p1 and p2
    int p1_cnt, p2_cnt;
    int choice;

    cout << "Enter the number of actions for p1: ";
    cin >> p1_cnt;

    cout << "Enter the number of actions for p2: ";
    cin >> p2_cnt;

    while (p1_cnt > 0 || p2_cnt > 0) {

        // Display the current clock values for both processes
        cout << "p1: " << p1 << endl;
        cout << "p2: " << p2 << endl;

        if(p1_cnt == 0) {
            cout<<"p1 has no more actions left"<<endl;
        }

        if(p2_cnt == 0) {
            cout<<"p2 has no more actions left"<<endl;
        }

        cout << "Which process wants to perform the task (1 or 2): ";
        cin >> choice;

        if(choice != 1 && choice != 2) {
            cout << "Invalid choice" << endl;
            continue;
        }

        // Process 1
        if(choice == 1 && p1_cnt > 0) {
            int action;
            cout << "Enter the type of action for p1 (1 = internal action and 2 = send msg): ";
            cin >> action;
            p1_cnt--;

            // Internal action
            if(action == 1) {
                p1++; // Increment process p1's clock
            } 
            
            // Send message
            else if(action == 2) {
                cout << "p1 sends msg to p2" << endl;
                p1++; // Increment p1's clock before sending the message
                p2 = max(p2, p1) + 1; // Update p2's clock based on p1's clock
            }
            else {
                cout << "Invalid action" << endl;
            }
        }

        // Process 2
        if(choice == 2 && p2_cnt > 0) {
            int action;
            cout << "Enter the type of action for p2 (1 = internal action and 2 = send msg): ";
            cin >> action;
            p2_cnt--;

            // Internal action
            if(action == 1) {
                p2++; // Increment process p2's clock
            } 
            
            // Send message
            else if(action == 2) {
                cout << "p2 sends msg to p1" << endl;
                p2++; // Increment p2's clock before sending the message
                p1 = max(p2, p1) + 1; // Update p1's clock based on p2's clock
            }
            else {
                cout << "Invalid action" << endl;
            }
        }

    }  

    // Display final clock values for both processes
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;

    return 0;
}