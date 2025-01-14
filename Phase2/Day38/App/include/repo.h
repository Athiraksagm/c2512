#pragma once
#include "type.h"
#include <vector>

template<class T>
class ICreatable {
    public: 
        virtual void Create(T& entity) = 0;
        virtual ~ICreatable() { }
};

template<class T>
class IReadableOne {
    public: 
        virtual T ReadById(identity_t id) = 0;
        virtual ~IReadableOne() { }
};
    

template<class T>
class IHCrud : public ICreatable<T>, public IReadableOne<T> {       // C R-1 R-A 
    public: 
        virtual std::vector<T> ReadAll() = 0;
        virtual ~IHCrud() { }
};
