#include "enemy.h"

Enemy::Enemy(int damage, bool angry){
    this->damage=damage;
    this->anger=angry;
    this->dead = false;
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

void Enemy::setHealth(int health){
    this->health = health;
    if (this->health <= 0) {
        this->health = 0;
    }else if(this->health>150){
        this->health = 150;
    }
}

bool Enemy::deathStatus(){
    return dead;
}

void Enemy::isDead(){
    if(this->health==0){
        dead = true;
    }
}

