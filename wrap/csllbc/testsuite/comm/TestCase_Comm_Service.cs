/**
 * @file    TestCase_Comm_Service.cs
 * @author  Longwei Lai<lailongwei@126.com>
 * @date    2016/01/25
 * @version 1.0
 *
 * @brief
 */

using System;
using llbc;

using Console = llbc.SafeConsole;
using System.Threading;
using System.Net;
using System.IO;
using System.Collections.Generic;
using System.Runtime.Serialization.Formatters.Binary;

class TestCase_Comm_Service : ITestCase
{
    public void Run(string[] args)
    {
        Console.WriteLine("Comm/Service test:");

        // _BaseMethodsTest();
        _StartStopTest();
        // _ListenTest();
        // _ConnectTest();
        // _SendRecvTest();
        // _PreHandleTest();
        // _PacketExcTest();
        // _FrameExcTest();

        Console.WriteLine("Press any key to exit...");
        Console.ReadKey();
    }

    #region BaseMethods test
    private void _BaseMethodsTest()
    {
        Console.WriteLine("BaseMethods test:");

        using (Service svc = new Service("BaseMethodsTest"))
        {
            Console.WriteLine("DriveMode: {0}", svc.driveMode);
            Console.WriteLine("FPS: {0}", svc.fps);
            Console.WriteLine("frameInterval: {0}", svc.frameInterval);
            Console.WriteLine("isStarted: {0}", svc.isStarted);
            Console.WriteLine("svc type: {0}", svc.svcType);

            svc.fps = 1;
            Console.WriteLine("After set fps to 1, FPS: {0}, frameInterval: {1}", svc.fps, svc.frameInterval);

            try
            {
                svc.fps = LibConfig.commMaxServiceFPS + 10;
            }
            catch (Exception e)
            {
                Console.WriteLine("After set fps to {0}, exception occurred, right!", LibConfig.commMaxServiceFPS + 10);
                Console.WriteLine("exception:\n{0}", e);
            }
        }

        Console.WriteLine("Press any key to finish BaseMethods test...");
        Console.ReadKey();
    }
    #endregion

    #region StartStop test
    private void _StartStopTest()
    {
        Console.WriteLine("Start/Stop service test:");

        using (Service svc = new Service("StartStopTest"))
        {
            svc.Start();
            Console.WriteLine("Start service, wait 2 seconds...");
            Thread.Sleep(2000);

            Console.WriteLine("Stop service...");
            svc.Stop();

            Console.WriteLine("ReStart service...");
            svc.Start(2);
            Thread.Sleep(5000);

            Console.WriteLine("Stop service...");
            svc.Stop();
        }

        Console.WriteLine("Press any key to finish Start/Stop service test...");
        Console.ReadKey();
    }

    [BindTo("StartStopTest")]
    class TestFacade_StartStop : IFacade
    {
        public override void OnInit()
        {
            _updateOutputTimes = 0;
            _idleOutputTimes = 0;
            Console.WriteLine("Service [{0}] init", svc.svcName);
        }

        public override void OnDestroy()
        {
            Console.WriteLine("Service [{0}] destroy", svc.svcName);
        }

        public override void OnStart()
        {
            Console.WriteLine("Service [{0}] start", svc.svcName);
        }

        public override void OnStop()
        {
            Console.WriteLine("Service [{0}] stop", svc.svcName);
            _idleOutputTimes = 0;
            _updateOutputTimes = 0;
        }

        public override void OnUpdate()
        {
            if (_updateOutputTimes == 5)
                return;

            Console.WriteLine("Service [{0}] update", svc.svcName);
            _updateOutputTimes += 1;
        }

        public override void OnIdle(int idleTime)
        {
            if (_idleOutputTimes == 5)
                return;

            Console.WriteLine("Service [{0}] idle, idleTime: {1}", svc.svcName, idleTime);
            _idleOutputTimes += 1;
        }

        private int _updateOutputTimes;
        private int _idleOutputTimes;
    }
    #endregion StartStop test

    # region Listen test
    private void _ListenTest()
    {
        Console.WriteLine("Listen test:");

        using (Service svc = new Service("ListenTest"))
        {
            svc.Start();

            IPEndPoint endPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 7788);

            int sessionId = svc.Listen(endPoint);
            Console.WriteLine("Listened on {0}, sessionId: {1}", endPoint, sessionId);

            Console.WriteLine("Remove listen session: {0}", sessionId);
            svc.RemoveSession(sessionId, "Listen test remove", true);

            Console.WriteLine("Press any key to exit listen test...");
            Console.ReadKey();
        }
    }

    [BindTo("ListenTest")]
    class TestFacade_ListenTest : IFacade
    {
        public override void OnInit()
        {
            Console.WriteLine("Service[{0}] init", svc.svcName);
        }

        public override void OnDestroy()
        {
            Console.WriteLine("Service[{0}] destroy", svc.svcName);
        }

        public override void OnSessionCreate(SessionInfo sessionInfo)
        {
            Console.WriteLine("SessionCreate: {0}", sessionInfo);
        }

        public override void OnSessionDestroy(SessionDestroyInfo destroyInfo)
        {
            Console.WriteLine("SessionDestroy: {0}", destroyInfo);
        }
    }
    #endregion

    #region Connect test
    private void _ConnectTest()
    {
        Console.WriteLine("Connect test:");

        using (Service svc = new Service("ConnectTest"))
        {
            svc.Start();

            IPEndPoint endPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 7788);

            // Listen
            int listenSessionId = svc.Listen(endPoint);
            Console.WriteLine("Listened on {0}, sessionId: {1}", endPoint, listenSessionId);
            // Synchronous connect.
            int connSessionId = svc.Connect(endPoint);
            Console.WriteLine("Connected to {0}, sessionId: {1}", endPoint, connSessionId);
            // Asynchronous connect.
            svc.AsyncConn(endPoint);
            // Error endpoint's asynchronous connect.
            svc.AsyncConn(new IPEndPoint(IPAddress.Parse("127.0.0.1"), 7789));

            Console.WriteLine("Press any key to exit connect test...");
            Console.ReadKey();
        }
    }

    [BindTo("ConnectTest")]
    class TestFacade_ConnectTest : IFacade
    {
        public override void OnAsyncConnResult(AsyncConnResult asyncConnResult)
        {
            Console.WriteLine("Async-Connect result: {0}", asyncConnResult);
        }

        public override void OnSessionCreate(SessionInfo sessionInfo)
        {
            Console.WriteLine("New session create: {0}", sessionInfo);
        }

        public override void OnSessionDestroy(SessionDestroyInfo destroyInfo)
        {
            Console.WriteLine("Session destory: {0}", destroyInfo);
        }
    }
    #endregion

    #region SendRecv test
    private void _SendRecvTest()
    {
        Console.WriteLine("Send/Recv test:");
        using (Service svc = new Service("SendRecvTest"))
        {
            svc.Start();

            IPEndPoint ep = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 7788);
            int listenSessionId = svc.Listen(ep);
            Console.WriteLine("Listened on [{0}], sessionId: {1}", ep, listenSessionId);

            int connSessionId = svc.Connect(ep);
            Console.WriteLine("Connected to {0}, sessionId: {1}", ep, connSessionId);

            // Test Send
            TestPacket data = new TestPacket();
            data.intVal = 10086;
            data.strVal = "Hello World";
            svc.Send(connSessionId, data);

            // Test Multicast
            TestMulticastPacket multicastData = new TestMulticastPacket();
            multicastData.intVal = 10010;
            multicastData.strVal = "Multicast data";
            List<int> multicastSessionIds = new List<int>();
            multicastSessionIds.Add(connSessionId);
            svc.Multicast(multicastSessionIds, multicastData);

            // Test Broadcast
            TestBroadcastPacket broadcastData = new TestBroadcastPacket();
            broadcastData.intVal = 8888;
            broadcastData.strVal = "Broadcast data";
            svc.Broadcast(broadcastData);

            // Test unhandled packet
            svc.Send(connSessionId, new UnHandledPacket());

            // Test coder not found
            MemoryStream unhandledStream = new MemoryStream();
            unhandledStream.Write(new byte[30], 0, 30);
            svc.Send(connSessionId, 10086, unhandledStream);

            Console.WriteLine("Press any key to exit Send/Recv test...");
            Console.ReadKey();
        }
    }

    [BindTo("SendRecvTest", "PreHandleTest", "PacketExcTest")]
    class TestPacket : ICoder
    {
        public int intVal;
        public string strVal;

        public bool Encode(MemoryStream stream)
        {
            BinaryFormatter fmter = new BinaryFormatter();
            fmter.Serialize(stream, intVal);
            fmter.Serialize(stream, strVal);

            return true;
        }

        public bool Decode(MemoryStream stream)
        {
            BinaryFormatter fmter = new BinaryFormatter();
            intVal = (int)fmter.Deserialize(stream);
            strVal = fmter.Deserialize(stream) as string;

            return true;
        }
    }

    [BindTo("SendRecvTest")]
    class UnHandledPacket : ICoder
    {
        public bool Encode(MemoryStream stream)
        {
            return true;
        }

        public bool Decode(MemoryStream stream)
        {
            return true;
        }
    }

    [BindTo("SendRecvTest")]
    class TestMulticastPacket : TestPacket
    {
    }

    [BindTo("SendRecvTest")]
    class TestBroadcastPacket : TestPacket
    {
    }

    [BindTo("SendRecvTest")]
    class TestFacade_SendRecvTest : IFacade
    {
        public override void OnInit()
        {
            Console.WriteLine("Service {0} init", svc.svcName);
        }

        public override void OnDestroy()
        {
            Console.WriteLine("Service {0} destroy", svc.svcName);
        }

        public override void OnProtoReport(ProtoReport report)
        {
            Console.WriteLine("Proto report: {0}", report);
        }

        public override void OnUnHandledPacket(Packet packet)
        {
            Console.WriteLine("UnHandled packet: {0}", packet);
        }

        [Handler(typeof(TestPacket))]
        public void OnPacket(Packet packet)
        {
            Console.WriteLine("Recv packet: {0}", packet);
        }

        [Handler(typeof(TestMulticastPacket))]
        public void OnMulticastPacket(Packet packet)
        {
            Console.WriteLine("Recv multicast-packet: {0}", packet);
        }

        [Handler(typeof(TestBroadcastPacket))]
        public void OnBroadcastPacket(Packet packet)
        {
            Console.WriteLine("Recv broadcast packet: {0}", packet);
        }
    }
    #endregion

    #region PreHandle, UnifyPreHandle test
    private void _PreHandleTest()
    {
        Console.WriteLine("PreHandle test:");
        using (Service svc = new Service("PreHandleTest"))
        {
            var facade = new TestFacade_PreHandleTest();
            svc.Start();

            IPEndPoint ep = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 7788);
            int sessionId = svc.Listen(ep);
            Console.WriteLine("Listened on {0}", ep);

            int connSessionId = svc.Connect(ep);
            Console.WriteLine("Connected to {0}, sessionId: {1}", ep, connSessionId);

            TestPacket data = new TestPacket();
            data.intVal = 10086;
            data.strVal = "Hello World";
            svc.Send(connSessionId, data);

            Console.WriteLine("Press any key to exit PreHandle test...");
            Console.ReadKey();
        }
    }

    [BindTo("PreHandleTest")]
    class TestFacade_PreHandleTest : IFacade
    {
        public override void OnInit()
        {
            Console.WriteLine("Service {0} init", svc.svcName);
        }

        public override void OnDestroy()
        {
            Console.WriteLine("Service {0} destroy", svc.svcName);
        }

        [UnifyPreHandler]
        public bool OnUnifyPreHandle(Packet packet)
        {
            Console.WriteLine("OnUnifyPreHandle, packet: {0}", packet);
            return true;
        }

        [PreHandler(typeof(TestPacket))]
        public bool OnPreHandle(Packet packet)
        {
            Console.WriteLine("OnPreHandle, packet: {0}", packet);
            return true;
        }

        [Handler(typeof(TestPacket))]
        public void OnHandle(Packet packet)
        {
            Console.WriteLine("OnHandle, packet: {0}", packet);
        }
    }
    #endregion

    #region PacketException test
    private void _PacketExcTest()
    {
        Console.WriteLine("PacketExc test:");
        using (Service svc = new Service("PacketExcTest"))
        {
            var facade = new TestFacade_PacketExcTest();
            svc.Start();

            IPEndPoint ep = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 7788);
            int listenSessionId = svc.Listen(ep);
            Console.WriteLine("Listened on {0}", ep);

            int connSessionId = svc.Connect(ep);
            Console.WriteLine("Connected to {0}, sessionId: {1}", ep, connSessionId);

            TestPacket data = new TestPacket();
            data.intVal = 10086;
            data.strVal = "Hello World";
            svc.Send(connSessionId, data);

            Console.WriteLine("Press any key to exit PacketExc test...");
            Console.ReadKey();
        }
    }

    [BindTo("PacketExcTest")]
    class TestFacade_PacketExcTest : IFacade
    {
        public override void OnInit()
        {
            Console.WriteLine("Service {0} init", svc.svcName);
        }

        public override void OnDestroy()
        {
            Console.WriteLine("Service {0} destroy", svc.svcName);
        }

        public override void OnSessionDestroy(SessionDestroyInfo destroyInfo)
        {
            Console.WriteLine("Session destroy: {0}", destroyInfo);
        }

        [Handler(typeof(TestPacket))]
        public void OnPacket(Packet packet)
        {
            Console.WriteLine("OnPacket: {0}", packet);
            throw new Exception("Test exception, Yep!");
        }

        [PacketExcHandler(PacketHandlePhase.Handle)]
        public void OnPacketExcHandler(PacketExceptionInfo excInfo)
        {
            Console.WriteLine("Packet exception, phase: {0}, packet: {1}, e: {2}", excInfo.phase, excInfo.packet, excInfo.exception);
        }

        [FrameExcHandler]
        public void OnFrameException(Service svc, Exception e)
        {
            Console.WriteLine("Frame exception: {0}", e);
        }

        [PreHandler(typeof(TestPacket))]
        public bool OnPrePacket(Packet packet)
        {
            Console.WriteLine("OnPrePacket: {0}", packet);
            return true;
        }

        [UnifyPreHandler]
        public bool OnUnifyPrePacket(Packet packet)
        {
            Console.WriteLine("OnUnifyPrePacket: {0}", packet);
            return true;
        }
    }
    #endregion

    #region FrameExc test
    private void _FrameExcTest()
    {
        Console.WriteLine("FrameExc test:");
        using (Service svc = new Service("FrameExcTest"))
        {
            var facade = new TestFacade_FrameExcTest();
            var facade2 = new TestFacade_FrameExcTest2();
            svc.Start();

            Console.WriteLine("Press any key to exit FrameExc test...");
            Console.ReadKey();
        }
    }

    [BindTo("FrameExcTest")]
    class TestFacade_FrameExcTest : IFacade
    {
        public override void OnInit()
        {
            Console.WriteLine("Service {0} init(By Facade)", svc.svcName);
            throw new Exception("Test Exception throw by OnInit!!!");
        }

        public override void OnDestroy()
        {
            Console.WriteLine("Service {0} destroy(By Facade)", svc.svcName);
        }

        [FrameExcHandler]
        public void OnFrameExc(Service svc, Exception e)
        {
            Console.WriteErrorLine("Service {0} exception raised, exception: {1}", svc.svcName, e);
        }
    }

    [BindTo("FrameExcTest")]
    class TestFacade_FrameExcTest2 : IFacade
    {
        public override void OnInit()
        {
            Console.WriteLine("Service {0} init(By Facade2)", svc.svcName);
        }

        public override void OnDestroy()
        {
            Console.WriteLine("Service {0} destroy(By Facade2)", svc.svcName);
        }
    }
    #endregion
}