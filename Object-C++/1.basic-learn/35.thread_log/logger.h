/*************************************************************************
	> File Name: logger.h
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月20日 星期日 20时18分42秒
 ************************************************************************/

#ifndef _LOGGER_H
#define _LOGGER_H
#include <iostream>
#include <sstream>
#include <mutex>
#include <map>
#include <string>
#include "color.h"

#define LOG_TRACE(level) worst::worst_log_global(__FILE__, __func__, __TIME__, __LINE__, level)
#define LOG_INFO LOG_TRACE(worst::LogLevel::INFO)
#define LOG_DEBUG LOG_TRACE(worst::LogLevel::DEBUG)
#define LOG_WARN LOG_TRACE(worst::LogLevel::WARN)
#define LOG_ERROR LOG_TRACE(worst::LogLevel::ERROR)
#define LOG_SET(levels) worst::Logger::set_level(levels)

namespace worst {
class LogLevel {
public :
    static const int INFO;
    static const int DEBUG;
    static const int WARN;
    static const int ERROR;
};

const int LogLevel::INFO = 1;
const int LogLevel::DEBUG = 2;
const int LogLevel::WARN = 4;
const int LogLevel::ERROR = 8;

std::map<int, std::string> LogLevelStr = {
    {LogLevel::INFO, "INFO"},
    {LogLevel::DEBUG, "DEBUG"},
    {LogLevel::WARN, "WARN"},
    {LogLevel::ERROR, "ERROR"},
};

class Logger {
    class LoggerStream : public std::ostringstream {
    public :
        LoggerStream(
            Logger &raw_obj,
            const char *file_name,
            const char *func_name,
            const char *current_time,
            int line_no,
            int l)
        : raw_obj(raw_obj),
        line_no(line_no),
        flag(1) {
            std::ostringstream &now = *this;
            now << GREEN"[" << file_name << " project]" << NONE;
            now << YELLOW"[" << current_time << "] " << NONE;
            now << BLUE"[" << func_name << "]" << NONE;
            now << RED"[" << LogLevelStr[l] << "]" << NONE; 
            flag = Logger::logger_level_conf & static_cast<int>(l);
        }
        LoggerStream(const LoggerStream &ls) : raw_obj(ls.raw_obj) {}
        ~LoggerStream() {
            if (flag) output();
        }
    private:
        void output() {
            std::unique_lock<std::mutex> lock(raw_obj.m_mutex);
            std::ostringstream &now = *this;
            now << PINK" (" << line_no << ")" << NONE;
            std::cout << this->str() << std::endl;
            std::cout.flush();
            return ;
        }
        Logger &raw_obj;
        int line_no, flag;
    };
public :
    LoggerStream operator()(
        const char *file_name, 
        const char *func_name,
        const char *current_time,
        int line_no,
        int l) {
        return LoggerStream(*this, file_name, func_name, current_time, line_no, l);
    }
    static void set_level(int levels) {
        Logger::logger_level_conf = levels;
        return ;
    }
private:
    std::mutex m_mutex;
    static int logger_level_conf;
};

int Logger::logger_level_conf = 0;

Logger worst_log_global;
}

#endif
