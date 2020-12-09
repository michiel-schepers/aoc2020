input = open("input.txt","r")

instructions = []
for x in input:
    instructions += [x.strip().split(" ")]

stopped = False

for i in range(len(instructions)):
    if 'nop' in instructions[i]:
        original = 'nop'
        instructions[i][0] = 'jmp'
    elif 'jmp' in instructions[i]:
        original = 'jmp'
        instructions[i][0] = 'nop'

    accumulator = 0
    visited = set()
    current = 0
    while not current in visited: 
        if current == len(instructions):
            stopped = True
            break
            
        visited.add(current)
        instr = instructions[current]

        if "acc" in instr[0]:
            accumulator += int (instr[1])
            current += 1
        
        elif  "jmp" in instr[0]:
            current += int(instr[1].strip("+"))
            
        else:
            current += 1
    
    if not 'acc' in instructions[i]:
        instructions[i][0] = original

    if stopped:
        print(accumulator)
        break



