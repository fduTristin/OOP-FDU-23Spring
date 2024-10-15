#include<fstream>
#include<cstring>
#include"board.h"
#include"game.h"

/*

board.h:

Class Board:
    Structure Net:
        String row
        Integer number[4][4]
    
    Long score
    
    Constructor Board():
        Initialize score to 0
        For i from 0 to 3:
            For j from 0 to 3:
                Set net.number[i][j] to 0
        Call put_number_()
    
    Static function size(n: Integer):
        Define string size type sz as 0
        Loop while n is not equal to 0:
            Increment sz by 1
            Divide n by 10
        Return sz
    
    Function print():
        For i from 0 to 3:
            Output net.row
            Output newline
            For j from 0 to 3:
                If net.number[i][j] is not 0, then output "|" followed by spaces and net.number[i][j] (center-aligned)
                Otherwise, output "|     "
            Output '|'
            Output newline
        Output net.row
        Output "Your score: " and get_score()
        Output newline
        Output "(↑:u) (↓:d) (←:l) (→:r) (quit:q): "
    
    Function put_number_():
        If the board is not full:
            Loop until a number is inserted:
                Generate a random number a between 0 and 3
                Generate a random number b between 0 and 3
                If net.number[a][b] is 0, then set it to 2 and exit the loop
        Loop until a number is inserted:
            Generate a random number a between 0 and 3
            Generate a random number b between 0 and 3
            If net.number[a][b] is 0, then set it to 2 and exit the loop
    
    Function put_number():
        If the board is not full:
            Loop until a number is inserted:
                Generate a random number a between 0 and 3
                Generate a random number b between 0 and 3
                Generate a random number n. If n is 0, set it to 4; otherwise, set it to 2
                If net.number[a][b] is 0, then set it to n and exit the loop
    
    Function move():
        For i from 0 to 3:
            For n from 0 to 2:
                For j from 0 to 2:
                    If net.number[i][j] is 0, then set net.number[i][k] equal to net.number[i][k + 1] (where k goes from j to 2)
                    Set net.number[i][3] to 0
    
    Function move(c: Character):
        If c is 'l', call move()
        If c is 'r', call right_turn() and then call move()
        If c is 'u', call up_turn() and then call move()
        If c is 'd', call down_turn() and then call move()
    
    Function move_back(c: Character):
        If c is 'l', call move()
        If c is 'r', call move() and then call right_turn()
        If c is 'u', call move() and then call up_turn()
        If c is 'd', call move(), then call right_turn(), and then call up_turn()
    
    Function combine(c: Character):
        Call move(c)
        For i from 0 to 3:
            For j from 0 to 2:
                If net.number[i][j] is equal to net.number[i][j + 1] and net.number[i][j] is not 0:
                    Multiply net.number[i][j] by 2
                    Add net.number[i][j] to score
                    Set net.number[i][j + 1] to 0
        Call move_back(c)
    
    Function isFull() -> Boolean:
        Set flg to true
        For i from 0 to 3:
            For j from 0 to 3:
                If net.number[i][j] is 0, set flg to false
        Return flg
    
    Function isOver() -> Boolean:
        If the board is not full, return false
        Set flg to true
        For i from 0 to 3:
            For j from 0 to 2:
                If net.number[i][j] is equal to net.number[i][j + 1] or net.number[j][i] is equal to net.number[j + 1][i]:
                    Set flg to false
        Return flg
    
    Function right_turn():
        For i from 0 to 3:
            Set temp to net.number[i][0]
            Set net.number[i][0] to net.number[i][3]
            Set net.number[i][3] to temp
            Set temp to net.number[i][1]
            Set net.number[i][1] to net.number[i][2]
            Set net.number[i][2] to temp
    
    Function up_turn():
        For i from 1 to 5:
            For j from 0 to i:
                If j is between 0 and 3 and (i - j) is between 0 and 3 and j is less than (i - j):
                    Set temp to net.number[j][i - j]
                    Set net.number[j][i - j] to net.number[i - j][j]
                    Set net.number[i - j][j] to temp
    
    Function down_turn():
        Call up_turn()
        Call right_turn()


game.h:

Structure Game2048:
    Board* board
    
    Constructor Game2048():
        Create a new instance of Board and assign it to board
        Output "Welcome to the game of 2048!"
        Call print()
    
    Destructor ~Game2048():
        Delete the board
    
    Function ask_direction() -> Character:
        Declare a character variable c
        Read a character from input and assign it to c
        Return c
    
    Function get_score() -> Long:
        Return the score obtained from the board
    
    Function print():
        Call the print() function of the board
    
    Function put_number():
        Call the put_number() function of the board
    
    Function combine(c: Character):
        Call the combine(c) function of the board
    
    Function isFull() -> Boolean:
        Return the result of the isFull() function of the board
    
    Function isOver() -> Boolean:
        Return the result of the isOver() function of the board

main:

Function main():
    Declare a variable start_time of type time_t
    Call time() and assign the current time to start_time
    Call srand() with the result of time(NULL) as the seed
    
    Create an instance of Game2048 and assign it to the variable game
    
    Create an instance of ofstream named outfile with "game2048.csv" as the filename and std::ofstream::app as the open mode
    
    Loop while the game is not over:
        Call game.ask_direction() and assign the result to a variable temp
        If temp is 'q', break the loop
        Else:
            Call game.combine(temp)
            Call game.put_number()
            Call game.print()
    
    Output "Game Over"
    
    Declare a variable end_time of type time_t
    Call time() and assign the current time to end_time
    
    Declare a character array start_time_str with a size of 26
    Call ctime(&start_time) and assign the result to start_time_str
    Replace the newline character '\n' in start_time_str with a null character '\0'
    
    Output start_time_str, game.get_score(), and the difference in seconds between end_time and start_time
    
    Write start_time_str, game.get_score(), and the difference in seconds between end_time and start_time to outfile
    
    Close outfile

*/

int main() {
    time_t start_time;
    time(&start_time);
    srand((unsigned)time(NULL));
    Game2048 game;
    std::ofstream outfile("game2048.csv",std::ofstream::app);
    while(!game.isOver())
    {
        char temp = game.ask_direction();
        if(temp == 'q') break;
        else {
            game.combine(temp);
            game.put_number();
            game.print();
        }  
    }
    cout<<"Game Over"<<endl;
    time_t end_time;
    time(&end_time);

    char* start_time_str = ctime(&start_time);
    start_time_str[std::strcspn(start_time_str, "\n")] = '\0';

    
    outfile<<start_time_str<<','<<game.get_score()<<','<<difftime(end_time,start_time)<<endl;
    
}
