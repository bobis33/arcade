/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Text.cpp
*/

#include <SDL2/SDL_ttf.h>

#include "Arcade/Sdl2.hpp"

bool Arcade::Sdl2::loadFont(const std::string &filepath, const std::string &name)
{
    if (_fonts.find(name) != _fonts.end())
        return true;
    TTF_Font *font = TTF_OpenFont(filepath.c_str(), 50);
    if (font == nullptr)
        return false;
    _fonts[name] = font;
    return true;
}

void Arcade::Sdl2::createText(const std::string &fontName, const std::string &text, const int size, const float pos_x, const float pos_y)
{
    (void)size; // TODO: Implement font size (size)
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(_fonts[fontName], text.c_str(), color);
    _texts[text] = SDL_CreateTextureFromSurface(_renderer, surface);
    _textsRect[text].x = static_cast<int>(pos_x);
    _textsRect[text].y = static_cast<int>(pos_y);
    _textsRect[text].w = surface->w;
    _textsRect[text].h = surface->h;
}

void Arcade::Sdl2::displayText(const std::string &textName)
{
    SDL_RenderCopy(_renderer, _texts[textName], nullptr, &_textsRect[textName]);
}