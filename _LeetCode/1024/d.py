def beautifulExtensions(s):
    MOD = 998244353
    n = len(s)
    dp = [0] * (n + 1)
    ones = 0
    zeros = 0
    for i in range(n):
        if s[i] == '1':
            ones += 1
        else:
            zeros += 1
        if abs(ones - zeros) == 1:
            dp[i + 1] = dp[i] + 1
        dp[i + 1] %= MOD
    return sum(dp) % MOD

# 示例用法
s = "11001"
result = beautifulExtensions(s)
print(result)
