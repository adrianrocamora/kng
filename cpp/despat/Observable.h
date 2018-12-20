#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <functional>
#include <iostream>
#include <unordered_map>
#include <array>
#include <utility>
#include <vector>
// Simple type safe event class with auxiliary iterable array
enum class Event { RED, GREEN, BLUE, ORANGE, CYAN };
const std::array<Event, 5> all_events = { 
    Event::RED, Event::GREEN, Event::BLUE, Event::ORANGE, Event::CYAN 
};

// We shouldn't need this with our current approach
//class Observer; // passable suscriber callback class
// We are storing the observer in a vector of std::function<void()>
// and if we attempt to store something incompatible we'll get a 
// compile-time error

class Observable {
public:
    template <typename Observer>
    void registerObserver(const Event& event, Observer&& observer)
    {
        //observers_[event].push_back(std::forward<Observer>(observer));
        observers_[event].push_back(static_cast<Observer&&>(observer));
    }

    // Note making this methods const changes the syntax due to [] restrictions
    virtual void notify(const Event& event)
    {
        for (const auto& obs : observers_[event]) {
            obs();
        }
    }
    virtual void unregisterEvent(const Event& event) {
        observers_[event].clear();
    }

    virtual void unregisterAllEvents() {
        for (auto& event : all_events) {
            observers_[event].clear();
        }
    }
    virtual ~Observable() { }
protected:
    std::unordered_map<Event, std::vector<std::function<void()>>> observers_;
};

#endif //OBSERVABLE_H
