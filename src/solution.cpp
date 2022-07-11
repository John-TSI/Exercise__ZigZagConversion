#include<vector>
#include<algorithm>
#include"../inc/solution.hpp"


std::string Solution::convert(const std::string& s, int numRows)
{
    //int numCols = s.length()/numRows + s.length()%numRows; // INCORRECT

    int numCols{0}, charCount = s.length();
    while(charCount)
    {
        if(charCount >= numRows){ charCount -= numRows; ++numCols; }
        if(charCount >= numRows-2)
        {
            for(int i{0}; i<numRows-2; ++i)
            {
                --charCount; ++numCols;
            }  
        }
        if(charCount <= numRows){ charCount = 0; ++numCols; }
    }

    std::vector<std::vector<char>> vec(numCols);

    bool insertDiagonally{false};
    for(int col{0}; col<numCols; ++col)
    {
        for(int row{0}; row<numRows; ++row)
        {
            // when row == numRows-1 : set a bool so that ' ' is inserted into vec at next position (start of next col)
            // print a single char in the current col once row != numRows-1 && vec[row+1][col-1] != ' '
            // flip the bool (print chars normally for the current col) once row == 0 && vec[row+1][col-1] != ' ' 

            if(insertDiagonally)
            {
                vec[row][col] = (row != numRows-1 && vec[row+1][col-1] != ' ')
                    ?  s[col*row + row]
                    : ' ';
                if(row == 0 && vec[row+1][col-1] != ' '){ insertDiagonally = false; }
            }
            else
            {
                if(row == numRows-1){ insertDiagonally = true; }
                vec[row][col] = s[col*row + row];
            }
        }
    }

    // generate the converted string
    std::string converted(numRows*numCols, ' ');
    for(int row{0}; row<numRows; ++row)
    {
        for(int col{0}; col<numCols; ++col)
        {
            converted[row*col + col] = vec[row][col];
        }
    } 
    converted.erase(remove_if(converted.begin(), converted.end(), isspace), converted.end());
    return converted;
}