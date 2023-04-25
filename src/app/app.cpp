#include "pch.h"
#include "GameOfLife.h"
#include <format>

constexpr const int CELL_SIZE = 4;

int WINAPI WinMain([[maybe_unused]] _In_ HINSTANCE hInstance, [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance,
                   [[maybe_unused]] _In_ LPSTR lpCmdLine, [[maybe_unused]] _In_ int nShowCmd)
{
    GameOfLife game{ 400, 400 };

    game.SetCell(199, 199, true);
    game.SetCell(200, 200, true);
    game.SetCell(201, 201, true);

    sf::RenderWindow window(sf::VideoMode(game.GetWidth() * CELL_SIZE, game.GetHeight() * CELL_SIZE),
                            "Conway Game of Life");

    // Initialize the full map
    sf::VertexArray pixelmap{ sf::Quads, static_cast<size_t>(game.GetWidth()) * game.GetHeight() * 4 };
    for (int x = 0; x < game.GetWidth(); x++)
    {
        for (int y = 0; y < game.GetHeight(); y++)
        {
            sf::Vertex* quad = &pixelmap[(x + y * game.GetWidth()) * 4];
            quad[0].position = sf::Vector2f(static_cast<float>(x * CELL_SIZE), static_cast<float>(y * CELL_SIZE));
            quad[1].position = sf::Vector2f(static_cast<float>((x + 1) * CELL_SIZE), static_cast<float>(y * CELL_SIZE));
            quad[2].position =
                sf::Vector2f(static_cast<float>((x + 1) * CELL_SIZE), static_cast<float>((y + 1) * CELL_SIZE));
            quad[3].position = sf::Vector2f(static_cast<float>(x * CELL_SIZE), static_cast<float>((y + 1) * CELL_SIZE));

            quad[0].color = sf::Color::Black;
            quad[1].color = sf::Color::Black;
            quad[2].color = sf::Color::Black;
            quad[3].color = sf::Color::Black;
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }

        game.Generate();

        // Update the map
        for (int x = 0; x < game.GetWidth(); x++)
        {
            for (int y = 0; y < game.GetHeight(); y++)
            {
                sf::Vertex* quad = &pixelmap[(x + y * game.GetWidth()) * 4];
                quad[0].color = quad[1].color = quad[2].color = quad[3].color =
                    game.GetCell(x, y) ? sf::Color::Green : sf::Color::Black;
            }
        }

        window.setTitle(std::format("Generation {}", game.GetGeneration()).c_str());
        window.clear();
        window.draw(pixelmap);
        window.display();
    }

    return ERROR_SUCCESS;
}
