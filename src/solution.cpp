#include<vector>
#include<algorithm>
#include"../inc/solution.hpp"


std::string Solution::convert(const std::string& s, int numRows)
{
    int numCols{0}, charCount = s.length(), spaceCount{0};
    // count the number of columns required
    while(charCount)
    {
        if(charCount >= numRows){ charCount -= numRows; ++numCols; }
        for(int i{0}; i<numRows-2; ++i)
        {
            if(charCount){ --charCount; ++numCols; }
        }  
        if(0 < charCount && charCount <= numRows){ charCount = 0; ++numCols; }
    }
    std::vector<std::vector<char>> vec(numRows, std::vector<char>(numCols));

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
                if(row == 0 && vec[row][col-1] == ' ' && vec[row+1][col-1] != ' ')
                { 
                    vec[row][col] = s[col*row + row - spaceCount]; // ?
                    insertDiagonally = false; 
                }
                else if(row != 0 && row != numRows-1 && vec[row+1][col-1] != ' ')
                {
                    vec[row][col] = s[col*row + row - spaceCount];
                }
                else
                {
                    vec[row][col] = ' '; ++spaceCount;
                }
/*                 if(row == 0 && vec[row][col-1] == ' ' && vec[row+1][col-1] != ' ')
                { 
                    vec[row][col] = s[col*row + row - spaceCount]; // ?
                    insertDiagonally = false; 
                } */
            }
            else
            {
                if(row == numRows-1){ insertDiagonally = true; }
                vec[row][col] = s[col*row + row - spaceCount];
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