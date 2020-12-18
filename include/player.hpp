/**
 * @file player.hpp
 * @author Manuel Gachs Ballegeer
 * @brief The player that plays the game
 */

#include<utility>
#include<vector>
#include<set>
#include"event.hpp"
#include"stats.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

/**
 * @brief Player
 */
class player {
public:
    /**
     * @brief Default constructor
     */
    player();
    /** 
     * @brief Get the modifiers to the stats based on the status
     * @return The list of pairs modifier-operation
     */
    std::vector<std::pair<stat_set,operation> > get_modifiers() const;
    /**
     * @brief Shows a description of the player
     * @return The description of the player
     */
    std::string show() const;
    /**
     * @brief Get the current player's stats
     * @return The player's stats when the function is called
     */
    stat_set get_stats() const;
    /** 
     * @brief Get the current player's status
     * @return The player's status when the function is called
     */
    std::set<status> get_status() const;
    /**
     * @brief Change the player status
     * @param s New status
     * @todo Set the behaviour for reverting statuses
     */
    void set_status(status s);
    /**
     * @brief Change the player's stats by adding a modifier
     * @param s The modifier of the stats
     */
    void change_stats(stat_set s);
    /**
     * @brief Determines if the player loses the game
     * @return @retval True if the player has lost
     *         @retval False is the player hasn't lost
     */
    bool lose() const;
private:
    stat_set stats;                     ///< Player stats
    std::set<status> current_status;              ///< Player status
};

#endif