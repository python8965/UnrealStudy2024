// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "URSAnimInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALSTUDY0325_URSAnimInstance_generated_h
#error "URSAnimInstance.generated.h already included, missing '#pragma once' in URSAnimInstance.h"
#endif
#define UNREALSTUDY0325_URSAnimInstance_generated_h

#define FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAnimNotify_NextAttackCheck); \
	DECLARE_FUNCTION(execAnimNotify_AttackHitCheck);


#define FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUURSAnimInstance(); \
	friend struct Z_Construct_UClass_UURSAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UURSAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/UnrealStudy0325"), NO_API) \
	DECLARE_SERIALIZER(UURSAnimInstance)


#define FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UURSAnimInstance(UURSAnimInstance&&); \
	UURSAnimInstance(const UURSAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UURSAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UURSAnimInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UURSAnimInstance) \
	NO_API virtual ~UURSAnimInstance();


#define FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_14_PROLOG
#define FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_17_INCLASS_NO_PURE_DECLS \
	FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALSTUDY0325_API UClass* StaticClass<class UURSAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
