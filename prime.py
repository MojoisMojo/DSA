class PrimeHelper:
    __slots__ = "_minPrime"  # 每个数的最小质因数

    def __init__(self, maxN):
        """
        maxN_type: int
        """
        """预处理 O(nloglogn)"""
        minPrime = list(range(maxN + 1))
        upper = int(maxN**0.5) + 1
        for i in range(2, upper):
            if minPrime[i] < i:
                continue
            for j in range(i * i, maxN + 1, i):
                if minPrime[j] == j:
                    minPrime[j] = i
        self._minPrime = minPrime

    def isPrime(self, n):
        """
        n_type: int
        rtype: bool
        """
        if n < 2:
            return False
        return self._minPrime[n] == n

    def getPrimeFactors(self, n):
        """
        n_type: int
        """
        """求n的质因数分解 O(logn)"""
        pre, f = 1, self._minPrime
        while n > 1:
            m = f[n]
            if m != pre:
                yield m 
                #不是很理解 可以使用return List替换 但是会多一些时间
                pre = m
            n //= m

    def getPrimes(self):
        """
        _rtype_:  List[int]
        """
        return [x for i, x in enumerate(self._minPrime) if i >= 2 and i == x]
    
prime = open("prime.txt", "w")
PP = PrimeHelper(1000100)
print(PP.getPrimes(),file=prime)
