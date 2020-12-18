/**
 * @file stats.hpp
 * @author Manuel Gachs Ballegeer
 * @brief Sets of stats and statuses
 */

#include<string>

#ifndef STATS_HPP
#define STATS_HPP

/**
 * @brief Possible operations with stat sets
 */
enum class operation {
    rep,
    sum,
    mult
};

/**
 * @brief Set of stats
 */
struct stat_set {
    int sanity;    ///< Sanity
    int light;     ///< Light level
    int cold;      ///< Level of body temperature
    int hunger;    ///< Hunger
    
    /**
     * @brief Default constructor
     */
    stat_set();
    /**
     * @brief Constructor
     */
    stat_set(int s,int l,int c,int h);
    /**
     * @brief Sums two stat sets
     */
    stat_set operator+(const stat_set& a);
    /**
     * @brief Multiplies two stat sets
     */
    stat_set operator*(const stat_set& a);
    /**
     * @brief Converts the values of the stat set to a strings
     * @return A string containing the values of the outcome
     */
    std::string show() const;
};

/**
 * @brief Statuses of the player
 * @todo Add statuses
 */
enum class status {
    exhausted,      ///< Hunger x2
    paranoid,       ///< Sanity -2
    wet,            ///< Cold +1
    revert_status,  ///< Removes status
    end,            ///< Ends the game
    no_status       ///< Default value
};

/**
 * @brief Sets the stats' modifiers of a status
 * @param s The status
 * @return The modifiers of the status
 * @todo Add statuses' modifiers
 */
std::pair<stat_set,operation> set_modifiers(const status s);
/**
 * @brief Shows the name of the status
 * @param s The status to show
 * @return The description of the status
 * @todo Add statuses' names
 */
std::string name(status s);

#endif