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
    float* currentSpeed = new float();
    *currentSection = 0;
    float colorSelection[3];

    const char* items[] = { "Solid Color", "Rainbow", "Fade", "Tachometer", "Knight Rider"};
    static const char* current_item = NULL;
    static const char* previous_item = NULL;

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
        ImGui::SliderFloat("Speed for Tach", currentSpeed, 0, 6000, "%.1f");
        ImGui::ColorPicker3("LED Color", colorSelection);

        if (ImGui::BeginCombo("Mode selection", current_item))
        {
            for (int n = 0; n < IM_ARRAYSIZE(items); n++)
            {
                bool is_selected = (current_item == items[n]);
                if (ImGui::Selectable(items[n], is_selected)) {
                    current_item = items[n];
                    if (is_selected) {
                        ImGui::SetItemDefaultFocus();
                    }
                }
            }
            ImGui::EndCombo();
        }

        ImGui::End();

        if (current_item == "Rainbow" && previous_item != current_item) {
            subsystem.SetSectionToRainbow(*currentSection);
        }
        else if (current_item == "Fade" && previous_item != current_item) {
            subsystem.SetSectionToFade(*currentSection, colorSelection[0], colorSelection[1], colorSelection[2]);
        }
        else if (current_item == "Solid Color") {
            subsystem.SetSectionToColor(*currentSection, colorSelection[0], colorSelection[1], colorSelection[2]);
        }
        else if (current_item == "Tachometer") {
            subsystem.SetSectionToTachometer(*currentSection, *currentSpeed, 6000);
        }
        else if (current_item == "Knight Rider" && previous_item != current_item) {
            subsystem.SetSectionToKnightRider(*currentSection, colorSelection[0], colorSelection[1], colorSelection[2]);
        }

        previous_item = current_item;
        window->clear();
        ImGui::SFML::Render(*window.get());
        subsystem.Periodic();
        window->display();
    }

    ImGui::SFML::Shutdown();
	return 0;
}