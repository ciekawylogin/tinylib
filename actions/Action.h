#ifndef ACTION_H
#define ACTION_H

class Action
{
    bool cancelled;
public:
    Action();
    virtual void perform() = 0;

    bool isCancelled() const
    {
        return cancelled;
    }

    void cancel()
    {
        cancelled = true;
    }
};

#endif // ACTION_H
