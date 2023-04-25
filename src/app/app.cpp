#include "pch.h"
#include "GameOfLife.h"

int WINAPI WinMain(
    [[maybe_unused]] _In_ HINSTANCE hInstance,
    [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance,
    [[maybe_unused]] _In_ LPSTR lpCmdLine,
    [[maybe_unused]] _In_ int nShowCmd
)
{
    [[maybe_unused]] GameOfLife game{400, 400};

    sf::RenderWindow window(sf::VideoMode(game.GetWidth(), game.GetHeight()), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return ERROR_SUCCESS;
}
