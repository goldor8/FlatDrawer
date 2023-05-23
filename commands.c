//
// Created by Dimitri on 23/05/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "commands.h"
#include "app.h"

Command** CommandList = NULL;
int CommandCount;

void ReadCommand(){
    char* commandString = malloc(sizeof(char) * 100);
    printf(">> ");
    fgets(commandString, 100, stdin);
    commandString[strlen(commandString) - 1] = '\0'; // remove newline

    //count spaces between args
    int argCount = 1;
    for (int i = 0; commandString[i] != '\0'; ++i) {
        if(commandString[i] == ' ') argCount++;
    }

    //split commandString into args
    char** args = malloc(sizeof(char*) * argCount);
    int argIndex = 0;
    int argStart = 0;
    int i = 0;
    do {
        if(commandString[i] == ' ' || commandString[i] == '\0'){
            if(i == argStart){
                argStart++;
                continue;
            }
            args[argIndex] = malloc(sizeof(char) * (i - argStart + 1));
            for (int j = 0; j < i - argStart; ++j) {
                args[argIndex][j] = commandString[argStart + j];
            }
            args[argIndex][i - argStart] = '\0';
            argIndex++;
            argStart = i + 1;
        }
    } while (commandString[i++] != '\0');

    free(commandString);
    ExecuteCommand(args, argIndex);
    for (int j = 0; j < argCount; ++j) {
        free(args[j]);
    }
    free(args);
}
void AddCommand(char* name, char* description, void (*function)(char** args, int argCount), char* argsInfo){
    Command* command = malloc(sizeof(Command));
    command->name = name;
    command->description = description;
    command->function = function;
    command->argsInfo = argsInfo;
    command->subCommandCount = 0;
    command->subCommands = NULL;
    CommandList = realloc(CommandList, sizeof(Command) * (CommandCount + 1));
    CommandList[CommandCount] = command;
    CommandCount++;
}

void AddSubCommand(char* commandPath[], int commandPathLength, char* name, char* description, void (*function)(char** args, int argCount), char* argsInfo){
    Command* command = NULL;
    for (int i = 0; i < CommandCount; ++i) {
        if(strcmp(CommandList[i]->name, commandPath[0]) == 0){
            command = CommandList[i];
            break;
        }
    }
    if(command == NULL){
        printf("Root command not found\n");
        return;
    }
    for (int i = 1; i < commandPathLength; ++i) {
        int found = 0;
        for (int j = 0; j < command->subCommandCount; ++j) {
            if(strcmp(command->subCommands[j]->name, commandPath[i]) == 0){
                command = command->subCommands[j];
                found = 1;
                break;
            }
        }
        if(!found){
            printf("Root command not found\n");
            return;
        }
    }
    Command* subCommand = malloc(sizeof(Command));
    subCommand->name = name;
    subCommand->description = description;
    subCommand->function = function;
    subCommand->argsInfo = argsInfo;
    subCommand->subCommandCount = 0;
    subCommand->subCommands = NULL;
    command->subCommands = realloc(command->subCommands, sizeof(Command) * (command->subCommandCount + 1));
    command->subCommands[command->subCommandCount] = subCommand;
    command->subCommandCount++;
}

void FreeCommands(){
    for (int i = 0; i < CommandCount; ++i) {
        free(CommandList[i]);
    }
    free(CommandList);
}

void ExecuteCommand(char** args, int argCount){
    int success = 0;
    char** commandArgs = malloc(sizeof(char*) * (argCount));
    for (int j = 0; j < argCount; ++j) {
        commandArgs[j] = args[j + 1];
    }

    for (int i = 0; i < CommandCount; ++i) {
        if(strcmp(CommandList[i]->name, args[0]) == 0){
            if(argCount > 1){
                if(strcmp(args[1], "help") == 0){
                    CommandUsage(CommandList[i]);
                    success = 1;
                    break;
                }
                if(TryExecuteSubCommand(commandArgs, argCount - 1, CommandList[i])){
                    success = 1;
                    break;
                }
            }
            if(CommandList[i]->function != NULL)
                CommandList[i]->function(commandArgs, argCount - 1);
            else
                printf("Command not found, type 'help' after a command to get a list of usages\n");
            success = 1;
            break;
        }
    }

    free(commandArgs);
    if(!success)
        printf("Command not found, type 'help' to get a list of available commands\n");
}

int TryExecuteSubCommand(char** args, int argCount, Command* command){
    int success = 0;
    char** commandArgs = malloc(sizeof(char*) * (argCount));
    for (int j = 0; j < argCount; ++j) {
        commandArgs[j] = args[j + 1];
    }

    for (int i = 0; i < command->subCommandCount; ++i) {
        if(strcmp(command->subCommands[i]->name, args[0]) == 0){
            if(argCount > 1){
                if(strcmp(args[1], "help") == 0){
                    CommandUsage(command->subCommands[i]);
                    success = 1;
                    break;
                }
                if(TryExecuteSubCommand(commandArgs, argCount - 1, command->subCommands[i])){
                    success = 1;
                    break;
                }
            }
            if(command->subCommands[i]->function != NULL){
                command->subCommands[i]->function(commandArgs, argCount - 1);
                success = 1;
            }
            break;
        }
    }

    free(commandArgs);
    return success;
}

void PrintCommands(){
    printf("Available commands:\n");
    for (int i = 0; i < CommandCount; ++i) {
        printf("\t - %s: %s\n", CommandList[i]->name, CommandList[i]->description);
    }
}

void CommandUsage(Command* command){
    printf("%s\n", command->description);
    printf("Argument usages:\n");
    if(command->argsInfo != NULL)
        printf("\t%s\n", command->argsInfo);
    if(command->subCommandCount == 0)
        return;
    printf("\nSub commands:\n");
    for (int i = 0; i < command->subCommandCount; ++i) {
        printf("\t - %s: %s\n", command->subCommands[i]->name, command->subCommands[i]->description);
    }
}

int isNumber(char number[])
{
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return 0;
    }
    return 1;
}

void HelpCommand(char** args, int argCount){
    PrintCommands();
}

void ClearCommand(char** args, int argCount){
    ClearLayersAndShapes();
}

void ExitCommand(char** args, int argCount){
    StopApp();
}

void PlotCommand(char** args, int argCount){
    Draw();
}

void AddLayerCommand(char** args, int argCount){
    if(argCount < 1){
        printf("Not enough arguments\n");
        return;
    }
    AddLayer(args[0]);
}

void RemoveLayerCommand(char** args, int argCount){
    if(argCount < 1){
        printf("Not enough arguments\n");
        return;
    }
    RemoveLayer(args[0]);
}

void ListLayersCommand(char** args, int argCount){
    ListLayers();
}

void SelectLayerCommand(char** args, int argCount){
    if(argCount < 1){
        printf("Not enough arguments\n");
        return;
    }
    SetActiveLayer(args[0]);
}

void CreatePointCommand(char** args, int argCount){
    if(argCount < 2){
        printf("Not enough arguments\n");
        return;
    }

    for (int i = 0; i < 2; ++i) {
        if(!isNumber(args[i])){
            printf("Arguments must be numbers\n");
            return;
        }
    }

    int x = (int) strtof(args[0], NULL);
    int y = (int) strtof(args[0], NULL);
    AddShapeToApp(CreatePointShape(x, y));
}

void CreateLineCommand(char** args, int argCount){
    if(argCount < 4){
        printf("Not enough arguments\n");
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if(!isNumber(args[i])){
            printf("Arguments must be numbers\n");
            return;
        }
    }

    int x1 = (int) strtof(args[0], NULL);
    int y1 = (int) strtof(args[1], NULL);
    int x2 = (int) strtof(args[2], NULL);
    int y2 = (int) strtof(args[3], NULL);
    AddShapeToApp(CreateLineShape(x1, y1, x2, y2));
}

void CreateCircleCommand(char** args, int argCount){
    if(argCount < 3){
        printf("Not enough arguments\n");
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if(!isNumber(args[i])){
            printf("Arguments must be numbers\n");
            return;
        }
    }

    int x = (int) strtof(args[0], NULL);
    int y = (int) strtof(args[1], NULL);
    int r = (int) strtof(args[2], NULL);
    AddShapeToApp(CreateCircleShape(x, y, r));
}

void CreateSquareCommand(char** args, int argCount){
    if(argCount < 3){
        printf("Not enough arguments\n");
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if(!isNumber(args[i])){
            printf("Arguments must be numbers\n");
            return;
        }
    }

    int x = (int) strtof(args[0], NULL);
    int y = (int) strtof(args[1], NULL);
    int length = (int) strtof(args[2], NULL);
    AddShapeToApp(CreateSquareShape(x, y, length));
}

void CreateRectangleCommand(char** args, int argCount){
    if(argCount < 4){
        printf("Not enough arguments\n");
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if(!isNumber(args[i])){
            printf("Arguments must be numbers\n");
            return;
        }
    }

    int x = (int) strtof(args[0], NULL);
    int y = (int) strtof(args[1], NULL);
    int width = (int) strtof(args[2], NULL);
    int height = (int) strtof(args[3], NULL);
    AddShapeToApp(CreateRectangleShape(x, y, width, height));
}

void CreatePolygonCommand(char** args, int argCount){
    if(argCount % 2 != 0){
        printf("Not enough arguments\n");
        return;
    }

    for (int i = 0; i < argCount; ++i) {
        if(!isNumber(args[i])){
            printf("Arguments must be numbers\n");
            return;
        }
    }

    int* points = malloc(sizeof(int) * argCount);
    for (int i = 0; i < argCount / 2; ++i) {
        points[i * 2] = (int) strtof(args[i * 2], NULL);
        points[i * 2 + 1] = (int) strtof(args[i * 2 + 1], NULL);
    }
    AddShapeToApp(CreatePolygonShape(points, argCount / 2));
    free(points);
}

void DeleteShapeCommand(char** args, int argCount){
    if(argCount < 1){
        printf("Not enough arguments\n");
        return;
    }

    for (int i = 0; i < 1; ++i) {
        if(!isNumber(args[i])){
            printf("Arguments must be numbers\n");
            return;
        }
    }

    int id = (int) strtof(args[0], NULL);
    RemoveShapeFromApp(id);
}

void ListShapesCommand(char** args, int argCount){
    ListShapes();
}

void SizeCommand(char** args, int argCount){
    if(argCount < 2){
        printf("Not enough arguments\n");
        return;
    }

    for (int i = 0; i < 2; ++i) {
        if(!isNumber(args[i])){
            printf("Arguments must be numbers\n");
            return;
        }
    }

    int width = (int) strtof(args[0], NULL);
    int height = (int) strtof(args[1], NULL);
    SetScreenSize(width, height);
}

void InitCommands(){
    AddCommand("help", "Prints all commands", HelpCommand, NULL);
    AddCommand("clear", "Clears all layers and shapes", ClearCommand, NULL);
    AddCommand("exit", "Exits the application", ExitCommand, NULL);
    AddCommand("plot", "Draws all", PlotCommand, NULL);
    AddCommand("list", "Lists all shapes", ListShapesCommand, NULL);
    AddCommand("size", "Set screen size", SizeCommand, "<width> <height>");

    AddCommand("layer", "Layer commands", NULL, NULL);
    AddSubCommand((char*[]){"layer"}, 1, "add", "Adds a new layer", AddLayerCommand, "<name>");
    AddSubCommand((char*[]){"layer"}, 1, "remove", "Removes a layer", RemoveLayerCommand, "<name>");
    AddSubCommand((char*[]){"layer"}, 1, "list", "Lists all layers", ListLayersCommand, NULL);
    AddSubCommand((char*[]){"layer"}, 1, "select", "Selects a layer", SelectLayerCommand, "<name>");

    AddCommand("point", "Creates a point", CreatePointCommand, "<x> <y>");
    AddCommand("line", "Creates a line", CreateLineCommand, "<x1> <y1> <x2> <y2>");
    AddCommand("circle", "Creates a circle", CreateCircleCommand, "<x> <y> <radius>");
    AddCommand("square", "Creates a square", CreateSquareCommand, "<x> <y> <length>");
    AddCommand("rectangle", "Creates a rectangle", CreateRectangleCommand, "<x> <y> <width> <height>");
    AddCommand("polygon", "Creates a polygon", CreatePolygonCommand, "<x1> <y1> <x2> <y2> ... <xn> <yn>");
    AddCommand("delete", "Deletes a shape", DeleteShapeCommand, "<id>");
}