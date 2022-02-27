#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "You are a hired agent breaking in to a Pizza Hut with level " << Difficulty << " security.";
    std::cout << "\nPizza Hut is heavily fortified! You'll have to enter the correct door code to continue.\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int codeA = rand() % Difficulty + Difficulty; // adds the level difficulty to itself to increase the game's difficulty
    const int codeB = rand() % Difficulty + Difficulty; // ex: difficulty 2 gives you values between 1-3 since 2+2 = 4
    const int codeC = rand() % Difficulty + Difficulty; // of course as you progress, it gets much harder

    const int codeSum = codeA + codeB + codeC;
    const int codeProduct = codeA * codeB * codeC;

    //outputting variable and sums
    std::cout << "- There are 3 numbers in the code.";
    std::cout << "\n- The code adds up to: " << codeSum << std::endl;
    std::cout << "- The code multiplies to: " << codeProduct << std::endl;

    // store player guess
    int guessA, guessB, guessC;
    std::cin >> guessA >> guessB >> guessC;

    int guessSum = guessA + guessB + guessC;
    int guessProduct = guessA * guessB * guessC;
    
    // checking if the player's guess is correct
    if (guessSum == codeSum && guessProduct == codeProduct)
    {
        std::cout << "\nThat code is correct, moving on to the next room.\n\n";
        return true;
    }
    else
    {
        std::cout << "\n*** Wrong code. Only so many more tries before the missiles get to your location. Try again. ***\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // creates a new random sequence based on the time of day
    int LevelDifficulty = 1; 
    int const MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty) // loops all levels until they are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "*** Congratulations! You have successfully broken into the Pizza Hut! Take whatever you desire! ***";
    return 0;
}