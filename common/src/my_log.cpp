#ifndef _MOBILE_

#include "my_log.h"
#include <iostream>

using std::string;

const string LY_MCAST = "com.luyun.multicast";
const string LY_BCAST = "com.luyun.broadcast";
const string LY_FEED = "com.luyun.feed";

char* find_file_name(const char* name)
{
    int sep = '/';
    if (NULL == name)
    {
        return NULL;
    }

    char *name_start = (char*) strrchr(name, sep);
    return (NULL == name_start) ? (char*) name : (name_start + 1);
}

string GetLogFile(string &file_name)
{
    return "log/" + file_name + ".log";
}

const log4cplus::Logger getLogger(char *argv0)
{
    string file_name = find_file_name(argv0);
    string LogFile = GetLogFile(file_name);

    string cfg = "log4cplus.cfg";
    string CfgFile = "cfg/" + cfg;

    if (access(CfgFile.c_str(), R_OK) != 0)
    {
        std::cerr << "log cfg file wrong!" << CfgFile << std::endl;

        SharedAppenderPtr pFileAppender(new FileAppender((LogFile)));
        std::auto_ptr<Layout> pPatternLayout(
                new PatternLayout("[%p] [%l] [PID:%i] [TID:%t] [%D] - %m %n"));
        pFileAppender->setLayout(pPatternLayout);

        Logger::getInstance(file_name).setLogLevel(DEBUG_LOG_LEVEL);
        Logger::getInstance(file_name).addAppender(pFileAppender);

        return Logger::getInstance(file_name);
    }
    else
    {
//        std::cout << "use default log config" << std::endl;
        PropertyConfigurator::doConfigure(CfgFile);
        return Logger::getInstance(file_name);
    }
}

#endif //_MOBILE_
