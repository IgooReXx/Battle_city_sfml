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

/// Structure used to describe all parameters of an object
/// FloatRect contains four variables which describe the position of an object in a 2D plane (top lefthand corner is defined by two variables left and top,
/// the other two of the variables hold the width and height of an object).
struct mvObject // mvObject - movableObject
{
    sf::FloatRect object;
    Facing facing;
    float velocity;
    Type type;
    Status status;
};

class MovableObject {

    mvObject objectParam; // objectParam - objectParameters

public:

    explicit MovableObject(float v, Type t, float width, float height);

    virtual void take_hit(); // Allows an object to be "damaged"

    virtual void update(); // Used for updating objects parameters

    // Simple setters
    void set_facing(Facing f);
    void set_position(sf::Vector2f position);
    void set_velocity(float v);
    void set_status_destroyed();

    // Simple getters
    mvObject get_objectParam() const;
    mvObject get_next_objectParam() const;     // Returns the parameters of an object in after updating based on the current parameters
    bool is_destroyed() const;

};


#endif //PLAGIATCITY_MOVABLEOBJECT_H
