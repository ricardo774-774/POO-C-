#include <iostream>

using namespace std;

// father class 
class pokemon {
protected: 
    char name[15];
    int attack;
    int life;
    char color[15];

public:
    pokemon(){
        strcpy(name, "Undefined");
        attack = 100;
        life = 100;
        strcpy(color, "Undefined");
    }
    pokemon(char n[15], int a, int l, char c[15]){
        strcpy(name, n);
        attack = a;
        life = l;
        strcpy(color, c);
    }
    ~pokemon(){ cout << endl << "Pokemon " << name << " deleted" << endl; }

    void regenerateLife(){
        life = 100;
    }

    void evolutionPokemon(char n[15], char c[15]){
        strcpy(name, n);
        attack = attack + ( attack * .20);
        strcpy(color, "Undefined");
    }

    char* getName() { return name; }
    void setName(char n[15]) { strcpy(name, n); }

    int getAttack() { return attack; }
    void setAttack(int a) { attack = a; }

    int getLife() { return life; }
    void setLife(int l) { life = l; }

    char* getColor() { return color; }
    void setColor(char c[15]) { strcpy(color, c); }

    virtual void pokemonAttack() {
        cout << "Pokemon " << name << "is attacking" << endl;
    }

    void showAttributes() {
        cout << endl;
        cout << "Pokemon name: " << name <<endl;
        cout << "Pokemon attack: " << attack <<endl;
        cout << "Pokemon life: " << life <<endl;
        cout << "Pokemon color: " << color <<endl;
    }

    void helloPokemon() { 
        cout << "Hello my name is " << name << " you can select me" <<endl; 
    }
};

// class ball of water
class  waterBall  {
private: 
    int size = 15;
    int strong = 10;

public:
    waterBall(int strong) {
        strong = strong;
    }

    void showBall() {
        cout << "Ball strong: " << strong <<endl;
        cout << "Ball size: " << size <<endl;
    }
};

// Pokemon son of water
class waterPokemon: public pokemon {
private: 
    int maxResist;
    int countTime;
    int strong;

public:
    waterPokemon(int mR, int cT, int strong) {
        maxResist = mR;
        countTime = cT;
        strong = strong;
    }

    waterPokemon(char n[15], int a, int l, char c[15], int mR, int cT, int strong) {
        strcpy(name, n);
        attack = a;
        life = l;
        strcpy(color, c);
        maxResist = mR;
        countTime = cT;
        strong = strong;
    }
    ~waterPokemon(){ cout << endl << "Pokemon water " << name << " deleted" << endl; }

    void breathe(){
        countTime = 0;
    }

    void evolutionWaterResist(){
        maxResist += (maxResist * .20);
    }

    int getMaxResist() { return maxResist; }
    void setMaxResist(int mR) { maxResist = mR; }

    int getCountTime() { return countTime; }
    void setCountTime(int cT) { countTime = cT; }

    void throwWaterAttack(){
        waterBall ball(strong);
        cout << endl << "Water ball craeted succesfully" << endl;
        ball.showBall();
    }

    void pokemonAttack() override {
        cout << endl << "Pokemon " << name << " is attacking:"; 
        throwWaterAttack();
    }

    void showAttributesWater() {
        showAttributes();
        cout << "Pokemon underwater resistance :" << maxResist <<endl;
        cout << "Pokemon underwater cout:" << countTime <<endl;
    }
};

// class ball of fire
class fireBall{
private: 
    int size = 10;
    int temperature;

public:
    fireBall(int temperature) {
        temperature = temperature;
    }

    void showBall() {
        cout << "Ball temperature: " << temperature <<endl;
        cout << "Ball size: " << size <<endl;
    }
};

// Pokemon son of fire
class firePokemon: public pokemon {


private: 
    int ballTemperature;
    int maxTemperature;

public:
    firePokemon(int bT, int mT) {
        ballTemperature = bT;
        maxTemperature = mT;
    }

    firePokemon(char n[15], int a, int l, char c[15], int mT, int bT) {
        strcpy(name, n);
        attack = a;
        life = l;
        strcpy(color, c);
        maxTemperature = mT;
        ballTemperature = bT;
    }
    ~firePokemon(){ cout << endl << "Pokemon fire " << name << " deleted" << endl; }

    void throwFireAttack(){
        fireBall fBall(ballTemperature);
        cout << endl << "Fire ball craeted succesfully" << endl;
        fBall.showBall();
    }

    void evolutionMaxTemperature(){
        maxTemperature += (maxTemperature * .20);
    }

    void pokemonAttack() override {
        cout << endl << "Pokemon " << name << " is attacking:"; 
        throwFireAttack();
    }

    int getMaxTemperature() { return maxTemperature; }
    void setMaxTemperature(int mT) { maxTemperature = mT; }

    int getBallTemperature() { return ballTemperature; }
    void setBallTemperature(int bT) { ballTemperature = bT; }

    void showAttributesFire() {
        showAttributes();
        cout << "Pokemon max temperature resistance: " << maxTemperature <<endl;
        cout << "Pokemon max ball temperature: " << ballTemperature <<endl;
    }
};

class stoneBall{
private: 
    int size = 10;
    int weight = 10;

public:
    stoneBall(int weight) {
        weight = weight;
    }

    void showBall() {
        cout << "Ball weight: " << weight <<endl;
        cout << "Ball size: " << size <<endl;
    }
};

// Pokemon son of stone
class stonePokemon: public pokemon {
private: 
    int depth;
    int weight;

public: 
    stonePokemon(int d, int weight) {
        depth = d;
        weight = weight;
    }
    stonePokemon(char n[15], int a, int l, char c[15], int d, int weight) {
        strcpy(name, n);
        attack = a;
        life = l;
        strcpy(color, c);
        depth = d;
        weight = weight;
    }

    ~stonePokemon(){ cout << endl << "Pokemon stone " << name << " deleted" << endl; }

    void digTunnel() {
        cout << endl << "Pokemon stone created tunnel with the depth of: "<< depth << endl;
    }

    void evolutionDepth(){
        depth += (depth * .20);
    }

    int getDepth() { return depth; }
    void setDepth(int d) { depth = d; }

    void throwStoneAttack(){
        stoneBall ball(weight);
        cout << endl << "Stone ball craeted succesfully" << endl;
        ball.showBall();
    }

    void pokemonAttack() override {
        cout << endl << "Pokemon " << name << " is attacking:"; 
        throwStoneAttack();
    }

    void showAttributesStone() {
        showAttributes();
        cout << "Pokemon depth resistance :" << depth <<endl;
    }

};

void fight(pokemon pok1, pokemon pok2) {

    while( (pok1.getLife() && pok2.getLife()) > 0) {
        pok1.pokemonAttack();
        pok2.setLife( pok2.getLife() - pok1.getAttack() );

        if( pok2.getLife() > 0 ) {
            pok2.pokemonAttack();
            pok1.setLife( pok1.getLife() - pok2.getAttack() );
        }
    }

    if( pok1.getLife() > 0 ) {
        cout << "Pokemon " << pok1.getName() << " is the winner" <<endl;
    } else {
        cout << "Pokemon " << pok2.getName() << " is the winner" <<endl;
    }

}


// Functions Call
int main() {
    char auxName[15], auxColor[15];

    //father pokemon with default value
    // pokemon Picachu;
    // Picachu.showAttributes();

    //father pokemon with real values
    // strcpy(auxName, "Chairo");
    // strcpy(auxColor, "Orange");
    // pokemon Chairo(auxName, 150, 120, auxColor);
    // Chairo.showAttributes();
    // Chairo.helloPokemon();

    //water pokemon
    // strcpy(auxName, "Squirtle");
    // strcpy(auxColor, "Blue");
    // waterPokemon Squirtle(auxName, 150, 120, auxColor, 120, 0, 50);
    // Squirtle.showAttributesWater();
    // Squirtle.pokemonAttack();

    // fire pokemon
    strcpy(auxName, "Charmander");
    strcpy(auxColor, "Orange");
    firePokemon Charmander(auxName, 10, 100, auxColor, 30, 500);
    // Charmander.throwFireAttack();
    // Charmander.showAttributesFire();
    // Charmander.pokemonAttack();

    //stone pokemon
    strcpy(auxName, "Golem");
    strcpy(auxColor, "Gray");
    stonePokemon Golem(auxName, 20, 100, auxColor, 120, 90);
    // Golem.digTunnel();
    // Golem.showAttributesStone();
    // Golem.pokemonAttack();


    // fight pokemons 
    fight(Golem, Charmander);

}