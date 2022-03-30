def busiestservers(k, arrival, load):
    em = [0] * 2 * k
    cnt = [0] * k
    endtime = [0] * k
    n = len(arrival)
    ans = []
    if n <= k:
        for i in range(n):
            ans.append(i)
        return ans
    j = 0
    while j < n:
        jj = j % k
        if em[jj] == 0:
            em[jj] = 1
            em[jj + k] = em[jj]
            cnt[jj] += 1
            endtime[jj] = arrival[j] + load[j]
        else:
            if endtime[jj] <= arrival[j]:
                # em[jj] = 1
                # em[jj + k] = em[jj]
                cnt[jj] += 1
                endtime[jj] = arrival[j] + load[j]
            else:
                for x in range(jj + 1, k + jj):
                    if endtime[x % k] <= arrival[j]:
                        # em[x % k] = 1
                        cnt[x % k] += 1
                        endtime[x % k] = arrival[j] + load[j]
                        break

        j += 1
        # print(j, cnt)
        # print(em)
        # print(endtime)
        # print('=' * 10)
    maxcnt = max(cnt)
    for i in range(k):
        if cnt[i] == maxcnt:
            ans.append(i)
    return ans
