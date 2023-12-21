#include <bits/stdc++.h>

using namespace std;
namespace two_pq
{

    class MedianFinder {
        priority_queue<int, vector<int>, greater<int>> topK;
        priority_queue<int> left;
        int _size;
    public:
        MedianFinder() {
            _size = 0;
        }

        void addNum(int num) {
            _size++;
            if (!topK.empty() && num > topK.top()) {
                left.push(topK.top());
                topK.pop();
                topK.push(num);
            }
            else {
                left.push(num);
            }
            if (_size & 1) {
                topK.push(left.top());left.pop();
            }
        }

        double findMedian() {
            if (_size & 1) {
                return topK.top();
            }
            else {
                return (topK.top() + left.top()) / 2.0;
            }
        }
    };
} // namespace two_pq

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
    multiset<int> nums;
    multiset<int>::iterator left, right;

public:
    MedianFinder() : left(nums.end()), right(nums.end()) {}

    void addNum(int num) {
        const size_t n = nums.size();

        nums.insert(num);
        if (!n) {
            left = right = nums.begin();
        }
        else if (n & 1) {
            if (num < *left) {
                left--;
            }
            else {
                right++;
            }
        }
        else {
            if (num > *left && num < *right) {
                left++;
                right--;
            }
            else if (num >= *right) {
                left++;
            }
            else {
                right--;
                left = right;
            }
        }
    }

    double findMedian() {
        return (*left + *right) / 2.0;
    }
};
