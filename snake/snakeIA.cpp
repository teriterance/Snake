#include "snakeIA.hpp"
#include <map>
#include <vector>
#include <limits>
#include <cmath>
SnakeAI::SnakeAI(int pos_x, int pos_y, int taille_x, int taille_y):Snake(pos_x, pos_y, taille_x, taille_y){

}

void SnakeAI::constructInf( std::map<std::pair<float, float>, float> &g){
    for(int i=0; i < this->taille_X; i=i+10){
        for(int j=0; j < this->taille_Y; j=j+10){
            g.insert( std::pair<std::pair<float, float>, float>
                        (std::pair<float, float>(static_cast<float>(i), static_cast<float>(i)),
                        std::numeric_limits<float>::max()));
        }
    }
}

char SnakeAI::astar(float x, float y){
    std::vector<std::pair<float, float>> openSet;
    openSet.push_back(std::pair<float,float>(x,y)); // openSet:={start}

    std::map<std::pair<float, float>, std::pair<float, float>> cameFrom; //empty map

    std::map<std::pair<float, float>, float> gScore;
    this->constructInf( gScore );
    gScore[std::pair<float, float>(x, y)] = 0;
    
    std::map<std::pair<float, float>, float> fScore;
    this->constructInf( fScore );
    fScore[std::pair<float, float>(x, y)] = 0;

    while (!openSet.empty()){

        std::pair<float, float> current;
        std::pair<float, float> c = min_element(fScore.begin(), fScore.end(),
            [](const auto& l, const auto& r) { return l.second < r.second; })->first;
        
        if( std::find(openSet.begin(), openSet.end(), c) != openSet.end() ){
            current = c;
        }
        if(current == std::pair<float, float>(x, y)){
            std::pair<float, float> e = cameFrom[current];
            if(e.first == x+5){
                return 'L';
            }else{
                if(e.first == x-5 ){
                    return 'R';
                }
            }

            if(e.second == y+5){
                return 'D';
            }else{
                if(e.second == y-5 ){
                    return 'U';
                }
            }
        }
        auto it = std::find(openSet.begin(), openSet.end(), current);
        if(it != openSet.end()){
            openSet.erase(it);
        }

        std::vector<std::pair<float, float>> neigh = {
            std::pair<float, float>(x-5, y),
            std::pair<float, float>(x+5, y),
            std::pair<float, float>(x, y-5),
            std::pair<float, float>(x, y+5),
        };
        for(auto pa: neigh){
            float t_gScore = gScore[current] + sqrt(pow(pa.first - current.first, 2) +
                pow(pa.second - current.second, 2));

            if( t_gScore < gScore[current] ){
                cameFrom.insert(std::pair<std::pair<float, float>, std::pair<float, float>>(current, pa));
                gScore[current] = t_gScore;
                fScore[current] = t_gScore + 1;
                if( std::find(openSet.begin(), openSet.end(), pa) != openSet.end()){
                    openSet.push_back(current);
                }

            }
        }
    }    
}

void SnakeAI::move(float x, float y, Snake &s){

}
