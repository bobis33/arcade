/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core.cpp
*/

#include "Arcade/abstractions/IRenderer.hpp"
#include "Arcade/Core.hpp"

void Arcade::Core::gameLoop()
{
    while (_mode != CoreMode::QUIT) {
        handleEvents(_window->getEvent());
        _window->displayWindow();
    }
}
