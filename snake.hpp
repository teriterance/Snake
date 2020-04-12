#include <vector>
#include <ostream>
#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Point
{
    /* data */
    public:
        Point(int x, int y){
            this->x = x;
            this->y = y;
        }
        int get_x(){
            return x;
        }
        int get_y(){
            return y;
        }

        void set_x(int x){
            this->x = x;
        }
        void set_y(int y){
            this->y = y;
        }
    private:
        int x;
        int y;
};


class Snake{
    
    public:
    Snake(int pos_x, int pos_y, int taille_x, int taille_y);

    void move(char direction);
    
    void eat();

    void draw(sf::RenderWindow* window);

    bool canEat(sf::Shape* s);

    bool estMort();

    Point getPosfirst();

    private:
    std::vector<Point *> positions;
    sf::RenderWindow* window;

    int mortOuVif = false;
    int taille_X;
    int taille_Y;
    int taille_car = 10;
    sf::Vector2f size = sf::Vector2f(10, 10);

    void mourir();

    void moveAll();

    void grandir();
};