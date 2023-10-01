from typing import List
class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        return list(map(lambda x:x[0],
                        sorted(
                            sorted(list(map(lambda cr:cr[:2],
                                            filter(
                                                lambda r: r[2]>=veganFriendly and r[3]<=maxPrice and r[4]<=maxDistance,
                                                restaurants))
                                        ),key=lambda x: x[0],reverse=True
                                    ),key=lambda x: x[1],reverse=True
                                )
                        )
                    )


restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]
veganFriendly = 1
maxPrice = 50
maxDistance = 10

print(Solution().filterRestaurants(
    restaurants,veganFriendly,maxPrice,maxDistance
))