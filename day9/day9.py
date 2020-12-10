input = open("input.txt", "r")

data = []

for x in input:
    data.append(int(x.strip()))

invalid = 0
for i in range(25, len(data)):
    valid = False
    for j in range(i-25, i):
        for k in range(j, i):
            if data[j] + data[k] == data[i]:
                valid = True
    if (valid is False):
        invalid = data[i]
        print(invalid)

for i in range(0, len(data)):
    sum = data[i]
    list = [data[i]]
    for j in range(i+1, len(data)):
        sum += data[j]
        list.append(data[j])
        if sum == invalid:
            print(min(list) + max(list))
            break
        if sum > invalid:
            break

        
