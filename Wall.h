//
// Created by IGOR on 18.06.2023.
//

#ifndef PLAGIATCITY_WALL_H
#define PLAGIATCITY_WALL_H

#include "./Objects/CollidableObject.h"

enum WallClass {REGULAR, BASE};

class Wall : public CollidableObject {
    WallClass wallClass;
public:
    Wall(WallClass wc);
    virtual ~Wall();
    void take_hit() override;
    WallClass get_wallClass() const;
};


#endif //PLAGIATCITY_WALL_H
