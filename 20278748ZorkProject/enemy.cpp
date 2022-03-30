#include "enemy.h"

Enemy::Enemy(int damage, bool angry){
    this->damage=damage;
    this->anger=angry;
}

int Enemy::attack(bool angry){
    if(angry){
        return getDamage();

    }
}

int Enemy::getDamage(){
    return this->damage;
}

void Enemy::setDamage(int damage){
    this->damage = damage;
}

bool Enemy::getAnger(){
    return this->anger;
}

void Enemy::setAnger(bool anger){
    this->anger=anger;
}

