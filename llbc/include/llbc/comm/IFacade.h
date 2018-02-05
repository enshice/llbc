/**
 * @file    IFacade.h
 * @author  Longwei Lai<lailongwei@126.com>
 * @date    2013/06/17
 * @version 1.0
 *
 * @brief
 */
#ifndef __LLBC_COMM_IFACADE_H__
#define __LLBC_COMM_IFACADE_H__

#include "llbc/common/Common.h"
#include "llbc/core/Core.h"
#include "llbc/objbase/ObjBase.h"

__LLBC_NS_BEGIN

/**
 * Previous declare Packet/Session/Service class.
 */
class LLBC_Packet;
class LLBC_IService;
class LLBC_SessionCloseInfo;

__LLBC_NS_END

__LLBC_NS_BEGIN

/**
 * \brief The session info class encapsulation.
 */
class LLBC_EXPORT LLBC_SessionInfo
{
public:
    /**
     * Constructor & Destructor.
     */
    LLBC_SessionInfo();
    ~LLBC_SessionInfo();

public:
    /**
     * Get the session Id.
     * @return int - the session Id.
     */
    int GetSessionId() const;
    /**
     * Set the session Id.
     * @param[in] sessionId - the session Id.
     */
    void SetSessionId(int sessionId);

    /**
     * Confirm this create session is listen session.
     * @return bool - return true is this session is listen session, otherwise return false.
     */
    bool IsListenSession() const;
    /**
     * Set session listen flag.
     * @param[in] flag - the session listen flag.
     */
    void SetIsListenSession(bool flag);

    /**
     * Get local address.
     * @return const LLBC_SockAddr_IN & - the local address.
     */
    const LLBC_SockAddr_IN &GetLocalAddr() const;
    /**
     * Set local address.
     * @param[in] addr - the local address.
     */
    void SetLocalAddr(const LLBC_SockAddr_IN &addr);

    /**
     * Get peer address.
     * @return const LLBC_SockAddr_IN & - the peer address.
     */
    const LLBC_SockAddr_IN &GetPeerAddr() const;
    /**
     * Set peer address.
     * @param[in] addr - the peer address.
     */
    void SetPeerAddr(const LLBC_SockAddr_IN &addr);

    /**
     * Get session socket handle.
     *   Note: Unsafe, if its not necessary, do not use it.
     * @return LLBC_SocketHandle - the socket handle.
     */
    LLBC_SocketHandle GetSocket() const;
    /**
     * Set session socket handle.
     * @param[in] handle - the socket handle.
     */
    void SetSocket(LLBC_SocketHandle handle);

public:
    /**
     * Get SessionInfo clas string representation.
     * @return LLBC_String - the session string representation.
     */
    LLBC_String ToString() const;

private:
    int _sessionId;
    bool _isListen;
    LLBC_SockAddr_IN _localAddr;
    LLBC_SockAddr_IN _peerAddr;
    LLBC_SocketHandle _sockHandle;
};

/**
 * \brief The session destroy information class encapsulation.
 */
class LLBC_EXPORT LLBC_SessionDestroyInfo
{
public:
    LLBC_SessionDestroyInfo(LLBC_SessionInfo *sessionInfo, 
                            LLBC_SessionCloseInfo *closeInfo);
    ~LLBC_SessionDestroyInfo();

public:
    /**
     * Get destroyed session information.
     */
    const LLBC_SessionInfo &GetSessionInfo() const;

    /**
     * Help methods about get session infos.
     */
    int GetSessionId() const;
    bool IsListenSession() const;
    LLBC_SocketHandle GetSocket() const;
    const LLBC_SockAddr_IN &GetLocalAddr() const;
    const LLBC_SockAddr_IN &GetPeerAddr() const;

public:
    /**
     * Is destroy from service layer flag getter.
     */
    bool IsDestroyedFromService() const;

    /**
    * Error No getter, available while IsDestroyedFromService() == false.
    */
    int GetErrno() const;

    /**
    * SubError No getter, available while IsDestroyedFromService() == false.
    */
    int GetSubErrno() const;

    /**
    * Reason getter.
    * Note: If is destroyed from service, it return Service destroy reason, otherwise return 
    *       network network layer error reason(Call LLBC_StrError() to get).
    */
    const LLBC_String &GetReason() const;

public:
    /**
     * Get the class object string representation.
     * @return LLBC_String - the string representation.
     */
    LLBC_String ToString() const;

private:
    LLBC_SessionInfo *_sessionInfo;
    LLBC_SessionCloseInfo *_closeInfo;
};

/**
 * \brief The asynchronous connect result info class encapsulation.
 */
class LLBC_EXPORT LLBC_AsyncConnResult
{
public:
    /**
     * Constructor & Destructor.
     */
    LLBC_AsyncConnResult();
    ~LLBC_AsyncConnResult();

public:
    /**
     * Get connected flag.
     * @return bool - the connected flag.
     */
    bool IsConnected() const;
    /**
     * Set connected flag.
     * @param[in] connected - the connected flag.
     */
    void SetIsConnected(bool connected);

    /**
     * Get last error.
     * @return const LLBC_String & - the reason.
     */
    const LLBC_String &GetReason() const;
    /**
     * Set reason.
     * @param[in] reason - the reason.
     */
    void SetReason(const LLBC_String &reason);

    /**
     * Get peer address.
     * @return const LLBC_SockAddr_IN & - the peer address.
     */
    const LLBC_SockAddr_IN &GetPeerAddr() const;
    /**
     * Set peer address.
     * @param[in] addr - the peer address.
     */
    void SetPeerAddr(const LLBC_SockAddr_IN &addr);

public:
    /**
     * Get this class object string representation.
     * @return LLBC_String - the string representation.
     */
    LLBC_String ToString() const;

private:
    int _sessionId;
    bool _connected;
    LLBC_String _reason;
    LLBC_SockAddr_IN _peerAddr;
};

/**
 * \brief The protocol stack report class encapsulation.
 */
class LLBC_EXPORT LLBC_ProtoReport
{
public:
    /**
     * Constructor & Destructor.
     */
    LLBC_ProtoReport();
    ~LLBC_ProtoReport();

public:
    /**
     * Session getter & setter.
     */
    int GetSessionId() const;
    void SetSessionId(int sessionId);

    /**
     * Opcode getter & setter.
     */
    int GetOpcode() const;
    void SetOpcode(int opcode);

    /**
     * Layer getter & setter.
     */
    int GetLayer() const;
    void SetLayer(int layer);

    /**
     * Report level getter & setter.
     * To get more about level information, see ProtoReportLevel.h header file.
     */
    int GetLevel() const;
    void SetLevel(int level);

    /**
     * Report string getter & setter.
     */
    const LLBC_String &GetReport() const;
    void SetReport(const LLBC_String &report);

public:
    /**
     * Get this class string representation.
     * @return LLBC_String - the string representation.
     */
    LLBC_String ToString() const;

private:
    int _sessionId;
    int _opcode;

    int _layer;
    int _level;
    LLBC_String _report;
};

/**
 * \brief The facade interface class encapsulation.
 */
class LLBC_EXPORT LLBC_IFacade
{
public:
    LLBC_IFacade();
    virtual ~LLBC_IFacade();

public:
    /**
     * Get service.
     * @return LLBC_IService * - service object.
     */
    virtual LLBC_IService *GetService() const;

public:
    /**
     * When service start and not not init facade before, will call then event handler function.
     */
    virtual void OnInitialize();

    /**
     * When service destroy, will call this event handler function.
     */
    virtual void OnDestroy();

    /**
     * When service start, will call this event handler function.
     */
    virtual void OnStart();

    /**
     * When service stop, will call this event handler function.
     */
    virtual void OnStop();

public:
    /**
     * Heartbeat function.
     */
    virtual void OnUpdate();

    /**
     * Idle event handler.
     * @param[in] idleTime - idle time, in milliseconds.
     */
    virtual void OnIdle(int idleTime);

public:
    /**
     * When new session create, will call this event handler.
     * @param[in] sessionInfo - the session info.
     */
    virtual void OnSessionCreate(const LLBC_SessionInfo &sessionInfo);

    /**
     * When session destroy, will call this event handler.
     * @param[in] destroyInfo - the session destroy info.
     */
    virtual void OnSessionDestroy(const LLBC_SessionDestroyInfo &destroyInfo);

    /**
     * When asynchronous connect result, will call this event handler.
     * @param[in] result - asynchronous connect result data.
     */
    virtual void OnAsyncConnResult(const LLBC_AsyncConnResult &result);

public:
    /**
     * When protocol layer report something, will call this event handler.
     * @param[in] layer  - protocol layer.
     * @param[in] report - the report string.
     */
    virtual void OnProtoReport(const LLBC_ProtoReport &report);

    /**
     * When service receive a unhandled packet, will call this event handler.
     * @param[in] packet - the unhandled packet.
     */
    virtual void OnUnHandledPacket(const LLBC_Packet &packet);

private:
    /**
     * Friend class: LLBC_Service.
     *  Access methods:
     *      void SetService()
     * Access data members:
     *      _inited;
     */
    friend class LLBC_Service;

    /**
     * Set service.
     * @param[in] service - service object.
     */
    virtual void SetService(LLBC_IService *service);

private:
    bool _inited;
    LLBC_IService *_svc;
};

__LLBC_NS_END

/**
 * Some stream output operator functions(in global ns).
 */
LLBC_EXTERN LLBC_EXPORT std::ostream &operator <<(std::ostream &o, const LLBC_NS LLBC_SessionInfo &si);
LLBC_EXTERN LLBC_EXPORT std::ostream &operator <<(std::ostream &o, const LLBC_NS LLBC_SessionDestroyInfo &destroy);
LLBC_EXTERN LLBC_EXPORT std::ostream &operator <<(std::ostream &o, const LLBC_NS LLBC_AsyncConnResult &result);
LLBC_EXTERN LLBC_EXPORT std::ostream &operator <<(std::ostream &o, const LLBC_NS LLBC_ProtoReport &report);

#endif // !__LLBC_COMM_IFACADE_H__
