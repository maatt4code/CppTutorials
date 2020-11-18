#include <string>
#include <vector>

/*
 * I find myself searching for this way too frequently
 * and frankly, i am surprised STL does not have this ready made
 */
vector<string> split(const string& str, const string& delims) {
    vector<string> ret;
    size_t prev = 0;
    size_t pos = str.find_first_of(delims, prev);
    // loop we go
    while(pos != string::npos) {
        const auto& tmp = str.substr(prev, pos - prev);
        if(!tmp.empty())
            ret.push_back(tmp);
        prev = pos + 1;
        pos = str.find_first_of(delims, prev);
    }
    // don't forget the last one
    ret.push_back(str.substr(prev));
    return ret;
}
