/*
#############################################################################################
# Tribes Ascend (1.4.2913.0) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
# ========================================================================================= #
# File: SdkHeaders.h
# ========================================================================================= #
# Credits: uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL
# Thanks: HOOAH07, lowHertz
# Forums: www.uc-forum.com, www.gamedeception.net
#############################################################################################
*/

#pragma once

#include <string>

/*
# ========================================================================================= #
# Defines
# ========================================================================================= #
*/

#define GObjects            0x013B7D78
#define GNames              0x01375A68

/*
# ========================================================================================= #
# Structs
# ========================================================================================= #
*/

template< class T > struct TArray 
{ 
public: 
    T* Data; 
    int Count; 
    int Max; 

public: 
    TArray() 
    { 
        Data = NULL; 
        Count = Max = 0; 
    }; 

    TArray(const TArray &arr)
    {
        Data = (T *)malloc(arr.Count * sizeof(T));
        if (Data)
            memcpy(Data, arr.Data, arr.Count * sizeof(T));
        Count = arr.Count;
        Max = arr.Max;
    }

public: 
    int Num() 
    { 
        return this->Count; 
    }; 

    T& operator() ( int i ) 
    { 
        return this->Data[ i ]; 
    }; 

    T *Get(int i)
    {
        return this->Data + i;
    };

    T &GetRef(int i)
    {
        return this->Data[i];
    };

    T GetStd(int i)
    {
        return this->Data[i];
    };

    void Set(int i, T val)
    {
        this->Data[i] = val;
    };

    const T& operator() ( int i ) const 
    { 
        return this->Data[ i ]; 
    }; 

    void Add ( T InputData ) 
    { 
        Data = (T*) realloc ( Data, sizeof ( T ) * ( Count + 1 ) ); 
        Data[ Count++ ] = InputData; 
        Max = Count; 
    }; 

    void Remove(int i)
    {
        memmove(Data + i, Data + (i + 1), (Count - (i + 1)) * sizeof(T));
        --Count;
    };

    void Clear() 
    { 
        free ( Data ); 
        Data = NULL; 
        Count = Max = 0; 
    }; 
}; 

struct FNameEntry 
{ 
    unsigned char    UnknownData00[ 0x10 ]; 
    char            Name[ 0x10 ]; 
}; 

struct FName 
{ 
    int                Index; 
    unsigned char    unknownData00[ 0x4 ]; 

    FName() : Index ( 0 ) {}; 

    FName ( int i ) : Index ( i ) {}; 

    ~FName() {}; 

    FName ( const char* FindName ) 
    { 
        static TArray< int > NameCache; 
        Index = 0;

        for ( int i = 0; i < NameCache.Count; ++i ) 
        { 
        if ( ! strcmp ( this->Names()->Data[ NameCache ( i ) ]->Name, FindName ) ) 
            { 
                Index = NameCache ( i ); 
                return; 
            } 
        } 

        for ( int i = 0; i < this->Names()->Count; ++i ) 
        { 
            if ( this->Names()->Data[ i ] ) 
            { 
                if ( ! strcmp ( this->Names()->Data[ i ]->Name, FindName ) ) 
                { 
                    NameCache.Add ( i ); 
                    Index = i; 
                } 
            } 
        } 
    }; 

    static TArray< FNameEntry* >* Names() 
    { 
        return (TArray< FNameEntry* >*) GNames; 
    }; 

    char* GetName() 
    { 
        char *ret = this->Names()->Data[Index]->Name;
        return ret ? ret : "(null)";
    }; 

    bool operator == ( const FName& A ) const 
    { 
        return ( Index == A.Index ); 
    }; 
}; 

struct FString : public TArray< wchar_t > 
{ 
    FString() {}; 

    FString ( wchar_t* Other ) 
    { 
        this->Max = this->Count = *Other ? ( wcslen ( Other ) + 1 ) : 0; 

        if ( this->Count ) 
            this->Data = Other; 
    }; 

    ~FString() {}; 

    FString operator = ( wchar_t* Other ) 
    { 
        if ( this->Data != Other ) 
        { 
            this->Max = this->Count = *Other ? ( wcslen ( Other ) + 1 ) : 0; 

            if ( this->Count ) 
                this->Data = Other; 
        } 

        return *this; 
    }; 
}; 

struct FScriptDelegate 
{ 
    unsigned char UnknownData00[ 0xC ]; 
}; 

/*
# ========================================================================================= #
# Includes
# ========================================================================================= #
*/

#include "SDK_HEADERS\Core_structs.h"
#include "SDK_HEADERS\Core_classes.h"
#include "SDK_HEADERS\Core_f_structs.h"
#include "SDK_HEADERS\Engine_structs.h"
#include "SDK_HEADERS\Engine_classes.h"
#include "SDK_HEADERS\Engine_f_structs.h"
#include "SDK_HEADERS\GameFramework_structs.h"
#include "SDK_HEADERS\GameFramework_classes.h"
#include "SDK_HEADERS\GameFramework_f_structs.h"
#include "SDK_HEADERS\UDKBase_structs.h"
#include "SDK_HEADERS\UDKBase_classes.h"
#include "SDK_HEADERS\UDKBase_f_structs.h"
#include "SDK_HEADERS\GFxUI_structs.h"
#include "SDK_HEADERS\GFxUI_classes.h"
#include "SDK_HEADERS\GFxUI_f_structs.h"
#include "SDK_HEADERS\UTGame_structs.h"
#include "SDK_HEADERS\UTGame_classes.h"
#include "SDK_HEADERS\UTGame_f_structs.h"
#include "SDK_HEADERS\IpDrv_structs.h"
#include "SDK_HEADERS\IpDrv_classes.h"
#include "SDK_HEADERS\IpDrv_f_structs.h"
#include "SDK_HEADERS\PlatformCommon_structs.h"
#include "SDK_HEADERS\PlatformCommon_classes.h"
#include "SDK_HEADERS\PlatformCommon_f_structs.h"
#include "SDK_HEADERS\TribesGame_structs.h"
#include "SDK_HEADERS\TribesGame_classes.h"
#include "SDK_HEADERS\TribesGame_f_structs.h"
#include "SDK_HEADERS\XAudio2_structs.h"
#include "SDK_HEADERS\XAudio2_classes.h"
#include "SDK_HEADERS\XAudio2_f_structs.h"
#include "SDK_HEADERS\WinDrv_structs.h"
#include "SDK_HEADERS\WinDrv_classes.h"
#include "SDK_HEADERS\WinDrv_f_structs.h"
#include "SDK_HEADERS\OnlineSubsystemMcts_structs.h"
#include "SDK_HEADERS\OnlineSubsystemMcts_classes.h"
#include "SDK_HEADERS\OnlineSubsystemMcts_f_structs.h"
#include "SDK_HEADERS\TribesGameContent_structs.h"
#include "SDK_HEADERS\TribesGameContent_classes.h"
#include "SDK_HEADERS\TribesGameContent_f_structs.h"
