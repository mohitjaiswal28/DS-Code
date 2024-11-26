#include <bits/stdc++.h>
using namespace std;

class LamportClock {
private:
    int clock;

public:
    LamportClock() : clock(0) {}

    int getClock() const { return clock; }
    
    void increment() { clock++; }

    void sendMessage(LamportClock& receiver) {
        increment();
        receiver.updateClock(clock);
    }

    void updateClock(int receivedClock) {
        clock = max(clock, receivedClock) + 1;
    }

    void performAction(int action) {
        if (action == 1) {
            increment(); // Internal action
        } else if (action == 2) {
            // Send message
            cout << "Process sends message.\n";
        } else {
            cout << "Invalid action\n";
        }
    }
};

int main() {
    LamportClock p1, p2;
    int p1_actions, p2_actions;
    int choice, action;

    cout << "Enter the number of actions for p1: ";
    cin >> p1_actions;
    cout << "Enter the number of actions for p2: ";
    cin >> p2_actions;

    while (p1_actions > 0 || p2_actions > 0) {
        cout << "p1: " << p1.getClock() << "  p2: " << p2.getClock() << endl;

        if (p1_actions == 0) cout << "p1 has no more actions left.\n";
        if (p2_actions == 0) cout << "p2 has no more actions left.\n";

        cout << "Which process wants to perform the task (1 or 2): ";
        cin >> choice;

        if (choice == 1 && p1_actions > 0) {
            cout << "Enter the action for p1 (1 = internal action, 2 = send message): ";
            cin >> action;
            p1.performAction(action);
            if (action == 2) p1.sendMessage(p2);
            p1_actions--;
        } else if (choice == 2 && p2_actions > 0) {
            cout << "Enter the action for p2 (1 = internal action, 2 = send message): ";
            cin >> action;
            p2.performAction(action);
            if (action == 2) p2.sendMessage(p1);
            p2_actions--;
        } else {
            cout << "Invalid choice or no actions left for this process.\n";
        }
    }

    cout << "Final clock values: p1 = " << p1.getClock() << ", p2 = " << p2.getClock() << endl;

    return 0;
}
