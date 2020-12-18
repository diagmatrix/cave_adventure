/**
 * @file event_pool.hpp
 * @author Manuel Gachs Ballegeer
 * @brief All events
 */

#include<vector>
#include<string>
#include"event.hpp"

/**
 * @brief All strings containing the descriptions of the events
 */
struct event_desc {
    std::string crossroad_common = "Delante de ti el camino se bifurca. Te encuentras en una encrucijada. ¿Qué camino escoger?";
    std::string crossroad_pool = "Delante de ti aparece una piscina natural, que bloquea el camino. Sin embargo, parece que puedes seguir por otros caminos. ¿Qué eliges?";
    std::string rat = "Escuchas unos ruidos y, al acercarte, te das cuenta de que se trata de un ratón.";
    std::string find_dog_normal = "Escuchas ladridos muy cerca de ti. Tras unos pasos, encuentras a Lulú. ¡Finalmente encontraste a tu perrita!";
};
const event_desc ev_str;

/** 
 * @brief All strings containing the descriptions of outcomes
 */
struct outcome_desc {
    std::string ignore = "Lo ignoras y sigues tu camino";
    std::string go_left = "Sigues el camino que gira a la izquierda";
    std::string go_right = "Sigues el camino que gira a la derecha";
    std::string cross_pool = "Nadas para atravesar la piscina natural";
    std::string flee = "Corres, huyendo del encuentro";
    std::string give_food = "Sacas algo de comida de tu mochila y se la das";
    std::string end_game = "Continuar...";
};
const outcome_desc out_str;

//***************************************************************************************
// No status & end outcomes
outcome ignore(stat_set(-1,-1,0,0),out_str.ignore); ///< Ignore
outcome go_left(stat_set(0,-1,0,1),out_str.go_left); ///< Go left
outcome go_right(stat_set(0,-1,1,0),out_str.go_right); ///< Go right
outcome flee(stat_set(-5,-1,0,2),out_str.flee); ///< Flee
outcome give_food(stat_set(1,0,0,1),out_str.give_food); ///< Give food
outcome end_game(stat_set(),out_str.end_game,status::end); ///< End game

//***************************************************************************************
// Wet & revert wet outcomes
outcome cross_pool(stat_set(-1,-1,5,0),out_str.cross_pool,status::wet); ///< Cross pool

//***************************************************************************************
// Common events
event crossroad_common({go_left,go_right},ev_str.crossroad_common); ///< Crossroad right-left
event crossroad_pool({go_left,go_right,cross_pool},ev_str.crossroad_pool); ///< Crossroad with pool
event rat({ignore,flee,give_food},ev_str.rat); ///< Rat

//***************************************************************************************
// End events
event find_dog_normal({end_game},ev_str.find_dog_normal); ///< Normal encounter with dog

/** 
 * @brief All event pools
 */
struct event_pools {
    std::vector<event> common = {crossroad_common,crossroad_pool,rat}; ///< Common events
    event find_dog = find_dog_normal; ///< End: Find the dog
};