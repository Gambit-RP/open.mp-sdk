#pragma once

#include <Server/Components/CustomModels/custom_model_registry.hpp>

namespace Impl
{

/// Returns 0xFF for invalid vehicles, and returns 0 for vehicles with only a driver.
inline uint8_t getVehiclePassengerSeats(int model)
{
	ICustomModelRegistry& registry = getCustomModelRegistry();

	if (!registry.isValidVehicleModel(model))
	{
		return 0xFF;
	}

	CustomVehicleModelView vehicle {};

	if (!registry.getVehicleModel(model, vehicle))
	{
		return 0xFF;
	}

	return vehicle.Passengers;
}

}
