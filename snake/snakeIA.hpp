#include "snake.hpp"


class SnakeAI: public Snake{
    private:
    
    public:
    SnakeAI(int pos_x, int pos_y, int taille_x, int taille_y);

    void move(float x, float y, Snake &s);

    private:

    char astar(float x, float y);
    void constructInf(std::map<std::pair<float, float>, float> &g);
};