#ifndef COMMANDTASK_H
#define COMMANDTASK_H

#include "Command.h"
#include "TaskClass.h"
#include <wiringPi.h>
#include "rc-switch/RCSwitch.h"

#define PIN 28

using namespace std;


class TaskCommand : public Command {
    public:
        TaskCommand(string json);
        virtual ~TaskCommand();

        bool execute();
        bool createRequestFromJson();

        TaskClass getTask();
        void setTask(TaskClass);


    protected:


    private:
        TaskClass task;


};

#endif // COMMANDTASK_H
