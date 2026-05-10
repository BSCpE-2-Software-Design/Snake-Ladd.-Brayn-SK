# Snake-Ladder-SBK
Snake &amp; Ladder SBK is a fun-filled board game experience that blends chance and strategy. Players race to the top of the board, climbing ladders to leap ahead while avoiding snakes that send them sliding back. 
```mermaid

classDiagram
    class Game {
        - Player player1
        - Player player2
        - Dice dice
        - Board board
        + Game(string name1, string name2)
        + void start()
        + void showScore()
        + void draw_line(int n, char ch)
    }

    class Player {
        - string name
        - int position
        + Player(string playerName)
        + void setPosition(int pos)
        + void move(int steps)
        + int getPosition()
        + string getName()
    }

    class Dice {
        + Dice()
        + int roll()
    }

    class Board {
        + void display()
        + int checkPosition(int pos)
    }

    Game --> Player : has
    Game --> Dice : uses
    Game --> Board : uses

```
```mermaid

    sequenceDiagram
    participant Main
    participant Game
    participant Player
    participant Dice
    participant Board

    Main->>Game: start()
    Game->>Board: display()
    Game->>Game: showScore()

    Game->>Dice: roll()
    Dice-->>Game: diceValue

    Game->>Player: move(diceValue)
    Player-->>Game: newPosition

    Game->>Board: checkPosition(newPosition)
    Board-->>Game: adjustedPosition

    Game->>Player: setPosition(adjustedPosition)
    Player-->>Game: finalPosition

    Game->>Main: display result (snake/ladder/position)


```
