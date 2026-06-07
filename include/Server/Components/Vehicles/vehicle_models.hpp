#pragma once

#include "vehicles.hpp"
#include <Server/Components/CustomModels/custom_model_registry.hpp>
#include <types.hpp>

namespace Impl
{

inline bool getVehicleModelInfo(int model, CustomVehicleModelInfoType type, Vector3& out)
{
	ICustomModelRegistry& registry = getCustomModelRegistry();

	if (!registry.isValidVehicleModel(model))
	{
		return false;
	}

	return registry.getVehicleModelData(model, type, out);
}

}
