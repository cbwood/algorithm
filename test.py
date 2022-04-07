a = list(map(int, input().split()))
n, ans = a[0], a[1]
s = input()

for x in s:
    if x == 'U':
        ans //= 2
    elif x == 'L':
        ans = ans * 2;
    else:
        ans *= 2

print(ans)
