#ifndef TERMWORK_CONSTANTS_H
#define TERMWORK_CONSTANTS_H

#include <ncurses.h>
#include <stdexcept>
#include <random>

//color constants
#define BROWN 9
#define GREY 10
#define LIGHT_BLUE 11
#define WHITE 12
#define RED 13
#define YELLOW 14
#define ORANGE 15
#define GREEN 16
#define BLUE 17

//terrain color pair constants
#define BACKGROUND 20
#define WINDOW_BG 21
#define STONE 22
#define DIRT 23
#define IRON 24
#define WATER 25
#define LAVA 26
#define PLAYER 27
#define RANGED 28
#define MEELE 29

//attack constants
#define AGRO_RANGE 20
#define ATTACK_RANGE 2
#define MAX_ENEMIES 4
#define DAMAGE_FROM_HEIGHT 4

//block type char
#define DIRT_CH "dt"
#define STONE_CH "st"
#define WATER_CH "wt"
#define LAVA_CH "la"
#define PLAYER_CH "pl"
#define MEELE_CH "me"
#define RANGED_CH "ra"
#define BULLET '-'

//player model
#define PLAYER_MD 'T'

//movement actions
#define JUMP 'w'
#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'

//interacting actions
#define ATTACK ' '
#define MINE 'q'
#define PLACE 'e'
#define MEDITATE 'f'

//max lendght of file
#define FILE_MAX_LENGHT 20

//likeliness of displaying
#define RAND_SPACE 0.5
#define RAND_LIQUID 20
#define RAND_SOLID 20

//menu constants
#define QUIT 2
#define LOAD 1
#define NEW 0
#define RESUME 3
#define SAVE 4

//characters health points
#define PLAYER_HP 30
#define RANGED_HP 15
#define MEELE_HP 15

//ctrl + D input
#define CTRL_D  0x04

/**
 * Initializes the custom defined colors
 */
void initializeColors();
/**
 * @author https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
 * Gives a random integer from range
 * @param low lowest possible integer
 * @param high highest possible integer
 * @return returns a random integer
 */
int randomInt (int low, int high);

#endif //TERMWORK_CONSTANTS_H