/*
 * File: CommandLine.cpp
 * Project: CommandLine
 * File Created: Thursday, 1st January 1970 1:00:00 am
 * Author: simon (simon.racaud@epitech.eu)
 * -----
 * Last Modified: Saturday, 20th February 2021 10:00:03 am
 * Modified By: simon (simon.racaud@epitech.eu>)
 * -----
 * Copyright 2021 - 2021 TEK2, Epitech
 */

#include "CommandLine.hpp"

using namespace nts;

std::unordered_map<std::string, cmdFunc> CommandLine::CMD = {
    {"exit", &CommandLine::exitCmd},
    {"display", &CommandLine::displayCmd},
    {"simulate", &CommandLine::simulateCmd},
    {"loop", &CommandLine::loopCmd},
    {"dump", &CommandLine::dumpCmd},
    {"help", &CommandLine::helpCmd},
    {"h", &CommandLine::helpCmd},
    {"input=value", &CommandLine::editValueCmd},
};

std::unordered_map<std::string, std::string> CommandLine::CMD_DESC = {
    {"exit", "exit the program."},
    {"display",
        "prints the current tick and the value of all inputs and outputs the "
        "standard output."},
    {"simulate", "simulate a tick of the circuit."},
    {"loop", "continiously runs the simulation until SIGINT is received."},
    {"dump", "display de internal state of all components of the circuit."},
    {"help/h", "usage."},
    {"input=value", "set the output state of an input component."},
};

CommandLine::CommandLine()
    : _loop(true), _loopCmdLoop(false), _circuit(nullptr),
      _ERR_NO_CIRCUIT("Error: no circuit loaded"), _prompt("> ")
{
}

CommandLine::~CommandLine()
{
}

void CommandLine::loop()
{
    std::string input;

    while (this->_loop) {
        std::cout << this->_prompt;
        if (!std::getline(std::cin, input))
            break;
        if (CommandLine::CMD.find(input) != CommandLine::CMD.end()) {
            this->_lastInput = input;
            CALL_MEMBER_FN((*this), CommandLine::CMD[input])();
        } else if (input.size() > 0) {
            CALL_MEMBER_FN((*this), CommandLine::CMD["input=value"])();
        }
    }
}

void CommandLine::helpCmd()
{
    std::cout << "# Commands:" << std::endl;
    for (auto it = CommandLine::CMD_DESC.begin();
         it != CommandLine::CMD_DESC.end(); it++) {
        std::cout << "  > " << it->first << "\t\t" << it->second << std::endl;
    }
    std::cout << std::endl;
}

void CommandLine::exitCmd()
{
    this->_loop = false;
}

void CommandLine::displayCmd()
{
    if (this->_circuit) {
        std::cout << "tick: " << this->_circuit->getTick() << std::endl;
        std::deque<ComponentContent *> &content = this->_circuit->getContent();
        this->_displayCmdInOut(ComponentType::INPUT, content);
        this->_displayCmdInOut(ComponentType::OUTPUT, content);
        while (content.empty() == false) {
            content.erase(content.begin());
        }
        delete &content;
    } else {
        std::cerr << this->_ERR_NO_CIRCUIT << std::endl;
    }
}

void CommandLine::_displayCmdInOut(
    ComponentType type, std::deque<ComponentContent *> &content)
{
    std::unordered_map<size_t, Tristate> outputs;

    if (type == ComponentType::INPUT)
        std::cout << "input(s):" << std::endl;
    else
        std::cout << "output(s):" << std::endl;
    for (ComponentContent *cc : content) {
        if (cc && cc->getType() == type) {
            outputs = cc->getOutputs();
            if (outputs.size() > 0) {
                std::cout << "  " << cc->getName() << ": " << outputs[0]
                          << std::endl;
            } else {
                std::cout << "  " << cc->getName() << ": " << std::endl;
            }
        }
    }
}

void CommandLine::simulateCmd()
{
    if (this->_circuit) {
        this->_circuit->simulate();
    } else {
        std::cerr << this->_ERR_NO_CIRCUIT << std::endl;
    }
}

static void stopLoopCmd(CommandLine *commandLine)
{
    static CommandLine *cl = nullptr;

    if (commandLine)
        cl = commandLine;
    else if (cl)
        cl->setLoopCmdLoop(false);
}

static void sigintHandler(__attribute__((unused)) int sig)
{
    stopLoopCmd(nullptr);
}

void CommandLine::setLoopCmdLoop(bool status)
{
    this->_loopCmdLoop = status;
}

void CommandLine::loopCmd()
{
    stopLoopCmd(this);
    if (std::signal(SIGINT, &sigintHandler) == SIG_ERR) {
        std::cerr << "Fatal Error: signal fail" << std::endl;
        this->exitCmd();
        return;
    }
    this->_loopCmdLoop = true;
    while (this->_loopCmdLoop) {
        this->simulateCmd();
        this->displayCmd();
        usleep(1000000);
    }
}

void CommandLine::dumpCmd()
{
    if (this->_circuit) {
        this->_circuit->dump();
    } else {
        std::cerr << this->_ERR_NO_CIRCUIT << std::endl;
    }
}

Tristate CommandLine::stateNameToState(const std::string &stateName)
{
    if (stateName == "0") {
        return FALSE;
    } else if (stateName == "1") {
        return TRUE;
    } else {
        return UNDEFINED;
    }
}

void CommandLine::editValueCmd()
{
    std::string compName;
    std::string valueName;

    if (this->_circuit) {
        if (!std::regex_match(
                this->_lastInput, std::regex("^[a-z]+=[01U]$"))) {
            std::cerr << "Error: invalid input format" << std::endl;
            return;
        }
        compName = this->_lastInput.substr(0, this->_lastInput.find('='));
        valueName = this->_lastInput.substr(this->_lastInput.find('=') + 1);
        try {
            Tristate ts = CommandLine::stateNameToState(valueName);
            this->_circuit->setInputComponentValue(compName, ts);
        } catch (const InvalidComponentNameException &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return;
        }
    } else {
        std::cerr << this->_ERR_NO_CIRCUIT << std::endl;
    }
}

void CommandLine::_exceptionHandler()
{
}

void CommandLine::setCircuit(Circuit *circuit)
{
    this->_circuit = circuit;
}