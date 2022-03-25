n = int(input())
while n:
    n -= 1
    l = list(map(int, input().split()))
    l.sort()
    ans = 0
    ans += l[0]
    l = [l[1]] + [l[i] - ans for i in range(2, len(l))]
    l.sort()
    ans += l[0]
    print(ans)
