#include <iostream>
#include<string>
using namespace std;

bool is_matched(string s1, string s2) {
    int len1 = s1.length(), len2 = s2.length();
    if (len1 != len2) {
        try {
            throw runtime_error("len1 != len2");
        }
        catch (runtime_error e) {
            ;
        }
        return false;
    }
    int sum = 0;
    for (int i = 0;i < len1;i++)
        sum += s2[i];

    int sumsum = 0;
    for (int i = 0;i < len2;i++)
        sumsum += s1[i];

    return (sumsum == sum && s1[0] == s2[0]);
}
bool is_really_matched(string s1, string s2) {
    int len1 = s1.length(), len2 = s2.length();
    if (len1 != len2) {
        return false;
    }
    for (int i = 0; i < len1; ++i) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}
