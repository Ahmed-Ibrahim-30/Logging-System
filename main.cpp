#include <iostream>
#include "Logging.h"
int main() {
    LOG(LogLevel::Info , "Info LOG");
    LOG(LogLevel::Debug , "Debug LOG");
    LOG(LogLevel::Error , "Error LOG");
    LOG(LogLevel::Warning , "Warning LOG");
    return 0;
}
