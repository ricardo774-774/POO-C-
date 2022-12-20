#include <iostream>

using namespace std;

class athlete {
// Attributes that are inherited 
protected:
    float phone = 3334413921;
    int power;
    int speed;
    char name[15];

public:
// Default constructor
    athlete() {
        power = 100;
        speed = 0;
        strcpy(name, "Undefined");
    }

// Constructor with data 
    athlete(int p, int s, char n[15]) {
        power = p;
        speed = s;
        strcpy(name, n);
    }

// Delete data 
    ~athlete() { cout << name <<" Has been destroyed" << endl; }

// Value change 
    virtual void upSpeed() {
        speed++;
        power--;
    }

// Get and Set values
    int getPower() { return power; }
    void setPower(int p) { power = p; }

    int getSpeed() { return speed; }
    void setSpeed(int s) { speed = s; }

    char* getName() { return name; }
    void setName(char n[15]) { strcpy(name, n); }

// Set phone number
    void setPhone() {
        float ph;
        cout << "Type your current phone number: "; cin >> ph;

        if(ph == phone) {
            cout << "Type your new phone number: "; cin >> phone;
            cout << "Phone number updated succesfully: "<< phone << endl;
        } else { cout << "Phone number incorrect" << endl; }
    }

// Show athlete attributes
    void showAttributes() {
        cout << "Athlete name: " << name <<endl;
        cout << "Athlete power: " << power <<endl;
        cout << "Athlete speed: " << speed <<endl;
    }
};

// Son of father
class soccerAthlete: public athlete {
// Attributes
private:
    int num;
    char team[10];
    char position[10];
    int goals;

public:
// Constructor soccer athlete whit values, and default values 
    soccerAthlete(int nu, char t[10], char pt[10], int g) {
        num = nu;
        strcpy(team, t);
        strcpy(position, pt);
        goals = g;
    }
// Constructor soccer athlete whit all values
    soccerAthlete(int nu, char t[10], char pt[10], int g, int p, int s, char n[15], float ph) {
        num = nu;
        strcpy(team, t);
        strcpy(position, pt);
        goals = g;
        power = p;
        speed = s;
        strcpy(name, n);
        phone = ph;
    }

    void upSpeed() override {
        speed += 3;
        power --;
    }

// Get and Set values
    int getNum() { return num; }
    void setNum(int nu) { num = nu; }

// Overload
    int getGoals() { return goals; } 
    void upGoals() { goals++; }
    void upGoals(int g) { goals += g; }

// Show athlete attributes and soccer attributes
    void showSoccerAtt() {
        showAttributes();
        cout << "Athlete number: " << num << endl;
        cout << "Athlete team: " << team << endl;
        cout << "Athlete posittion: " << position << endl;
        cout << "Athlete goals: " << goals << endl << endl ;
    }

};

class swimmerAthlete: public athlete {
private:
    int goldMedal;
    int silverMedal;
    int bronzeMedal;
    char style[15];
public:
    swimmerAthlete() : athlete(){
        goldMedal = 0;
        silverMedal = 0;
        bronzeMedal = 0;
    }
    swimmerAthlete(int gold,int silver,int bronze,char sty[15], int p, int s, char n[15]) {
        goldMedal = gold;
        silverMedal = silver;
        bronzeMedal = bronze;
        strcpy(style, sty);
        power = p;
        speed = s;
        strcpy(name, n);
    }

    void upSpeed() override {
        speed += 2;
        power --;
    }

    void setStyle( char sty[15] ) { strcpy(style, sty); }
    char* getStyle() { return style; }

    void showSwimmerAtt() {
        showAttributes();
        cout << "Athlete gold medals: " << goldMedal << endl;
        cout << "Athlete silver medals: " << silverMedal << endl;
        cout << "Athlete bronze medals: " << bronzeMedal << endl;
        cout << "Athlete style: " << style << endl << endl;
    }
};

class cyclistAthlete: public athlete {
private:
    int medalsCount;

public: 
    cyclistAthlete() :athlete(){
        medalsCount = 0;
    }
    cyclistAthlete(int mC, int p, int s, char n[15]) {
        medalsCount = mC;
        power = p;
        speed = s;
        strcpy(name, n);
    }

    void upSpeed() override {
        speed += 5;
        power --;
    }

    void eat(char food[15]) { 
        cout << "Cyclist eating "<< food << endl; 
        power ++;
    }

    void showCyclistAtt() {
        showAttributes();
        cout << "Athlete medals count: " << medalsCount << endl << endl;
    }

};

class runnerAthlete: public athlete {
private: 
    float maxSpeed;

public: 
    runnerAthlete() :athlete(){
        maxSpeed = 0;
    }
    runnerAthlete(int ms, int p, int s, char n[15]) {
        maxSpeed = ms;
        power = p;
        speed = s;
        strcpy(name, n);
    }

    void upSpeed() override {
        speed += 4;
        power --;
    }

    void setMaxSpeed(float ms) { maxSpeed = ms; }
    int getMaxSpeed() { return maxSpeed; }

    void showRunnerAtt() {
        showAttributes();
        cout << "Athlete max speed: " << maxSpeed << endl << endl;
    }
};

void loadAthlete( athlete* ath) {
    ath->setPower(100);
}

int main(){
    // String Auxiliary variables //
    char name[15];
    char team[15];
    char position[15];
    char style[15];

    // Create Bolt Athlete //
    // strcpy(name, "Bolt");
    // athlete Bolt(150, 10, name);
    // Bolt.setPhone();
    // Bolt.showAttributes();

    // Create Jordan Athlete //
    // strcpy(name, "Jordan");
    // athlete *Jordan = new athlete(30, 15, name);
    // Jordan->showAttributes();
    // delete Jordan;

    // Create Soccer Athlete //
    // strcpy(team, "Paris");
    // strcpy(position, "D.L");
    // strcpy(name, "Messi");
    // soccerAthlete Messi(10, team, position, 14, 150, 10, name, 33);
    // cout << Messi.getGoals() <<endl;
    // Messi.upGoals();
    // Messi.upGoals(10);
    // Messi.showAttributes();
    // Messi.showSoccerAtt();

    // Create Swimmer Athlete //
    strcpy(name, "Felps");
    strcpy(style, "Crol");
    swimmerAthlete Felps(1, 2, 0, style, 100, 100, name);
    Felps.upSpeed();
    Felps.showSwimmerAtt();

    // Create Cyclist Athlete //
    strcpy(name, "Ricardo");
    cyclistAthlete Ricardo(10, 100, 100, name);
    Ricardo.upSpeed();
    Ricardo.showCyclistAtt();

    // Create Runer Athlete //
    strcpy(name, "Bolt");
    runnerAthlete Bolt(200, 100, 100, name);
    Bolt.upSpeed();
    Bolt.showRunnerAtt();

    // Objetos en funcion power = 100//
    loadAthlete(&Bolt);
    Bolt.showAttributes();

    loadAthlete(&Ricardo);
    Ricardo.showAttributes();

    loadAthlete(&Felps);
    Felps.showAttributes();

}
