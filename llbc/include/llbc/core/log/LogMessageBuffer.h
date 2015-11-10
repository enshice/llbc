/**
 * @file    LogMessageBuffer.h
 * @author  Longwei Lai<lailongwei@126.com>
 * @date    2013/11/16
 * @version 1.0
 *
 * @brief
 */
#ifndef __LLBC_CORE_LOG_LOG_MESSAGE_BUFFER_H__
#define __LLBC_CORE_LOG_LOG_MESSAGE_BUFFER_H__

#include "llbc/common/Common.h"

#if LLBC_CFG_LOG_USING_WITH_STREAM

__LLBC_NS_BEGIN

/**
 * \brief The Insertion operator for STL manipulators such as std::fixed.
 */
typedef std::ios_base & (*ios_base_manip)(std::ios_base &);

/**
 * \brief The log message buffer class encapsulation.
 */
class LLBC_EXPORT LLBC_LogMessageBuffer
{
public:
    LLBC_LogMessageBuffer();
    virtual ~LLBC_LogMessageBuffer();

public:
    /**
     * Appends string to buffer.
     * @param[in] msg - msg string to append.
     * @return LLBC_LogMessageBuffer & - message buffer.
     */
    LLBC_LogMessageBuffer &operator <<(const LLBC_String &msg);
    LLBC_LogMessageBuffer &operator <<(const std::basic_string<char> &msg);
    LLBC_LogMessageBuffer &operator <<(char *msg);
    LLBC_LogMessageBuffer &operator <<(const char *msg);
    LLBC_LogMessageBuffer &operator <<(char msg);

    /**
     * Built-in type stream output operator support.
     * @param[in] val - value to append.
     * @return std::basic_ostream<char> & - stream object.
     */
    std::basic_ostream<char> &operator <<(bool val);
    std::basic_ostream<char> &operator <<(uint8 val);
    std::basic_ostream<char> &operator <<(sint16 val);
    std::basic_ostream<char> &operator <<(uint16 val);
    std::basic_ostream<char> &operator <<(sint32 val);
    std::basic_ostream<char> &operator <<(uint32 val);
    std::basic_ostream<char> &operator <<(sint64 val);
    std::basic_ostream<char> &operator <<(uint64 val);
    std::basic_ostream<char> &operator <<(long val);
    std::basic_ostream<char> &operator <<(ulong val);
    std::basic_ostream<char> &operator <<(float val);
    std::basic_ostream<char> &operator <<(double val);
    std::basic_ostream<char> &operator <<(ldouble val);
    std::basic_ostream<char> &operator <<(void *val);

    /**
     * Insertion operator for STL manipulators such as std::fixed.
     */
    std::basic_ostream<char> &operator <<(ios_base_manip manip);

    /**
     * Cast to basic_ostream.
     */
    operator std::basic_ostream<char> &();

public:
    /**
     * Get content of buffer.
     * @return const LLBC_String & - content data.
     */
    const LLBC_String &str(LLBC_LogMessageBuffer &);
    const LLBC_String &str(std::basic_ostream<char> &);

private:
    LLBC_DISABLE_ASSIGNMENT(LLBC_LogMessageBuffer);
    
private:
    LLBC_String _buf;
    std::basic_ostringstream<char> *_stream;
};

__LLBC_NS_END

/**
 * operator << function define, using to adapt other implemented
 * stream output operator's class.
 */
template <typename T>
std::basic_ostream<char> &operator <<(LLBC_NS LLBC_LogMessageBuffer &msg, const T &val);

#include "llbc/core/log/LogMessageBufferImpl.h"

#endif // LLBC_CFG_LOG_USING_WITH_STREAM

#endif // !__LLBC_CORE_LOG_LOG_MESSAGE_BUFFER_H__
