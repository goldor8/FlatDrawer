//
// Created by Dimitri on 23/05/2023.
//

#ifndef FLATDRAWER_COMMANDS_H
#define FLATDRAWER_COMMANDS_H

typedef struct command{
    char* name;
    char* description;
    struct command** subCommands;
    int subCommandCount;
    void (*function)(char** args, int argCount);
    char* argsInfo;
} Command;

void InitCommands();
void ReadCommand();
void AddCommand(char* name, char* description, void (*function)(char** args, int argCount), char* argsInfo);
void AddSubCommand(char* commandPath[], int commandPathLength, char* name, char* description, void (*function)(char** args, int argCount), char* argsInfo);
void FreeCommands();
void ExecuteCommand(char** args, int argCount);
int TryExecuteSubCommand(char** args, int argCount, Command* command);
void PrintCommands();
void CommandUsage(Command* command);


#endif //FLATDRAWER_COMMANDS_H
