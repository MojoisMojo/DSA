class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        ans = ""
        l,r=0,0
        cnt = 0
        while cnt < k and r < len(s):
            cnt += (s[r]=="1")
            r += 1
        if cnt < k: return ""
        while l < r and s[l] == "0":
            l+=1
        ans = s[l:r] # r 开区间
        while r < len(s):
            l += 1 # 去1
            cnt -= 1
            while l < r and s[l] == "0":
                #去0
                l += 1
            # 加1
            while cnt < k and r < len(s):
                cnt += (s[r] == "1")
                r+=1 # r 开区间
            if cnt < k: return ans
            newans = s[l:r]
            if len(newans) < len(ans): ans = newans
            elif len(newans) == len(ans): ans = min(ans,newans)
        return ans