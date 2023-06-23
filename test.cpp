//
// Created by IGOR on 16.06.2023.
//

#include <cassert>

#include "Objects/MovableObject.h"
#include "Objects/CollidableObject.h"

void test_movement()
{
    MovableObject mv(5, PLAYERTANK, 64, 64);
    assert(mv.get_objectParam().velocity == 5);
    assert(mv.get_objectParam().facing == RIGHT);
    assert(mv.get_objectParam().object.left == 0);
    assert(mv.get_objectParam().object.top == 0);
    assert(mv.get_objectParam().type == PLAYERTANK);

    mv.update();
    assert(mv.get_objectParam().object.left == 5);

    mv.set_facing(DOWN);
    assert(mv.get_objectParam().facing == DOWN);

    mv.set_velocity(1);
    mv.update();
    assert(mv.get_objectParam().object.left == 5);
    assert(mv.get_objectParam().object.top == 1);
}

void test_collision()
{
    MovableObject t(0, AITANK, 32, 32);
    MovableObject b(0, BULLET, 8, 8);
    CollidableObject tank{{true,true, true, true}, t};
    CollidableObject bullet{{true,true, true, true}, b};
    assert(tank.check_collision(bullet));
    assert(bullet.check_collision(tank));

    tank.set_velocity(150);

    assert(!tank.check_collision(bullet));
    assert(!bullet.check_collision(tank));

}

int main() {

    test_movement();
    test_collision();


}