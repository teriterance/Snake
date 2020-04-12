#include "snake.hpp"
#include <iostream>

Snake::Snake(int pos_x, int pos_y, int taille_x, int taille_y){
        this->positions.push_back(new Point(pos_x, pos_y));
        this->taille_X = taille_x;
        this->taille_Y = taille_y;
}

void Snake::move(char direction){

    this->moveAll();

    switch (direction)
    {
    case 'L':
        this->positions[0]->set_x( this->positions[0]->get_x() - this->taille_car );
        break;
    case 'R':
        this->positions[0]->set_x( this->positions[0]->get_x() + this->taille_car );
        break;
    case 'U':
        this->positions[0]->set_y( this->positions[0]->get_y() - this->taille_car );
        break;
    case 'D':
        this->positions[0]->set_y( this->positions[0]->get_y() + this->taille_car );
        break;
    default:
        break;
    }

    // cas de mort 
    if( this->positions[0]->get_x() >= this->taille_X || this->positions[0]->get_y() >= this->taille_Y || this->positions[0]->get_x() < 0 || this->positions[0]->get_y() < 0 ){
        this->mortOuVif = true;
    }

    for(int i = 1; i < this->positions.size(); i++){
        float a = this->positions[i]->get_x() - this->positions[0]->get_x();
        float b = this->positions[i]->get_y() - this->positions[0]->get_y();

        if ( a*a + b*b < 5 ){
            this->mortOuVif = true;
            break;
        }
    }
}

bool Snake::canEat(sf::Shape* s){
    sf::Vector2f vec = s->getPosition();
    float a = vec.x - (float)this->positions[0]->get_x();
    float b = vec.y - (float)this->positions[0]->get_y();

    if ( (a*a + b*b) <= 50){
        return true;
    }
    return false;
}

void Snake::eat(){
    this->grandir();
}

void Snake::draw(sf::RenderWindow* window){
    for(int i = 0; i < this->positions.size(); i++){
        sf::RectangleShape rectangle;
        rectangle.setSize(this->size);
        rectangle.setOutlineColor(sf::Color::Red);
        rectangle.setPosition(this->positions[i]->get_x(), this->positions[i]->get_y());
        window->draw(rectangle);
    }
}

bool Snake::estMort(){
    return this->mortOuVif;
}

void Snake::mourir(){
    this->mortOuVif = true;
}

Point Snake::getPosfirst(){
    return *this->positions[0];
}

void Snake::moveAll(){
    for(int i = this->positions.size() - 1; i > 0  ; i--){
        this->positions[i]->set_x( this->positions[i - 1]->get_x() );
        this->positions[i]->set_y( this->positions[i - 1]->get_y() );
    }
}

void Snake::grandir(){
    this->positions.push_back(new Point(this->positions[0]->get_x(), this->positions[0]->get_y()));
}