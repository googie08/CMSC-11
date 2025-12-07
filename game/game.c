/*
 * CMSC 11 Machine Problem
 * Project : ENCANWORDLE (Encantadia Wordle)
 * Creators: Leguarda, Parcero, Sano, Silvio
 * Date    : 2025-12-08
 * Description:
 *   A Wordle-style terminal game using Encantadia-themed words.
 *   Improvements: Better input handling, game stats tracking,
 *   animated title, enhanced user experience.
 */

#include <ctype.h>          // Character handling functions
#include <stdio.h>          // Standard input/output
#include <stdlib.h>         // General utilities
#include <string.h>         // String operations
#include <time.h>           // Time functions
#ifdef _WIN32
#include <windows.h>        // SetConsoleOutputCP and Sleep on Windows
#endif

/* ------------------- CONSTANTS ------------------- */
#define MAX_WORD_LEN 64     // Maximum length for words and hints
#define MAX_TRIES 6         // Maximum attempts per round
#define WORD_COUNT 24       // Number of items inside the entries array

/* ANSI background colors */
const char *BG_GREEN = "\x1b[42m\x1b[30m";
const char *BG_YELLOW = "\x1b[43m\x1b[30m";
const char *BG_GRAY = "\x1b[47m\x1b[30m";
const char *RESET = "\x1b[0m";

/* Defines a custom data type named 'Entry' */
typedef struct {
    const char *word;       // stores the actual word the player must guess
    const char *hint;       // a clue describing the word
} Entry;

/* ------------------- WORD DATABASE ------------------- */
/* Creates an array of Entry structures. Serves as the game's built-in dictionary */
Entry entries[WORD_COUNT] = {
    {"ENCANTADIA", "The magical world where the Mythical beings live."},
    {"AMIHAN", "Sang'gre associated with wind."},
    {"DANAYA", "Sang'gre associated with earth."},
    {"PIRENA", "Eldest Sang'gre; keeper of the fire gem."},
    {"ALENA", "Sang'gre associated with water."},
    {"BRILYANTE", "The powerful elemental gems that hold the balance and magic of Encantadia."},
    {"HATHORIA", "Kingdom known for warriors and fire."},
    {"LIREO", "Kingdom of the Diwatas."},
    {"ADAMYA", "Kingdom of the Adamyans."},
    {"SAPIRO", "Kingdom of the Sapirians."},
    {"CASSIOPEIA", "The oracle of Encantadia known for her visions of the future."},
    {"EMRE", "The highest god worshipped across all Encantadia."},
    {"EVICTUS", "Invisibility skill."},
    {"HARA", "A term for Queen."},
    {"DIWATA", "Mythical beings of Encantadia."},
    {"ETHER", "A Cursed Bathaluman."},
    {"KAWAL", "A soldier or guardian."},
    {"SANGGRE", "A powerful heir of Lireo gifted with magic tied to the Brilyantes."},
    {"MASHNA", "A term for General."},
    {"HATHORIAN", "A Hathor warrior."},
    {"YBARRO", "Prince of Sapiro."},
    {"MITENA", "Twin of Cassiopea; Queen of Mineave."}

};

int used_words[WORD_COUNT] = {0};  // 0 = unused, 1 = used
int words_used_count = 0;

/* ------------------- UTILITY FUNCTIONS ------------------- */
/* Converts strings to uppercase to allow case-insensitive inputs */
void strtoupper(char *s) {
    for (int i = 0; s[i]; i++){
        s[i] = toupper((unsigned char)s[i]);
    }
}

/* Cleans fgets() inputs by removing trailing newline characters*/
void trimnl(char *s) {
    int len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[--len] = '\0';
    }
}

/* Clear leftover characters in the input buffer */
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (c == EOF)
        clearerr(stdin); // Clear error state
}

/* Check if a string contains only letters and has the expected length
   Returns 1 if valid, 0 otherwise. */
int is_alpha_string(const char *s, int expected_len) {
    if ((int)strlen(s) != expected_len) {
        return 0;
    }
    for (int i = 0; i < expected_len; i++) {
        if (!isalpha((unsigned char)s[i]))
            return 0;
    }
    return 1;
}

/* ------------------- GAME LOGIC ------------------- */
/* Wordle-style marking function where:
 *  target: word to guess
 *  guess: player input
 *  marks: output array that stores 'G' (Green), 'Y' (Yellow), or 'X' (Gray)
 */
void mark_guess(const char *target, const char *guess, char *marks) {
    int n = strlen(target);     // Length of the target word
    int freq[26] = {0};         // Letter frequency (A-Z)

    /* Counts how many times each letter appears in the target word */
    for (int i = 0; i < n; i++) {
        char t = toupper((unsigned char)target[i]);
        if (isalpha(t)) {
            freq[t - 'A']++;
        }
    }

    /* Marks exact matches (Green) */
    for (int i = 0; i < n; i++) {
        char g = toupper((unsigned char)guess[i]);
        char t = toupper((unsigned char)target[i]);
        if (g == t) {
            marks[i] = 'G';
            freq[g - 'A']--;
        } else {
            marks[i] = ' ';
        }
    }

    /* Marks letters in wrong position (Yellow) or not in target (Gray) */
    for (int i = 0; i < n; i++) {
        if (marks[i] == 'G')
            continue;

        char g = toupper((unsigned char)guess[i]);

        int idx = g - 'A';
        if (freq[idx] > 0) {
            marks[i] = 'Y';
            freq[idx]--;
        } else {
            marks[i] = 'X';
        }
    }
}

/* ------------------- DISPLAY FUNCTIONS ------------------- */
/* Print letters with colored backgrounds (Wordle-style) */
void print_block(char ch, const char *bg) {
    printf("%s %c %s", bg, ch, RESET);
}

/* Animated title reveal with delay between letters */
void reveal_title(void) {
    const char *title = "ENCANWORDLE";
    printf("\n");
    for (int i = 0; title[i] != '\0'; i++) {
        printf("\033[1;42m  %c  \033[0m", title[i]);  // green box + white text
        fflush(stdout);
#ifdef _WIN32
        Sleep(120);         // 120 milliseconds delay on Windows
#else
        usleep(120000);     // 120000 microseconds delay on Unix/Linux
#endif
    }
    printf("\n\n");
}

/* Prints the game introduction and instructions */
void print_intro(void) {
    printf("\n");
    // ANIMATED GREEN BLOCK TITLE
    reveal_title();

    printf("━━━━━ GUESS THE ENCANTADIA WORD ━━━━━\n\n");

    printf("HOW TO PLAY:\n");
    printf("• Guess the hidden word in %d attempts\n", MAX_TRIES);
    printf("• After each guess, colors show how close you are:\n");
    printf("  ");
    print_block('G', BG_GREEN);
    printf(" Green  = Right letter, right spot\n");
    printf("  ");
    print_block('Y', BG_YELLOW);
    printf(" Yellow = Right letter, wrong spot\n");
    printf("  ");
    print_block('X', BG_GRAY);
    printf(" Gray   = Letter not in word\n\n");

    printf("COMMANDS:\n");
    printf("• Type your guess (letters only, matching word length)\n");
    printf("• Type HINT for a clue (costs 1 attempt, use once per round)\n");
    printf("• Type QUIT to exit during the game\n\n");

    printf("Good luck, Sang'gre! ✨\n");
    printf("\nPress ENTER to start...");
    getchar();  // Waits for user to press Enter
}

/* Prints mini color guide during the game */
void print_color_guide(void) {
    printf("\n");
    print_block('G', BG_GREEN);
    printf(" = Correct  ");
    print_block('Y', BG_YELLOW);
    printf(" = Wrong spot  ");
    print_block('X', BG_GRAY);
    printf(" = Not in word\n");
}

/* Clears the screen */
void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* ------------------- GAME SESSION ------------------- */
/* Plays a single round, returns: 1=win, 0=loss, -1=quit */
int play_round(int *wins) {
    clear_screen();             // Refreshes terminal for new round

    /* Selects random word and corresponding hint from word database */
    int idx = -1;
if (words_used_count >= WORD_COUNT) {
    printf("\nAll words have been used! No more rounds available.\n");
    return -1;  // Ends the game
}

/* Find an unused word */
while (1) {
    int r = rand() % WORD_COUNT;
    if (!used_words[r]) {
        idx = r;
        used_words[r] = 1;    // Mark as used
        words_used_count++;
        break;
    }
}

    const char *targetWord = entries[idx].word;
    const char *targetHint = entries[idx].hint;

    /* Copies the word into a mutable array and convert to uppercase */
    char target[MAX_WORD_LEN];  // Will store the uppercase version of target
    strncpy(target, targetWord, MAX_WORD_LEN - 1);
    target[MAX_WORD_LEN - 1] = '\0';
    strtoupper(target);

    int len = strlen(target);   // Length of target word
    int attempts = MAX_TRIES;   // Remaining attempts
    char input[MAX_WORD_LEN];   // Player input
    int hintUsed = 0;           // Hint flag: 0 = hint available, 1 = hint already used

    /* Print round title and wins so far */
    printf("\n");
    const char *title = "ENCANWORDLE";
    for (int i = 0; title[i]; i++) {
        printf("\033[1;42m  %c  \033[0m", title[i]);
    }
    printf("\n");

    printf("\n🏆 Wins: %d\n", *wins);
    printf("\n🎯 Round Start! The word has %d letters.\n", len);
    print_color_guide();
    printf("\n");

    /* Guessing loop */
    while (attempts > 0) {
        printf("\n[%d/%d] Enter guess: ", MAX_TRIES - attempts + 1, MAX_TRIES);

        /* Reads player input */
        if (!fgets(input, sizeof(input), stdin)) {
            printf("\n");
            return -1;      // If input fails, game quits
        }

        trimnl(input);      // Removes trailing newline

        /* Checks if buffer was filled (input too long) */
        if (strlen(input) >= MAX_WORD_LEN - 1) {
            clear_input_buffer();
            printf("⚠️  Input too long! Please try again.\n");
            continue;
        }

        /* Checks for empty input */
        if (strlen(input) == 0) {
            printf("⚠️  Please enter something!\n");
            continue;
        }

        strtoupper(input);  // Converts input to uppercase

        /* Handles QUIT command */
        if (strcmp(input, "QUIT") == 0) {
            return -1;
        }

        /* Handles HINT command */
        if (strcmp(input, "HINT") == 0) {
            if (hintUsed) {
                printf("Oops, you already used your 1 hint!\n");
                continue;
            }
            hintUsed = 1;
            attempts--;
            printf("\n💡 HINT: %s\n", targetHint);
            continue;
        }

        /* Validates input length and characters */
        if (!is_alpha_string(input, len)) {
            if ((int)strlen(input) != len)
                printf("⚠️  Your guess must be exactly %d letters.\n", len);
            else
                printf("⚠️  Your guess must contain only letters (A-Z).\n");
            continue;
        }

        /* Marks and displays guess */
        char marks[MAX_WORD_LEN] = {0};     // Stores G/Y/X for each letter
        mark_guess(target, input, marks);   // Compare guess with target

        for (int i = 0; i < len; i++) {
            char c = input[i];
            if (marks[i] == 'G') {
                print_block(c, BG_GREEN);   // Correct letter & position
            } else if (marks[i] == 'Y') {
                print_block(c, BG_YELLOW);  // Correct letter, wrong position
            } else {
                print_block(c, BG_GRAY);    // Letter not in word
            }
            printf(" ");
        }
        printf("\n");

        /* Checks winning condition based on presence of non-'G' marks */
        int win = 1;        // Assume win (all green), will be set to 0 if any non-green found
        for (int i = 0; i < len; i++) {
            if (marks[i] != 'G')
                win = 0;
        }

        if (win) {
            int guesses_used = MAX_TRIES - attempts + 1;          // Calculate total guesses used in this round
            printf("\n✨ You guessed the word: %s ✨\n", target);
            printf("Guesses used: %d/%d\n", guesses_used, MAX_TRIES);
            (*wins)++;    // Updates total wins
            return 1;     // Round won
        }

        attempts--;
    }

    /* Out of attempts */
    printf("\n💀 Out of attempts! The word was: %s\n", target);
    return 0;
}

/* ------------------- MAIN GAME LOOP ------------------- */
int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);    // For Windows UTF-8 characters
#endif

    srand((unsigned int)time(NULL)); // Seed the random number generator with the current time
    int wins = 0;           // Tracks total wins in runtime
    clear_screen();         // Clears terminal at start
    print_intro();          // Displays title and instructions
    clear_screen();         // Clears screen again before first round

    int playing = 1;        // Main loop control flag: 0 = exit, 1 = continue

    /* Main game loop */
    while (playing) {
        int result = play_round(&wins);

        /* Player quit or input failed */
        if (result == -1) {
            clear_screen();
            break;              // Exits the loop and end game
        }

        /* Asks to play again */
        char again[MAX_WORD_LEN];   // Player's response to play again
        int valid_response = 0;     // Response flag: 0 = waiting for valid input, 1 = valid input reveived

        /* Validates player response to 'play again' */
        while (!valid_response) {
            printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
            printf("Play again? (Y/N): ");

            if (!fgets(again, sizeof(again), stdin)) {
                playing = 0;    // Exit on input failure
                break;
            }

            trimnl(again);

            /* Clear buffer if input was too long */
            if (strlen(again) == MAX_WORD_LEN - 1 && again[MAX_WORD_LEN - 2] != '\n') {
                clear_input_buffer();
            }

            strtoupper(again);

            /* Check for valid responses */
            if (strcmp(again, "Y") == 0 || strcmp(again, "YES") == 0) {
                valid_response = 1;
            } else if (strcmp(again, "N") == 0 || strcmp(again, "NO") == 0) {
                valid_response = 1;
                playing = 0;            // Signal to exit main loop
            } else {
                printf("⚠️  Invalid input! Please enter Y for YES or N for NO.\n");
            }
        }
    }

    /* Game ending */
    printf("\n🏆 Final Wins: %d\n", wins);
    printf("\nThank you for playing, Sang'gre! 🌟\n");
    return 0;
}
