#include "my_2048.h"

using namespace std;

int board[4][4], judge;

int main()
{
    srand((unsigned)time(nullptr));

    add_random(board, 1);

    while (check_2048(board) == 0 && game_close(board) == 0)
    {
        system("cls");
        show_board(board);
        dir_o_move(board);
        add_random(board, 0);
    }

    end_judge(judge);
    system("pause");
    return 0;
}
