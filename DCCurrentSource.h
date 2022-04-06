#ifndef DCCURRENTSOURCE_H
#define DCCURRENTSOURCE_H
#include "Component.h"
#include <fstream>

class DCCurrentSource : public Component {
    private:
        double current;
    public:
        // constructor
        DCCurrentSource();
        // mutators and accessors
        void setCurrent(double i);
        const double getCurrent();
        const double getPower();
        // other members
        void reportInfo(std::ofstream&);
};

#endif