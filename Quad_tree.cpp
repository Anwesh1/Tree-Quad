#include <iostream>
#include <string>
#include <limits>
#include "node.cpp"

class Quad{
    private:
    Node *root = NULL;
    public:
    Quad();
    Node *get_root();
    bool set_root(Node *set);
    Node *convert(std::string Name, double Lon, double Lat, long Pop, double Cost, double Sal);
    Node *insert(Node *ins, Node *comp);
    Node *search(Node *rt, double Lon, double Lat);
    double q_max(Node *use, std::string attr);
    double q_min(Node *use, std::string attr);
    double q_total(Node *use, std::string attr);
    long q_max_p(Node *use, std::string attr);
    long q_min_p(Node *use, std::string attr);
    long q_total_p(Node *use, std::string attr);
    std::string print(Node *pr);
    void clear(Node *del);
    long size(Node *use);
};

Node *Quad::get_root(){
    return root;
}

bool Quad::set_root(Node *set){
    root = set;
    return true;
}

Quad::Quad(){
    root = NULL;
}

Node *Quad::convert(std::string N, double Lon, double Lat, long Pop, double C, double Sal){
    Node *use = new Node(N, Lon, Lat, Pop, C, Sal);
    return use;
}

Node *Quad::insert(Node *ins, Node *comp){
    if(root == NULL){
        root = ins;
        std::cout << "success" << std::endl;
        return root;
    }
    if(comp == NULL){
        std::cout << "success" << std::endl;
        return ins;
    }
    if (ins->Longitude == comp->Longitude && ins->Latitude == comp->Latitude){
        std::cout << "failure" << std::endl;
        delete ins;
        return comp;
    }
    if (ins->Longitude >= comp->Longitude && ins->Latitude > comp->Latitude){
        comp->NE = insert(ins, comp->NE);
        return comp;
    }
    if (ins->Longitude < comp->Longitude && ins->Latitude >= comp->Latitude){
        comp->NW = insert(ins, comp->NW);
        return comp;
    }
    if (ins->Longitude <= comp->Longitude && ins->Latitude < comp->Latitude){
        comp->SW = insert(ins, comp->SW);
        return comp;
    }
    if (ins->Longitude > comp->Longitude && ins->Latitude <= comp->Latitude){
        comp->SE = insert(ins, comp->SE);
        return comp;
    }
}

Node *Quad::search(Node *rt, double Lon, double Lat){
    if (rt == NULL){
        return NULL;
    }
    if (rt->Longitude == Lon && rt->Latitude == Lat){
        return rt;
    }
    Node *checkNE = search(rt->NE, Lon, Lat);
    if (checkNE) return checkNE;
    Node *checkNW = search(rt->NW, Lon, Lat);
    if (checkNW) return checkNW;
    Node *checkSW = search(rt->SW, Lon, Lat);
    if (checkSW) return checkSW;
    Node *checkSE = search(rt->SE, Lon, Lat);
    if (checkSE) return checkSE;
    return NULL;
}

long Quad::q_max_p(Node *use, std::string attr){
    if(use == NULL){
        return 0;
    }
    if (attr == "p"){
        long maxNE = q_max_p(use->NE, "p");
        long maxNW = q_max_p(use->NW, "p");
        long maxSE = q_max_p(use->SE, "p");
        long maxSW = q_max_p(use->SW, "p");
        long maxN = std::max(maxNE,maxNW);
        long maxS = std::max(maxSE,maxSW);
        long max = std::max(maxN, maxS);
        long final = std::max(max, use->Population);
        return final;
    }
}

double Quad::q_max(Node *use, std::string attr){
    if(use == NULL){
        return 0;
    }
    if (attr == "s"){
        double maxNE = q_max(use->NE, "s");
        double maxNW = q_max(use->NW, "s");
        double maxSE = q_max(use->SE, "s");
        double maxSW = q_max(use->SW, "s");
        double maxN = std::max(maxNE,maxNW);
        double maxS = std::max(maxSE,maxSW);
        double max = std::max(maxN, maxS);
        double final = std::max(max, use->Salary);
        return final;
    }
    if (attr == "r"){
        double maxNE = q_max(use->NE, "r");
        double maxNW = q_max(use->NW, "r");
        double maxSE = q_max(use->SE, "r");
        double maxSW = q_max(use->SW, "r");
        double maxN = std::max(maxNE,maxNW);
        double maxS = std::max(maxSE,maxSW);
        double max = std::max(maxN, maxS);
        double final = std::max(max, use->Cost);
        return final;
    }
}

long Quad::q_min_p(Node *use, std::string attr){
    if(use == NULL){
        return std::numeric_limits<long>::max();
    }
    if (attr == "p"){
        long maxNE = q_min_p(use->NE, "p");
        long maxNW = q_min_p(use->NW, "p");
        long maxSE = q_min_p(use->SE, "p");
        long maxSW = q_min_p(use->SW, "p");
        long maxN = std::min(maxNE,maxNW);
        long maxS = std::min(maxSE,maxSW);
        long max = std::min(maxN, maxS);
        long final = std::min(max, use->Population);
        return final;
    }
}

double Quad::q_min(Node *use, std::string attr){
    if(use == NULL){
        return std::numeric_limits<double>::max();
    }
    if (attr == "s"){
        double maxNE = q_min(use->NE, "s");
        double maxNW = q_min(use->NW, "s");
        double maxSE = q_min(use->SE, "s");
        double maxSW = q_min(use->SW, "s");
        double maxN = std::min(maxNE,maxNW);
        double maxS = std::min(maxSE,maxSW);
        double max = std::min(maxN, maxS);
        double final = std::min(max, use->Salary);
        return final;
    }
    if (attr == "r"){
        double maxNE = q_min(use->NE, "r");
        double maxNW = q_min(use->NW, "r");
        double maxSE = q_min(use->SE, "r");
        double maxSW = q_min(use->SW, "r");
        double maxN = std::min(maxNE,maxNW);
        double maxS = std::min(maxSE,maxSW);
        double max = std::min(maxN, maxS);
        double final = std::min(max, use->Cost);
        return final;
    }
}

long Quad::q_total_p(Node *use, std::string attr){
    if(use == NULL){
        return 0;
    }
    if (attr == "p"){
        long total = use->Population + q_total_p(use->NE, "p") + q_total_p(use->NW, "p") + q_total_p(use->SE, "p") + q_total_p(use->SW, "p");
        return total;
    }
}

double Quad::q_total(Node *use, std::string attr){
    if(use == NULL){
        return 0;
    }
    if (attr == "s"){
        double total = use->Salary + q_total(use->NE, "s") + q_total(use->NW, "s") + q_total(use->SE, "s") + q_total(use->SW, "s");
        return total;
    }
    if (attr == "r"){
        double total = use->Cost + q_total(use->NE, "r") + q_total(use->NW, "r") + q_total(use->SE, "r") + q_total(use->SW, "r");
        return total;
    }
}

std::string Quad::print(Node *pr){
    if (pr == NULL) return "";
    std::string name = print(pr->NE) + print(pr->NW) + pr->Name + " " + print(pr->SW) + print(pr->SE);
    return name;
}

long Quad::size(Node *use){
    if (use == NULL){
        return 0;
    } 
    else {
        return (size(use->NE) + size(use->NW) + 1 + size(use->SW) + size(use->SE));
    }
}

void Quad::clear(Node *del){
    if (del == NULL) return;
    clear(del->NE);
    clear(del->NW);
    clear(del->SW);
    clear(del->SE);
    delete del;
}

