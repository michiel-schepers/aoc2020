file = open("input.txt", "r")
input = file.readlines()
file.close()

d = dict()

# put input into 1 big dict, containing one dict for every line of input
for x in input: 
    splitted = x.split(" contain ")
    e = dict()
    stripped = splitted[1].strip().strip(".").split(", ")
    if 'no other bags' not in stripped:
        for y in stripped:
            number = int(y.strip()[0])
            if y.strip()[-1] == 's':
                key = y.strip()[2:-1]
            else:
                key = y.strip()[2:]
            e[key] = number
    d[splitted[0][0:-1]] = e

# create set of dependent bags recursively
def expand(key, d):
  if d[key] == {}:
    return set()
  else:
    result = set()
    for k in d[key]:
      result.add(k)
      result = result.union(expand(k,d))
    return result

# count number of bags inside of key recursively
def inside(key, d):
    if d[key] == {}:
      return 0
    else:
      counter = 0
      for k in d[key]:
        counter += d[key][k]
        counter += d[key][k] * inside(k, d)
    
    return counter

counter = 0
for key in d:
    expanded = expand(key, d)
    for i in expanded:
        if "shiny gold" in i:
            counter += 1
    
print("part 1: " + str(counter))
print("part 2: " + str(inside("shiny gold bag", d)))





