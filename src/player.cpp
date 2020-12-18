/**
 * @author Manuel Gachs Ballegeer
 */

#include<sstream>
#include"player.hpp"

player::player() {
    stats.sanity = 100;
    stats.light = 100;
    stats.cold = 0;
    stats.hunger = 0;
}

std::vector<std::pair<stat_set,operation> > player::get_modifiers() const {
    std::vector<std::pair<stat_set,operation>> ans;
    for (auto it=current_status.begin();it!=current_status.end();it++)
        ans.push_back(set_modifiers(*it));
    return ans;
}

std::string player::show() const {
    std::ostringstream stats;
    stats<<get_stats().show()<<"\nStatus:";
    for (auto it=current_status.begin();it!=current_status.end();it++)
        stats<<" ["<<name(*it)<<"]";
    return stats.str();
}

stat_set player::get_stats() const {
    return stats;
}

std::set<status> player::get_status() const {
    return current_status;
}

void player::set_status(status s) {
    switch(s) {
        default:
            current_status.insert(s);
            break;
        case status::revert_wet:
            current_status.erase(status::wet);
            break;
        case status::revert_exh:
            current_status.erase(status::exhausted);
            break;
    }
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