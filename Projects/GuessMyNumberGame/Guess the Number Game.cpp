#include <iostream>
#include <iomanip>
#include <vector>
#include <random> 
#include <string>
using namespace std;
// Functions
int RandomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(min, max);
    int random_number = distribution(gen);
    return random_number;
}

ostream& operator<<(ostream& COUT, Player& player) {
    COUT << setw(32) << player.name << setw(10) << player.score << endl;
    return COUT;
}

// Player Structure
struct Player {
private:
    int jackPot = RandomNumber(1, 100);
public:
    string name;
    int score = 0; 
    int attempts = 0;


    Player() {};
    Player(const string& name, int score) : name(name), score(score) {} // Use const reference

    void play() {
        int guess = 0;
        string name;

      
        while (attempts < 10 && guess != jackPot) {
            if (attempts == 0) {
                cout << "Enter player " << name << "'s Guess:";
                cin >> guess;
            }

            if (guess == jackPot) {
                cout << "Correct" << endl;
                break;
            }
            else if (guess < jackPot) {
                cout << "TOO LOW!" << endl;
                this->jackPot = RandomNumber(guess, 100);
                attempts++;
            }
            else if (guess > jackPot) {
                cout << "TOO HIGH!" << endl;
                this->jackPot = RandomNumber(1, guess);
                attempts++;
            }
        }
        if (attempts >= 10) {
            cout << "You Failed to guess the Number!!!" << endl;
        }
        if (attempts < 10) {
            cout << "You Guessed the Number in " << attempts << " Attempts!!!" << endl;
        }
    }
};


// Game structure
struct Game {
    vector<string> players_name;
    vector<Player> player;

  

    Game() {};
    Game(vector<string>& player_name) : players_name(player_name) {
        for (const string& player_name : players_name) 
            this->player.push_back(Player(player_name, 0)); 
    }
};


int main() {

    // Determines Number of Players
    int numPlayers = 0;
    cout << "Please enter number of players: " << endl;
    cin >> numPlayers;

    
    // Input player names 
    vector<string> PlayerNames(numPlayers);
    for (int i = 0; i < numPlayers; i++) {
        string name;
        cout << "Enter Player " << i + 1 << ": " << endl;
        cin >> PlayerNames[i];
    }


    Game game{PlayerNames};


    // runs the game for all players
    for (int i = 0; i < numPlayers; i++) {
        cout << "Player " << i + 1 << "'s Turn!" << endl;
        game.player[i].play();
    }

    

    return 0;
}