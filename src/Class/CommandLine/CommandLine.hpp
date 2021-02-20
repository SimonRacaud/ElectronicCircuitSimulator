/*
 * File: CommandLine.h
 * Project: CommandLine
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Saturday, 20th February 2021 9:50:41 am
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#ifndef H_COMMAND_LINE
#define H_COMMAND_LINE

#include "Class/Circuit/Circuit.hpp"
#include "Class/Parser/Parser.hpp"
#include "ComponentType.hpp"

#include <algorithm>
#include <csignal>
#include <regex>
#include <string>
#include <unistd.h>
#include <unordered_map>

#define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember))

namespace nts
{
    class CommandLine;

    typedef void (CommandLine::*cmdFunc)(void);

    class CommandLine {
      public:
        CommandLine();
        ~CommandLine();

        void loop();

        void setLoopCmdLoop(bool status);

      protected:
        void exitCmd();

        void displayCmd();
        void _displayCmdInOut(
            ComponentType type, std::deque<ComponentContent *> &content);

        void simulateCmd();
        void loopCmd();
        void dumpCmd();
        void editValueCmd();
        void helpCmd();
        void _exceptionHandler();
        static Tristate stateNameToState(const std::string &stateName);

      private:
        bool _loop;
        bool _loopCmdLoop;
        Circuit *_circuit;
        const std::string _ERR_NO_CIRCUIT;
        std::string _prompt;
        std::string _lastInput;
        Parser _parser;
        static std::unordered_map<std::string, cmdFunc> CMD;
        static std::unordered_map<std::string, std::string> CMD_DESC;
    };
} // namespace nts

#endif // !H_COMMAND_LINE