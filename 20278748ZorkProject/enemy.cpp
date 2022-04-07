#include "enemy.h"

Enemy::Enemy(string description, int health, int damage, bool angry) : Character(description, health)
{
    this->damage=damage;
    this->anger=angry;
    //this->dead = false;
}

Enemy::~Enemy(){

}

int Enemy::attack(bool angry)
{
    if(angry){
        return getDamage();
    }else{
        ;
    }
}

int Enemy::getDamage()
{
    return this->damage;
}

void Enemy::setDamage(int damage)
{
    this->damage = damage;
}

bool Enemy::getAnger()
{
    return this->anger;
}

void Enemy::setAnger(bool anger)
{
    this->anger=anger;
}

void Enemy::setHealth(int health)
{
    this->health = health;
    if (this->health <= 0) {
        this->health = 0;
    }else if(this->health>150){
        this->health = 150;
    }
}
