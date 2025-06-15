#ifndef LOGGER_H
#define LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

// Default log level
#define LOG_LEVEL_ERR   1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_INFO  3
#define LOG_LEVEL_DBG   4

// basic logging macro
#define MSG(f, ...) printf(f, ##__VA_ARGS__)

// Macros for different Log message
#ifdef LOG_LEVEL
#if LOG_LEVEL < LOG_LEVEL_ERR || LOG_LEVEL > LOG_LEVEL_DBG
#error "Wrong log level"
#endif
#else
#define LOG_LEVEL   LOG_LEVEL_DBG
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERR
#define ERROR(f, ...)  fprintf(stderr, "[ERR ] " f "\n", ##__VA_ARGS__)
#else
#define ERROR(f, ...) 
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#define WARN(f, ...)  fprintf(stderr, "[WARN] " f "\n", ##__VA_ARGS__)
#else
#define WARN(f, ...) 
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
#define INFO(f, ...)   fprintf(stdout, "[INFO] " f "\n", ##__VA_ARGS__)
#else
#define INFO(f, ...) 
#endif

#if LOG_LEVEL >= LOG_LEVEL_DBG
#define DEBUG(f, ...)  fprintf(stdout, "[DBG ] " f "\n", ##__VA_ARGS__)
#else
#define DEBUG(f, ...) 
#endif

// Assert wrapper
#define ASSERT(x) if(!(x))fflush(stdout);assert((x))
#define ASSERT_MSG(x, msg) if(!(x)){fflush(stdout);ERROR(msg);} ASSERT(x)

#ifdef __cplusplus
}
#endif

#endif //LOGGER_H