/**
 * @author Manuel Gachs Ballegeer
 */

#include<sstream>
#include"stats.hpp"

stat_set::stat_set() {
    sanity = 0;
    light = 0;
    cold = 0;
    hunger = 0;
}

stat_set::stat_set(int s,int l,int c,int h) {
    sanity = s;
    light = l;
    cold = c;
    hunger = h;
}

stat_set stat_set::operator+(const stat_set& a) {
    int n_sanity = (a.sanity+sanity>100)?100:a.sanity+sanity;
    int n_light = (a.light+light>100)?100:a.light+light;
    int n_cold = (a.cold+cold<0)?0:a.cold+cold;
    int n_hunger = (a.hunger+hunger<0)?0:a.hunger+hunger;
    return stat_set(n_sanity,n_light,n_cold,n_hunger);
}

stat_set stat_set::operator*(const stat_set& a) {
    int n_sanity = (a.sanity*sanity>100)?100:a.sanity*sanity;
    int n_light = (a.light*light>100)?100:a.light*light;
    int n_cold = (a.cold*cold<0)?0:a.cold*cold;
    int n_hunger = (a.hunger*hunger<0)?0:a.hunger*hunger;
    return stat_set(n_sanity,n_light,n_cold,n_hunger);
}

std::string stat_set::show() const {
    std::ostringstream stats;
    stats << "[Sanity - "<<sanity<<"] [Light - "<<light<<"] [Cold - "<<cold<<"] [Hunger - "<<hunger<<"]";
    return stats.str();
}

// VERY IMPORTANT: Modifiers of the status
std::pair<stat_set,operation> set_modifiers(const status s) {
    std::pair<stat_set,operation> ans;
    switch(s) {
        // Default action
        default:
            ans.first = stat_set(0,0,0,0);
            ans.second = operation::sum;
            break;
        // Exhausted
        case status::exhausted:
            ans.first = stat_set(0,0,0,2);
            ans.second = operation::mult;
            break;
        // Paranoid
        case status::paranoid:
            ans.first = stat_set(-2,0,0,0);
            ans.second = operation::sum;
            break;
        // Wet
        case status::wet:
            ans.first = stat_set(0,0,2,0);
            ans.second = operation::sum;
            break;
        // TODO: Add statuses
    }
    return ans;
}

std::string name(const status s) {
    std::string ans;
    switch(s) {
        // Default action
        default:
            ans = " ";
            break;
        // Exhausted
        case status::exhausted:
            ans = "Exhausto";
            break;
        // Paranoid
        case status::paranoid:
            ans = "Paranoico";
            break;
        // Wet
        case status::wet:
            ans = "Mojado";
            break;
        // TODO: Add statuses
    }
    return ans;
}