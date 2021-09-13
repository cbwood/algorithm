class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        t = 0
        while k > 0:
            while(t < len(num)-1 and num[t] <= num[t+1]):
                t += 1
            if t < len(num)-1:
                k -= 1
                num = num[:t]+num[t+1:]
                t = max(0, t-1)
            else:
                break
            while len(num)> 0 and num[0] == '0':
                num = num[1:]
        while k > 0 and len(num)>0:
            tmp = len(num)-1
            while tmp > 0 and num[tmp] == '0':
                tmp -= 1
            k -= 1
            num = num[:tmp] + num[tmp+1:]
        if len(num) == 0:
            num = '0'
        return num
        

if __name__ == "__main__":
    so = Solution()
    print(so.removeKdigits("5337", 2))