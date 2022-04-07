#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception{
public:
    const char* error(){
        return "There are no rooms in this direction try another direction";
    }
};

#endif // EXCEPTION_H
