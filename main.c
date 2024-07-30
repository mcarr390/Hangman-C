#include <stdio.h>

void initializeGuessedWord(char *guessedWord, int len);

short getStringLength(const char *finalWord);

bool updateGuessedWord(const char *finalWord, const char guessedLetter, short len, char *guessedWord);

int main(void) {
    char hangMan[] = "  +---+\n"
                     "  |   |\n"
                     "      |\n"
                     "      |\n"
                     "      |\n"
                     "      |\n"
                     "=========";

    int failChars[6] = {79, 47, 124, 92, 47, 92};
    int failIndexes[6] = {18, 25, 26, 27, 33, 35};

    short failCounter = 0;
    char *finalWord = "WIZARD";
    char guessedLetter;

    bool correctGuess = 0;

    short lengthOfGuessedWord = getStringLength(finalWord);


    char guessedWord[lengthOfGuessedWord];

    initializeGuessedWord(guessedWord, lengthOfGuessedWord);


    bool notFinished = 1;

    short incorrectGuesses = -1;

    while(notFinished){
        printf("Please enter a letter \n");

        scanf(" %c", &guessedLetter);

        bool correctGuess = updateGuessedWord(finalWord, guessedLetter, lengthOfGuessedWord, guessedWord);

        if(!correctGuess){

            if(incorrectGuesses == 4){
                printf("You lose FUCKTARD");
                break;
            }
            incorrectGuesses++;
            //printf(" %d", incorrectGuesses);
            char failedChar = *(failChars + incorrectGuesses);
            int failedIndex = *(failIndexes + incorrectGuesses);

            *(hangMan + failedIndex) = failedChar;

        }

        printf(hangMan);

    }
    return 0;
}

bool updateGuessedWord(const char *finalWord, const char guessedLetter, short len, char *guessedWord) {
    char correct = 0;
    for (int i = 0; i < len; ++i) {

        char finalWordLetter = *(finalWord + i);

        if(guessedLetter == finalWordLetter){
            // correctly guessed a letter
            *(guessedWord + i) = guessedLetter;
            correct = 1;
        }
        char guessedWordLetter = *(guessedWord + i);

        //printf("letter at %d is %c in finalWord \n", i, finalWordLetter);
        printf("%c", guessedWordLetter);
    }
    printf("\n");
    return correct;
}

short getStringLength(const char *finalWord) {
    short counter = 0;
    short len = 0;

    while(counter < 10){
        char ch = *(finalWord + counter);

        if(ch == 0){
            len = counter;
            break;
        }

        //printf("%c", ch);
        counter++;
    }
    return len;
}

void initializeGuessedWord(char *guessedWord, int len){
    for (int i = 0; i < len; ++i) {
        *(guessedWord + i) = '_';
    }
}
