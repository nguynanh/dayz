modded class ModItemRegisterCallbacks
{
    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded(pType, pBehavior);
		
        pType.AddItemInHandsProfileIK("Boat_01_Base_Kit", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi",	pBehavior,	"dz/anims/anm/player/ik/two_handed/WaterproofBag.anm");	
	}
};