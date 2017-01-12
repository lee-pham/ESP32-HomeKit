from sense_hat import SenseHat
import sys
import json
import colorsys

sense = SenseHat()

def clean(input):
        output = json.JSONDecoder().decode(input)
        h = round(output[0]/360.0)
        s = round(output[1]/100.0)
        v = round(output[2]/100.0)
        output = list(colorsys.hsv_to_rgb(h, s, v))
        output[0] = int(round(output[0]*255))
        output[1] = int(round(output[1]*255))
        output[2] = int(round(output[2]*255))
        return output

while True:
        line = sys.stdin.readline()
        rgb = clean(line)
        sense.clear(rgb[0], rgb[1], rgb[2])
