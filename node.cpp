#include <iostream>
#include <string>

class Node{
    public:
    Node *NW, *NE, *SW, *SE;
    std::string Name;
    double Longitude;
    double Latitude;
    long Population;
    double Cost;
    double Salary;
    Node(std::string Name, double Lon, double Lat, long Pop, double Cost, double Sal);
};

Node::Node(std::string N, double Lon, double Lat, long Pop, double C, double Sal){
    Name = N;
    Longitude = Lon;
    Latitude = Lat;
    Population = Pop;
    Cost = C;
    Salary = Sal;
    NW = NE = SW = SE = NULL;
}
