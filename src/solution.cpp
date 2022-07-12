#include<vector>
#include<string>
#include<numeric>
#include"../inc/solution.hpp"


std::string Solution::convert(const std::string& s, int numRows)
{
    std::vector<std::string> strings(numRows, "");
    int strIndex{0}, strLen = s.length();

    while(strIndex < strLen)
    {
        for(int row{0}; (row < numRows && strIndex < strLen); ++row, ++strIndex){ strings[row] += s[strIndex]; }
        for(int row{numRows-2}; (row>0 && strIndex < strLen); --row, ++strIndex){ strings[row] += s[strIndex]; }
    }

    std::string converted{};
    return std::accumulate(strings.begin(), strings.end(), converted);
}