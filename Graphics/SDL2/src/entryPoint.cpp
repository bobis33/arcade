/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** entryPoint.cpp
*/

#include <memory>
#include "Sdl2.hpp"

extern "C" {
    std::unique_ptr<Arcade::AGraphic> entryPoint() {
        return std::make_unique<Arcade::Sdl2>();
    }
}