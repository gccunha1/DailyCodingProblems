import time
import threading
import logging


def func1():
    print("Hello f1")
    time.sleep(1)
    print("Goodbye f1")


def func2():
    print("Hello f2")
    time.sleep(2)
    print("Goodbye f2")


input_to_call = {"f1": func1, "f2": func2, "q": exit}


class JobThread(threading.Thread):
    def __init__(self, job, time_to_run):
        threading.Thread.__init__(self)
        self.job = job
        self.time_to_run = time_to_run

    def run(self):
        time.sleep(self.time_to_run / 1000)
        self.job()


if __name__ == "__main__":
    while True:
        print("Schedule a job [<job_name> <time>]")
        print("->", end=" ")
        input_command = input()
        if input_command == "q":
            break
        input_command = input_command.split(" ")
        if len(input_command) != 2:
            logging.error("Two arguments only.")
            continue

        if input_command[0] not in input_to_call.keys():
            logging.error(f"Job does not exist. Possible jobs: {input_to_call.keys()}")
            continue
        try:
            JobThread(input_to_call[input_command[0]], int(input_command[1])).start()
        except ValueError:
            logging.error("Time must be an integer.")
            continue
