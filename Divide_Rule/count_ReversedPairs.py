from typing import List


class Solution:
    def __mergeSort(self, array: List[int], tmp: List[int], l: int, r: int) -> int:
        if l >= r:
            return 0

        mid = (l + r) // 2
        cntPairs = self.__mergeSort(array, tmp, l, mid) + self.__mergeSort(
            array, tmp, mid + 1, r
        )
        i, j = l, mid + 1
        _now = l
        while i <= mid and j <= r:
            if array[i] <= array[j]:
                tmp[_now] = array[i]
                i += 1
                cntPairs += j - (mid + 1)
            else:
                tmp[_now] = array[j]
                j += 1

            _now += 1

        while i <= mid:
            tmp[_now], _now, i = array[i], _now + 1, i + 1
            cntPairs += j - (mid + 1)

        while j <= r:
            tmp[_now], _now, j = array[j], _now + 1, j + 1

        array[l : r + 1] = tmp[l : r + 1]
        return cntPairs

    def count_ReversedPairs(self, array: List[int]) -> int:
        n = len(array)
        tmp = [0] * n
        return self.__mergeSort(array, tmp, 0, n - 1)


if __name__ == "__main__":
    """
    (11,7)  (11,6)  (11,4)  (11,5)  (7,6)  (7,4)  (7,5)  (6,4)  (6,5)
    """
    print(Solution().count_ReversedPairs([11, 7, 6, 4, 5]))  # 9
