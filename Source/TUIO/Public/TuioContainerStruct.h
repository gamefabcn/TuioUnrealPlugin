// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TUIO/TuioContainer.h"
#include "Math/Vector2D.h"
#include "CoreMinimal.h"
#include "TuioContainerStruct.generated.h"

/**
 * TUIO Container Struct（已修复 UE5.7.4 初始化警告）
 */
USTRUCT(BlueprintType)
struct FTuioContainerStruct
{
	GENERATED_BODY()

	/** 默认构造函数 - 显式初始化所有成员（解决 UE UHT 警告） */
	FTuioContainerStruct()
		: Position(0.0f, 0.0f)
		, Speed(0.0f, 0.0f)
		, SessionID(0.0f)
		, SourceID(0.0f)
		, Timestamp(0.0)
	{}

	/** 从 TUIO::TuioContainer 转换构造函数（保持原功能） */
	FTuioContainerStruct(const TUIO::TuioContainer& source);

	/**
	 * Coordinates of the touch event.
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_t_u_i_o_point.html#a547710f33dd3786eaa8ca326b34911c0
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	FVector2D Position;

	/**
	 * Velocity of the touch event.
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_t_u_i_o_container.html#ad71a4dba72e5c46fa8b8f7fc0f961705
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	FVector2D Speed;

	/**
	 * TUIO session ID (device) for this touch event.
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_t_u_i_o_container.html#a43a9b95e3108a178e16c8d86a9816f8a
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	float SessionID;

	/**
	 * TUIO source ID (finger) for this touch event.
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_t_u_i_o_container.html#a667ab7e367870bd5feabe91289309fbe
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	float SourceID;

	/**
	 * Timestamp of the touch event, in seconds.
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_t_u_i_o_point.html#ac86687cf27772d0fd602c2044b6c8cdd
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_t_u_i_o_time.html#ac403aea1a8928e714f9f6388f488fa33
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	double Timestamp;
};
