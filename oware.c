/*





                            OWARE CONSOLE GAME


                            © 2015 - 2016



                            ANYANWU MIRACLE


                                                              */


#include <stdio.h> //STANDARD INPUT AND OUTPUT
#include <stdlib.h> // STANDARD LIBRARY HEADER FILES

void welcomeMessage(void); // Welcome message declaration prototype
int move(int pos,char player); // MOVE PROTOTYPE
int board_a[12];    // ARRAY BOARD POTS

const int board_size = 12;  // FIXED BOARD SIZE IE ITS VALUE DOES NOT CHANGE
void printBoard(int,int); // PRINT BOARD FUNCTION PROTOTYPE
int score_player_one = 0; // PLAYER 1 SCORE VARIABLE DECLARATION
int score_player_two = 0; // PLAYER 2 SCORE VARIABLE DECLARATION

// MAIN FUNCTION
int main(){

    int position; // POSITION DECLARATION


    //BOARD FOR PLAYER B WITH FIXED STARTING SCORE
    board_a [0] = 4;
    board_a [1] = 4;
    board_a [2] = 4;
    board_a [3] = 4;
    board_a [4] = 4;
    board_a [5] = 4;

    // BOARD FOR PLAYER A WITH FIXED STARTING SCORE
    board_a [6] = 4;
    board_a [7] = 4;
    board_a [8] = 4;
    board_a [9] = 4;
    board_a [10] = 4;
    board_a [11] = 4;

    welcomeMessage(); // calling the welcome message function

            // BOARD DESIGN PREVIEW.. THIS DOES NOT AFFECT THE MAIN CODE OF THE GAME

//    printf("            ==================================================================\n"
//           "Player A    |        |  1    |   2   |   3   |  4    |   5   |   6    |      |\n"
//                       "\t    ===================================================================|\n"
//                       "\t    |        |        |       |       |       |       |        |       |\n"
//                       "\t    |        |   4    |   4   |   4   |   4   |   4   |   4    |       |\n"
//                       "\t    |        |        |       |       |       |       |        |       |\n"
//                       "\t    |   0    |========|=======|=======|=======|=======|========|  0    |\n"
//                       "\t    |        |        |       |       |       |       |        |       |\n"
//                       "\t    |        |   4    |   4   |   4   |   4   |   4   |   4    |       |\n"
//                       "\t    |        |        |       |       |       |       |        |       |\n"
//                       "\t    ===================================================================|\n"
//          "Player B    |        |   7    |   8  |   9  |   10  |   11    |   12    |     |\n"
//                       "\t    ===================================================================|\n");
//

        int val; // well number being picked
        char player='A'; // first player

                //GAME LAUNCH DISPLAY SCREEN
        do{

                if(player == 'A'){
/*
                                            Different while for each player
              while evaluates if position picked by user is invalid and prompts user to resubmit position conforming to restrictions
                                                                                                                                        */
                    do{

                        printBoard(score_player_one,score_player_two);

                        printf("Player %c\nEnter positions from 7 to 12:\n",player);
                        scanf("%d",&val);

                      }while(!(val >= 7 && val <= 12)); // VALIDATE POSITIONS
                }

                    else if(player == 'B')
                {
                        do{

                            printBoard(score_player_one,score_player_two);

                            printf("Player %c\nEnter positions from 1 to 6:\n",player);
                            scanf("%d",&val);

                        }while(!(val >= 1 && val <= 6)); // VALIDATE POSITIONS
                }

                // PLAYER TO MOVE
				switch(player){
                    case 'A':
                        score_player_one += move(val,player); // handles score to add to existing score for player A
                     break;

                    case 'B':
                        score_player_two += move(val,player);  // handles score to add to existing score for player A
                        break;
                }

               printBoard(score_player_one,score_player_two); // Print the current score after the testing of the conditions

                // it controls who plays next
			   switch(player){
                    case 'A':
                        player = 'B';
                        break;

                    case 'B':
                        player = 'A';
                    break;
               }

        }

        while(1); // code to repeat players indefinitely


    return 0;
}


// MOVE FUNCTION
int move(int pos,char player){
    if(pos < 1 || pos > 12){

       printf("ERROR...Position does not exist!"); //display error message for move outside board size
    }

    else {

        int stones = board_a[pos-1]; // stones = ar[pos - 1] ie the board position

        if (stones == 0){
            return 0;
        }

        int slot = (pos-1) % board_size; // Transform a number to comply with the range to the board
        board_a[slot] -= stones; // remove stones from the well you just picked from

        int nextPosition = ((slot + stones)% board_size)+1; // show where the next stone will stop

        int balls = stones; // to print the stones on the screen

        int moves = 0; // move declaration

        while( stones >= 1){
                stones--; //SUBTRACT STONES by 1
                moves++;	// INCREASE MOVES by one
                board_a[(slot + moves) % board_size]++; //CHECK WHEN THE BOARD SIZE IS FINISHED
                printBoard(score_player_one,score_player_two);
                printf("Current Player: %c\n", player);
                printf("startPosition: %i value: %i nextPosition: %i \nCurrent position: %i value: %i Remainder: %i\n",
				pos, balls, nextPosition, ((slot+moves) % 12) + 1, board_a[(slot + moves) % board_size], stones);
                int microseconds = 999900; // time to wait before you resume
				usleep(microseconds); //
        }



        switch(board_a[(slot + moves) % board_size]){
        	case 4:    // IF YOU END IN A STONE TO MAKE IT FOUR
        	    {

					board_a[(slot + moves) % board_size]=0;//
					return 4 ; // return 4 as the winner score
					break;
				}

        	case 1:

        	    return 0 ; // else continue to another
                break;

        	default: // unless continue to pick and distribute
            {

        		int nextPos = (slot+moves) % board_size;
        		system("pause");
        		return move(nextPos+1,player);
        		break;
        	}
        }

    }

}

// PRINT BOARD FUNCTION
void printBoard(int x,int y){
	 system("cls");
    printf("            ==================================================================\n"
           "Player A    |        |  12   |  11   |  10   |  9    |   8   |   7    |      |\n"
                       "\t    ===================================================================|\n"
                       "\t    |        |        |       |       |       |       |        |       |\n"
                       "\t    |        |  %-3d   |  %-3d  |  %-3d  |  %-3d  |  %-3d  |  %-3d   |       |\n"
                       "\t    |        |        |       |       |       |       |        |       |\n"
                       "\t    |  %-3d   |========|=======|=======|=======|=======|========| %-3d  |\n"
                       "\t    |        |        |       |       |       |       |        |       |\n"
                       "\t    |        |  %-3d   |  %-3d  |  %-3d  |  %-3d  |  %-3d  |  %-3d   |       |\n"
                       "\t    |        |        |       |       |       |       |        |       |\n"
                       "\t    ===================================================================|\n"
          "Player B    |        |   1    |   2  |   3  |   4   |   5     |   6     |     |\n"
                       "\t    ===================================================================|\n",

                       board_a[11],board_a[10],board_a[9],board_a[8],board_a[7],board_a[6],
                       x,y,board_a[0],board_a[1],board_a[2],board_a[3],board_a[4],board_a[5]); // each array board here controls a particular position

}

// welcome message function
void welcomeMessage(void){

    // THE GAME INSTRUCTIONS TO DISPLAY TO THE USER
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWelcome TO MY OWARE GAME...\n\n\n\n\t\t\t\t\t\t\tGAME INSTRUCTIONS\n\n(1) Equipment and Initial Setup"

"To play OWARE you will need a game board and forty-eight game pieces, which are so-called seeds. Usually the board consists of two rows of six holes" "located at opposite sides. Two larger holes on the sides of the board are used to store the seeds players capture during the match. The upper row" "belongs to the player""who moves first, named Player A, and the lower row belong to the second called Player B.\n\n(2) Goal 0f the game- The goal of the game is to acquire more seeds" "than your opponents.\n\n(3)Playing the Game"

"Each move of the game is done in three phases: collecting, sowing and capturing. During the sowing a player distributes the collected seeds along the board, and"" during the capture phase the player takes, if possible, the seeds found in the pits of the opponent.\n\n\n\n"
"Collecting Seeds- "

"In the first phase of a movement, the player who is to move chooses one of the holes on his own side of the board and collects all the seeds on it, leaving the hole empty. Subsequently, these seeds will be distributed on the board during the sowing phase.\n"

"A player may collect the seeds from any of the holes that belong to him if it contains one or more seeds, only with the exception that after making the move his" "opponent must be able to play." "Therefore, a move that would leave all the holes empty on the opponent's side is not legal."
"Sowing Seeds-\n\n"

"During sowing, the player distributes the seeds collected in the first phase along the board in a counter clockwise direction; dropping one seed in each of the" "playing holes until all the seeds are distributed. A player will never sow on the holes used for storage.After sowing the seeds, the hole from which the player" "has collected seeds will be empty. It may well be the case that the player sows twelve or more seeds, in which case the player will sow them going round around" "the board, dropping one seed in each hole in every round, but never dropping a seed in the hole from which the seeds were collected.\n\n\n"
"Capturing Seeds-\n\n"

"When the last sown seed is dropped in one of the holes belonging to the opponent, and after dropping the seed the hole contains exactly two or three seeds, the" "player will capture them. Taking all the seeds from the hole and saving them in his own store.\n"

"When the hole immediately to the right of the last pit from which seeds were captured contains also two or three seeds, the player will capture them too. And" "so"" on until the player cannot capture more seeds, always taking into account that players can only capture seeds from their opponents holes and never from" "their own holes.""\n\n""(4)End of the game- The game is ended when a player has more seeds than his opponent and there are no seeds left to distribute or" "sow""\n\n\n\n\n\n\n\n\n\n\n\t\tTO PROCEED TO GAME PLAY PRESS THE ENTER KEY..\n""\n\n\n");

    getchar(); // respond to the enter key the user will press
    system("cls"); // clear this current screen



}


/*

                                                WRITTEN BY MIRACLE ANYANWU


                                                                                    */
