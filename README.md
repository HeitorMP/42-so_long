
# 42-So_Long

You must create a basic 2D game in which a dolphin escapes Earth after eating some fish. Instead of a dolphin, fish, and the Earth, you can use any
character, any collectible and any place you want.

## What i learned:
 - Structuring Large Projects
 - C programming
 - Basic algorithms
 - Minilibx

## Screenshot:
![App Screenshot](https://i.imgur.com/exiohV2.gif)
Image credit : [https://pipoya.itch.io/](https://pipoya.itch.io/)

## Game:

• The player’s goal is to collect every collectible present on the map, then escape
chosing the shortest possible route.

• The W, A, S, and D keys must be used to move the main character.

• The player should be able to move in these 4 directions: up, down, left, right.

• The player should not be able to move into walls.

• At every move, the current number of movements must be displayed in the shell.

• You have to use a 2D view (top-down or profile).

• The game doesn’t have to be real time.

• Although the given examples show a dolphin theme, you can create the world you want.

## Graphic management:

• Your program has to display the image in a window.

• The management of your window must remain smooth (changing to another win-
  dow, minimizing, and so forth).

• Pressing ESC must close the window and quit the program in a clean way.

• Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way.

• The use of the images of the MiniLibX is mandatory.

## Map:
• The map has to be constructed with 3 components: walls, collectibles, and free
space.

• The map can be composed of only these 5 characters:

[ P - Player | E - Exit | 0 - Floor | C - Collectable | 1 - Wall ]

• The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.
• The map must be rectangular.

• The map must be closed/surrounded by walls. If it’s not, the program must return
an error.

• You have to check if there’s a valid path in the map.

• You must be able to parse any kind of map, as long as it respects the above rules

## Installation and Running:

Install solong with make

```bash
  make
  ./so_long /maps/[map_name.ber]
  
  make bonus
  ./so_long_bonus /maps/[map_name.ber]
```

## Useful links:

 - [minilibx Docs](https://harm-smits.github.io/42docs/libs/minilibx)


