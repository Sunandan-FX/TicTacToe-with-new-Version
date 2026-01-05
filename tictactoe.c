#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char PLAYER1 = '+';
const char PLAYER2 = '#';
const char COMPUTER = '#';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMoveOne();
void playerMoveTwo();
void computerMove();
char checkWinner();
void printwinner(char winner);

int main()
{
    char winner = ' ';
    char response;
    int mode;

    srand(time(0));

    do
    {
        winner = ' ';
        response = ' ';
        
        printf("\nWelcome to TicTacToe game with new symbols");
        printf("\nChoose game mode:\n");
        printf("1. Play with Friend\n");
        printf("2. Play with Computer\n");
        printf("Enter choice (1 or 2): ");
        scanf("%d", &mode);

        resetBoard();

        while(winner == ' ' && checkFreeSpaces() != 0)
        {
            printBoard();

            playerMoveOne();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            if(mode == 1)
            {
                playerMoveTwo();
            }
            else if(mode == 2)
            {
                computerMove();
            }

            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        }

        printBoard();
        printwinner(winner);

        printf("\nWould you like to play again? (Y/N): ");
        scanf("%c");
        scanf("%c",&response);
        response = toupper(response);

    } while (response == 'Y');

    printf("Thanks for playing!");
    return 0;
}

void resetBoard()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces = 9;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMoveOne()
{
    int x, y;

    do
    {
        printf("PLAYER1 = +\n");
        printf("Enter row #(1-3): ");
        scanf("%d",&x);
        x--;
        printf("Enter column #(1-3): ");
        scanf("%d",&y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("invalid move\n");
        }
        else
        {
            board[x][y] = PLAYER1;
            break;
        }
    } while (board[x][y] != ' ');
}

void playerMoveTwo()
{
    int x, y;

    do
    {
        printf("PLAYER2 = #\n");
        printf("Enter row #(1-3): ");
        scanf("%d",&x);
        x--;
        printf("Enter column #(1-3): ");
        scanf("%d",&y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("invalid move\n");
        }
        else
        {
            board[x][y] = PLAYER2;
            break;
        }
    } while (board[x][y] != ' ');
}

void computerMove()
{
    int x, y;

    if(checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
}

char checkWinner()
{
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }

    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}

void printwinner(char winner)
{
    if(winner == PLAYER1)
    {
        printf("PLAYER1 WIN!");
    }
    else if(winner == PLAYER2)
    {
        printf("PLAYER2 WIN!");
    }
    else
    {
        printf("DRAW");
    }
}
