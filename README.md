# Tekdoom
A multiplayer Doom-like in C

Works with the LibLapin (Epitech's graphic lib, based on SFML).
The library only allows us to open a window and set pixels. That is why we had to do everything by ourselves.

We had to code a Doom-Like game.

Bonus :   

          - Our own 3D engine (100% handmade)
          - Multiplayer
              - In-game chat (TPC thread)
              - Up to 8 players (UDP thread)
              - Ready for procedural generation of map (sending / receiving seed)
          - HUD with animations
          - Menus (glitch animation, text input)

Every weapon is animated (and with sound effects as well). 

Because of a huge lack of time, the project isn't 100% finished (we still need to fix some graphical bugs), but stay tuned for the v2 !

Every menu item is animated with a glitch effect, you can enter text in textboxes.
The menu features the famous Solarized theme also !
![Game Screenshot](/menu1.png?raw=true "Main Menu")
![Game Screenshot](/menu2.png?raw=true "Login Screen")

Once you start the game, you can wait for other players to come, and chat with them in the lobby room (up to 8 players).
![Game Screenshot](/room1.png?raw=true "Lobby")
![Game Screenshot](/room2.png?raw=true "Lobby")

The game features 3 weapon : the knife, the pistol and the rifle.
The ammunitions are displayed next to the health indicator.
When the player looses too many health, the border of the screen become red.
![Game Screenshot](/knife.png?raw=true "Knife")
![Game Screenshot](/pistol.png?raw=true "Pistol")
![Game Screenshot](/rifle.png?raw=true "Rifle")

Realized with Luka Boulagnon, Ludovic Petrenko and Lucas Troncy.
