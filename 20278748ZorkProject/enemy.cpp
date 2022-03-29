#include "enemy.h"

Enemy::Enemy(int damage, bool angry){
    this->damage=damage;
    this->angry=angry;
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
    return this->angry;
}

void Enemy::setAnger(bool angry){
    this->angry=angry;
}

