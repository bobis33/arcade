/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-arcade-elliot.masina
** File description:
** entryPoint
*/

#include <memory>

#include "Arcade/Nibbler.hpp"

extern "C"
{
    std::unique_ptr<Arcade::AGame> entryPoint()
    {
        return std::make_unique<Arcade::Nibbler>();
    }
}
