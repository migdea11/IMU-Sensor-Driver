#include <cstdint>

template<class T>
class SerialSensor 
{
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual T Read() = 0; 
}