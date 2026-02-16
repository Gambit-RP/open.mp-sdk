#pragma once

#include "vehicles.hpp"
#include <types.hpp>

#include "../../../../../Server/Source/launcher_impl.hpp"

namespace Impl
{

/// Returns 0xFF for invalid vehicles, and returns 0 for vehicles with only a driver.
inline uint8_t getVehiclePassengerSeats(int model)
{
	GambitClient& client = GambitClient::Instance();

	if (!client.IsValidVehicleModel(model))
	{
		return 0xFF;
	}

	GambitClient::VehicleModelInfo vehicle = client.GetVehicleModelInfo(model);

	return vehicle.Passengers;
}

}
