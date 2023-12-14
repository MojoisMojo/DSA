
class Factorial:
    def __init__(self, N, mod) -> None:
        # Initialize the class with maximum value for factorials (N) and the modulus (mod)
        N += 1
        self.mod = mod

        # Initialize arrays to store factorials and inverses of factorials modulo mod
        self.f = [1 for _ in range(N)]
        self.g = [1 for _ in range(N)]

        # Precompute factorials modulo mod and store in the f array
        for i in range(1, N):
            self.f[i] = self.f[i - 1] * i % self.mod

        # Calculate inverses of factorials modulo mod and store in the g array
        self.g[-1] = pow(self.f[-1], mod - 2, mod)
        for i in range(N - 2, -1, -1):
            self.g[i] = self.g[i + 1] * (i + 1) % self.mod

    # Method to get the factorial of n modulo mod
    def fac(self, n):
        return self.f[n]

    # Method to get the inverse of the factorial of n modulo mod
    def fac_inv(self, n):
        return self.g[n]

    # Method to calculate "n choose m" modulo mod
    def combi(self, n, m):
        if n < m or m < 0 or n < 0:
            return 0
        return self.f[n] * self.g[m] % self.mod * self.g[n - m] % self.mod

    # Method to calculate permutations of n elements taken m at a time modulo mod
    def permu(self, n, m):
        if n < m or m < 0 or n < 0:
            return 0
        return self.f[n] * self.g[n - m] % self.mod

    # Method to calculate the nth Catalan number modulo mod
    def catalan(self, n):
        return (self.combi(2 * n, n) - self.combi(2 * n, n - 1)) % self.mod

    # Method to get the inverse of n modulo mod
    def inv(self, n):
        return self.f[n - 1] * self.g[n] % self.mod

# Instantiate an object of the Factorial class with specific parameters
fact = Factorial(2 * 10 ** 5, 99876543)
