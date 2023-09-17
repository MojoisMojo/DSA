from typing import List
class Solution:
    def maxNumberOfAlloys(self, n: int, k: int, budget: int, composition: List[List[int]], stock: List[int], cost: List[int]) -> int:
        ans = 0
        mx = min(stock) + budget
        for com in composition:
            def check(num: int) -> int:
                money = 0
                for s, base, c in zip(stock, com, cost):
                    if s < base * num:
                        money += (base * num - s) * c
                        if money > budget:
                            return False
                return True

            left, right = 0, mx + 1
            while left + 1 < right:  # 开区间写法
                mid = (left + right) // 2
                if check(mid):
                    left = mid
                else:
                    right = mid
            ans = max(ans, left)
        return ans

if __name__ == "__main__":
    n = 3
    k = 2
    budget = 0
    composition = [[2,2,2],[1,10,1]]
    stock = [3,12,3]
    cost = [10,10,10]
    print(Solution().maxNumberOfAlloys(n,k,budget,composition,stock,cost))