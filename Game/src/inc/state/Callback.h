#ifndef SDL_Game_Programming_Book_Callback_h
#define SDL_Game_Programming_Book_Callback_h

class Callback
{
public:
    virtual void call() = 0;
};

class StaticCallback : public Callback
{
public:
    
    StaticCallback(void (*func)()) : m_func(func)
    {
        
    }
    
    virtual void call()
    {
        m_func();
    }
    
private:
    
    void (*m_func)();
};

#endif
