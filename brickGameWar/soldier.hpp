#include <vector>
#include <ostream>
#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Point
{
    /* data */
    public:
        Point(int x, int y);
        int get_x();

        int get_y();

        void set_x(int x);

        void set_y(int y);
    protected:
        int x;
        int y;
};

class Ball : public Point{
    /* data */
    public:
        Ball(char direction, int size, int pos_x, int pos_y);
        void move( char direction );
        void draw( sf::RenderWindow* window );

    private:
        char dir;
        int size;
        sf::Vector2f size_;
};

class Solda{
    /* data */
    public:
        Solda(int pos_x, int pos_y, int taille_x, int taille_y, int size_ =100);

        void move(char direction);
        
        Ball* shoot();

        void draw(sf::RenderWindow* window);

        bool estMort();

    private:
        std::vector<Point *> positions;
        int size_;
        char dir;
        sf::Vector2f size;
        bool estVivant = true;

        void rotate(char direction);
        void goStrait();

        void mourir();
};