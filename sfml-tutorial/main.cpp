#include <SFML/Graphics.hpp>

#define AMPLITUDE   512   // pixels
#define ANG_VEL     1.f   // s^(-1)
#define RADIUS      100.f // pixels
#define FPS         60    // frames per second

int main()
{
  sf::RenderWindow window(sf::VideoMode(1024, 1024), "SFML works!");
  window.setFramerateLimit(FPS);

  sf::RectangleShape shape(sf::Vector2f(RADIUS, RADIUS));
  shape.setFillColor(sf::Color::Green);
  bool right = true;

  shape.setOrigin(RADIUS / 2, RADIUS / 2);
  shape.setPosition(200.0f, 200.0f);

  //Euler formula
  float velocity = ANG_VEL * RADIUS; // pixels per second

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    if (right) {
      shape.move(velocity / FPS, 0.f); // velocity in pixels per frame
      shape.rotate(ANG_VEL * 180 / (3.14 * FPS));
      if (shape.getPosition().x >= AMPLITUDE + 200.f)
        right = false;
    }
    else {
      shape.move(-velocity / FPS, 0.f);
      shape.rotate(-ANG_VEL * 180 / (3.14 * FPS));
      if (shape.getPosition().x < 200.f)
        right = true;
    }


    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}