#include <iostream>
#include <chrono>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include "LedSubsystem.h"

int main(int argc, char* argv[]) {
	std::cout << "Starting LED Testing Program!" << "\n";

    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "Led Subsystem Tester");

	LedSubsystem subsystem(window);

    int* currentSection = new int();
    *currentSection = 0;
    float colorSelection[3];

    window->setFramerateLimit(50);
    window->setVerticalSyncEnabled(false);
    sf::Clock fpsClock;
    sf::Clock deltaClock;
    ImGui::SFML::Init(*window.get());

    while (window->isOpen())
    {
        float framerate = 1.f / fpsClock.getElapsedTime().asSeconds();
        fpsClock.restart();

        sf::Event event;
        while (window->pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window->close();
        }

        ImGui::SFML::Update(*window.get(), deltaClock.restart());

        ImGui::Begin("Framerate");
        ImGui::Text(std::to_string(framerate).c_str());
        ImGui::End();

        ImGui::Begin("Control Section");
        ImGui::SliderInt("Section", currentSection, 0, 4, "%d");
        ImGui::ColorPicker3("LED Color", colorSelection);
        ImGui::End();

        subsystem.SetSectionToColor(*currentSection, colorSelection[0], colorSelection[1], colorSelection[2]);

        window->clear();
        ImGui::SFML::Render(*window.get());
        subsystem.Periodic();
        window->display();
    }

    ImGui::SFML::Shutdown();
	return 0;
}