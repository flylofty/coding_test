N = int(input())

v = list(map(int, input().split()))

Max = 0


def find_answer(n, temp, total):
    if n > 2:
        for i in range(n):
            if i == 0 or i == n - 1:
                continue
            mul = temp[i - 1] * temp[i + 1]

            t = []
            for j in range(n):
                if j == i:
                    continue
                t.append(temp[j])

            find_answer(n - 1, t, total + mul)
    else:
        global Max
        if Max < total:
            Max = total


find_answer(N, v, 0)
print(Max)
# import copy

# N = int(input())

# v = list(map(int, input().split()))

# Max = 0


# def find_answer(n, temp, total):
#     if n > 2:
#         for i in range(n):
#             if i == 0 or i == n - 1:
#                 continue
#             mul = temp[i - 1] * temp[i + 1]
#             t = copy.deepcopy(temp)
#             t.remove(t[i])
#             find_answer(n - 1, t, total + mul)
#     else:
#         global Max
#         if Max < total:
#             Max = total


# find_answer(N, v, 0)
# print(Max)