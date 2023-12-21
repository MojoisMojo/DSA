from typing import List
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        char_map = [-1 for i in range(26)]
        ans = 0
        for word in words:
            flagtemp = [False for i in range(26)]
            for c in word:
                flagtemp[ord(c)-ord('a')] = True
            length = len(word)
            for i,flag in enumerate(flagtemp):
                if(flag): 
                    ans = max(ans,char_map[i]*length)
                else:
                    char_map[i] = max(char_map[i],length)
        return ans

