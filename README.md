# **Reversi Game 🎮**

Reversi Game is a strategic board game developed in C++. The game allows players to compete against an AI with multiple difficulty levels or participate in a league mode with other players. It incorporates clear game logic, a dynamic AI system, and a leaderboard for tracking player scores.

---

## **🎯 Project Objective**
To create a fully-functional Reversi game featuring multiple game modes, an intelligent AI, and persistent score management for an engaging and challenging user experience.

---

## **✨ Key Features**
1. **Game Modes**:
   - **Player vs. AI**: Challenge the computer at varying levels of difficulty.
   - **League Mode**: Compete with other players in a structured league to determine the ultimate champion.
2. **AI Logic**:
   - Uses the **Minimax Algorithm** for decision-making, with difficulty levels that adjust the depth of AI calculations.
3. **Dynamic Gameplay**:
   - Ensures all moves follow official Reversi rules.
   - Displays valid moves for players during their turn.
   - Prevents illegal moves: If a player attempts an invalid move, the system rejects it and prompts the player to try again.
4. **Scoreboard Management**:
   - Persistent storage of player scores across sessions.
   - View a leaderboard of all registered players.
5. **User Account Management**:
   - Players register with a username and password.
   - Data is stored securely in text files.
6. **Interactive Interface**:
   - A text-based interface offering clear options for all actions.

---

## **🛠️ Technologies**
- **Programming Language**: C++  
- **AI Algorithm**: Minimax for AI decision-making.  
- **Data Management**: Text files for storing user information and scores.

---

## **🚀 How to Use**
1. **Start the Program**:
   - How to Compile and Run the Project
      - Open the project in Visual Studio Code
        Make sure the terminal is open in the root directory of the project.
      - Compile the project
        Run the following command in the terminal to compile the project:
        g++ -o reversi *.cpp
      - Run the program
        After successful compilation, execute the following command to run the program:
        ./reversi
   - Run the program to access the main menu.
   - Register with a username and password (mandatory to play).
2. **Game Options**:
   - **Play vs. AI**:
     - Select the difficulty level (easy, medium, or hard).
     - The system displays valid moves for your turn.
     - Invalid moves are rejected, and the player is prompted to select a valid move.
   - **League Mode**:
     - Requires at least two registered players.
     - Compete in knockout rounds until one player emerges victorious.
3. **View Leaderboard**:
   - Access the scoreboard to see player rankings and scores.
4. **Exit**:
   - Save progress and quit the program.

---

## **📂 Project Structure**
The project is divided into well-organized files and classes for clarity:
- **`main.cpp`**: Contains the main game logic and menu.
- **Player Management**:
  - `Player.cpp` / `Player.h`: Manages player information and scores.
  - `ScoreBoard.txt`: Stores persistent player data.
- **Game Logic**:
  - Implements official Reversi rules and validates moves.
  - AI logic resides in dedicated functions.
- **League Mode**:
  - `League.txt`: Manages player matchups and results.

---

## **💡 Future Enhancements**
1. **Graphical Interface**:
   - Replace the text-based interface with an interactive GUI for better user experience.
2. **Enhanced AI**:
   - Implement advanced machine learning models for smarter gameplay.
3. **Cloud Integration**:
   - Store user data and scores in a cloud database for improved accessibility.
4. **Multiplayer Mode**:
   - Enable online gameplay with real-time competition between players.

---

## **🤝 Contributing**
Contributions are welcome! Feel free to fork the repository and submit pull requests to enhance the game.

---

## **📞 Contact**
For any inquiries, feel free to reach out:
- **Email**: Tamir111Refael@gmail.com  
- **GitHub**: [TamirRefael](https://github.com/TamirRefael/ReversiGame)  
- **LinkedIn**: [Tamir Refael](https://www.linkedin.com/in/tamir-refael-92b683270/)

