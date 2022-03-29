#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
public:
    Enemy(int damage, bool angry);
    int attack(bool angry);
    void setDamage(int damage);
    int getDamage();
    void setAnger(bool angry);
    bool getAnger();
private:
    int damage;
    bool angry;

};

#endif // ENEMY_H
