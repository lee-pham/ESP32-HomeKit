from sense_hat import SenseHat

sense = SenseHat()
index = range(0, 256) + range(0, 256)[::-1]

for j in range(0, 3):
  for i in index:
    sense.clear(i, i, i)
