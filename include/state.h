//
// Created by mateusz on 12/5/21.
//

#ifndef MEINKRAFT_STATE_H
#define MEINKRAFT_STATE_H

#include <memory>

#include "renderer.h"

class State {
public:
    virtual bool init() = 0;
    virtual void update() = 0;
    virtual void draw(Renderer& renderer) = 0;
    virtual ~State() = default;
};

class StateManager {
private:
    std::unique_ptr<State> current_state_;

public:
//    void scheduleStateChange();
    explicit StateManager(std::unique_ptr<State> state) {
        current_state_ = std::move(state);
        // pass handle to change state
    }

    void updateState() {
        // if state change was scheduled, change current_state to it
        // change should be able to keep previous state or destroy it
    }

    State* getCurrentState() {
        return current_state_.get();
    }
};

#endif //MEINKRAFT_STATE_H
