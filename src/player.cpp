/**
 * @author Manuel Gachs Ballegeer
 */

#include"player.hpp"

player::player() {
    current_status = status::no_status;
    stats.sanity = 100;
    stats.light = 100;
    stats.cold = 0;
    stats.hunger = 0;
}

std::pair<stat_set,operation> player::get_modifiers() const {
    return set_modifiers(current_status);
}

std::string player::show() const {
    return get_stats().show() + "\n[" + "Status: " + name(current_status) + "]";
}

stat_set player::get_stats() const {
    return stats;
}

status player::get_status() const {
    return current_status;
}

void player::set_status(status s) {
    current_status = s;
}

void player::change_stats(stat_set s) {
    stats = stats + s;
}

bool player::lose() const {
    if (stats.sanity<=0 || stats.light<=0 || stats.cold>=100 || stats.hunger>=100)
        return true;
    else
        return false;
}