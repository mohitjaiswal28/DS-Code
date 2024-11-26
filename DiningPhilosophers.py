import threading
import time

# Number of philosophers and forks
N = 5  

# Create a list of locks to represent forks
forks = []
for _ in range(N):
    forks.append(threading.Lock())  # Each fork is represented by a threading.Lock

def philosopher(id):
    for _ in range(3):  # Each philosopher repeats the process of THINKING, HUNGRY, and EATING three times
        print(f"Philosopher {id} is THINKING.")  
        time.sleep(1)  

        print(f"Philosopher {id} is HUNGRY.")  # Philosopher transitions to the HUNGRY state

        # Determine the order of picking up forks
        if id % 2 == 0:  # Even-numbered philosophers pick their left fork first
            first, second = id, (id + 1) % N
        else:  # Odd-numbered philosophers pick their right fork first
            first, second = (id + 1) % N, id

        # Acquire both forks (locks) using the determined order
        with forks[first], forks[second]:
            print(f"Philosopher {id} is EATING.")  # Philosopher transitions to the EATING state
            time.sleep(2)  # Simulate eating time

        print(f"Philosopher {id} finished EATING.")  # Philosopher finishes eating

# Create and start threads for each philosopher
threads = []
for i in range(N):  # Create a thread for each philosopher
    t = threading.Thread(target=philosopher, args=(i,))
    threads.append(t)  # Add the thread to the list

for t in threads:
    t.start()  # Start each thread

for t in threads:
    t.join()  # Wait for all threads to finish
