#pragma once

#include <types.hpp>

enum class CustomVehicleModelInfoType : int
{
	Size = 1,
	FrontSeat,
	RearSeat,
	PetrolCap,
	WheelsFront,
	WheelsRear,
	WheelsMid,
	FrontBumperZ,
	RearBumperZ
};

struct CustomVehicleModelView
{
	int Passengers = 0;
	int GtaAnalog = -1;
	Vector3 Size {};
	Vector3 FrontSeat {};
	Vector3 RearSeat {};
	Vector3 PetrolCap {};
	Vector3 FrontWheel {};
	Vector3 RearWheel {};
	Vector3 MidWheel {};
	float FrontBumperZ = 0.f;
	float RearBumperZ = 0.f;
};

struct CustomSkinModelView
{
	int GtaAnalog = -1;
};

struct ICustomModelRegistry
{
	virtual ~ICustomModelRegistry() = default;

	virtual bool isValidVehicleModel(int model) const = 0;
	virtual bool getVehicleModel(int model, CustomVehicleModelView& out) const = 0;
	virtual bool getVehicleModelData(int model, CustomVehicleModelInfoType type, Vector3& out) const = 0;
	virtual bool isValidSkinModel(int model) const = 0;
	virtual bool getSkinModel(int model, CustomSkinModelView& out) const = 0;
};

// Implemented by GambitClient in Server/Source/launcher_impl.hpp.
ICustomModelRegistry& getCustomModelRegistry();

inline int resolveStreamSkinId(int skinId, const CustomSkinModelView& skinInfo, bool viewerIsGambitClient)
{
	if (skinInfo.GtaAnalog != -1 && !viewerIsGambitClient)
	{
		return skinInfo.GtaAnalog;
	}

	return skinId;
}

inline int resolveStreamVehicleModelId(int modelId, const CustomVehicleModelView& vehicleInfo, bool viewerIsGambitClient)
{
	if (vehicleInfo.GtaAnalog != -1 && !viewerIsGambitClient)
	{
		return vehicleInfo.GtaAnalog;
	}

	return modelId;
}
