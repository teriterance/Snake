#include "soldier.hpp"

// attribut de point
Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}

int Point::get_x(){
    return x;
}

int Point::get_y(){
    return y;
}

void Point::set_x(int x){
    this->x = x;
}

void Point::set_y(int y){
    this->y = y;
}


// attribut de balle
Ball::Ball(char direction, int pos_x, int pos_y, int size = 3):Point(pos_x, pos_y){
    this->size = size;
    this->dir = direction;
    this->size_ = sf::Vector2f(size, size);
}

void Ball::move( char direction ){
    switch (direction)
    {
        case 'L':
            /* code */
            this->x = this->x - this->size;
            break;
        case 'R':
            /* code */
            this->x = this->x + this->size;
            break;
        case 'U':
            /* code */
            this->y = this->y - this->size;
            break;
        case 'D':
            /* code */
            this->y = this->y + this->size;
            break;
        default:
            break;
    }
}

void Ball::draw( sf::RenderWindow* window ){
    sf::RectangleShape rectangle;
    rectangle.setSize(this->size_);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setPosition(this->x, this->y);
    window->draw(rectangle);
}


// attribut de solda
Solda::Solda(int pos_x, int pos_y, int taille_x, int taille_y, int size_){
    this->size = sf::Vector2f(this->size_, this->size_);

    //fabrique du personnage
    this->dir = 'U';
    this->positions.push_back(new Point(pos_x, pos_y - this->size_));
    this->positions.push_back(new Point(pos_x - this->size_, pos_y));

    this->positions.push_back(new Point(pos_x, pos_y));
    this->positions.push_back(new Point(pos_x + this->size_, pos_y));
    
    this->positions.push_back(new Point(pos_x - this->size_, pos_y + this->size_));
    this->positions.push_back(new Point(pos_x + this->size_, pos_y + this->size_));

    //Rotation aleatoire

}

void Solda::rotate(char direction){
    int pos_x = this->positions[3]->get_x();
    int pos_y = this->positions[3]->get_y();

    this->positions.clear();
    
    switch (direction)
    {
    case 'R':
        /* code */
        this->positions.push_back(new Point(pos_x + this->size_, pos_y ));
        this->positions.push_back(new Point(pos_x , pos_y - this->size_));

        this->positions.push_back(new Point(pos_x, pos_y));
        this->positions.push_back(new Point(pos_x, pos_y + this->size_));
    
        this->positions.push_back(new Point(pos_x - this->size_, pos_y - this->size_));
        this->positions.push_back(new Point(pos_x + this->size_, pos_y + this->size_));
        break;
    
    case 'L':
        /* code */
        this->positions.push_back(new Point(pos_x - this->size_, pos_y ));
        this->positions.push_back(new Point(pos_x, pos_y + this->size_));

        this->positions.push_back(new Point(pos_x, pos_y));
        this->positions.push_back(new Point(pos_x, pos_y - this->size_));
    
        this->positions.push_back(new Point(pos_x + this->size_, pos_y + this->size_));
        this->positions.push_back(new Point(pos_x - this->size_, pos_y + this->size_));
        break;

    case 'U':
        /* code */
        this->positions.push_back(new Point(pos_x, pos_y - this->size_));
        this->positions.push_back(new Point(pos_x - this->size_, pos_y));

        this->positions.push_back(new Point(pos_x, pos_y));
        this->positions.push_back(new Point(pos_x + this->size_, pos_y));
    
        this->positions.push_back(new Point(pos_x - this->size_, pos_y + this->size_));
        this->positions.push_back(new Point(pos_x + this->size_, pos_y + this->size_));
        break;

    case 'D':
        /* code */
        this->positions.push_back(new Point(pos_x, pos_y + this->size_));
        this->positions.push_back(new Point(pos_x + this->size_, pos_y));

        this->positions.push_back(new Point(pos_x, pos_y));
        this->positions.push_back(new Point(pos_x - this->size_, pos_y));
    
        this->positions.push_back(new Point(pos_x - this->size_, pos_y - this->size_));
        this->positions.push_back(new Point(pos_x + this->size_, pos_y - this->size_));
        break;

    default:
        break;
    }
}

void Solda::move(char direction){
    if (direction == this->dir){
        this->goStrait();
    }else
    {
        this->rotate(direction);
    }

}

void Solda::goStrait(){
    
    switch (this->dir)
    {
    case 'U':
        /* code */
        for(int i = 0; i < this->positions.size() ; i++){
            this->positions[i]->set_y( this->positions[i]->get_y() - this->size_ );
        }
        break;
    
    case 'D':
        /* code */
        for(int i = 0; i < this->positions.size() ; i++){
            this->positions[i]->set_y( this->positions[i]->get_y() + this->size_ );
        }
        break;
    
    case 'L':
        /* code */
        for(int i = 0; i < this->positions.size() ; i++){
            this->positions[i]->set_x( this->positions[i]->get_x() - this->size_ );
        }
        break;
    
    case 'R':
        /* code */
        for(int i = 0; i < this->positions.size() ; i++){
            this->positions[i]->set_x( this->positions[i]->get_x() + this->size_ );
        }
        break;
    default:
        break;
    }
}
    
Ball* Solda::shoot(){
    switch (this->dir)
    {
    case 'U':
        /* code */
        return new Ball('U', this->positions[1]->get_x(), this->positions[1]->get_y() + this->size_);
        break;
    
    case 'D':
        /* code */
        return new Ball('D', this->positions[1]->get_x(), this->positions[1]->get_y() - this->size_);
        break;
    
    case 'L':
        /* code */
        return new Ball('U', this->positions[1]->get_x() - this->size_, this->positions[1]->get_y());
        break;
    
    case 'R':
        /* code */
        return new Ball('U', this->positions[1]->get_x() + this->size_, this->positions[1]->get_y());
        break;
    default:
        break;
    }
}
        
void Solda::draw(sf::RenderWindow* window){
    for(int i = 0; i < this->positions.size(); i++){
        sf::RectangleShape rectangle;
        rectangle.setSize(this->size);
        rectangle.setOutlineColor(sf::Color::Red);
        rectangle.setPosition(this->positions[i]->get_x(), this->positions[i]->get_y());
        window->draw(rectangle);
    }
}
    
bool Solda::estMort(){
    return this->estVivant;
}
