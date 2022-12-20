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

    void showAttributes() {
        cout << endl;
        cout << "Pokemon name:" << name <<endl;
        cout << "Pokemon attack:" << attack <<endl;
        cout << "Pokemon life:" << life <<endl;
        cout << "Pokemon color:" << color <<endl;
    }

    void helloPokemon() { 
        cout << "Hello my name is " << name << " you can select me" <<endl; 
    }
};

// class ball
class ball{
private: 
    int size = 10;
    int temperature;

public:
    ball(int temperature) {
        temperature = temperature;
    }

    void showBall() {
        cout << "Ball temperature: " << temperature <<endl;
        cout << "Ball size: " << size <<endl;
    }
};

// Pokemon son of water
class waterPokemon: public pokemon {
private: 
    int maxResist;
    int countTime;

public:
    waterPokemon(int mR, int cT) {
        maxResist = mR;
        countTime = cT;
    }

    waterPokemon(char n[15], int a, int l, char c[15], int mR, int cT) {
        strcpy(name, n);
        attack = a;
        life = l;
        strcpy(color, c);
        maxResist = mR;
        countTime = cT;
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

    void showAttributesWater() {
        showAttributes();
        cout << "Pokemon underwater resistance :" << maxResist <<endl;
        cout << "Pokemon underwater cout:" << countTime <<endl;
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

    void throwBall(){
        ball fireBall(ballTemperature);
        cout << endl << "Fire ball craeted succesfully" << endl;
        fireBall.showBall();
    }

    void evolutionMaxTemperature(){
        maxTemperature += (maxTemperature * .20);
    }

    int getMaxTemperature() { return maxTemperature; }
    void setMaxTemperature(int mT) { maxTemperature = mT; }

    int getBallTemperature() { return ballTemperature; }
    void setBallTemperature(int bT) { ballTemperature = bT; }

    void showAttributesFire() {
        showAttributes();
        cout << "Pokemon max temperature resistance :" << maxTemperature <<endl;
        cout << "Pokemon max ball temperature:" << ballTemperature <<endl;
    }
};

// Pokemon son of stone
class stonePokemon: public pokemon {
private: 
    int depth;

public: 
    stonePokemon(int d) {
        depth = d;
    }
    stonePokemon(char n[15], int a, int l, char c[15], int d) {
        strcpy(name, n);
        attack = a;
        life = l;
        strcpy(color, c);
        depth = d;
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

    void showAttributesStone() {
        showAttributes();
        cout << "Pokemon depth resistance :" << depth <<endl;
    }

};

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
    // waterPokemon Squirtle(auxName, 150, 120, auxColor, 120, 0);
    // Squirtle.showAttributesWater();

    //fire pokemon
    // strcpy(auxName, "Charmander");
    // strcpy(auxColor, "Orange");
    // firePokemon Charmander(30, 500);
    // Charmander.throwBall();
    // Charmander.showAttributesFire();

    //stone pokemon
    strcpy(auxName, "Golem");
    strcpy(auxColor, "Gray");
    stonePokemon Golem(auxName, 100, 100, auxColor, 120);
    Golem.digTunnel();
    Golem.showAttributesStone();

}