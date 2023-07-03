//
// Created by IGOR on 18.06.2023.
//

#ifndef PLAGIATCITY_WALL_H
#define PLAGIATCITY_WALL_H

#define WALL_WIDTH 16
#define WALL_HEIGHT 16

#include "../Objects/CollidableObject.h"

/// Enum used to differentiate regular walls from player's base
enum WallClass {REGULAR, BASE};

/// Class handling walls and their behaviour
class Wall : public CollidableObject {

    WallClass wallClass;

public:
    Wall(WallClass wc, sf::Vector2f size);
    virtual ~Wall();

    void take_hit() override;

    // Simple getter
    WallClass get_wallClass() const;

};


#endif //PLAGIATCITY_WALL_H
