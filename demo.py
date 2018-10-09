from ProcessBar import Update
import time

if __name__ == "__main__":
    for percent in range(101):
        # your code #
        log = "test"+str(percent)
        Update(percent, log)
        time.sleep(0.1)

