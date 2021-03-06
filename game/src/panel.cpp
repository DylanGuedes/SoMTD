#include <iostream>

#include "game.h"

#include <ijengine/canvas.h>
#include <ijengine/engine.h>
#include <ijengine/texture.h>
#include <string>

#include "./player.hpp"

#include "panel.h"

SoMTD::Panel::Panel(std::string texture_name, unsigned id, int x, int y, int myp) :
    m_id(id),
    m_x(x),
    m_y(y),
    m_start(-1),
    texture_name_path(texture_name)
{
    set_priority(myp);
    m_texture = ijengine::resources::get_texture(texture_name);
    ijengine::event::register_listener(this);
}

SoMTD::Panel::~Panel()
{
    ijengine::event::unregister_listener(this);
}

bool
SoMTD::Panel::on_event(const ijengine::GameEvent&)
{
    return false;
}

void
SoMTD::Panel::draw_self(ijengine::Canvas *canvas, unsigned, unsigned)
{
    canvas->draw(m_texture.get(), m_x, m_y);
    if (texture_name_path == "coins_panel.png") {
        auto font = ijengine::resources::get_font("Forelle.ttf", 40);
        canvas->set_font(font);
        canvas->draw(std::to_string(player::get().gold()), m_x+70, m_y+10);
    }
}

void
SoMTD::Panel::draw_self_after(ijengine::Canvas *c, unsigned, unsigned)
{
          auto font = ijengine::resources::get_font("Inconsolata-Regular.ttf", 15);
          c->set_font(font);
          c->draw("1000", 40 , 573);
          c->draw("3000", 110 , 573);
          c->draw("10000", 180 , 573);
}

void
SoMTD::Panel::update_self(unsigned, unsigned)
{
}
