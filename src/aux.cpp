/**
 * @author Manuel Gachs Ballegeer
 */

#include<algorithm>
#include<random>
#include<chrono>
#include"aux.hpp"
#include"event_pool.hpp"

using namespace std;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator (seed);
const event_pools pool;

event choose_event(vector<event>& v) {
    shuffle(v.begin(),v.end(),default_random_engine(seed));
    uniform_int_distribution<int> distribution(0,v.size()-1);
    return v[distribution(generator)];
}

std::vector<event> create_pool(unsigned i,status s,stat_set st) {
    std::vector<event> ans;
    if (i<5)  
        ans = pool.common;
    else {
        ans = pool.common;
        ans.push_back(pool.find_dog);
    }
    
    return ans;
}