#include <bits/stdc++.h>
using namespace std;

void ringAlgorithm(vector <int> &processIds, int numProcesses, int initiator) {
  int leader = processIds[initiator];
  int current = initiator;

  cout << "Process " << processIds[initiator] << " initiates election." << endl;

  do {
    int next = (current + 1) % numProcesses;
    cout << "Process " << processIds[current] << " sends message to Process " << processIds[next] << endl;

    // Keep the highest ID as leader candidate 
    leader = max(leader, processIds[next]);
    current = next;

  } while (current != initiator);

  // Announce the leader 
  cout << "Leader is Process " << leader << endl;
}

int main() {
  int numProcesses;
  int initiator;

  cout << "Enter the number of processes: ";
  cin >> numProcesses;

  vector <int> processIds(numProcesses);

  for (int i = 0; i < numProcesses; i++) {
    cout << "Enter the ID for Process " << i + 1 << ": ";
    cin >> processIds[i];
  }

  cout << "Enter the initiator process index (0 to " << numProcesses - 1 << "): ";
  cin >> initiator;

  ringAlgorithm(processIds, numProcesses, initiator);

  return 0;
}