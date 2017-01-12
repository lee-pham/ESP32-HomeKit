from sense_hat import SenseHat
import sys
sense = SenseHat()

while True:
        line = sys.stdin.readline()

        if line == '\n':
                line = 0
        else:   
                line = int(line)

        sense.clear(line, line, line)
