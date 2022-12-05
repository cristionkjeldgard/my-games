#include <iostream>
#include <random>
#include <ctime>

// Function that generates a random number between 1 and 10
int generateNumber()
{
  // Seed the random number generator
  std::srand(std::time(nullptr));

  // Generate a random number between 1 and 10
  int number = std::rand() % 10 + 1;
  return number;
}

// Function that runs the game
void runGame()
{
  // Generate a random number
  int number = generateNumber();

  // Game loop
  while (true)
  {
    // Get the player's guess
    std::cout << "Enter your guess (1-10): ";
    int guess;
    std::cin >> guess;

    // Check if the player's guess is correct
    if (guess == number)
    {
      std::cout << "Correct! You have guessed the number!" << std::endl;
      break;
    }
    else
    {
      std::cout << "Incorrect! Please try again." << std::endl;
    }
  }
}

int main()
{
  // Start the game
  runGame();

  return 0;
