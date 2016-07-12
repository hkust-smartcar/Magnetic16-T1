/*
 * pResource.cpp
 *
 * Author: Peter
 * Copyright (c) 2014-2015 HKUST SmartCar Team
 * Refer to LICENSE for details
 */

#include <libsc/system.h>
#include <pResource.h>
#include <pFlash.h>

using namespace libsc;
using namespace std;

// UNIQUE_VAL SHOULD NOT be 255
//
// Change it if u changed the config table
// otherwise the config table in flash memory
// won't update
#define UNIQUE_VAL	80

pResource::ConfigTable	pResource::configTable;
pResource				*pResource::m_instance = nullptr;

pResource::pResource(void)
:
	pFlash(pFlash::Config(&configTable, sizeof(pResource::ConfigTable))),
	pSmartCar()
{
	System::Init();

	if (m_instance)
		assert(false);
	else
		m_instance = this;

	if (UNIQUE_VAL != ((ConfigTable *)getConfigTablePtr())->kUniqueVal)
	{
		pBuzzer::setEnabled(true);
		pBuzzer::noteDown(32, pBuzzer::defaultValue, pBuzzer::defaultValue, 100);
		pBuzzer::noteDown(48, pBuzzer::defaultValue, 50, 100);
		pBuzzer::setEnabled(false);
		reset();
	}

	if (!getConfigTablePtr())
		assert(false);
	else
		readConfig(&configTable, ((ConfigTable *)getConfigTablePtr())->kTableSize);

	if (configTable.kIsExist)
	{
		setInitialConfigTable();
		saveConfig();
	}
	else if (configTable.kTableSize != sizeof(ConfigTable))
	{
		setInitialConfigTable();
		saveConfig();
	}
}

void pResource::reset(void)
{
	eraseAll();
	setInitialConfigTable();
	saveConfig();
}

void pResource::saveConfig(void)
{
	writeConfig(&configTable);
}

void pResource::grapherOnChangedListener(void)
{
	m_instance->saveConfig();
}

void pResource::setInitialConfigTable(void)
{
	configTable.kIsExist = false;
	configTable.kTableSize = sizeof(ConfigTable);
	configTable.kUniqueVal = UNIQUE_VAL;

	configTable.kBatteryVoltageRatio = 0.3886279f;

	configTable.kAccelTruthVal = 0.6f;

	configTable.kIdealAngle = 72.0f;
	configTable.kAngleRange = 30.0f;

	configTable.kAngleKp = 94000.0f;
	configTable.kAngleKi = 0.0f;
	configTable.kAngleKd = 11.0f;
	configTable.kAngleKq = 0.001f;
	configTable.kAngleKr = 0.999f;

	configTable.kSpeedKp = 3.7f;
	configTable.kSpeedKi = 0.55;
	configTable.kSpeedKd = 0.0f;
	configTable.kSpeedKq = 0.001f;
	configTable.kSpeedKr = 0.999f;
	configTable.kAccelSpeed = 0.4f;
	configTable.kTargetSpeed = 9.5f;

	configTable.kErrorMfLimit = 1.0f;
	configTable.kErrorMfL = 0.83f;
	configTable.kErrorMfM = 0.73f;
	configTable.kErrorMfS = 0.6f;
	configTable.kErrorMfZ = 0.0f;

	configTable.kDerrorMfLimit = 200.0f;
	configTable.kDerrorMfL = 7.9f;
	configTable.kDerrorMfM = 5.7f;
	configTable.kDerrorMfS = 3.5f;
	configTable.kDerrorMfZ = 0.0f;

	configTable.kCountPerRevo = 9557.725f;
}

/**
 * kTargetSpeed: 5
 * SpeedKp: 3.49
 * SpeedKi: 0.531
 * AccelSpeed: 0.057
 * kErrorMfL = 0.83f;
 * kErrorMfM = 0.73f;
 * kErrorMfS = 0.64f;
 */


