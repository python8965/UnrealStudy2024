// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealStudy0325/Public/URSAnimInstance.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeURSAnimInstance() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
UNREALSTUDY0325_API UClass* Z_Construct_UClass_UURSAnimInstance();
UNREALSTUDY0325_API UClass* Z_Construct_UClass_UURSAnimInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_UnrealStudy0325();
// End Cross Module References

// Begin Class UURSAnimInstance Function AnimNotify_AttackHitCheck
struct Z_Construct_UFunction_UURSAnimInstance_AnimNotify_AttackHitCheck_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/URSAnimInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UURSAnimInstance_AnimNotify_AttackHitCheck_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UURSAnimInstance, nullptr, "AnimNotify_AttackHitCheck", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UURSAnimInstance_AnimNotify_AttackHitCheck_Statics::Function_MetaDataParams), Z_Construct_UFunction_UURSAnimInstance_AnimNotify_AttackHitCheck_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UURSAnimInstance_AnimNotify_AttackHitCheck()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UURSAnimInstance_AnimNotify_AttackHitCheck_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UURSAnimInstance::execAnimNotify_AttackHitCheck)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AnimNotify_AttackHitCheck();
	P_NATIVE_END;
}
// End Class UURSAnimInstance Function AnimNotify_AttackHitCheck

// Begin Class UURSAnimInstance Function AnimNotify_NextAttackCheck
struct Z_Construct_UFunction_UURSAnimInstance_AnimNotify_NextAttackCheck_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/URSAnimInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UURSAnimInstance_AnimNotify_NextAttackCheck_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UURSAnimInstance, nullptr, "AnimNotify_NextAttackCheck", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UURSAnimInstance_AnimNotify_NextAttackCheck_Statics::Function_MetaDataParams), Z_Construct_UFunction_UURSAnimInstance_AnimNotify_NextAttackCheck_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UURSAnimInstance_AnimNotify_NextAttackCheck()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UURSAnimInstance_AnimNotify_NextAttackCheck_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UURSAnimInstance::execAnimNotify_NextAttackCheck)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AnimNotify_NextAttackCheck();
	P_NATIVE_END;
}
// End Class UURSAnimInstance Function AnimNotify_NextAttackCheck

// Begin Class UURSAnimInstance
void UURSAnimInstance::StaticRegisterNativesUURSAnimInstance()
{
	UClass* Class = UURSAnimInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AnimNotify_AttackHitCheck", &UURSAnimInstance::execAnimNotify_AttackHitCheck },
		{ "AnimNotify_NextAttackCheck", &UURSAnimInstance::execAnimNotify_NextAttackCheck },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UURSAnimInstance);
UClass* Z_Construct_UClass_UURSAnimInstance_NoRegister()
{
	return UURSAnimInstance::StaticClass();
}
struct Z_Construct_UClass_UURSAnimInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "URSAnimInstance.h" },
		{ "ModuleRelativePath", "Public/URSAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPawnSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "Public/URSAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsInAir_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "Public/URSAnimInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackMontage_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Public/URSAnimInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentPawnSpeed;
	static void NewProp_bIsInAir_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsInAir;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackMontage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UURSAnimInstance_AnimNotify_AttackHitCheck, "AnimNotify_AttackHitCheck" }, // 2362749372
		{ &Z_Construct_UFunction_UURSAnimInstance_AnimNotify_NextAttackCheck, "AnimNotify_NextAttackCheck" }, // 1812269820
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UURSAnimInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UURSAnimInstance_Statics::NewProp_CurrentPawnSpeed = { "CurrentPawnSpeed", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UURSAnimInstance, CurrentPawnSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPawnSpeed_MetaData), NewProp_CurrentPawnSpeed_MetaData) };
void Z_Construct_UClass_UURSAnimInstance_Statics::NewProp_bIsInAir_SetBit(void* Obj)
{
	((UURSAnimInstance*)Obj)->bIsInAir = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UURSAnimInstance_Statics::NewProp_bIsInAir = { "bIsInAir", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UURSAnimInstance), &Z_Construct_UClass_UURSAnimInstance_Statics::NewProp_bIsInAir_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsInAir_MetaData), NewProp_bIsInAir_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UURSAnimInstance_Statics::NewProp_AttackMontage = { "AttackMontage", nullptr, (EPropertyFlags)0x0040000000030015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UURSAnimInstance, AttackMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackMontage_MetaData), NewProp_AttackMontage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UURSAnimInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UURSAnimInstance_Statics::NewProp_CurrentPawnSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UURSAnimInstance_Statics::NewProp_bIsInAir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UURSAnimInstance_Statics::NewProp_AttackMontage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UURSAnimInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UURSAnimInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_UnrealStudy0325,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UURSAnimInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UURSAnimInstance_Statics::ClassParams = {
	&UURSAnimInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UURSAnimInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UURSAnimInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UURSAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UURSAnimInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UURSAnimInstance()
{
	if (!Z_Registration_Info_UClass_UURSAnimInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UURSAnimInstance.OuterSingleton, Z_Construct_UClass_UURSAnimInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UURSAnimInstance.OuterSingleton;
}
template<> UNREALSTUDY0325_API UClass* StaticClass<UURSAnimInstance>()
{
	return UURSAnimInstance::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UURSAnimInstance);
UURSAnimInstance::~UURSAnimInstance() {}
// End Class UURSAnimInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UURSAnimInstance, UURSAnimInstance::StaticClass, TEXT("UURSAnimInstance"), &Z_Registration_Info_UClass_UURSAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UURSAnimInstance), 4122835234U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_2747097481(TEXT("/Script/UnrealStudy0325"),
	Z_CompiledInDeferFile_FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealStudy0325_Source_UnrealStudy0325_Public_URSAnimInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
