#include "pch.h"
#include "GameOfLife.h"
#include <format>

constexpr const int CELL_SIZE = 4;

int WINAPI WinMain([[maybe_unused]] _In_ HINSTANCE hInstance, [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance,
                   [[maybe_unused]] _In_ LPSTR lpCmdLine, [[maybe_unused]] _In_ int nShowCmd)
{
    GameOfLife game{ 400, 400 };
    bool paused{ false };

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
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                auto pos = sf::Mouse::getPosition(window);

                switch (event.key.code)
                {
                // Pause
                case sf::Keyboard::Space:
                    paused = !paused;
                    break;

                // Clear
                case sf::Keyboard::C:
                    game.Clear();
                    break;

                // Insert Blinker
                case sf::Keyboard::B:
                    if (pos.x >= 0 && pos.x < static_cast<int>(window.getSize().x) && pos.y >= 0 &&
                        pos.y < static_cast<int>(window.getSize().y))
                    {
                        auto x = pos.x / CELL_SIZE;
                        auto y = pos.y / CELL_SIZE;
                        game.SetCell(x, y - 1, true);
                        game.SetCell(x, y, true);
                        game.SetCell(x, y + 1, true);
                    }
                    break;

                // Insert Glider
                case sf::Keyboard::G:
                    if (pos.x >= 0 && pos.x < static_cast<int>(window.getSize().x) && pos.y >= 0 &&
                        pos.y < static_cast<int>(window.getSize().y))
                    {
                        auto x = pos.x / CELL_SIZE;
                        auto y = pos.y / CELL_SIZE;
                        game.SetCell(x, y, true);
                        game.SetCell(x + 1, y, true);
                        game.SetCell(x + 2, y, true);
                        game.SetCell(x + 2, y + 1, true);
                        game.SetCell(x + 1, y + 2, true);
                    }
                    break;
                }
                break;
            }
        }

        // Iterate the next generation
        if (!paused)
        {
            game.Generate();
            for (int x = 0; x < game.GetWidth(); x++)
            {
                for (int y = 0; y < game.GetHeight(); y++)
                {
                    sf::Vertex* quad = &pixelmap[(x + y * game.GetWidth()) * 4];
                    quad[0].color = quad[1].color = quad[2].color = quad[3].color =
                        game.GetCell(x, y) ? sf::Color::Green : sf::Color::Black;
                }
            }
        }

        window.setTitle(std::format("Generation {}", game.GetGeneration()).c_str());
        window.clear();
        window.draw(pixelmap);
        window.display();
    }

    return ERROR_SUCCESS;
}
