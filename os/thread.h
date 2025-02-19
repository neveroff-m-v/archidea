class thread
{
public:
    thread();

    u32 mask;
    void (*function)();
};