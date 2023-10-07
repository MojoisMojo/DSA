class StockSpanner:

    def __init__(self):
        self.st = [[0x3f3f3f3f,0]]
        self.cnt = 0


    def next(self, price: int) -> int:
        self.cnt += 1
        while self.st and self.st[-1][0] <= price:
            self.st.pop()
        self.st.append([price,self.cnt])

        return self.st[-1][1] - self.st[-2][1]



# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)