🎮 Noughts & Crosses (Tic-Tac-Toe) — C Console Game

A simple, clean, and fully functional Tic-Tac-Toe game written in C.
This console-based game supports two players, handles input validation, and checks for win/draw conditions after every move.

✨ Features

🎲 Two-player turn-based gameplay (X vs O)

🧠 Win detection for all 8 winning combinations

❌ Input validation (range check + occupied slot check)

🟦 ASCII-art board rendering

🔄 Automatic draw detection

🧹 Grid auto-reset before each game run

📸 Game Preview
--- Noughts & Crosses ---

  1  ||  2  ||  3  
======++=====++======
  4  ||  5  ||  6  
======++=====++======
  7  ||  8  ||  9  

Player [X] choose slot: 5

  X  ||  2  ||  3  
======++=====++======
  4  ||  5  ||  6  
======++=====++======
  7  ||  8  ||  9  

🛠️ How It Works
🔹 Game Board Representation

The board is stored in a simple char grid[9], sequentially representing positions 1–9.

🔹 Win Checking

There are 8 winning lines (rows, columns, diagonals).
The program checks them efficiently using:

int wins[8][3] = {
    {0,1,2}, {3,4,5}, {6,7,8},
    {0,3,6}, {1,4,7}, {2,5,8},
    {0,4,8}, {2,4,6}
};

🔹 Input Handling

The game safely handles:

invalid characters

out-of-range input

selecting an already occupied slot

▶️ How to Compile & Run
Using GCC
gcc tic_tac_toe.c -o ttt
./ttt

Using Clang
clang tic_tac_toe.c -o ttt
./ttt

📁 Project Structure
.
├── tic_tac_toe.c
└── README.md

📌 Future Improvements (Optional Ideas)

Add support for single-player mode (AI)

Implement a scoreboard

Add colorful terminal output

Add replay option without restarting program

📄 License

This project is free to use, modify, and share.
Feel free to fork and enhance it!
