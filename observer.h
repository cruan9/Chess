#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <iostream>
class Subject;
class Board;

class Observer {
public:
    virtual void notify() = 0;
    virtual ~Observer() = default;
};

class TextObserver : Observer {
    std::ostream &out = std::cout;

    Board * subject;
public:
    void notify() override;
    TextObserver(Board * subject);
    ~TextObserver(){};
};

class GraphicalObserver : Observer {
    Board * subject;
public:
    void notify() override;
    GraphicalObserver(Board * subject);
    ~GraphicalObserver(){};
};


#endif