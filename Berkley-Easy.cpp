#include <bits/stdc++.h>
using namespace std;

void berkeleyAlgorithm(vector<int> &clientTime, int &leaderTime) {
    int sum = 0;
    int avgTime = 0;
    int clientsCount = clientTime.size();

    for (int i = 0; i < clientsCount; i++) {
        sum += clientTime[i] - leaderTime;
    }

    avgTime = sum / (clientsCount + 1);

    leaderTime += avgTime;

    for (int i = 0; i < clientsCount; i++) {
        clientTime[i] += leaderTime - clientTime[i];
    }

}

int main() {
    int clientsCount = 0;
    int leaderTime = 0;

    cout << "Enter the clock time of the leader: ";
    cin >> leaderTime;

    cout << "Enter the number of clients: ";
    cin >> clientsCount;

    vector<int> clientTime(clientsCount, 0);

    cout << "Enter the clock time of each client: "<<endl;
    for (int i = 0; i < clientsCount; i++) {
        cout<< "Client "<< i+1 << " : ";
        cin >> clientTime[i];
    }


    cout << "Before Syncronization";
    cout << "Leader time = "<< leaderTime << endl;
    cout<< "Client time = ";
    for (int i = 0; i < clientsCount; i++) {
        cout << clientTime[i] << " ";
    }

    berkeleyAlgorithm(clientTime, leaderTime);

    cout << "After Syncronization";
    cout << "Leader time = "<< leaderTime << endl;
    cout<< "Client time = ";
    for (int i = 0; i < clientsCount; i++) {
        cout << clientTime[i] << " ";
    }
}