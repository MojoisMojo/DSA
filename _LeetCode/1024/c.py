class Solution:
    def mathProblem(self, s: str) -> str:
        left, right = s.split("=")
        mathF = "+-"
        varible = "x"
        alph = "1234567890"

        def process(seq: str):
            cnt_x = 0
            cnt_v = 0
            idx = len(seq)

            def getNum() -> int:
                nonlocal idx
                idx = end = idx + 1
                while idx > 0 and seq[idx - 1] in alph:
                    idx -= 1
                m = -1 if (idx > 0 and seq[idx - 1] == "-") else 1
                if idx < end:
                    idx -= 1
                    return m * int(seq[idx + 1 : end])
                else:
                    idx -= 1
                    return m * 1

            while idx > 0:
                idx -= 1
                c = seq[idx]
                if c == varible:
                    idx -= 1
                    cnt_x += getNum()

                else:
                    cnt_v += getNum()
            return cnt_x, cnt_v

        cnt_xl, cnt_constl = process(left)
        cnt_xr, cnt_constr = process(right)
        x = cnt_xl - cnt_xr
        v = cnt_constr - cnt_constl
        if x == 0:
            if v == 0:
                return "Infinite solutions"
            else:
                return "No solution"
        else:
            if v == 0:
                return "x=0"
            else:
                if abs(x) % abs(v):
                    return "x=" + str(x // v)
                else:
                    return "No solution"
