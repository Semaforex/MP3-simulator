#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include <unordered_set>

class Battery {
    private:
        unsigned int capacity;
        unsigned int battery_left;
    public:
        Battery(unsigned int Capacity = 100);
        void charge(unsigned int power);
        void discharge(unsigned int consumption);
        unsigned int get_battery_left() const;
        bool is_empty() const;
        bool is_full() const;
        void change_capacity(unsigned int Capacity);
        void change_battery_left(unsigned int Battery_left);
        nlohmann::json to_json() const;
        void from_json(nlohmann::json json_data);
};