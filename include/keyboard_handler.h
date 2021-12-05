//
// Created by mateusz on 12/5/21.
//

#include <SFML/Window/Event.hpp>
#include <set>
#include <iostream>

#ifndef MEINKRAFT_KEYBOARD_HANDLER_H
#define MEINKRAFT_KEYBOARD_HANDLER_H

#endif //MEINKRAFT_KEYBOARD_HANDLER_H

enum class Direction {
    NONE, UP, DOWN, LEFT, RIGHT
};

struct PlayerDirection {
    Direction horizontal = Direction::NONE;
    Direction vertical = Direction::NONE;
};


class KeyboardHandler {
public:
    void handleInput(sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                pressed_keys.insert(Direction::UP);
            }
            if (event.key.code == sf::Keyboard::Down) {
                pressed_keys.insert(Direction::DOWN);
            }
            if (event.key.code == sf::Keyboard::Left) {
                pressed_keys.insert(Direction::LEFT);
            }
            if (event.key.code == sf::Keyboard::Right) {
                pressed_keys.insert(Direction::RIGHT);
            }
        }
        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Up) {
                pressed_keys.erase(Direction::UP);
            }
            if (event.key.code == sf::Keyboard::Down) {
                pressed_keys.erase(Direction::DOWN);
            }
            if (event.key.code == sf::Keyboard::Left) {
                pressed_keys.erase(Direction::LEFT);
            }
            if (event.key.code == sf::Keyboard::Right) {
                pressed_keys.erase(Direction::RIGHT);
            }
        }

//        for (auto dir : pressed_keys) {
//            std::cout << getDirectionString(dir) << " ";
//        }
//        std::cout << std::endl;
        int vertical = 1;
        int horizontal = 1;
        if (pressed_keys.count(Direction::UP)) {
            vertical += 1;
        }
        if (pressed_keys.count(Direction::DOWN)) {
            vertical -= 1;
        }
        if (pressed_keys.count(Direction::LEFT)) {
            horizontal += 1;
        }
        if (pressed_keys.count(Direction::RIGHT)) {
            horizontal -= 1;
        }

        if (vertical == 0) {
            player_direction.vertical = Direction::DOWN;
        } else if (vertical == 2) {
            player_direction.vertical = Direction::UP;
        } else {
            player_direction.vertical = Direction::NONE;
        }

        if (horizontal == 0) {
            player_direction.horizontal = Direction::LEFT;
        } else if (horizontal == 2) {
            player_direction.horizontal = Direction::RIGHT;
        } else {
            player_direction.horizontal = Direction::NONE;
        }
    }

    static std::string getDirectionString(Direction dir) {
        if (dir == Direction::UP) {
            return "up";
        } else if (dir == Direction::DOWN) {
            return "down";
        } else if (dir == Direction::RIGHT) {
            return  "right";
        } else if (dir == Direction::LEFT){
            return "left";
        }
        return "none";
    }

    PlayerDirection getPlayerDirection() {
        return player_direction;
    }

private:
    std::set<Direction> pressed_keys;
    PlayerDirection player_direction;
};