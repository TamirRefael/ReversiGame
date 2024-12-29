# ReversiGame

Welcome to **ReversiGame**, a feature-rich implementation of the classic Reversi game, designed for both casual players and developers who are interested in exploring C++ game development.

---

## **Overview**
ReversiGame is a C++ console-based application that offers an engaging gaming experience for two players. This project not only demonstrates game logic and player interaction but also implements intelligent move validation, dynamic score calculation, and an interactive user interface in the terminal.

---

## **Features**

- **Dynamic Board Size**: Supports various board sizes to enhance gameplay flexibility.
- **Two-Player Mode**: Designed for competitive play between two players.
- **Move Validation**: Ensures all moves are valid based on the rules of Reversi.
- **Score Tracking**: Real-time calculation and display of scores for both players.
- **User-Friendly Interface**: Clear and concise prompts make the game accessible for all.

---

## **How to Run the Game**

### **Step 1: Clone the Repository**
Clone this repository to your local machine using the following command:
```bash
git clone https://github.com/TamirRefael/ReversiGame.git
```

### **Step 2: Compile the Game**
Use a C++ compiler such as `g++` to compile the project files. Run the following command from the project directory:
```bash
g++ main.cpp Player.cpp -o ReversiGame
```

### **Step 3: Execute the Game**
Run the compiled executable to start playing:
```bash
./ReversiGame
```

---

## **Gameplay Instructions**
1. The game begins with a dynamically created board.
2. Player 1 (`X`) and Player 2 (`O`) take turns.
3. Each player must choose a valid position on the board to place their marker.
4. The game follows the traditional Reversi rules:
   - Flipping opponent pieces between your pieces.
   - Valid moves must result in at least one opponent piece being flipped.
5. The game ends when no more valid moves are available for either player.

---

## **Project Structure**

| File             | Description                                  |
|------------------|----------------------------------------------|
| `main.cpp`       | Main entry point and game loop logic.        |
| `Player.cpp`     | Handles player-related functionality.        |
| `Player.h`       | Header file for player functionality.        |
| `ScoreBoard.txt` | Tracks player scores and game history.       |
| `.gitignore`     | Prevents unnecessary files from being added. |

---

## **Future Improvements**
We are looking to enhance the game with the following features:
- Graphical user interface (GUI) using modern frameworks.
- Online multiplayer functionality.


---

## **Contributions**
Contributions are welcome! If you have suggestions or improvements, feel free to create a pull request or open an issue.

---

## **Contact**
Created by [Tamir Refael](https://github.com/TamirRefael). If you have any questions or feedback, feel free to reach out.

---

Enjoy playing ReversiGame and exploring the code! 🎮
