N = int(input())

answer = []
arr = []
for i in range(N):
    arr.append(list(input()))

    total = 0
    temp = 0
    for j in range(len(arr[i])):
        if arr[i][j] == 'O':
            temp += 1
            total += temp
        else:
            temp = 0

    print(total)

# import sys

# N = int(sys.stdin.readline())

# for i in range(N):
#     s = sys.stdin.readline()
#     total = 0
#     temp = 0
#     for j in range(len(s)):
#         if s[j] == 'O':
#             temp += 1
#             total += temp
#         else:
#             temp = 0

#     print(total)