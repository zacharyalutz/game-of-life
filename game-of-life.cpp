#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

int main() {
    int width = 32, height = 20;
    std::vector<std::vector<bool>> grid(height, std::vector<bool>(width)), newGrid(height, std::vector<bool>(width));

    srand(time(0)); // Use current time as seed for random generator

    // Randomly initialize the grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    // // Seed: Gosper glider gun
    // grid[5][1] = grid[5][2] = grid[6][1] = grid[6][2] = true;
    // grid[5][11] = grid[6][11] = grid[7][11] = grid[4][12] = grid[8][12] = grid[3][13] = grid[9][13] = grid[3][14] = grid[9][14] = true;
    // grid[6][15] = grid[4][16] = grid[8][16] = grid[5][17] = grid[6][17] = grid[7][17] = grid[6][18] = true;
    // grid[3][21] = grid[4][21] = grid[5][21] = grid[3][22] = grid[4][22] = grid[5][22] = grid[2][23] = grid[6][23] = true;
    // grid[1][25] = grid[2][25] = grid[6][25] = grid[7][25] = true;
    // grid[3][35] = grid[4][35] = grid[3][36] = grid[4][36] = true;

    while (true) {
        bool hasChanged = false;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int alive = 0;
                for (int di = -1; di <= 1; di++)
                    for (int dj = -1; dj <= 1; dj++)
                        if ((di || dj) && i + di >= 0 && i + di < height && j + dj >= 0 && j + dj < width && grid[i + di][j + dj]) alive++;
                newGrid[i][j] = alive == 3 || (alive == 2 && grid[i][j]);
                if (grid[i][j] != newGrid[i][j]) hasChanged = true;
                std::cout << (newGrid[i][j] ? '*' : ' ');
            }
            std::cout << "\n";
        }
        if (!hasChanged) break;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "\033[" << height << "A";
        grid = newGrid;
    }
}
