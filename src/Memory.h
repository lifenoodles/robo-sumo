#ifndef GUARD_MEMORY
#define GUARD_MEMORY

class Memory
{
public:
    static Memory* get();
    void init(unsigned char id);
private:
    static Memory* instance;
};

#endif
