//
// Created by mateusz on 12/5/21.
//

#include "state.h"
#include "sprite.h"
#include "sprite_sheet.h"
#include "entities/render_entity.h"

#ifndef MEINKRAFT_GAME_STATE_H
#define MEINKRAFT_GAME_STATE_H

class GameState : public State {
public:
    bool init() override;
    void update() override;
    void draw(Renderer& renderer) override;

    ~GameState() override = default;

private:
    std::unique_ptr<RenderEntity> entity_;


};


#endif //MEINKRAFT_GAME_STATE_H
