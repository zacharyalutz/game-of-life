#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

int main() {

  bool gameOn = true;
  int width = 32, height = 20;
  std::vector<std::vector<bool>> grid(height, std::vector<bool>(width)), newGrid(height, std::vector<bool>(width));

  // Use current time as seed for random generator
  srand(time(0));

  // Randomly initialize the grid
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      grid[i][j] = rand() % 2;
    }
  }

  while (gameOn) {
    // Assume the game is over until we find a cell that is alive
    gameOn = false;

    // Print each row
    for (int i = 0; i < height; i++)
    {
      // Print each column
      for (int j = 0; j < width; j++)
      {
        int alive = 0;
        // Scan horizontal neighbors
        for (int di = -1; di <= 1; di++)
        {
          // Scan vertical neighbors
          for (int dj = -1; dj <= 1; dj++)
          {
            // count the neighbors as alive iff:
            // (a) we are not looking at the cell itself;
            // (b) the cell is in bounds; and
            // (c) the cell we are looking at is alive
            if ((di || dj) && i + di >= 0 && i + di < height && j + dj >= 0 && j + dj < width && grid[i + di][j + dj])
            {
              alive++;
            }
          }
        }

        // Rules of the game: Current cell is alive if either
        // (a) 3 neighbors are alive; or
        // (b) 2 neighbors and alive
        newGrid[i][j] = alive == 3 || (alive == 2 && grid[i][j]);

        // If the new grid is different from the old grid, then the game is still going
        if (grid[i][j] != newGrid[i][j])
        {
          gameOn = true;
        }

        // Print the cell
        std::cout << (newGrid[i][j] ? '*' : ' ');
      }

      // end of row
      std::cout << "\n";
    }

    // 10 Hz frame rate
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Return cursor to the top of the grid
    std::cout << "\033[" << height << "A";

    // update the grid
    grid = newGrid;
  }
}
