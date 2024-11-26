import time
import threading

N = 5
forks = []
mutex = threading.Semaphore(1)

for _ in range(N):
    forks.append(threading.Lock())

def philosopher(index):
    while True:
        print(f"Philosopher {index} is thinking...")
        time.sleep(2)

        print(f"Philosopher {index} is hungry...")

        mutex.acquire()

        left_fork_index = index
        right_fork_index = (index + 1) % N

        forks[left_fork_index].acquire()
        forks[right_fork_index].acquire()


        print(f"Philosopher {index} is eating...")
        time.sleep(2)

        forks[left_fork_index].release()
        forks[right_fork_index].release()
        
        mutex.release()

threads = []

for i in range(N):
    t = threading.Thread(target=philosopher, args=(i,))
    threads.append(t)

for t in threads:
    t.start()

for t in threads:
    t.join()

