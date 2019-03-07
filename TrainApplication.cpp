#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;
 
class CAR // class for train cars
{
        public:
            CAR(); // constructor
            int getWeight(); // returns the weight of the car in pounds
            void loadCar(int); // loads a cargo with parameter weight
            CAR *nextCar; // pointer to the next car on the train
 
        private:
            int cargoWeight; // the weight of the trains cargo
};
 
class TRAIN // train class as a linked list of cars
{
 
        private:
            int trainWeight;
 
        public:
            TRAIN(); //constructor
            int getWeight(); // returns the weight of the train
            void loadTrain(); // load train with initial cars
            void addCar_front(int);
            void addCar_end(int); // THIS IS CODE YOU MUST WRITE//
            ~TRAIN(); // destructor THIS IS CODE YOU MUST WRITE
            void displayTrainInfo();
            CAR *firstCar;
};
 
int main()
{
           TRAIN MetroLiner;
           cout << "PROGRAM OUTPUT:" << endl;
           MetroLiner.loadTrain();
           MetroLiner.displayTrainInfo();
           //system("pause");
           return 0;
}
 
CAR::CAR ()
{
           cargoWeight = 75;
           nextCar = NULL;
}
 
int CAR::getWeight()
{
            return cargoWeight;
}
 
void CAR::loadCar (int cargo)
{
            cargoWeight = cargo;
}
 
TRAIN::TRAIN()
{
            trainWeight = 0;
            firstCar = NULL;
}
TRAIN::~TRAIN()
{           while (firstCar -> nextCar != NULL)
            {
                CAR *Temp = firstCar -> nextCar;
                delete firstCar;
                firstCar = Temp;
                displayTrainInfo();
            }
}
 
int TRAIN::getWeight() // returns the train weight
{
            return trainWeight;
}
 
void TRAIN::loadTrain() // load train with initial cars
 
{
            addCar_front(0); // add first car
            addCar_front(10);
            addCar_front(20);
            addCar_front(30);
            addCar_front(40);
            addCar_front(50);
            addCar_front(60);
            addCar_end(60);
            addCar_end(30);
            addCar_end(40);
}
 
void TRAIN::addCar_front (int cWeight) // add first car to train
{
            CAR* carptr = firstCar;
            firstCar = new CAR;
            firstCar -> nextCar = carptr;
            firstCar -> loadCar(cWeight);
}
void TRAIN::addCar_end (int cWeight) // add car to end
{
            if (firstCar==NULL)
            {
                this -> addCar_front(cWeight);
            }
            else
            {
                CAR* cursor;
                for (cursor = firstCar; cursor -> nextCar != NULL; )
                    cursor = cursor -> nextCar;
                    cursor -> nextCar = new CAR;
                    cursor -> nextCar -> loadCar(cWeight);
                    cursor -> nextCar -> nextCar = NULL;
            }
}
 
void TRAIN::displayTrainInfo()
{
    int cnt = 0;
    CAR* ptrCar;
    for (ptrCar = firstCar; ptrCar != NULL && ++cnt <11; ptrCar = ptrCar->nextCar)
        cout << "+-------+  ";
        cout << endl;
    cnt = 0;
    for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 11; ptrCar = ptrCar->nextCar)
        cout << "|       |  ";
        cout << endl; cnt = 0;
    for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 11; ptrCar = ptrCar->nextCar)
    {
        if ((*ptrCar).getWeight() < 10)
            cout << "|   " << (*ptrCar).getWeight() << "   |->";  else    cout << "|   " <<
                (*ptrCar).getWeight() << "  |->";
    }
    cout << endl; cnt = 0;
    for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 11; ptrCar = ptrCar->nextCar)
        cout << "|       |  ";
    cout << endl;
    cnt = 0;
    for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 11; ptrCar = ptrCar->nextCar)
        cout << "+-------+  ";
    cout << endl;
}
 
/*
PROGRAM OUTPUT:
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
|   60  |->|   50  |->|   40  |->|   30  |->|   20  |->|   10  |->|   0   |->|   60  |->|   30  |->|   40  |->
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
|   50  |->|   40  |->|   30  |->|   20  |->|   10  |->|   0   |->|   60  |->|   30  |->|   40  |->
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
|   40  |->|   30  |->|   20  |->|   10  |->|   0   |->|   60  |->|   30  |->|   40  |->
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
|       |  |       |  |       |  |       |  |       |  |       |  |       |
|   30  |->|   20  |->|   10  |->|   0   |->|   60  |->|   30  |->|   40  |->
|       |  |       |  |       |  |       |  |       |  |       |  |       |
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+
|       |  |       |  |       |  |       |  |       |  |       |
|   20  |->|   10  |->|   0   |->|   60  |->|   30  |->|   40  |->
|       |  |       |  |       |  |       |  |       |  |       |
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+
+-------+  +-------+  +-------+  +-------+  +-------+
|       |  |       |  |       |  |       |  |       |
|   10  |->|   0   |->|   60  |->|   30  |->|   40  |->
|       |  |       |  |       |  |       |  |       |
+-------+  +-------+  +-------+  +-------+  +-------+
+-------+  +-------+  +-------+  +-------+
|       |  |       |  |       |  |       |
|   0   |->|   60  |->|   30  |->|   40  |->
|       |  |       |  |       |  |       |
+-------+  +-------+  +-------+  +-------+
+-------+  +-------+  +-------+
|       |  |       |  |       |
|   60  |->|   30  |->|   40  |->
|       |  |       |  |       |
+-------+  +-------+  +-------+
+-------+  +-------+
|       |  |       |
|   30  |->|   40  |->
|       |  |       |
+-------+  +-------+
+-------+
|       |
|   40  |->
|       |
+-------+
*/
