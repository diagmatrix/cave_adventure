/**
 * @file aux.hpp
 * @author Manuel Gachs Ballegeer
 * @brief Functions for the main loop
 */

#include<algorithm>
#include<random>
#include<chrono>
#include<set>
#include"event.hpp"
#include"stats.hpp"

#ifndef AUX_HPP
#define AUX_HPP

/**
 * @brief Shuffles and chooses an event from the pool
 * @param v Array of events. Is modified
 * @return The chosen event
 */
event choose_event(std::vector<event>& v);

/** 
 * @brief Creates the event pool
 * @param i The number of events already played
 * @param s The current status of the player
 * @param st The current stats of the player
 * @return The pool of possible events to choose from
 * @todo Add different pools
 */
std::vector<event> create_pool(unsigned i,const std::set<status>& s,stat_set st);

#endif