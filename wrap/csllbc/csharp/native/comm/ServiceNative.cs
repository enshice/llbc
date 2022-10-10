// The MIT License (MIT)

// Copyright (c) 2013-2022 lailongwei<lailongwei@126.com>
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of 
// this software and associated documentation files (the "Software"), to deal in 
// the Software without restriction, including without limitation the rights to 
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of 
// the Software, and to permit persons to whom the Software is furnished to do so, 
// subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all 
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS 
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER 
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

//!!! This file is auto generated by script tool, do not modify it!!!

using System;
using System.Runtime.InteropServices;

namespace llbc
{

    /// <summary>
    /// Wrap comm/_Service.h file defined c functions
    /// </summary>
    internal partial class LLBCNative
    {
        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr csllbc_Service_Create(IntPtr svcName,
                                                          bool useNormalProtocolFactory,
                                                          bool fullStack,
                                                          Deleg_Service_EncodePacket encodeDeleg,
                                                          Deleg_Service_DecodePacket decodeDeleg,
                                                          Deleg_Service_PacketHandler handlerDeleg,
                                                          Deleg_Service_PacketPreHandler preHandlerDeleg,
                                                          Deleg_Service_PacketUnifyPreHandler unifyPreHandlerDeleg,
                                                          Deleg_Service_NativeCouldNotFoundDecoderReport notFoundDecoderDeleg);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static void csllbc_Service_Delete(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_GetId(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_IsFullStack(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_GetDriveMode(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_SetDriveMode(IntPtr svc, int driveMode);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Start(IntPtr svc, int pollerCount);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static void csllbc_Service_Stop(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_IsStarted(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_GetFPS(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_SetFPS(IntPtr svc, int fps);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_GetFrameInterval(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Listen(IntPtr svc, IntPtr ip, int port);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Connect(IntPtr svc, IntPtr ip, int port);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_AsyncConn(IntPtr svc, IntPtr ip, int port);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_RemoveSession(IntPtr svc, int sessionId, IntPtr reason, int reasonLen);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_IsSessionValidate(IntPtr svc, int sessionId);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_SendBytes(IntPtr svc,
                                                          int sessionId,
                                                          int opcode,
                                                          IntPtr data,
                                                          int dataLen,
                                                          int status);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_SendPacket(IntPtr svc,
                                                           int sessionId,
                                                           int opcode,
                                                           long packetId,
                                                           int status);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Multicast(IntPtr svc,
                                                          IntPtr sessionIds,
                                                          int sessionIdCount,
                                                          int opcode,
                                                          IntPtr data,
                                                          int dataLen,
                                                          int status);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Broadcast(IntPtr svc,
                                                          int opcode,
                                                          IntPtr data,
                                                          int dataLen,
                                                          int status);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_AddComponent(IntPtr svc,
                                                             Deleg_Comp_OnInit initDeleg,
                                                             Deleg_Comp_OnDestroy destroyDeleg,
                                                             Deleg_Comp_OnStart startDeleg,
                                                             Deleg_Comp_OnStop stopDeleg,
                                                             Deleg_Comp_OnUpdate updateDeleg,
                                                             Deleg_Comp_OnIdle idleDeleg,
                                                             Deleg_Comp_OnSessionCreate sessionCreateDeleg,
                                                             Deleg_Comp_OnSessionDestroy sessionDestroyDeleg,
                                                             Deleg_Comp_OnAsyncConnResult asyncConnResultDeleg,
                                                             Deleg_Comp_OnProtoReport protoReportDeleg,
                                                             Deleg_Comp_OnUnHandledPacket unHandledPacketDeleg);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_AddCoder(IntPtr svc, int opcode);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_Subscribe(IntPtr svc, int opcode);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_PreSubscribe(IntPtr svc, int opcode);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static int csllbc_Service_UnifyPreSubscribe(IntPtr svc);

        [DllImport(NativeLibName, CallingConvention = CallingConvention.Cdecl)]
        public extern static void csllbc_Service_OnSvc(IntPtr svc, bool fullFrame);
    }
}
