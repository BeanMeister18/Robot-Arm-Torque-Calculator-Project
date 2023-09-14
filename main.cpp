#include <iostream>
#include <cmath>
#include <iomanip>

//L3 can't be more than like .84
using namespace std;

//LOAD CONSTANTS
const double M1 = 4;
const double M2 = 2;
const double M3 = 1;
const double LOAD = -5*9.81;



double case1(double len1, double len2, double len3){
    double force1 = -M1 * len1 * 9.81;
    double force2 = -M2 * len2 * 9.81;
    double force3 = -M3 * len3 * 9.81;

    cout << "----------CASE 1----------" << endl;
    double x3 = 0.75;
    double y3 = 0.1;

    double x2 = x3 - len3*(cos(M_PI/3));
    double y2 = y3 + len3*(sin(M_PI/3));

    double length0 = sqrt(pow(x2, 2) + pow(y2, 2));


    //calculating angles of each
    double angle0to1 = acos((-pow(len2, 2) + pow(len1, 2) + pow(length0, 2))/(2*length0*len1));
    double q1 = atan2(y2, x2) + angle0to1; //FIRST ARM ANGLE

    double angle1to2 = acos((pow(length0,2) - pow(len1, 2) - pow(len2, 2))/(-2*len1*len2));
    double q2 = angle1to2 - M_PI + q1; //SECOND ARM ANGLE

    cout << "Angle Q1 = " << q1 << " RADIANS" << endl;
    cout << "Angle Q2 = " << q2 << " RADIANS" << endl;
    cout << "Angle Q3 = PI/3 RADIANS" << endl;


    //Getting Coordinates
    double x1 = len1 * cos(q1);
    double y1 = len2 * sin(q1);

    if(y1 < 0 || y2 < 0 || y3 < 0){
        cout << "One of the arms goes below x-axis, try again.\n";
        return 0;
    }


    //Getting moments of all joints
    double moment1 = force1 * (x1/2);
    double moment2 = force2 * (x1 + x2)/2;
    double moment3 = force3 * (x2 + x3)/2;
    double momentTip = LOAD*x3;

    cout << "Total Moment For Case One: " << moment1 + moment2 + moment3 + momentTip << endl << endl;
    return moment1 + moment2 + moment3 + momentTip;
}



double case2(double len1, double len2, double len3){
    double force1 = -M1 * len1 * 9.81;
    double force2 = -M2 * len2 * 9.81;
    double force3 = -M3 * len3 * 9.81;

    cout << "----------CASE 2----------" << endl;
    double x3 = 0.5;
    double y3 = 0.5;

    double x2 = x3 - len3*(cos(0)); //can remove 0
    double y2 = y3 + len3*(sin(0));

    double length0 = sqrt(pow(x2, 2) + pow(y2, 2));


    //calculating angles of each
    double angle0to1 = acos((-pow(len2, 2) + pow(len1, 2) + pow(length0, 2))/(2*length0*len1));
    double q1 = atan2(y2, x2) + angle0to1; //FIRST ARM ANGLE

    double angle1to2 = acos((pow(length0,2) - pow(len1, 2) - pow(len2, 2))/(-2*len1*len2));
    double q2 = angle1to2 - M_PI + q1; //SECOND ARM ANGLE

    cout << "Angle Q1 = " << q1 << " RADIANS" << endl;
    cout << "Angle Q2 = " << q2 << " RADIANS" << endl;
    cout << "Angle Q3 = 0 RADIANS" << endl;


    //Getting Coordinates
    double x1 = len1 * cos(q1);
    double y1 = len2 * sin(q1);


    if(y1 < 0 || y2 < 0 || y3 < 0){
        cout << "One of the arms goes below x-axis, try again.\n";
        return 0;
    }


    //Getting moments of all joints
    double moment1 = force1 * (x1/2);
    double moment2 = force2 * (x1 + x2)/2;
    double moment3 = force3 * (x2 + x3)/2;
    double momentTip = LOAD*x3;

    cout << "Total Moment For Case Two: " << moment1 + moment2 + moment3 + momentTip << endl << endl;
    return moment1 + moment2 + moment3 + momentTip;

}



double case3(double len1, double len2, double len3){
    double force1 = -M1 * len1 * 9.81;
    double force2 = -M2 * len2 * 9.81;
    double force3 = -M3 * len3 * 9.81;

    cout << "----------CASE 3----------" << endl;
    double x3 = 0.2;
    double y3 = 0.6;

    double x2 = x3 - len3*(cos(M_PI/4));
    double y2 = y3 - len3*(sin(M_PI/4));

    double length0 = sqrt(pow(x2, 2) + pow(y2, 2));


    //calculating angles of each
    double angle0to1 = acos((-pow(len2, 2) + pow(len1, 2) + pow(length0, 2))/(2*length0*len1));
    double q1 = atan2(y2, x2) + angle0to1; //FIRST ARM ANGLE

    double angle1to2 = acos((pow(length0,2) - pow(len1, 2) - pow(len2, 2))/(-2*len1*len2));
    double q2 = angle1to2 - M_PI + q1; //SECOND ARM ANGLE

    cout << "Angle Q1 = " << q1 << " RADIANS" << endl;
    cout << "Angle Q2 = " << q2 << " RADIANS" << endl;
    cout << "Angle Q3 = PI/4 RADIANS" << endl;


    //Getting Coordinates
    double x1 = len1 * cos(q1);
    double y1 = len2 * sin(q1);


    if(y1 < 0 || y2 < 0 || y3 < 0){
        cout << "One of the arms goes below x-axis, try again.\n";
        return 0;
    }


    //Getting moments of all joints
    double moment1 = force1 * (x1/2);
    double moment2 = force2 * (x1 + x2)/2;
    double moment3 = force3 * (x2 + x3)/2;
    double momentTip = LOAD*x3;

    cout << "Total Moment For Case Three: " << moment1 + moment2 + moment3 + momentTip << endl << endl;
    return moment1 + moment2 + moment3 + momentTip;
}



 int main(){
     double l1;
     double l2;
     double l3;

     cout << "**********INPUT**********" << endl << "Enter 3 lengths." << endl;
     cout << "L1:";
     cin >> l1;
     cout << "L2:";
     cin >> l2;
     cout << "L3:";
     cin >> l3;

     double case1Result = case1(l1, l2, l3);
     double case2Result = case2(l1, l2, l3);
     double case3Result = case3(l1, l2, l3);


    double T = sqrt(pow(case1Result,2) + pow(case2Result,2) + pow(case3Result, 2));
    cout << endl << endl << "TOTAL TORQUE: " << T;
    }

