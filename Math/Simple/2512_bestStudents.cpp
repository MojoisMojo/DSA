#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    // vector<string> split(const string &st, const string &token) {
    //     vector<string> res;

    //     int length_of_token = token.size();
    //     size_t pos = 0;
    //     for (size_t edpos = st.find(token, pos);
    //         edpos != string::npos;
    //         pos = edpos + length_of_token, edpos = st.find(token, pos)
    //         ) {
    //         res.push_back(st.substr(pos, edpos - pos));
    //     }
    //     if (pos < st.size()) res.push_back(st.substr(pos));
    //     return res;
    // }
    vector<int> topStudents(vector<string> &positive_feedback,
        vector<string> &negative_feedback,
        vector<string> &report,
        vector<int> &student_id, int k) {
        unordered_map<std::string, int> words;
        for (const auto &word : positive_feedback) {
            words[word] = 3;
        }
        for (const auto &word : negative_feedback) {
            words[word] = -1;
        }
        vector<int> scores(student_id.size(), 0);
        for (int i = 0; i < report.size(); i++) {
            stringstream ss; //stream根据空格分词
            string w;
            ss << report[i];
            // for(auto & w:split(report[i]," ")){

            while (ss >> w) {
                if (words.count(w)) {
                    scores[i] += words[w];
                }
            }
            // }
        }
        vector<int> idx(student_id.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j)->bool {
            return scores[i] == scores[j] ? scores[i] > scores[j]:student_id[i] < student_id[j];
            });

        vector<int> top_k;
        for (int i = 0; i < k; i++) {
            top_k.push_back(student_id[idx[i]]);
        }
        return top_k;

    }
};
int main() {

    //system("pause");
    return 0;
}
