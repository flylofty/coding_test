from collections import deque

N = int(input())
M = int(input())

g = [[] for i in range(N + 1)]
for i in range(M):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)


def bfs():

    q = deque()
    check = [False for i in range(N + 1)]
    q.append(1)
    check[1] = True

    cnt = 0
    while q:
        node = q.popleft()

        for i in range(len(g[node])):
            node2 = g[node][i]
            if check[node2] is False:
                q.append(node2)
                check[node2] = True
                cnt += 1

    print(cnt)


bfs()
