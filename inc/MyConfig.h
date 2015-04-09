/*
 * MyConfig.h
 *
 *  Created on: Mar 10, 2015
 *      Author: Peter
 */

#pragma once

class MyConfig
{

public:

	enum struct SmartCarPowerMode
	{
		kNormalMode = 0,
		kLowFrictionMode,
		kRcCarMode
	};

	enum struct SmartCarTurning
	{
		kStraightLine = 0,
		k90Degree,
		kCrossRoad,
		kNone
	};

	enum struct SmartCarPosition
	{
		kLeft = -1,
		kIdeal,
		kRight,
		kNone
	};

	enum struct SmartCarStatus
	{
		kNormal = 0,
		kGGed,
		kNone
	};

	// Put All Configuration Here

	// MyMotorPID
	// Kp:2.3 Pu: 140ms
	float			MyMotorSpeedControlRef = 60.0f;
	float			MyMotorSpeedControlKp = 0.25f;
	float			MyMotorSpeedControlKi = 0.0f;
	float			MyMotorSpeedControlKd = 1.8f;

	// MyServoTurningPID
	float			MyServoTurningRef = 0.0f;
	float			MyServoTurningKp = 2000.0f;
	float			MyServoTurningKi = 0.0f;
	float			MyServoTurningKd = 0.0f;

	// MyMagSen
	uint8_t			MyMagSenPairCount = 3;
	uint8_t			MyMagSenPairId0 = 0;
	uint8_t			MyMagSenPairId1 = 2;
	uint8_t			MyMagSenPairId2 = 4;

	float			MyMagSenFilterQ = 0.0005f;
	float			MyMagSenFilterR = 0.43f;

	float			MyMagSenDistanceWhenMaxDiff = 10.0f;
	float			MyMagMaxSenReadingDiff = 1.4f;

	float			MyMagSenSDWeakValue = 0.25f;
	float			MyMagSenSDStrongValue = 1.5f;

	float			MyMagSenHDWeakValue = 0.3050f;
	float			MyMagSenHDStrongValue = 1.05f;

	float			MyMagSenFDStrongValue = 1.85f;
	float			MyMagSenFDWeakValue = 0.34f;

	// MyLeds

	// MyServo
	uint8_t			MyServoId = 0;
	float			MyServoDefaultMaxSDValue = 0.0f;
	float			MyServoDefaultMinSDValue = 0.0f;
	float			MyServoDefaultMaxFDValue = 0.0f;
	float			MyServoDefaultMinFDValue = 0.0f;
	float			MyServoDefaultMaxLRValue = 0.0f;
	float			MyServoDefaultMinLRValue = 0.0f;

	float			MyServoCrossRoadKp = 2000.0f;
	float			MyServo90DegreeKp = 2000.0f;

	// MyMotor
	uint8_t			MyMotorId = 0;
	int32_t			MyEncoderTargetCount = 1000;

	// MyEncoder
	uint8_t			MyEncoderId = 0;

	// MyBatteryMeter
	float			MyBatteryMeterVoltageRatio = 0.32984f;
	float			MyBatteryMeterUpdateEvery = 0.02f;
	float			MyBatteryMeterVoltageMax = 8.25f;
	float			MyBatteryMeterVoltageMin = 7.5f;

	uint16_t		MyBatteryMeterHighColor = 0x063F;
	uint16_t		MyBatteryMeterNormalColor = 0x07E0;
	uint16_t		MyBatteryMeterLowColor = 0xF800;

	// MyLcd
	uint16_t		MyLcdBackgroundColor = 0x0000;
	uint16_t		MyLcdTextColor = 0xFFFF;
	bool			MyLcdIsRevert = true;
	uint8_t			MyLcdFps = 60;

	// MySmartCar
	SmartCarPowerMode
					MySmartCarPowerMode = MyConfig::SmartCarPowerMode::kNormalMode;
	SmartCarTurning
					MySmartCarTurningMode = MyConfig::SmartCarTurning::kStraightLine;
	SmartCarPosition
					MySmartCarInitialPosition = MyConfig::SmartCarPosition::kIdeal;
	SmartCarStatus
					MySmartCarInitialStatus = MyConfig::SmartCarStatus::kNormal;

};
