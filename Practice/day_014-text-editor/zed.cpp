/**
 * @file zed.cpp
 * @brief Provides Terminal class and main function.
 */

#include <unistd.h>
#include <iostream>
#include <termios.h>

/**
 * @class Terminal
 * @brief Manage terminal settings.
 */
class Terminal {
public:
    /**
     * @brief Enables raw mode in the terminal.
     *
     * In raw mode, input characters are sent directly to the application without processing.
     */
    void enableRawMode() {
        termios raw;

        // get current terminal attributes
        tcgetattr(STDIN_FILENO, &raw);

        // disable ECHO flag
        raw.c_lflag &= ~(ECHO);

        // set new terminal attributes
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    }
};

/**
 * @brief Main function.
 *
 * Creates a Terminal object, enables raw mode, and reads characters until 'q' is entered.
 */
int main() {
    char c;

    Terminal terminal;
    terminal.enableRawMode();
    while (std::cin.get(c) && c != 'q');

    return 0;
}