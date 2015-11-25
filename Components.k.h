/*     File:       Components.k.h      Contains:   Component Manager Interfaces.      Version:    Technology: QuickTime 5.0                 Release:    Universal Interfaces 3.4      Copyright:  � 1991-2001 by Apple Computer, Inc., all rights reserved. 	Disclaimer:	IMPORTANT:  This Apple software is supplied to you by Apple Computer, Inc.				("Apple") in consideration of your agreement to the following terms, and your				use, installation, modification or redistribution of this Apple software				constitutes acceptance of these terms.  If you do not agree with these terms,				please do not use, install, modify or redistribute this Apple software.				In consideration of your agreement to abide by the following terms, and subject				to these terms, Apple grants you a personal, non-exclusive license, under Apple�s				copyrights in this original Apple software (the "Apple Software"), to use,				reproduce, modify and redistribute the Apple Software, with or without				modifications, in source and/or binary forms; provided that if you redistribute				the Apple Software in its entirety and without modifications, you must retain				this notice and the following text and disclaimers in all such redistributions of				the Apple Software.  Neither the name, trademarks, service marks or logos of				Apple Computer, Inc. may be used to endorse or promote products derived from the				Apple Software without specific prior written permission from Apple.  Except as				expressly stated in this notice, no other rights or licenses, express or implied,				are granted by Apple herein, including but not limited to any patent rights that				may be infringed by your derivative works or by other works in which the Apple				Software may be incorporated.				The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO				WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED				WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR				PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE OR IN				COMBINATION WITH YOUR PRODUCTS.				IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR				CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE				GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)				ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION				OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER UNDER THEORY OF CONTRACT, TORT				(INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN				ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     Bugs?:      For bug reports, consult the following page on                 the World Wide Web:                      http://developer.apple.com/bugreporter/ */#ifndef __COMPONENTS_K__#define __COMPONENTS_K__#include <QuickTime/QuickTime.h>/*	Example usage:		#define CALLCOMPONENT_BASENAME()	Fred		#define CALLCOMPONENT_GLOBALS()	FredGlobalsHandle		#include <Components.k.h>	To specify that your component implementation does not use globals, do not #define CALLCOMPONENT_GLOBALS*/#ifdef CALLCOMPONENT_BASENAME	#ifndef CALLCOMPONENT_GLOBALS		#define CALLCOMPONENT_GLOBALS() 		#define ADD_CALLCOMPONENT_COMMA 	#else		#define ADD_CALLCOMPONENT_COMMA ,	#endif	#define CALLCOMPONENT_GLUE(a,b) a##b	#define CALLCOMPONENT_STRCAT(a,b) CALLCOMPONENT_GLUE(a,b)	#define ADD_CALLCOMPONENT_BASENAME(name) CALLCOMPONENT_STRCAT(CALLCOMPONENT_BASENAME(),name)	EXTERN_API( ComponentResult  ) ADD_CALLCOMPONENT_BASENAME(Open) (CALLCOMPONENT_GLOBALS() ADD_CALLCOMPONENT_COMMA ComponentInstance  self);	EXTERN_API( ComponentResult  ) ADD_CALLCOMPONENT_BASENAME(Close) (CALLCOMPONENT_GLOBALS() ADD_CALLCOMPONENT_COMMA ComponentInstance  self);	EXTERN_API( ComponentResult  ) ADD_CALLCOMPONENT_BASENAME(CanDo) (CALLCOMPONENT_GLOBALS() ADD_CALLCOMPONENT_COMMA short  ftnNumber);	EXTERN_API( ComponentResult  ) ADD_CALLCOMPONENT_BASENAME(Version) (CALLCOMPONENT_GLOBALS());	EXTERN_API( ComponentResult  ) ADD_CALLCOMPONENT_BASENAME(Register) (CALLCOMPONENT_GLOBALS());	EXTERN_API( ComponentResult  ) ADD_CALLCOMPONENT_BASENAME(Target) (CALLCOMPONENT_GLOBALS() ADD_CALLCOMPONENT_COMMA ComponentInstance  target);	EXTERN_API( ComponentResult  ) ADD_CALLCOMPONENT_BASENAME(Unregister) (CALLCOMPONENT_GLOBALS());	EXTERN_API( ComponentResult  ) ADD_CALLCOMPONENT_BASENAME(GetMPWorkFunction) (CALLCOMPONENT_GLOBALS() ADD_CALLCOMPONENT_COMMA ComponentMPWorkFunctionUPP * workFunction, void ** refCon);	EXTERN_API( ComponentResult  ) ADD_CALLCOMPONENT_BASENAME(GetPublicResource) (CALLCOMPONENT_GLOBALS() ADD_CALLCOMPONENT_COMMA OSType  resourceType, short  resourceID, Handle * resource);#endif	/* CALLCOMPONENT_BASENAME */#endif /* __COMPONENTS_K__ */