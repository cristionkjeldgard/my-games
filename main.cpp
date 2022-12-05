#include <iostream>
#include <string>
#include <random>
#include <ctime>

// Function that generates a random maze
void generateMaze(char maze[][10], int size)
{
  // Seed the random number generator
  std::srand(std::time(nullptr));

  // Fill the maze with walls
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      maze[i][j] = '#';
    }
  }

  // Generate a random path through the maze
  int x = std::rand() % size;
  int y = std::rand() % size;
  maze[x][y] = '.';
  for (int i = 0; i < size * size; i++)
  {
    int dx = std::rand() % 3 - 1;
    int dy = std::rand() % 3 - 1;
    if (x + dx >= 0 && x + dx < size && y + dy >= 0 && y + dy < size)
    {
      x += dx;
      y += dy;
      maze[x][y] = '.';
    }
  }
}

// Function that prints the maze to the terminal
void printMaze(const char maze[][10], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      std::cout << maze[i][j];
    }
    std::cout << std::endl;
  }
}

// Function that runs the game
void runGame()
{
  // Create an empty 10x10 maze
  const int size = 10;
  char maze[size][size];

  // Generate a random maze
  generateMaze(maze, size);

  // Print the maze
  printMaze(maze, size);

  // Start the player at the top-left corner of the maze
  int x = 0;
  int y = 0;

  // Game loop
  while (true)
  {
    // Print the player's current position
    std::cout << "You are at position (" << x << ", " << y << ")." << std::endl;

    // Check if the player has reached the bottom-right corner of the maze
    if (x == size - 1 && y == size - 1)
    {
      std::cout << "You have reached the end of the maze! Congratulations!" << std::endl;
      break;
    }

    // Get the player's input
    std::cout << "Enter your next move (u/d/l/r): ";
    std::string input;
    std::cin >> input;

    // Process the player's input and update the player's position
    if (input == "u" && x > 0 && maze[x - 1][y] == '.')
    {
      x--;
    }
    else if (input == "d" && x < size - 1 && maze[x + 1][y] == '.')
{
x++;
}
else if (input == "l" && y > 0 && maze[x][y - 1] == '.')
{
y--;
}
else if (input == "r" && y < size - 1 && maze[x][y + 1] == '.')
{
y++;
}
else
{
std::cout << "Invalid move!" << std::endl;
}
}
}

int main()
{
// Start the game
runGame();

return 0;
}