/**
 * @author Manuel Gachs Ballegeer
 */

#include<cassert>
#include"event.hpp"

// ****************************************************************************
// Class outcome
outcome::outcome() {
    desc = "default_outcome";
    outcome_status = status::no_status;
}

outcome::outcome(const std::string& d) {
    desc = d;
    outcome_status = status::no_status;
}

outcome::outcome(stat_set s,const std::string& d,status st) {
    desc = d;
    outcome_status = st;
    mods = s;
}

std::string outcome::show() const {
    return desc;
}

stat_set outcome::get_modifiers() const {
    return mods;
}

status outcome::get_status() const {
    return outcome_status;
}

void outcome::set_modifiers(stat_set s,operation op) {
    switch(op) {
        case operation::rep:
            mods = s;
            break;
        case operation::sum:
            mods = mods + s;
            break;
        case operation::mult:
            mods = mods * s;
            break;
    }
}

// ****************************************************************************
// Class event

event::event() {
    desc = "default_event";
}

event::event(const std::string& d) {
    desc = d;
}

event::event(const std::vector<outcome>& o,const std::string& d) {
    desc = d;
    outcomes = o;
}

std::string event::show() const {
    std::string aux = desc;
    for (size_t i=0;i<outcomes.size();i++)
        aux = aux + "\n" + std::to_string(i) + ". " + outcomes[i].show();
    
    return aux;
}

outcome event::get_outcome(unsigned i) const {
    assert(i>=0 && i<outcomes.size());
    return outcomes[i];
}

std::pair<stat_set,status> event::get_modifiers(unsigned i) const {
    assert(i>=0 && i<outcomes.size());
    return std::pair<stat_set,status>(outcomes[i].get_modifiers(),outcomes[i].get_status());
}

void event::add_outcome(const outcome& o) {
    outcomes.push_back(o);
}

void event::add_outcome(const std::vector<outcome>& o) {
    outcomes.insert(outcomes.end(),o.begin(),o.end());
}

void event::erase_outcome(unsigned i) {
    assert(i>=0 && i<outcomes.size());
    outcomes.erase(outcomes.begin()+i);
}

void event::set_modifiers(stat_set s,operation op,int i) {
    if (i==-1) {
        for (size_t j=0;j<outcomes.size();j++)
            outcomes[j].set_modifiers(s,op);
    } else {
        assert(i>=0 && i<int(outcomes.size()));
        outcomes[i].set_modifiers(s,op);
    }
}