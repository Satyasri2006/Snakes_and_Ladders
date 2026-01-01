**SNAKES AND LADDERS (C++ & OOP)**

Who doesn't love Snakes and Ladders? I do. So, I tried implementing one of my favourite board games as a console-based game in C++ using Object-Oriented Programming principles.

This project is simple, readable, and beginner-friendly, while still demonstrating clean OOP design. It's basically a basic version of Snakes and Ladders.


**FEATURES**

    ~ 2 Players

    ~ Dice Rolling Simulation

    ~ Snakes and Ladders at every step

    ~ Replay game option

    ~ Positions visible after each role


**OOP CONCEPTS USED**

    ~ Encapsulation

    ~ Abstraction

    ~ Composition

    ~ SOLID Principles


**STRUCTURE**

DICE:

      roll()

PLAYER:

      position
  
      getPosition()
  
      setPosition()
  
      reset()

BOARD:

      snakes
  
      ladders
  
      applySnakeorLadder()

GAME:

      player1
  
      player2
  
      dice
  
      board
  
      play()
  
      showPositions()


**WORKING**

    1. Player1 and Player2 take turns to roll the dice.

    2. Dice value moves the player forward.

    3. Landing on

       * Snake: Player moves down

       * Ladder: Player moves up

    4. Player must land exactly on 100 to win.

    5. Positions of both players are shown after each and every turn.

    6. Game can be replayed after completion.
