file = open("input.txt", "r")
input = file.read()
file.close()

answers = input.split("\n\n")
for i in range(len(answers)):
    answers[i] = answers[i].replace("\n", "")

def count(answer):
    unique = ""
    for i in answer:
        if i not in unique:
            unique += i
    return len(unique)

counter = 0
for answer in answers:
    counter += count(answer)

print(counter)