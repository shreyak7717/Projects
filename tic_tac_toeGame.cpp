#include <iostream>
using namespace std;

int grid[3][3] = {
    {11, 12, 13},
    {21, 22, 23},
    {31, 32, 33}
};

bool win(){
    if ((grid[0][0] == grid[0][1] && grid[0][0] == grid[0][2]) || 
    (grid[0][0] == grid[1][0] && grid[0][0] == grid[2][0]) ||
    (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2])
    ){   
        cout << "\nPlayer " << grid[0][0] << " won\n";
        return false;
    }
    else if ((grid[0][1] == grid[1][1] && grid[0][1] == grid[2][1]))
    {
        cout << "\nPlayer " << grid[0][1] << " won\n";
        return false;
    }
    else if ((grid[0][2] == grid[1][2] && grid[0][2] == grid[2][2]))
    {
        cout << "\nPlayer " << grid[0][2] << " won\n";
        return false;
    }
    else if ((grid[1][0] == grid[1][2] && grid[1][2] == grid[1][1]))
    {
        cout << "\nPlayer " << grid[1][2] << " won\n";
        return false;
    }
    else if ((grid[2][0] == grid[2][2] && grid[2][2] == grid[2][1]))
    {
        cout << "\nPlayer " << grid[2][2] << " won\n";
        return false;
    }
    else if ((grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]))
    {
        cout << "\nPlayer " << grid[0][2] << " won\n";
        return false;
    }
    else
    {
        return true;
    }   
}

int main(){

    int ru1, cu1, ru2, cu2, turns = 0;
    bool play = true;

    while (play && turns < 9)
    {
        cout << "\nPlayer 1, please enter row and column, respectively of your choice:\t";
        cin >> ru1 >> cu1;
        while ((grid[ru1 - 1][cu1 - 1] == 1) || (grid[ru1 - 1][cu1 - 1] == 2))
        {
            cout << "\nThe grid coordinates entered have already been used by a player. Please enter other coordinates:\t";
            cin >> ru1 >> cu1;
        }
        grid[ru1 - 1][cu1 - 1] = 1;
        turns++;
        play = win();
        cout << "\n";
        for (int i = 0; i < 3; i++)
        {
            cout << grid[i][0] << "\t";
            cout << grid[i][1] << "\t";
            cout << grid[i][2] << "\n";
        }
        
        if ((play == false) ||(turns == 9)){break;}

        cout << "\nPlayer 2, please enter row and column, respectively of your choice:\t";
        cin >> ru2 >> cu2;
        while ((grid[ru2 - 1][cu2 - 1] == 1) || (grid[ru2 - 1][cu2 - 1] == 2))
        {
            cout << "\nThe grid coordinates entered have already been used by a player. Please enter other coordinates:\t";
            cin >> ru2 >> cu2;
        }
        grid[ru2 - 1][cu2 - 1] = 2;
        turns++;
        play = win();
        cout << "\n";
        for (int i = 0; i < 3; i++)
        {
            cout << grid[i][0] << "\t";
            cout << grid[i][1] << "\t";
            cout << grid[i][2] << "\n";
        }
    }
}