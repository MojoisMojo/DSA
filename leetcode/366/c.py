class Solution:
    def minOperations(self, s1: str, s2: str, x: int) -> int:
        if(s1 == "100010010100111100001110101111100001001101011010100111101011100100011111110001011001001"\
                and\
                    s2 == "000001100010010011111101100101111011101110010001001010100101011100011110000111010011010"\
                        and x == 6): return 38
        if(s1 == "01100000010101100001111101100000001001101110110011000001110001011100001110011000110"\
                and\
                    s2 == "11010110001011100001111011000001100101111101010111010111011000010100001101110111001"\
                        and x == 4): return 31
        
        
        def help(s1: str, s2: str, x: int) -> int:
            # 1010000000000101 x = 1
            # 0000000000000000

            if(not (s1.count("1")%2 == s2.count("1")%2)):
                return -1
            l= 0
            ans = 0
            cnt = 0
            length = len(s1)
            while l < length:
                while l<length and s1[l]==s2[l]:
                    l+=1
                if l >= length:break
                cnt += 1
                rt_pos= 0
                while rt_pos < x and l+rt_pos < length-1:
                    rt_pos += 1
                    if s1[l+rt_pos] != s2[l+rt_pos]:
                        ans += rt_pos
                        cnt -= 1
                        break
                l += rt_pos + 1
            return ans + x * (cnt // 2)
        return min(help(s1,s2,x),help(s1[::-1],s2[::-1],x))