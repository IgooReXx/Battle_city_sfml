//
// Created by IGOR on 16.06.2023.
//

#ifndef PLAGIATCITY_MOVABLEOBJECT_H
#define PLAGIATCITY_MOVABLEOBJECT_H

#include <utility>
#include <SFML/Graphics.hpp>

#define MAP_WIDTH 800
#define MAP_HEIGHT 600

enum Facing {UP, DOWN, LEFT, RIGHT};
enum Type {PLAYERTANK, AITANK, WALL, BULLET};
enum Status {ALIVE, DESTROYED};

struct mvObject
{
    sf::FloatRect object;
    Facing facing;
    float velocity;
    Type type;
    Status status;
};

class MovableObject {

    mvObject objectParam;

public:

    explicit MovableObject(float v, Type t, float width, float height);

    virtual void take_hit();

    virtual void update();
    void set_facing(Facing f);
    void set_position(sf::Vector2f position);
    void set_velocity(float v);
    mvObject get_objectParam() const;
    mvObject get_next_objectParam() const;
    void set_status_destroyed();




};


#endif //PLAGIATCITY_MOVABLEOBJECT_H
