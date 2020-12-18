/**
 * @author Manuel Gachs Ballegeer
 */

#include<iostream>
#include"stats.hpp"
#include"event.hpp"
#include"aux.hpp"
#include"player.hpp"

using namespace std;

int main() {
    // Initialize variables
    player _player;
    event current_event;
    status new_status = status::no_status;
    unsigned n_events = 0;
    unsigned outcome_index = 0;

    // TODO: Show start of the game text and menu

    // Main loop
    while(!_player.lose() && new_status!=status::end) {
        // Show player stats
        cout<<"-------------------- CURRENT STATS --------------------\n";
        cout<<_player.show();
        cout<<"\n-------------------------------------------------------\n";

        // TODO: Event pool based on stats
        vector<event> pool = create_pool(n_events,_player.get_status(),_player.get_stats());
        vector<pair<stat_set,operation> > current_status_mods = _player.get_modifiers(); 
        for (size_t j=0;j<current_status_mods.size();j++)
            for (size_t i=0;i<pool.size();i++) {
                pair<stat_set,operation> mods = current_status_mods[j];
                pool[i].set_modifiers(mods.first,mods.second);
            }

        // Play the event
        current_event = choose_event(pool);
        cout<<current_event.show()<<endl;
        cout<<"Elige tu acción: ";
        cin>>outcome_index;

        // Set the consequences
        _player.change_stats(current_event.get_modifiers(outcome_index).first);
        new_status = current_event.get_modifiers(outcome_index).second;
        if (new_status!=status::no_status)
            _player.set_status(new_status);
        n_events++;
    }

    cout<<"FIN DE LA PARTIDA\n";
    return 0;
}