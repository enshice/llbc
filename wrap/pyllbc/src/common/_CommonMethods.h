/**
 *@file		_CommonMethods.h
 *@author	Longwei Lai<lailongwei@126.com>
 *@date		<auto generate code, not tag date>
 *@version	1.0
 *
 *@brief	Auto generate by script tools, do not modify this file!!
 */

#ifndef __PYLLBC_AUTOGEN__COMMONMETHODS_H__
#define __PYLLBC_AUTOGEN__COMMONMETHODS_H__

#include "pyllbc/common/LibHeader.h"
#include "src/common/_PyStream.h"
#include "src/common/_SecurePrint.h"
#include "src/common/_VerInfo.h"

class pyllbc_CommonMethods{
public:
    pyllbc_CommonMethods()
    {
        PyStreamFmtWrite.ml_name = "PyStreamFmtWrite";
        PyStreamFmtWrite.ml_meth = (PyCFunction)_pyllbc_PyStreamFmtWrite;
        PyStreamFmtWrite.ml_flags = METH_VARARGS;
        PyStreamFmtWrite.ml_doc = "pyllbc library method/function";
        PyStreamRead_Double.ml_name = "PyStreamRead_Double";
        PyStreamRead_Double.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Double;
        PyStreamRead_Double.ml_flags = METH_VARARGS;
        PyStreamRead_Double.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Bool.ml_name = "PyStreamWrite_Bool";
        PyStreamWrite_Bool.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Bool;
        PyStreamWrite_Bool.ml_flags = METH_VARARGS;
        PyStreamWrite_Bool.ml_doc = "pyllbc library method/function";
        PyStreamRead_Byte.ml_name = "PyStreamRead_Byte";
        PyStreamRead_Byte.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Byte;
        PyStreamRead_Byte.ml_flags = METH_VARARGS;
        PyStreamRead_Byte.ml_doc = "pyllbc library method/function";
        SetPyStreamPos.ml_name = "SetPyStreamPos";
        SetPyStreamPos.ml_meth = (PyCFunction)_pyllbc_SetPyStreamPos;
        SetPyStreamPos.ml_flags = METH_VARARGS;
        SetPyStreamPos.ml_doc = "pyllbc library method/function";
        PyStreamRead_Stream.ml_name = "PyStreamRead_Stream";
        PyStreamRead_Stream.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Stream;
        PyStreamRead_Stream.ml_flags = METH_VARARGS;
        PyStreamRead_Stream.ml_doc = "pyllbc library method/function";
        PyStreamWrite.ml_name = "PyStreamWrite";
        PyStreamWrite.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite;
        PyStreamWrite.ml_flags = METH_VARARGS;
        PyStreamWrite.ml_doc = "pyllbc library method/function";
        NewPyStream.ml_name = "NewPyStream";
        NewPyStream.ml_meth = (PyCFunction)_pyllbc_NewPyStream;
        NewPyStream.ml_flags = METH_VARARGS;
        NewPyStream.ml_doc = "pyllbc library method/function";
        PyStreamRead.ml_name = "PyStreamRead";
        PyStreamRead.ml_meth = (PyCFunction)_pyllbc_PyStreamRead;
        PyStreamRead.ml_flags = METH_VARARGS;
        PyStreamRead.ml_doc = "pyllbc library method/function";
        GetPyStreamPos.ml_name = "GetPyStreamPos";
        GetPyStreamPos.ml_meth = (PyCFunction)_pyllbc_GetPyStreamPos;
        GetPyStreamPos.ml_flags = METH_VARARGS;
        GetPyStreamPos.ml_doc = "pyllbc library method/function";
        PyStreamFmtRead.ml_name = "PyStreamFmtRead";
        PyStreamFmtRead.ml_meth = (PyCFunction)_pyllbc_PyStreamFmtRead;
        PyStreamFmtRead.ml_flags = METH_VARARGS;
        PyStreamFmtRead.ml_doc = "pyllbc library method/function";
        PyStreamWrite_PyLong.ml_name = "PyStreamWrite_PyLong";
        PyStreamWrite_PyLong.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_PyLong;
        PyStreamWrite_PyLong.ml_flags = METH_VARARGS;
        PyStreamWrite_PyLong.ml_doc = "pyllbc library method/function";
        PyStreamRead_ByteArray.ml_name = "PyStreamRead_ByteArray";
        PyStreamRead_ByteArray.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_ByteArray;
        PyStreamRead_ByteArray.ml_flags = METH_VARARGS;
        PyStreamRead_ByteArray.ml_doc = "pyllbc library method/function";
        PyStreamRead_Bool.ml_name = "PyStreamRead_Bool";
        PyStreamRead_Bool.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Bool;
        PyStreamRead_Bool.ml_flags = METH_VARARGS;
        PyStreamRead_Bool.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Int16.ml_name = "PyStreamWrite_Int16";
        PyStreamWrite_Int16.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Int16;
        PyStreamWrite_Int16.ml_flags = METH_VARARGS;
        PyStreamWrite_Int16.ml_doc = "pyllbc library method/function";
        PyStreamGetCachedSize.ml_name = "PyStreamGetCachedSize";
        PyStreamGetCachedSize.ml_meth = (PyCFunction)_pyllbc_PyStreamGetCachedSize;
        PyStreamGetCachedSize.ml_flags = METH_VARARGS;
        PyStreamGetCachedSize.ml_doc = "pyllbc library method/function";
        PyStreamRead_Str.ml_name = "PyStreamRead_Str";
        PyStreamRead_Str.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Str;
        PyStreamRead_Str.ml_flags = METH_VARARGS;
        PyStreamRead_Str.ml_doc = "pyllbc library method/function";
        DelPyStream.ml_name = "DelPyStream";
        DelPyStream.ml_meth = (PyCFunction)_pyllbc_DelPyStream;
        DelPyStream.ml_flags = METH_VARARGS;
        DelPyStream.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Double.ml_name = "PyStreamWrite_Double";
        PyStreamWrite_Double.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Double;
        PyStreamWrite_Double.ml_flags = METH_VARARGS;
        PyStreamWrite_Double.ml_doc = "pyllbc library method/function";
        PyStreamDiscardAllExprs.ml_name = "PyStreamDiscardAllExprs";
        PyStreamDiscardAllExprs.ml_meth = (PyCFunction)_pyllbc_PyStreamDiscardAllExprs;
        PyStreamDiscardAllExprs.ml_flags = METH_VARARGS;
        PyStreamDiscardAllExprs.ml_doc = "pyllbc library method/function";
        PyStreamRead_Int16.ml_name = "PyStreamRead_Int16";
        PyStreamRead_Int16.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Int16;
        PyStreamRead_Int16.ml_flags = METH_VARARGS;
        PyStreamRead_Int16.ml_doc = "pyllbc library method/function";
        PyStreamRead_Int32.ml_name = "PyStreamRead_Int32";
        PyStreamRead_Int32.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Int32;
        PyStreamRead_Int32.ml_flags = METH_VARARGS;
        PyStreamRead_Int32.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Buffer.ml_name = "PyStreamWrite_Buffer";
        PyStreamWrite_Buffer.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Buffer;
        PyStreamWrite_Buffer.ml_flags = METH_VARARGS;
        PyStreamWrite_Buffer.ml_doc = "pyllbc library method/function";
        SetPyStreamEndian.ml_name = "SetPyStreamEndian";
        SetPyStreamEndian.ml_meth = (PyCFunction)_pyllbc_SetPyStreamEndian;
        SetPyStreamEndian.ml_flags = METH_VARARGS;
        SetPyStreamEndian.ml_doc = "pyllbc library method/function";
        PyStreamRead_Float.ml_name = "PyStreamRead_Float";
        PyStreamRead_Float.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Float;
        PyStreamRead_Float.ml_flags = METH_VARARGS;
        PyStreamRead_Float.ml_doc = "pyllbc library method/function";
        GetVersionInfo.ml_name = "GetVersionInfo";
        GetVersionInfo.ml_meth = (PyCFunction)_pyllbc_GetVersionInfo;
        GetVersionInfo.ml_flags = METH_VARARGS;
        GetVersionInfo.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Byte.ml_name = "PyStreamWrite_Byte";
        PyStreamWrite_Byte.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Byte;
        PyStreamWrite_Byte.ml_flags = METH_VARARGS;
        PyStreamWrite_Byte.ml_doc = "pyllbc library method/function";
        PyStreamRead_Str2.ml_name = "PyStreamRead_Str2";
        PyStreamRead_Str2.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Str2;
        PyStreamRead_Str2.ml_flags = METH_VARARGS;
        PyStreamRead_Str2.ml_doc = "pyllbc library method/function";
        PyStreamRead_Buffer.ml_name = "PyStreamRead_Buffer";
        PyStreamRead_Buffer.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Buffer;
        PyStreamRead_Buffer.ml_flags = METH_VARARGS;
        PyStreamRead_Buffer.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Float.ml_name = "PyStreamWrite_Float";
        PyStreamWrite_Float.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Float;
        PyStreamWrite_Float.ml_flags = METH_VARARGS;
        PyStreamWrite_Float.ml_doc = "pyllbc library method/function";
        PyStreamDiscardExpr.ml_name = "PyStreamDiscardExpr";
        PyStreamDiscardExpr.ml_meth = (PyCFunction)_pyllbc_PyStreamDiscardExpr;
        PyStreamDiscardExpr.ml_flags = METH_VARARGS;
        PyStreamDiscardExpr.ml_doc = "pyllbc library method/function";
        SetPyStreamSize.ml_name = "SetPyStreamSize";
        SetPyStreamSize.ml_meth = (PyCFunction)_pyllbc_SetPyStreamSize;
        SetPyStreamSize.ml_flags = METH_VARARGS;
        SetPyStreamSize.ml_doc = "pyllbc library method/function";
        GetPyStreamEndian.ml_name = "GetPyStreamEndian";
        GetPyStreamEndian.ml_meth = (PyCFunction)_pyllbc_GetPyStreamEndian;
        GetPyStreamEndian.ml_flags = METH_VARARGS;
        GetPyStreamEndian.ml_doc = "pyllbc library method/function";
        PyStreamRead_None.ml_name = "PyStreamRead_None";
        PyStreamRead_None.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_None;
        PyStreamRead_None.ml_flags = METH_VARARGS;
        PyStreamRead_None.ml_doc = "pyllbc library method/function";
        PyStreamWrite_PyInt.ml_name = "PyStreamWrite_PyInt";
        PyStreamWrite_PyInt.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_PyInt;
        PyStreamWrite_PyInt.ml_flags = METH_VARARGS;
        PyStreamWrite_PyInt.ml_doc = "pyllbc library method/function";
        PyStreamWrite_ByteArray.ml_name = "PyStreamWrite_ByteArray";
        PyStreamWrite_ByteArray.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_ByteArray;
        PyStreamWrite_ByteArray.ml_flags = METH_VARARGS;
        PyStreamWrite_ByteArray.ml_doc = "pyllbc library method/function";
        GetPyStreamSize.ml_name = "GetPyStreamSize";
        GetPyStreamSize.ml_meth = (PyCFunction)_pyllbc_GetPyStreamSize;
        GetPyStreamSize.ml_flags = METH_VARARGS;
        GetPyStreamSize.ml_doc = "pyllbc library method/function";
        PyStreamRead_PyInt.ml_name = "PyStreamRead_PyInt";
        PyStreamRead_PyInt.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_PyInt;
        PyStreamRead_PyInt.ml_flags = METH_VARARGS;
        PyStreamRead_PyInt.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Str.ml_name = "PyStreamWrite_Str";
        PyStreamWrite_Str.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Str;
        PyStreamWrite_Str.ml_flags = METH_VARARGS;
        PyStreamWrite_Str.ml_doc = "pyllbc library method/function";
        PyStreamWrite_None.ml_name = "PyStreamWrite_None";
        PyStreamWrite_None.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_None;
        PyStreamWrite_None.ml_flags = METH_VARARGS;
        PyStreamWrite_None.ml_doc = "pyllbc library method/function";
        PyStreamGetCacheLimit.ml_name = "PyStreamGetCacheLimit";
        PyStreamGetCacheLimit.ml_meth = (PyCFunction)_pyllbc_PyStreamGetCacheLimit;
        PyStreamGetCacheLimit.ml_flags = METH_VARARGS;
        PyStreamGetCacheLimit.ml_doc = "pyllbc library method/function";
        PyStreamRead_Int64.ml_name = "PyStreamRead_Int64";
        PyStreamRead_Int64.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Int64;
        PyStreamRead_Int64.ml_flags = METH_VARARGS;
        PyStreamRead_Int64.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Int32.ml_name = "PyStreamWrite_Int32";
        PyStreamWrite_Int32.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Int32;
        PyStreamWrite_Int32.ml_flags = METH_VARARGS;
        PyStreamWrite_Int32.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Int64.ml_name = "PyStreamWrite_Int64";
        PyStreamWrite_Int64.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Int64;
        PyStreamWrite_Int64.ml_flags = METH_VARARGS;
        PyStreamWrite_Int64.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Sequence.ml_name = "PyStreamWrite_Sequence";
        PyStreamWrite_Sequence.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Sequence;
        PyStreamWrite_Sequence.ml_flags = METH_VARARGS;
        PyStreamWrite_Sequence.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Tuple.ml_name = "PyStreamWrite_Tuple";
        PyStreamWrite_Tuple.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Tuple;
        PyStreamWrite_Tuple.ml_flags = METH_VARARGS;
        PyStreamWrite_Tuple.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Dict.ml_name = "PyStreamWrite_Dict";
        PyStreamWrite_Dict.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Dict;
        PyStreamWrite_Dict.ml_flags = METH_VARARGS;
        PyStreamWrite_Dict.ml_doc = "pyllbc library method/function";
        PyStreamRead_PyLong.ml_name = "PyStreamRead_PyLong";
        PyStreamRead_PyLong.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_PyLong;
        PyStreamRead_PyLong.ml_flags = METH_VARARGS;
        PyStreamRead_PyLong.ml_doc = "pyllbc library method/function";
        PyStreamRead_Unicode.ml_name = "PyStreamRead_Unicode";
        PyStreamRead_Unicode.ml_meth = (PyCFunction)_pyllbc_PyStreamRead_Unicode;
        PyStreamRead_Unicode.ml_flags = METH_VARARGS;
        PyStreamRead_Unicode.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Unicode.ml_name = "PyStreamWrite_Unicode";
        PyStreamWrite_Unicode.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Unicode;
        PyStreamWrite_Unicode.ml_flags = METH_VARARGS;
        PyStreamWrite_Unicode.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Str2.ml_name = "PyStreamWrite_Str2";
        PyStreamWrite_Str2.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Str2;
        PyStreamWrite_Str2.ml_flags = METH_VARARGS;
        PyStreamWrite_Str2.ml_doc = "pyllbc library method/function";
        PyStreamWrite_List.ml_name = "PyStreamWrite_List";
        PyStreamWrite_List.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_List;
        PyStreamWrite_List.ml_flags = METH_VARARGS;
        PyStreamWrite_List.ml_doc = "pyllbc library method/function";
        PyStreamWrite_Stream.ml_name = "PyStreamWrite_Stream";
        PyStreamWrite_Stream.ml_meth = (PyCFunction)_pyllbc_PyStreamWrite_Stream;
        PyStreamWrite_Stream.ml_flags = METH_VARARGS;
        PyStreamWrite_Stream.ml_doc = "pyllbc library method/function";
        PyStreamSetRaw.ml_name = "PyStreamSetRaw";
        PyStreamSetRaw.ml_meth = (PyCFunction)_pyllbc_PyStreamSetRaw;
        PyStreamSetRaw.ml_flags = METH_VARARGS;
        PyStreamSetRaw.ml_doc = "pyllbc library method/function";
        output.ml_name = "output";
        output.ml_meth = (PyCFunction)_pyllbc_output;
        output.ml_flags = METH_VARARGS;
        output.ml_doc = "pyllbc library method/function";
        PyStreamEncodeSelf.ml_name = "PyStreamEncodeSelf";
        PyStreamEncodeSelf.ml_meth = (PyCFunction)_pyllbc_PyStreamEncodeSelf;
        PyStreamEncodeSelf.ml_flags = METH_VARARGS;
        PyStreamEncodeSelf.ml_doc = "pyllbc library method/function";
        PyStreamIsExprCompiled.ml_name = "PyStreamIsExprCompiled";
        PyStreamIsExprCompiled.ml_meth = (PyCFunction)_pyllbc_PyStreamIsExprCompiled;
        PyStreamIsExprCompiled.ml_flags = METH_VARARGS;
        PyStreamIsExprCompiled.ml_doc = "pyllbc library method/function";
        PyStreamGetRaw.ml_name = "PyStreamGetRaw";
        PyStreamGetRaw.ml_meth = (PyCFunction)_pyllbc_PyStreamGetRaw;
        PyStreamGetRaw.ml_flags = METH_VARARGS;
        PyStreamGetRaw.ml_doc = "pyllbc library method/function";
        PyStreamSetCacheLimit.ml_name = "PyStreamSetCacheLimit";
        PyStreamSetCacheLimit.ml_meth = (PyCFunction)_pyllbc_PyStreamSetCacheLimit;
        PyStreamSetCacheLimit.ml_flags = METH_VARARGS;
        PyStreamSetCacheLimit.ml_doc = "pyllbc library method/function";
    }

public:
    ::PyMethodDef PyStreamFmtWrite;
    ::PyMethodDef PyStreamRead_Double;
    ::PyMethodDef PyStreamWrite_Bool;
    ::PyMethodDef PyStreamRead_Byte;
    ::PyMethodDef SetPyStreamPos;
    ::PyMethodDef PyStreamRead_Stream;
    ::PyMethodDef PyStreamWrite;
    ::PyMethodDef NewPyStream;
    ::PyMethodDef PyStreamRead;
    ::PyMethodDef GetPyStreamPos;
    ::PyMethodDef PyStreamFmtRead;
    ::PyMethodDef PyStreamWrite_PyLong;
    ::PyMethodDef PyStreamRead_ByteArray;
    ::PyMethodDef PyStreamRead_Bool;
    ::PyMethodDef PyStreamWrite_Int16;
    ::PyMethodDef PyStreamGetCachedSize;
    ::PyMethodDef PyStreamRead_Str;
    ::PyMethodDef DelPyStream;
    ::PyMethodDef PyStreamWrite_Double;
    ::PyMethodDef PyStreamDiscardAllExprs;
    ::PyMethodDef PyStreamRead_Int16;
    ::PyMethodDef PyStreamRead_Int32;
    ::PyMethodDef PyStreamWrite_Buffer;
    ::PyMethodDef SetPyStreamEndian;
    ::PyMethodDef PyStreamRead_Float;
    ::PyMethodDef GetVersionInfo;
    ::PyMethodDef PyStreamWrite_Byte;
    ::PyMethodDef PyStreamRead_Str2;
    ::PyMethodDef PyStreamRead_Buffer;
    ::PyMethodDef PyStreamWrite_Float;
    ::PyMethodDef PyStreamDiscardExpr;
    ::PyMethodDef SetPyStreamSize;
    ::PyMethodDef GetPyStreamEndian;
    ::PyMethodDef PyStreamRead_None;
    ::PyMethodDef PyStreamWrite_PyInt;
    ::PyMethodDef PyStreamWrite_ByteArray;
    ::PyMethodDef GetPyStreamSize;
    ::PyMethodDef PyStreamRead_PyInt;
    ::PyMethodDef PyStreamWrite_Str;
    ::PyMethodDef PyStreamWrite_None;
    ::PyMethodDef PyStreamGetCacheLimit;
    ::PyMethodDef PyStreamRead_Int64;
    ::PyMethodDef PyStreamWrite_Int32;
    ::PyMethodDef PyStreamWrite_Int64;
    ::PyMethodDef PyStreamWrite_Sequence;
    ::PyMethodDef PyStreamWrite_Tuple;
    ::PyMethodDef PyStreamWrite_Dict;
    ::PyMethodDef PyStreamRead_PyLong;
    ::PyMethodDef PyStreamRead_Unicode;
    ::PyMethodDef PyStreamWrite_Unicode;
    ::PyMethodDef PyStreamWrite_Str2;
    ::PyMethodDef PyStreamWrite_List;
    ::PyMethodDef PyStreamWrite_Stream;
    ::PyMethodDef PyStreamSetRaw;
    ::PyMethodDef output;
    ::PyMethodDef PyStreamEncodeSelf;
    ::PyMethodDef PyStreamIsExprCompiled;
    ::PyMethodDef PyStreamGetRaw;
    ::PyMethodDef PyStreamSetCacheLimit;
};

#define pyllbc_s_CommonMethods LLBC_Singleton< ::pyllbc_CommonMethods, LLBC_DummyLock>::Instance()

#endif // !__PYLLBC_AUTOGEN__COMMONMETHODS_H__

