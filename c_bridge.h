#ifndef BRIDGE_H
#define BRIDGE_H

class Bridge {
    int start;
    int end;
    
public:
    Bridge(int s, int e) : start(s), end(e) {}

    int getStart() const {
        return start;
    }

    int getEnd() const {
        return end;
    }
};

#endif // BRIDGE_H
