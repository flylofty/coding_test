import copy

num = int(input())
answer = [num]


def find_answer():

    global num
    for i in range(num, 0, -1):
        temp = []
        temp.clear()
        temp.append(num)
        temp.append(i)

        index = 1
        while temp[index - 1] - temp[index] >= 0:
            temp.append(temp[index - 1] - temp[index])
            index += 1

        global answer
        if len(answer) < len(temp):
            answer.clear()
            answer = copy.deepcopy(temp)
            temp.clear()


find_answer()
print(len(answer))
for it in answer:
    print(it, end=' ')
