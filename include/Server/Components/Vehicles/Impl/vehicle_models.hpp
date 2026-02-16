#pragma once

#include "vehicles.hpp"
#include <types.hpp>

#include "../../../../../Server/Source/launcher_impl.hpp"

static bool getVehicleModelInfo(int model, GambitClient::VehicleModelInfoType type, Vector3& out)
{
	GambitClient& client = GambitClient::Instance();

	if (!client.IsValidVehicleModel(model))
	{
		return false;
	}

	return client.GetVehicleModelData(model, GambitClient::VehicleModelInfoType(type), out);
}
