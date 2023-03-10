#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

void printGrid(vector<vector<int>> grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));

    vector<vector<int>> grid(ROWS, vector<int>(COLS));

    // Fill the grid with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 10;
        }
    }

    // Shuffle the numbers in the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int newi = rand() % ROWS;
            int newj = rand() % COLS;
            swap(grid[i][j], grid[newi][newj]);
        }
    }

    cout << "Welcome to the memory puzzle game!" << endl;
    cout << "Try to find all matching pairs of numbers." << endl;
    cout << endl;
    printGrid(grid);
    cout << endl;

    int matches = 0;
    while (matches < (ROWS * COLS) / 2) {
        int x1, y1, x2, y2;
        cout << "Enter the coordinates of the first number (row column): ";
        cin >> x1 >> y1;
        cout << "Enter the coordinates of the second number (row column): ";
        cin >> x2 >> y2;

        if (grid[x1][y1] == grid[x2][y2]) {
            cout << "Match found!" << endl;
            matches++;
        } else {
            cout << "No match found." << endl;
        }
    }

    cout << "Congratulations! You found all matches." << endl;

    return 0;
}
