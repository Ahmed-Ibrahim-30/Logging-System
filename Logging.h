//
// Created by ahmed Ibrahim on 27-Nov-24.
//

#ifndef LOGINSYSTEM_LOGGING_H
#define LOGINSYSTEM_LOGGING_H



#include "LogLevel.h"
#include "iostream"
#include "filesystem"
#include "string"
#include "cstdio"
using namespace std;

class Logging {
private:
    /**
     * Parse Log level To String
     * @param level
     * @return
     */
    static string parseLogLevelToString(LogLevel level);

    /**
     * format Message to String
     * @param level
     * @param message
     * @param fileName
     * @param functionName
     * @param lineNum
     * @return
     */
    static string messageFormatting(LogLevel level , const string &message , string fileName , const string &functionName , int lineNum );
public:
    static void log(LogLevel level , const string &message ,
                    const string &fileName ,
                    const string &functionName ,
                    int lineNum );
    //= __builtin_FUNCTION()
};

#define LOG(level , message) \
    Logging::log(level , message , __FILE__ , __func__ , __LINE__)


#endif //LOGINSYSTEM_LOGGING_H
