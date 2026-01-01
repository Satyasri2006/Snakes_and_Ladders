#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

class Dice {
	public:
	    int roll() {
	        return rand() % 6 + 1;
	    }
};

class Player {
	private:
	    int position;
	public:
	    Player() : position(0) {}
	    int getPosition() const {
	        return position;
	    }
	    void setPosition(int pos) {
	        position = pos;
	    }
	    void reset() {
	        position = 0;
	    }
};

class Board {
	private:
	    unordered_map<int, int> snakes;
	    unordered_map<int, int> ladders;
	public:
	    Board() {
	        // Ladders
	        ladders[4]  = 14;
	        ladders[9]  = 31;
	        ladders[20] = 38;
	        ladders[28] = 84;
	        // Snakes
	        snakes[17] = 7;
	        snakes[54] = 34;
	        snakes[62] = 19;
	        snakes[87] = 36;
	        snakes[99] = 78;
	    }
	    int applySnakeOrLadder(int pos) {
	        if (ladders.count(pos)) {
	            cout << "Ladder! Climb to " << ladders[pos] << endl;
	            return ladders[pos];
	        }
	        if (snakes.count(pos)) {
	            cout << "Snake! Slide to " << snakes[pos] << endl;
	            return snakes[pos];
	        }
	        return pos;
	    }
};

class Game {
	private:
	    Player player1;
	    Player player2;
	    Dice dice;
	    Board board;
	    bool isPlayer1Turn;
	public:
		static const int MAX_TURNS = 500;
	    Game() : isPlayer1Turn(true) {}
	    void resetGame() {
	        player1.reset();
	        player2.reset();
	        isPlayer1Turn = true;
	    }
	    void showPositions() {
	        cout << "\nCurrent Positions:\n";
	        cout << "Player 1: " << player1.getPosition() << endl;
	        cout << "Player 2: " << player2.getPosition() << endl;
	    }
	    void play() {
	    	int turn_count=0, flag=0;
	        while (turn_count<MAX_TURNS) {
	        	turn_count++;
	            Player& currentPlayer = isPlayer1Turn ? player1 : player2;
	            int playerNumber = isPlayer1Turn ? 1 : 2;
	            cout << "\n--------------------------\n";
	            cout << "Player " << playerNumber << "'s turn\n";
	            cout << "Press ENTER to roll dice...";
	            cin.ignore();
	            cin.get();
		        int rollValue = dice.roll();
    	        cout << "Rolled: " << rollValue << endl;
	            int newPos = currentPlayer.getPosition() + rollValue;
	            if (newPos <= 100) {
	                currentPlayer.setPosition(newPos);
	                cout << "Moved to " << newPos << endl;
	                newPos = board.applySnakeOrLadder(newPos);
	                currentPlayer.setPosition(newPos);
	            }
				else {
	                cout << "Roll exceeds 100. Stay at same position.\n";
	            }
	            showPositions();
	            if (currentPlayer.getPosition() == 100) {
	                cout << "\nPlayer " << playerNumber << " WINS!\n";
	                flag=1;
	                break;
	            }
	            // switch turn
	            isPlayer1Turn = !isPlayer1Turn;
	        }
	        if(flag==1){
		        cout << "\n? Game ended due to too many turns.\n";
				cout << "It's a DRAW!\n";
			}
    	}
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    char playAgain;
    do {
        cout << "\nSNAKE AND LADDER (2 PLAYERS)\n";

        Game game;
        game.play();

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;

        cin.ignore(); // clear buffer
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing!\n";
    return 0;
}

