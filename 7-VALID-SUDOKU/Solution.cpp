// 1- SOLUTION EXPLANATION
// Use three SET collections to track used DIGITS in each ROW, COLUMN, and 3x3 BOX.
// If the current DIGIT already exists in any corresponding SET, the SUDOKU is INVALID.

// 2- NEW CONCEPTS LEARNED
// UNORDERED_SET: stores UNIQUE VALUES and provides fast INSERT and FIND operations.
// BOX INDEX: (ROW / 3) * 3 + (COLUMN / 3) maps each CELL to one of the 9 BOXES.

// 3- CODE
class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        std::vector<std::unordered_set<char> > Csets(9);
        std::vector<std::unordered_set<char> > Lsets(9);
        std::vector<std::unordered_set<char> > Bsets(9);

        int size = board.size();
        char currElement;
        int Bindex;

        for (int y = 0; y < size; y++)
        {
            int s = board[y].size();

            for (int x = 0; x < s; x++)
            {
                if (board[y][x] == '.')
                    continue;

                currElement = board[y][x];
                Bindex = (y / 3) * 3 + (x / 3);

                if (Lsets[y].find(currElement) != Lsets[y].end()
                    || Csets[x].find(currElement) != Csets[x].end()
                    || Bsets[Bindex].find(currElement) != Bsets[Bindex].end())
                {
                    return false;
                }

                Lsets[y].insert(currElement);
                Csets[x].insert(currElement);
                Bsets[Bindex].insert(currElement);
            }
        }

        return true;
    }
};