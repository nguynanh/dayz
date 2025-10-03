#define _ARMA_

class CfgPatches
{
	class Packable_Boats_Cargo
	{
		units[] = {
			// Boat Kits
			"Boat_01_Blue_Kit", "Boat_01_Orange_Kit", "Boat_01_Black_Kit", "Boat_01_Camo_Kit", "Boat_01_Fire_Kit",
			"Boat_01_Galaxy_Kit", "Boat_01_BW_Kit", "Boat_01_RedCamo_Kit", "Boat_01_Flower_Kit",
			"jmc_Boat_STAG_Red_Kit", "jmc_Boat_STAG_White_Kit", "jmc_Boat_STAG_Black_Kit",
			// Deployed Boats
			"Boat_01_Blue", "Boat_01_Orange", "Boat_01_Black", "Boat_01_Camo", "Boat_01_Fire",
			"Boat_01_Galaxy", "Boat_01_BW", "Boat_01_RedCamo", "Boat_01_Flower",
			"jmc_Boat_STAG_Red", "jmc_Boat_STAG_White", "jmc_Boat_STAG_Black",
			// Custom DryBags
			"DryBag_Fire", "DryBag_Flower", "DryBag_BW", "DryBag_RedCamo", "DryBag_Galaxy"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Vehicles_Water", "DZ_Characters", "DZ_Characters_Backpacks"};
	};
};

class CfgMods
{
	class Packable_Boats_Cargo
	{
		dir = "Packable_Boats_Cargo";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Packable Boats with Cargo";
		credits = "RetroMaja, Tyson";
		author = "RetroMaja, Tyson";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"Packable_Boats/scripts/4_World"};
			};
		};
	};
};

class CfgSlots
{
	class Slot_Boat_DryBag_1
	{
		name = "Boat_DryBag_1";
		displayName = "$STR_cfgVehicles_DryBag_ColorBase0";
		selection = "Boat_DryBag_1";
		ghostIcon = "back";
	};
	class Slot_Boat_DryBag_2
	{
		name = "Boat_DryBag_2";
		displayName = "$STR_cfgVehicles_DryBag_ColorBase0";
		selection = "Boat_DryBag_2";
		ghostIcon = "back";
	};
	class Slot_Boat_DryBag_3
	{
		name = "Boat_DryBag_3";
		displayName = "$STR_cfgVehicles_DryBag_ColorBase0";
		selection = "Boat_DryBag_3";
		ghostIcon = "back";
	};
	class Slot_Boat_DryBag_4
	{
		name = "Boat_DryBag_4";
		displayName = "$STR_cfgVehicles_DryBag_ColorBase0";
		selection = "Boat_DryBag_4";
		ghostIcon = "back";
	};
};

class CfgVehicles
{
	// Khai báo trước các lớp cơ sở của game
	class Container_Base;
	class BoatScript;
	class Clothing;

	// 1. Sửa đổi lớp THUYỀN cơ sở để thêm slot gắn đồ
	class Boat_01_ColorBase: BoatScript
	{
		attachments[] += {"Boat_DryBag_1", "Boat_DryBag_2", "Boat_DryBag_3", "Boat_DryBag_4"};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "Cargo";
				description = "";
				attachmentSlots[] += {"Boat_DryBag_1", "Boat_DryBag_2", "Boat_DryBag_3", "Boat_DryBag_4"};
				icon = "woodcrate";
			};
		};
	};
	
	// 2. Sửa đổi lớp TÚI cơ sở để cho phép gắn vào thuyền
	class DryBag_ColorBase: Clothing
	{
		inventorySlot[] += {"Boat_DryBag_1", "Boat_DryBag_2", "Boat_DryBag_3", "Boat_DryBag_4"};
	};

	// 3. Định nghĩa lớp cơ sở cho BỘ KIT THUYỀN (vật phẩm đóng gói)
	class Boat_01_Base_Kit: Container_Base
	{
		scope = 0; // Ẩn lớp cơ sở này
		displayName = "Boat Kit Base";
		descriptionShort = "A packed boat. Can be deployed on water surfaces.";
		model = "\dz\gear\containers\WaterproofBag.p3d";
		weight = 350;
		itemSize[] = {3,4};
		itemsCargoSize[] = {0,0};
		allowOwnedCargoManipulation = 1;
		canBeDigged = 0;
		varWetMax = 0;
		hiddenSelections[] = {"camoGround"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
				};
			};
		};
	};

	// 4. Định nghĩa các BỘ KIT THUYỀN cụ thể mà người chơi có thể tìm thấy
	class Boat_01_Blue_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat Blue";
		projectionTypename = "Boat_01_Blue";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_blue_kit_co.paa"};
	};
	class Boat_01_Orange_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat Orange";
		projectionTypename = "Boat_01_Orange";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_orange_kit_co.paa"};
	};
	class Boat_01_Black_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat Black";
		projectionTypename = "Boat_01_Black";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_black_kit_co.paa"};
	};
	class Boat_01_Camo_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat Camo";
		projectionTypename = "Boat_01_Camo";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_camo_kit_co.paa"};
	};
	class Boat_01_Fire_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat Fire";
		projectionTypename = "Boat_01_Fire";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_fire_kit_co.paa"};
	};
	class Boat_01_Galaxy_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat Galaxy";
		projectionTypename = "Boat_01_Galaxy";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_galaxy_kit_co.paa"};
	};
	class Boat_01_BW_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat BW";
		projectionTypename = "Boat_01_BW";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_bw_kit_co.paa"};
	};
	class Boat_01_RedCamo_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat Red Camo";
		projectionTypename = "Boat_01_RedCamo";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_redcamo_kit_co.paa"};
	};
	class Boat_01_Flower_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat Flower";
		projectionTypename = "Boat_01_Flower";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_flower_kit_co.paa"};
	};
	class jmc_Boat_STAG_Red_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat S.T.A.G. Red";
		projectionTypename = "jmc_Boat_STAG_Red";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\jmc_boat_stag_red_kit_co.paa"};
	};
	class jmc_Boat_STAG_White_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat S.T.A.G. White";
		projectionTypename = "jmc_Boat_STAG_White";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\jmc_boat_stag_white_kit_co.paa"};
	};
	class jmc_Boat_STAG_Black_Kit: Boat_01_Base_Kit
	{
		scope = 2;
		displayName = "Packed Boat S.T.A.G. Black";
		projectionTypename = "jmc_Boat_STAG_Black";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\jmc_boat_stag_black_kit_co.paa"};
	};

	// 5. Định nghĩa các THUYỀN thực tế (được tạo ra khi mở kit)
	class Boat_01_Blue: Boat_01_ColorBase { scope = 2; };
	class Boat_01_Orange: Boat_01_ColorBase { scope = 2; };
	class Boat_01_Black: Boat_01_ColorBase { scope = 2; };
	class Boat_01_Camo: Boat_01_ColorBase { scope = 2; };
	class jmc_Boat_STAG_Red: Boat_01_ColorBase { scope = 2; };
	class jmc_Boat_STAG_White: Boat_01_ColorBase { scope = 2; };
	class jmc_Boat_STAG_Black: Boat_01_ColorBase { scope = 2; };

	class Boat_01_Fire: Boat_01_ColorBase
	{
		scope = 2;
		model = "\Packable_Boats\proxies\drybag_1.p3d";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_fire_co.paa", "\Packable_Boats\Data\boat_01_fire_co.paa"};
	};
	class Boat_01_Galaxy: Boat_01_ColorBase
	{
		scope = 2;
		model = "\Packable_Boats\proxies\drybag_1.p3d";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_galaxy_co.paa", "\Packable_Boats\Data\boat_01_galaxy_co.paa"};
	};
	class Boat_01_BW: Boat_01_ColorBase
	{
		scope = 2;
		model = "\Packable_Boats\proxies\drybag_1.p3d";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_bw_co.paa", "\Packable_Boats\Data\boat_01_bw_co.paa"};
	};
	class Boat_01_RedCamo: Boat_01_ColorBase
	{
		scope = 2;
		model = "\Packable_Boats\proxies\drybag_1.p3d";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_redcamo_co.paa", "\Packable_Boats\Data\boat_01_redcamo_co.paa"};
	};
	class Boat_01_Flower: Boat_01_ColorBase
	{
		scope = 2;
		model = "\Packable_Boats\proxies\drybag_1.p3d";
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\boat_01_flower_co.paa", "\Packable_Boats\Data\boat_01_flower_co.paa"};
	};

	// 6. Định nghĩa các TÚI tùy chỉnh có thể gắn lên thuyền
	class DryBag_Fire: DryBag_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"Packable_Boats\Data\drybag_fire_co.paa", "Packable_Boats\Data\drybag_fire_co.paa", "Packable_Boats\Data\drybag_fire_co.paa"};
	};
	class DryBag_Flower: DryBag_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\drybag_flower_co.paa", "\Packable_Boats\Data\drybag_flower_co.paa", "\Packable_Boats\Data\drybag_flower_co.paa"};
	};
	class DryBag_BW: DryBag_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\drybag_bw_co.paa", "\Packable_Boats\Data\drybag_bw_co.paa", "\Packable_Boats\Data\drybag_bw_co.paa"};
	};
	class DryBag_RedCamo: DryBag_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\drybag_redcamo_co.paa", "\Packable_Boats\Data\drybag_redcamo_co.paa", "\Packable_Boats\Data\drybag_redcamo_co.paa"};
	};
	class DryBag_Galaxy: DryBag_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\Packable_Boats\Data\drybag_galaxy_co.paa", "\Packable_Boats\Data\drybag_galaxy_co.paa", "\Packable_Boats\Data\drybag_galaxy_co.paa"};
	};
};