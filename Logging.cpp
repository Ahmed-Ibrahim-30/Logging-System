//
// Created by ahmed Ibrahim on 27-Nov-24.
//

#include "Logging.h"

void Logging::log(LogLevel level, const string &message,const string &fileName,const string &functionName, int lineNum) {
    string messageFormatter = messageFormatting(level , message , fileName , functionName , lineNum);

    string colorReset = "\033[0m";

    cout<<messageFormatter + colorReset<<"\n";
}

string Logging::parseLogLevelToString(LogLevel level) {
    string colorReset = "\033[0m";  // Reset to default color
    string logLevelStr;

    switch (level) {
        case LogLevel::Debug:
            logLevelStr = "[DEBUG]";
            return "\033[34m" + logLevelStr ;  // Blue
        case LogLevel::Info:
            logLevelStr = "[INFO]";
            return "\033[32m" + logLevelStr ;  // Green
        case LogLevel::Warning:
            logLevelStr = "[WARNING]";
            return "\033[33m" + logLevelStr ;  // Yellow
        case LogLevel::Error:
            logLevelStr = "[ERROR]";
            return "\033[41m" + logLevelStr ;  // Red
        default:
            logLevelStr = "[UNKNOWN]";
            return colorReset + logLevelStr ;
    }
}

string
Logging::messageFormatting(LogLevel level, const string &message, string fileName, const string &functionName, int lineNum) {
    string messageFormatter;

    string logLevelString = parseLogLevelToString(level);
    string fileNameStr = filesystem::path(fileName).filename().string();
    messageFormatter = logLevelString + "-[" + fileNameStr + "] - " + functionName +" - Line :"+ to_string(lineNum);

    messageFormatter += " - "+ message;
    return messageFormatter;
}