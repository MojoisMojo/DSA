#include "stringmatch.cc"
#include <bits/stdc++.h>

using namespace std;
const int TESTTIMES = 1e2 + 9;
const int STRINGLENGTHS = 19;
ranlux48 engine(time(nullptr));//利用时间种子生成随机数引擎
uniform_int_distribution<> distrib('a', 'a' + 25);

fstream output("out.txt");

string generateString(int length) {
    string temp = "";
    while (length--)
        temp += distrib(engine);//随机数
    return temp;
}

int main() {
    int cnt = 0;
    for (int t = 0; t < TESTTIMES; ++t) {
        string s1 = generateString(STRINGLENGTHS), s2 = generateString(STRINGLENGTHS);
        output << s1 << "\t" << s2 << endl;
        cnt += (is_matched(s1, s2) == is_really_matched(s1, s2));
    }
    output << "概率是" << (cnt * 1.0) / TESTTIMES << endl;
    output.close();
    //system("pause");
    return 0;
}
