#include "game.hpp"

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    Snake snake(100, 100, 200, 200);

    sf::CircleShape cible(5.f);
    cible.setFillColor(sf::Color::Green);
    cible.setPosition(100, 100);

    char dir = 'L';

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if ( !snake.estMort() ){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (dir != 'R')
                    dir = 'L';
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {   if (dir != 'L')
                    dir = 'R';
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if (dir != 'D')
                    dir = 'U';
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                if (dir != 'U')
                    dir = 'D';
            }
            snake.move(dir);

            if (snake.canEat((sf::Shape*)&cible)){
                snake.eat();
                int x = rand()%195;
                int y = rand()%195;
                cible.setPosition(x, y);
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            window.clear();
            snake.draw(&window);
            window.draw(cible);
        }
        else{
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            {
                snake = Snake(100, 100, 200, 200);
            }
        }
        window.display();
    }
    return 0;
}