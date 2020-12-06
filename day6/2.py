file = open("input.txt", "r")
input = file.read()
file.close()

answers = input.split("\n\n")
for i in range(len(answers)):
    answers[i] = answers[i].split("\n")

def count_char(answer, char):
    counter = 0
    for i in answer:
        if i is char:
            counter += 1
    
    return counter

def count_yes(group_answer):
    unique = ""
    one_answer = ""
    length = len(group_answer)
    for answer in group_answer:
        one_answer += answer
    for char in one_answer:
        if count_char(one_answer, char) == length and char not in unique:
            unique += char
    return len(unique)  


counter = 0
for answer in answers:
    counter += count_yes(answer)

print(counter)