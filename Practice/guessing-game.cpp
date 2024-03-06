#include <iostream>
#include <cstdlib>
#include <random>

using std::cout, std::cin, std::endl;

void begin() {
    cout << "\n* Guessing Game *"
            "\nTry to guess the secret number\n" << endl;
}

void play() {
    int level;
    int chances;
    int rounds;
    int score = 1000;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    int secret = dis(gen);

    begin();

    cout << "Game Levels\n"
            "(1) - Level 1 w/ 20 chances\n"
            "(2) - Level 2 w/ 10 chances\n"
            "(3) - Level 3 w/ 5 chances\n"
            "Pick a level: ";
    cin >> level;

    switch (level) {
        case 1:
            chances = 20;
            break;
        case 2:
            chances = 10;
            break;
        case 3:
            chances = 5;
            break;
        default:
            cout << "Level not found, please pick an existing level\n" << endl;
            play();
            return;
    }

    for (rounds = 1; rounds <= chances; ++rounds) {
        int answer;

        cout << "\nRound " << rounds << " / " << chances << endl;
        cout << "Number: ";
        cin >> answer;

        bool correct = answer == secret;
        bool higher = answer > secret;
        bool less = answer < secret;

        if (correct) {
            cout << "\nCongratulations! You guessed the secret number"
                    "\nYou win " << score << " points" << endl;
            break;
        } else if (higher) {
            cout << "Your guess was higher than the secret number" << endl;
        } else if (less) {
            cout << "Your guess was less than the secret number" << endl;
        }

        int lose_score = abs(answer - secret);
        score -= lose_score;
    }

    cout << "\nEnd Game!";
}

int main() {
    play();
    return 0;
}
