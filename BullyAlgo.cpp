#include <bits/stdc++.h>
using namespace std;

void bullyAlgorithm(vector <int> &processIds, int numProcesses, int initiator) {
  int leader = -1;

  // Processes with higher IDs respond
  for (int i = 0; i < numProcesses; ++i) {
    if (processIds[i] > processIds[initiator]) {
      cout << "Process " << processIds[initiator] << " initiates election." << endl;
      cout << "Process " << processIds[i] << " responds to Process " << processIds[initiator] << endl;
      leader = processIds[i];
    }
  }

  if (leader == -1) {
    // If no higher process responds, the initiator becomes the leader
    leader = processIds[initiator];
  }
  
  // Announce the leader
  for (int i = 0; i < numProcesses; ++i) {
    if (processIds[i] != leader) {
      cout << "Process " << leader << " notifies Process " << processIds[i] << " as the new leader." <<
        endl;
    }
  }
  cout << "Final leader (coordinator) is Process " << leader << endl;
}

int main() {
  int numProcesses;
  int initiator;

  cout << "Enter the number of processes: ";
  cin >> numProcesses;
  
  vector<int> processIds(numProcesses);

  for (int i=0; i<numProcesses; i++) {
    cout << "Enter the ID for Process" << i + 1 << ": ";
    cin >> processIds[i];
  }

  cout << "Enter the initiator process index (0 to " << numProcesses - 1 << "): ";
  cin >> initiator;

  bullyAlgorithm(processIds, numProcesses, initiator);
  
  return 0;
}