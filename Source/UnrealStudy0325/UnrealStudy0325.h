// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(UnrealStudy, Log, All);

#define UNREALSTUDY_CALLINFO (FString(__FUNCTION__) + TEXT("{") + FString::FromInt(__LINE__) + TEXT("}"))

#define UNREALSTUDY_SIMPLE(Verbosity) UE_LOG(UnrealStudy, Verbosity, TEXT("%s"), *UNREALSTUDY_CALLINFO)

#define UNREALSTUDY_UELOG(Verbosity, Format, ...) UE_LOG(UnrealStudy, Verbosity, TEXT("%s %s"), *UNREALSTUDY_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

#define UNREALSTUDY_CHECK(Expr, ...) { if(!(Expr)) {UNREALSTUDY_UELOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; } }