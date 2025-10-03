class Boat_01_Base_Kit : ItemBase
{
	void Boat_01_Base_Kit()
	{
		
	}
	
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);
		
		if (GetGame().IsServer())
		{
			Boat_01_ColorBase boatitem = Boat_01_ColorBase.Cast(GetGame().CreateObjectEx(GetType().Substring(0,GetType().Length() - 4), position, ECE_PLACE_ON_SURFACE));
			boatitem.SetPosition(position);
			boatitem.SetOrientation(orientation);
			
		}
	}
	
	override string GetPlaceSoundset()
	{
		return "drivergetin_0_SoundSet";
	}
	
	override bool IsBasebuildingKit()
	{
		return true;
	}

	override bool IsDeployable()
	{
		return true;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
};

class Boat_01_Blue_Kit : Boat_01_Base_Kit{};
class Boat_01_Black_Kit : Boat_01_Base_Kit{};
class Boat_01_Orange_Kit : Boat_01_Base_Kit{};
class Boat_01_Camo_Kit : Boat_01_Base_Kit{};
class Boat_01_Fire_Kit : Boat_01_Base_Kit{};
class Boat_01_Galaxy_Kit : Boat_01_Base_Kit{};
class Boat_01_BW_Kit : Boat_01_Base_Kit{};
class Boat_01_RedCamo_Kit : Boat_01_Base_Kit{};
class Boat_01_Flower_Kit : Boat_01_Base_Kit{};

#ifdef DeerIsleScripts
class jmc_Boat_STAG_Red_Kit : Boat_01_Base_Kit{};
class jmc_Boat_STAG_White_Kit : Boat_01_Base_Kit{};
class jmc_Boat_STAG_Black_Kit : Boat_01_Base_Kit{};

#endif