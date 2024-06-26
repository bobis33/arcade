/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Text.cpp
*/

#include "Arcade/Sdl2Renderer.hpp"

void Arcade::Sdl2Renderer::moveText(const std::string &textName, int pos_x, int pos_y)
{
    _textsRect[textName].x = pos_x;
    _textsRect[textName].y = pos_y;
}

bool Arcade::Sdl2Renderer::loadFont(const std::string &filepath, const std::string &name)
{
    if (_fonts.find(name) != _fonts.end())
        return true;
    TTF_Font *font = TTF_OpenFont(filepath.c_str(), 50);
    if (font == nullptr)
        return false;
    _fonts[name] = font;
    return true;
}

std::string Arcade::Sdl2Renderer::updateTextBox()
{
    int width, height;

    TTF_Font *font = TTF_OpenFont("./assets/fonts/menu_i.ttf", 30);
    SDL_Surface *surface = TTF_RenderText_Solid(font, _input, {255, 255, 255, 255});
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_window.getRenderer(), surface);
    _texts[" "] = texture;

    TTF_SizeText(font, _input, &width, &height);
    SDL_Rect rect = {0, 0, width, height};
    rect.x = _textsRect[" "].x;
    rect.y = _textsRect[" "].y;
    _textsRect[" "] = rect;

    SDL_FreeSurface(surface);
    return _input;
}


void Arcade::Sdl2Renderer::createText(const std::string &fontName, const std::string &text, const int size, const float pos_x, const float pos_y)
{
    SDL_Color color{255, 255, 255, 255};
    SDL_Surface *surface{nullptr};

    if (size != 50) {
        TTF_Font *font{nullptr};
        std::string path = "./assets/fonts/" + fontName + ".ttf";
        font = TTF_OpenFont(path.c_str(), size);
        surface = TTF_RenderText_Solid(font, text.c_str(), color);
    } else {
        surface = TTF_RenderText_Solid(_fonts[fontName], text.c_str(), color);
    }
    _texts[text] = SDL_CreateTextureFromSurface(_window.getRenderer(), surface);
    _textsRect[text].x = static_cast<int>(pos_x);
    _textsRect[text].y = static_cast<int>(pos_y);
    _textsRect[text].w = surface->w;
    _textsRect[text].h = surface->h;
    SDL_FreeSurface(surface);
}

void Arcade::Sdl2Renderer::displayText(const std::string &textName)
{
    SDL_RenderCopy(_window.getRenderer(), _texts[textName], nullptr, &_textsRect[textName]);
}