/**
 * @file event.hpp
 * @author Manuel Gachs Ballegeer
 * @brief Events and their outcomes
 */

#include<string>
#include<utility>
#include<vector>
#include"stats.hpp"

#ifndef EVENT_HPP
#define EVENT_HPP

/**
 * @brief Possible outcome of an event
 */
class outcome {
public:
    /**
     * @brief Default constructor
     */
    outcome();
    /**
     * @brief Constructor
     * @param d Description text of the outcome
     */
    outcome(const std::string& d);
    /**
     * @brief Constructor
     * @param s Stats modifiers of the outcome
     * @param d Description text of the outcome
     * @param st The status of the outcome
     */
    outcome(stat_set s,const std::string& d="default_outcome",status st=status::no_status);
    /**
     * @brief Show the description of the outcome
     * @return The description of the outcome
     */
    std::string show() const;
    /**
     * @brief Get the stats' modifiers of the outcome
     * @return The stats' modifiers
     */
    stat_set get_modifiers() const;
    /**
     * @brief Get the status of the outcome
     * @return The status the outcome inflicts
     */
    status get_status() const;
    /**
     * @brief Modify the stats' modifiers of the outcome with an operation
     * @param s The stats' modifiers modification
     * @param op Operation
     */
    void set_modifiers(stat_set s,operation op);
private:
    std::string desc;   ///< Description of the outcome
    stat_set mods;      ///< Stat modifiers
    status outcome_status;      ///< Status that might inflict the outcome
};

/**
 * @brief An event of the story
 */
class event {
public:
    /**
     * @brief Default constructor
     */
    event();
    /**
     * @brief Constructor
     * @param d Description text of the event
     */
    event(const std::string& d);
    /**
     * @brief Constructor
     * @param o List of outcomes of the event
     * @param d Description text of the event
     */
    event(const std::vector<outcome>& o,const std::string& d="default_event");
    /**
     * @brief Show the descriptionof the event and its outcomes
     * @return The description of the event and its outcomes
     */
    std::string show() const;
    /**
     * @brief Get the outcome with index "i"
     * @param i The index of the outcome
     * @return The outcome with index "i"
     * @warning An unvalid index will result in an error
     */
    outcome get_outcome(unsigned i) const;
    /**
     * @brief Get the modifiers of the outcome with index "i"
     * @param i The index of the outcome
     * @return stats' modifier of the outcome with index "i" and the outcome
     * @warning An unvalid index will result in an error
     */
    std::pair<stat_set,status> get_modifiers(unsigned i) const;
    /**
     * @brief Add an outcome to the event
     * @param o The outcome to add
     */
    void add_outcome(const outcome& o);
    /**
     * @brief Add a list of outcomes to the event
     * @param o The list of outcomes to add
     */
    void add_outcome(const std::vector<outcome>& o);
    /**
     * @brief Erases the outcome with index "i"
     * @param i The index of the outcome
     * @warning An unvalid index will result in an error
     */
    void erase_outcome(unsigned i);
    /**
     * @brief Modifies the stats' modifiers of an outcome with an operation
     * @param s The stats' modifiers modification
     * @param op Operation
     * @param i The index of the outcome to modify. If no index is provided
     *          the function will apply the modification to all outcomes
     * @warning An unvalid index will result in an error
     */
    void set_modifiers(stat_set s,operation op,int i=-1);
private:
    std::string desc;   ///< Description of the modifier
    std::vector<outcome> outcomes;  ///< Possible outcomes of the event
};

#endif