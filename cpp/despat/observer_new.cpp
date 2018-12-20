#include <functional>
#include <iostream>
#include "Observable.h"

class Model : public Observable
{
};

void foo(int i)
{
    std::cout << "\tfoo( " << i << " )" << std::endl;
}

void bar()
{
    std::cout << "\tbar()" << std::endl;
}

// TODO: test with functors and methods
int main()
{
    Model s;

    s.registerObserver(Event::GREEN, bar);
    s.registerObserver(Event::ORANGE, std::bind(foo, 42));
    s.registerObserver(Event::GREEN, std::bind(foo, 12345));

    std::cout << "Event Green" << std::endl;
    s.notify(Event::GREEN); 
    std::cout << "Event Red" << std::endl;
    s.notify(Event::RED); 
    std::cout << "Event Orange" << std::endl;
    s.notify(Event::ORANGE);

    std::cout << "Unregistering all observers" << std::endl;
    s.unregisterAllEvents();

    std::cout << "Event Green" << std::endl;
    s.notify(Event::GREEN); 
    std::cout << "Event Red" << std::endl;
    s.notify(Event::RED); 
    std::cout << "Event Orange" << std::endl;
    s.notify(Event::ORANGE);
}
